#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

#include <string>
using namespace std;

bool isValidemail(string& email);
bool isValidpass(string& pass);
bool isPatient_registered(string& ,string&);
bool isValidphone(string& phone_num);

bool isValiddob(string& year ,string& month ,string& day);


#endif // VALIDATION_H_INCLUDED

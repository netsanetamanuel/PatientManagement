#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "validation.h"

using namespace std;



bool isPatient_registered(string& f_name, string& l_name){
ifstream data("patient_rec.txt");


if(!data.is_open()){

    cout<<"can't open file"<<endl;
}

string line;
int countr=0;
string fieldFname , fieldLname;

while(getline(data,line)){
    stringstream ss(line);
    string field;
    int field_ctr =0;
    while(getline(ss,field,'|')){
        if(field_ctr==1){
            fieldFname=field;
        }
         if(field_ctr==2){
            fieldLname=field;
        }
        if(fieldFname==f_name&&fieldLname==l_name){
            return true;
        }
        field_ctr++;
    }
    countr++;
}
return false;

}


bool isValidpass(string& pass){

    if(pass.length()<6)
        return false;
    return true;
}

bool isValidemail(string& email){

    auto att = find(email.begin(), email.end(), '@');
    auto dot = find(att, email.end(), '.');

    if (att == email.end() || dot == email.end())
        return false;

    return true;

}


bool isValidphone(string& phone_num){
    if(phone_num.length()<7 || phone_num.length()>15)
        return false;
    for(char c: phone_num){
        if(!isdigit(c))
            return false;
    }

    return true;

}

bool isValiddob(string& year ,string& month ,string& day){
        // year validation needed
        int months = stoi(month);
         int years = stoi(year);
          int days = stoi(day);

    if (months < 1 || months > 12)
        return false;


    if(year.length()<4)
        return false;


    if (days < 1 || days > 31)
        return false;
    if(years <1000 && years >9999)
        return false;

    if ((months == 4 || months == 6 || months == 9 || months == 11) && days > 30)
        return false;

    if (months == 2) {
        if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {

          if (days > 29)
            return false;
        } else {
          if (days > 28)
            return false;
        }
      }


      return true;



}


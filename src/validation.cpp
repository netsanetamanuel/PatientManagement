#include <algorithm>
#include <string>
#include "validation.h"

using namespace std;

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

bool isValiddob(int& years ,int& months ,int& days){
        // year validation needed
    if (months < 1 || months > 12)
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


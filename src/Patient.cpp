#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Patient.h"
#include "validation.h"


using namespace std;

void Patient::patient_dashboard(){
    int choice;

    cout<<"------- PATIENT DASHBOARD -------\n"
        <<"1. My Profile \n"
        <<"2. Book Appointment \n"
        <<"3. My Appointments \n"
        <<"4. Medical Records \n"
        <<"5. Logout \n"
        <<"6. Exit \n"
        <<"Choose [1-4]: ";

    cin>>choice;
    switch(choice){
    case 1:
        show_profile();
        return;
    case 2:
        book_appointment();
        break;
    case 3:
        cout<<"uc";
        break;
    case 4:
        cout<<"uc";
        break;
    case 5:
        return;

    case 6:
        exit(0);
    default:
        cout<<"input valid value"<<endl;
        break;



    }


}

void edit_profile(){







}

void Patient::login(){

    //
    string inputemail,inputpassword;
    bool found=false;
    cout<<"-------- Login ---------- \n";
 do{
    cout<<"Email: ";
    cin>>inputemail;
    cout<<"Password: ";
    cin>>inputpassword;


    ifstream file("patient_rec.txt",ios::in);

if(!file.is_open()){
    cout<<"Error Opening File"<<endl;
    return;
}

    string line;

    int linenum = 0;

while(getline(file,line)){
    linenum++;

    stringstream ss(line);
    string field;
    string passwordF,emailF;
    int fieldindex=0;

    while(getline(ss , field , '|')){
        fieldindex++;
        if(fieldindex==4){
           emailF=field;

        }
        if(fieldindex==7) {
                passwordF=field;

        }
    }


    if(inputemail == emailF && inputpassword == passwordF){
        found = true;
        load_data(inputemail);
        patient_dashboard();

    }
}
    file.close();

if(!found){
    cout<<"invalid email or password"<<endl;
     /*cin.ignore();
    cin.get();*/
}

    // reenter fun needed
}while(!found);


}

void Patient::register_patient(){
    // patient profile registery function
    string conf_password;


    int choi;
    cout<<"---------- Patient Registration ------------- \n"
        <<"Enter Details: "<<endl;

    cout<<"Enter First Name : ";
    cin>>fName;
    cout<<"Enter Last Name : ";
    cin>>lName;
    cout<<"Enter Your Email : ";

    // calling form validation helper functions
    do{
        cin>>email;
    if(!isValidemail(email))
        cout<<"Enter Valid Email: ";
    }while(!isValidemail(email));

cout<<"Enter Your Phone Number: ";
    do{
        cin>>phone;
        if(!isValidphone(phone)){
            cout<<"Enter Valid Phone: ";
        }

    }while(!isValidphone(phone));

cout<<"Enter Date of BirthDay: ";


    do {

        cout<<"Enter Year: ";cin>>year;
        cout<<"Enter Month: ";cin>>month;
        cout<<"Enter Day: ";cin>>day;

        if(!isValiddob(year,month,day)){
            cout<<"Enter valid birth day: ";
    }
}while(!isValiddob(year,month,day));




cout<<"Enter Your Password : ";

    do{
    cin>>password;
    if(!isValidpass(password)){
        cout<<"Enter valid email: ";
    }
    }while(!isValidpass(password));

    do {
        cout << "Confirm Your password : ";
        cin >> conf_password;

        if(conf_password != password) {
            cout << "Passwords don't match! Try again." << endl;
        }

    }while(conf_password != password);

    cout<<endl;
    cout<<"1. Edit Response \n"
        <<"2. Save Response \n"
        <<"3. Back to Menu \n"
        <<"4. Exit "<<endl;
    cin>>choi;
    if(choi==1){
       register_patient();
    } else if(choi==2){
        ++pat_countr;
        id = "PA0" + to_string(pat_countr);

        save_patientrec();
        cout<<"Registration Succesfull"<<endl;

    } else if(choi ==3){
        exit(0);
    }



}

void Patient::save_patientrec(){
    // save patient response to file
    ofstream data("patient_rec.txt",ios::app);
    data <<id<<"|"
         << fName << "|"
         << lName << "|"
         << email << "|"
         << phone << "|"
         << year << "-" << month << "-" << day << "|"
         << password << endl;

    data.close();

}

void Patient::load_data(const string& pat_email){
    ifstream file("patient_rec.txt");

    if(!file.is_open()){
        cout<<"Cannot open file"<<endl;

    }

string line;
bool found = false;
while(getline(file,line)){
    stringstream ss(line);
    string currentemail,dob;
    // display current patient recored

    getline(ss, id, '|');
    getline(ss, fName, '|');
    getline(ss, lName, '|');
    getline(ss, currentemail, '|');

    if(pat_email==currentemail){

    getline(ss, phone, '|');
    getline(ss, dob, '|');
    getline(ss, password, '|');

     email = pat_email;

    found = true;
            break;

    }




}
file.close();
}
void Patient::show_profile(){

    int choice;
    cout<<"-------"<<toupper(fName)<<" Profile -------- "<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"First Name: "<<toupper(fName)<<endl;
    cout << "Last Name:  " << toupper(lName) << endl;
    cout << "Email:  " << email << endl;
    cout << "Phone:  " << phone << endl;
    cout << "Date of Birth: " << year<<"-"<<month<<"-"<<day<< endl;
    cout << "password: "<<password<<endl;
    cout<<"--------------------------------"<<endl;
    }



}






void Patient::book_appointment(){

// show available slots for patient .
// diplay doctor name , specialty , exprience , avail time

cout<<"under construction";


}


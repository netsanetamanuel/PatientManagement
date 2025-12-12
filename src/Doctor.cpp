#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Doctor.h"

using namespace std;
void Doctor::doc_dashboard(){

    int choice;

cout<<"-------Doctor Dashboard -------- \n"
    <<"1. Show Appointments \n"
    <<"2. Patient Records \n"
    <<"3. Show Profile \n"
    <<"4. Appointment Management \n"
    <<"5. Logout \n"
    <<" 6. Exit \n"
    <<"Choose [1-6]: ";
cin>>choice;

switch(choice){
    case 1:
        cout<<"UC";
        break;
    case 2:
        cout<<"UC";
        break;
    case 3:
        cout<<"UC";
        break;
    case 4:
        cout<<"UC";
        break;
    case 5:
        return;
    case 6:
        cout<<"Closing Program , Goodbye"<<endl;
        exit(0);
    default:
        cout<<"Invalid choice "<<endl;
        break;





}





void Doctor::login(){
    string input_email,input_pwd;
    bool found =false;
    cout<<"----------Login---------\n";
    do{
        cout<<"Email: ";
        cin>>input_email;
        cout<<"Password: ";
        cin>>input_pwd;

        // read data
        fstream data("doctors.txt",ios::in);
        if(!data.is_open()){
            cout<<"Error Opening Data! "<<endl;
        }

        string line;
        int line_num =0;

        while(getline(data,line)){
            line_num++;

            // read whole line of text from file
            stringstream ss(line);
            string field_str;
            int field_index=0;

            string emailf , pwdf;

            while(getline(ss,field_str,'|')){
                field_index++;
                if(field_index == 5) {
                    emailf=field_str;
                }
                if (field_index == 7 ) {
                    pwdf=field_str;
                }
            }
            if(emailf == input_email && pwdf == input_pwd){
                found = true;
                doc_dashboard();
            }
        }
        data.close();
        if(!found){
            cout<<"Invalid Input Please ,try again"<<endl;

        }
    }while(!found);

}

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
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
    <<"6. Exit \n"
    <<"Choose [1-6]: ";
cin>>choice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

switch(choice){
    case 1:
        cout<<"Show Appointment: under construction";
        break;
    case 2:
        show_patientrec();
        break;
    case 3:
        show_profile();
        return;
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
                load_data(input_email);
                doc_dashboard();
            }
        }
        data.close();
        if(!found){
            cout<<"Invalid Input Please ,try again"<<endl;

        }
    }while(!found);

}



void Doctor::show_patientrec(){

    int choice;

cout<<"======== Show Patient Record ==========\n"
    <<"1. Search By Id \n"
    <<"2. Search By Name \n"
    <<"3. Show All Patients \n"
    <<"4. Back to Menu \n"
    <<"5. Exit \n"
    <<"========================================\n"
    <<"Choose [1-5]: "<<endl;
cout<<endl;

    do{
    cin>>choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(choice){
    case 1:
        cout<<"uc";
        break;
    case 2:
        cout<<"uc";
        break;
    case 3:
        showallrec();
        break;
    default:
        cout<<"input valid input"<<endl;
        break;

    }

    }while(choice!=5);



}

void Doctor::showallrec() {


    int choice;
    cout << "\n======= ALL PATIENT RECORDS =======\n\n";

    // First, count the number of patients
    ifstream countFile("patient_rec.txt");
    if (!countFile.is_open()) {
        cout << "No patient records found or error opening file!\n";
        return;
    }

    int patientCount = 0;
    string line;

    // Count lines in files in the text
    while (getline(countFile, line)) {
        if (!line.empty()) {
            patientCount++;
        }
    }
    countFile.close();

    if (patientCount == 0) {
        cout << "No patient records available.\n";
        return;
    }

    // Create  arrays to store patient data


    string ids[patientCount];
    string fNames [patientCount];
    string lNames [patientCount];
    string emails [patientCount];
    string phones [patientCount];
    string dobs [patientCount];

    // Read and store all patient data
    ifstream dataFile("patient_rec.txt");
    int index = 0;

    while (getline(dataFile, line) && index < patientCount) {
        if (line.empty()) continue;

        stringstream ss(line); // parse the line to string

        // Read each field separated by '|'
        getline(ss, ids[index], '|');
        getline(ss, fNames[index], '|');
        getline(ss, lNames[index], '|');
        getline(ss, emails[index], '|');
        getline(ss, phones[index], '|');
        getline(ss, dobs[index], '|');
        // Password is the last field, but we won't display it for security reason since it is patient
        // cofindential data

        index++;
    }
    dataFile.close();

    // Display all patient records in a formatted table
   cout << string(220, '=')<<endl;
    cout << left << setw(8) << "ID"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(25) << "Email"
         << setw(15) << "Phone"
         << setw(15) << "Date of Birth" << endl;
    cout << string(220, '=')<<endl;



    for (int i = 0; i < patientCount; i++) {
        cout << left << setw(8) << ids[i]
             << setw(15) << fNames[i]
             << setw(15) << lNames[i]
             << setw(25) << emails[i]
             << setw(15) << phones[i]
             << setw(15) << dobs[i] << endl;
    }

    cout << string(220, '=')<<endl;
    cout << "Total Patients: " << patientCount << endl << endl;

     do{
        cout<<"1. Back to Menu \n"
            <<"2. Exit \n"
            <<"Choose [1-2]: "<<endl;
        cin>> choice;
          cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
        case 1:
             cin.ignore();
            return;
        case 2:
            exit(0);
            break;
        default:
            cout<<"invalid input"<<endl;

        }
    }while(choice!=2);



}


void Doctor::load_data(const string& doc_email){

ifstream data("doctors.txt");
if(!data.is_open()){
    cout<<"can't open file"<<endl;
    return;
}

string line;
while(getline(data,line)){
    stringstream ss(line);
    string current_email;


    string str_room = to_string(room);

        getline(ss, id, '|');
        getline(ss, fname, '|');
        getline(ss, lname, '|');
        getline(ss,speciality,'|');
        getline(ss, current_email, '|');

     if(current_email==doc_email){

        getline(ss, phone, '|');
        getline(ss, password, '|');
        getline(ss, exprience, '|');
        getline(ss, str_room, '|');
        getline(ss,slot,'|');

        email = doc_email;
        break;
     }


}
data.close();
}

void Doctor::show_profile(){

    cout<<"========= Dr"<<fname<<" =============="<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<fname + " " +lname<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"Speciality: "<<speciality<<endl;
        cout<<"Exprience: "<<exprience<<endl;
        cout<<"Duty Day: "<<slot<<endl;
        cout<<"Room: "<<room<<endl;
return;
}





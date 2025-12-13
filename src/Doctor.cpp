#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
<<<<<<< HEAD
#include <limits>
#include <iomanip>
=======
>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)
#include "Doctor.h"

using namespace std;
void Doctor::doc_dashboard(){

<<<<<<< HEAD
void Doctor::doc_dashboard(){

=======
>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)
    int choice;

cout<<"-------Doctor Dashboard -------- \n"
    <<"1. Show Appointments \n"
    <<"2. Patient Records \n"
    <<"3. Show Profile \n"
    <<"4. Appointment Management \n"
    <<"5. Logout \n"
<<<<<<< HEAD
    <<"6. Exit \n"
=======
    <<" 6. Exit \n"
>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)
    <<"Choose [1-6]: ";
cin>>choice;

switch(choice){
    case 1:
        cout<<"UC";
        break;
    case 2:
<<<<<<< HEAD
        show_patientrec();
=======
        cout<<"UC";
>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)
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

<<<<<<< HEAD
=======



>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)

}


<<<<<<< HEAD
}
=======

>>>>>>> parent of 781d64f (Merge pull request #1 from Kaleab-Ayenew/patient-array)


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

void Doctor::show_patientrec(){

    int choice;

cout<<"--------- Show Patient Record ---------\n"
    <<"1. Search By Id \n"
    <<"2. Search By Name \n"
    <<"3. Show All Patients \n"
    <<"4. Back to Menu \n"
    <<"5. Exit \n"
    <<"---------------------------------------\n"
    <<"Choose [1-5]: "<<endl;

    do{
    cin>>choice;
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
    cout << "\n======= ALL PATIENT RECORDS =======\n\n";

    // First, count the number of patients
    ifstream countFile("patient_rec.txt");
    if (!countFile.is_open()) {
        cout << "No patient records found or error opening file!\n";
        return;
    }

    int patientCount = 0;
    string line;

    // Count lines in file
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

    // Create dynamic arrays to store patient data
    string* ids = new string[patientCount];
    string* fNames = new string[patientCount];
    string* lNames = new string[patientCount];
    string* emails = new string[patientCount];
    string* phones = new string[patientCount];
    string* dobs = new string[patientCount];

    // Read and store all patient data
    ifstream dataFile("patient_rec.txt");
    int index = 0;

    while (getline(dataFile, line) && index < patientCount) {
        if (line.empty()) continue;

        stringstream ss(line);

        // Read each field separated by '|'
        getline(ss, ids[index], '|');
        getline(ss, fNames[index], '|');
        getline(ss, lNames[index], '|');
        getline(ss, emails[index], '|');
        getline(ss, phones[index], '|');
        getline(ss, dobs[index], '|');
        // Password is the last field, but we won't display it for security

        index++;
    }
    dataFile.close();

    // Display all patient records in a formatted table
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << left << setw(8) << "ID"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(25) << "Email"
         << setw(15) << "Phone"
         << setw(15) << "Date of Birth" << endl;
    cout << "------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < patientCount; i++) {
        cout << left << setw(8) << ids[i]
             << setw(15) << fNames[i]
             << setw(15) << lNames[i]
             << setw(25) << emails[i]
             << setw(15) << phones[i]
             << setw(15) << dobs[i] << endl;
    }

    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Total Patients: " << patientCount << endl << endl;

    // Free the dynamically allocated memory
    delete[] ids;
    delete[] fNames;
    delete[] lNames;
    delete[] emails;
    delete[] phones;
    delete[] dobs;

    // Option to continue
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}












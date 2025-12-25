#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include "Doctor.h"
#include "handle_rec.h"

using namespace std;

void Doctor::doc_dashboard(){

    int choice;
    cout<<"-------Doctor Dashboard -------- \n"
    <<"1. Show Appointments \n"
    <<"2. Patient Records \n"
    <<"3. Show Profile \n"
    <<"4. Logout \n"
    <<"5. Exit \n"
    <<"Choose [1-6]: ";
do{

cin>>choice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

switch(choice){
    case 1:
        show_apt();
        break;
    case 2:
        show_patientrec();
        break;
    case 3:
        show_profile();
        return;
    case 4:
       return;
    case 5:
         cout<<"Closing Program , Goodbye"<<endl;
        exit(0);
    default:
        cout<<"Invalid choice "<<endl;
        break;


}


}while(choice!=5);

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
    const int ROW=500;
    const int COL=10;

cout<<"======== Show Patient Record ==========\n"
    <<"1. Search By Id \n"
    <<"2. Search By Name \n"
    <<"3. Sort By Name (Descending or Ascending)\n"
    <<"4. Sort By ID(Descening or Ascending) \n"
    <<"5. Show All Patients \n"
    <<"6. Delete records \n"
    <<"7. Back to Menu \n"
    <<"8. Exit \n"
    <<"========================================\n"
    <<"Choose [1-5]: "<<endl;
    cout<<endl;

    // get col and row
    fstream data("patient_rec.txt");

    string pa_array[ROW][COL];
    string line;
    int row=0;

    while(getline(data,line)&&row<ROW){
        stringstream ss(line);
        string field;
        int col=0;
        while(getline(ss,field,'|') && col<COL){
            pa_array[row][col]=field;
            col++;
        }
        row++;
    }
    data.close();
    int actual_col=7;



    do{
    cin>>choice;


    switch(choice){
    case 1:
        search_byid(pa_array,row,actual_col);
        break;
    case 2:
        search_byname(pa_array,row,actual_col);
        break;
    case 3:
        sort_byname(pa_array,row,actual_col);
        break;
    case 4:
        sort_byid(pa_array,row,actual_col);
        break;
    case 5:
        view_allrec(pa_array,row,actual_col);
        break;
    case 6:
        del_rec(pa_array,row,actual_col);
        break;
    case 7:
        return;
    default:
        cout<<"input valid input"<<endl;
        break;

    }

    }while(choice!=8);



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

void Doctor::show_apt(){

ifstream data("appointment.txt");
ofstream temp("temp.txt");
ofstream med("medical.txt");

    if (!data.is_open()) {
        cout << "Unable to open appointment file.\n";
        return;
    }

    string line;
    bool found = false;
    int opt;

    while (getline(data, line)) {
        stringstream ss(line);

        string pat_id, pat_name, doc_id, doc_name, day, stat;
        string advice,prescription,diagnosis;

        getline(ss, pat_id, '|');
        getline(ss, pat_name, '|');
        getline(ss, doc_id, '|');
        getline(ss, doc_name, '|');
        getline(ss, day, '|');
        getline(ss, stat, '|');

        // If this appointment belongs to the logged-in doctor
        if (id == doc_id && stat == "Scheduled") {

            cout << "\n==============================\n";
            cout << "      APPOINTMENT FOUND\n";
            cout << "==============================\n";
            cout << "Patient ID   : " << pat_id << endl;
            cout << "Patient Name : " << pat_name << endl;
            cout << "Doctor Name  : " << doc_name << endl;
            cout << "Schedule     : " << day << endl;
            cout << "Status       : " << stat << endl;

            found = true;

            cout << "\nConfirm Appointment?\n";
            cout << "[1] Accept\n";
            cout << "[0] Cancel\n";
            cout << "> ";
            cin >> opt;

            if (opt == 0) {
                stat = "Canceled";
                cout << "\nAppointment CANCELED.\n";
            }
            else if (opt == 1) {
                stat = "Confirmed";
                cin.ignore();

                cout << "Enter Diagnosis     : ";
                getline(cin, diagnosis);

                cout << "Enter Prescription : ";
                getline(cin, prescription);

                cout << "Enter Advice        : ";
                getline(cin, advice);
                cout << "\nAppointment CONFIRMED.\n";

            }
             med << pat_id << "|"
                     << pat_name << "|"
                     << doc_id << "|"
                     << doc_name << "|"
                     << diagnosis<<"|"
                     << prescription<<"|"
                     << advice <<"|"
                     << day<<endl;

        }

        // Write (updated or unchanged) record
        temp << pat_id << "|"
             << pat_name << "|"
             << doc_id << "|"
             << doc_name << "|"
             << day << "|"
             << stat <<endl;
    }

    data.close();
    temp.close();

    remove("appointment.txt");
    rename("temp.txt", "appointment.txt");

    if (!found) {
        cout << "\nNo appointments found.\n";
    }

    cout << "\nReturning to Doctor Dashboard...\n";
    doc_dashboard();
}



#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "Patient.h"
#include "validation.h"


using namespace std;

void Patient::patient_dashboard(){
     int choice;

    cout<<"=========== PATIENT DASHBOARD ==========\n"
        <<"==         1. My Profile              ==\n"
        <<"==         2. Book Appointment        ==\n"
        <<"==         3. My Appointments         ==\n"
        <<"==         4. Medical Records         ==\n"
        <<"==         5. Logout                  ==\n"
        <<"==         6. Exit                    ==\n"
        <<"========================================\n"
        <<"Choose [1-6]: ";
    while(true){
    cin>>choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(choice){
    case 1:
        show_profile();
        break ;
    case 2:
        book_appointment();
        break;
    case 3:
       show_appointment();
        break;
    case 4:
        show_medrecords();
        break;
    case 5:
        clear_data();
        return;
    case 6:
        exit(0);
    default:
        cout<<"input valid value"<<endl;
        break;
    }
    }

}



void Patient::login(){

    //input email and password

    string inputemail,inputpassword;
    bool found=false;

    cout<<endl;
    cout<<"========== Login ==========\n";
 do{
    cout<<"Email: ";
    getline(cin,inputemail);
    cout<<"Password: ";
    getline(cin,inputpassword);



    // open patient file in input mode
    ifstream file("patient_rec.txt",ios::in);


    if(!file.is_open()){ // if file won't open display error message
        cout<<"Error Opening File"<<endl;
        return;
    }

    string line;   // string to store line of data from text file

    int linenum = 0; // line countr

while(getline(file,line)){   // read whole line from text file until eof
    linenum++; // increment while it reads lint to line

    stringstream ss(line);  // parse the line from text to string
    string field;
    string passwordF,emailF; // field pass and email to valid with user input


    int fieldindex=0;

    while(getline(ss , field , '|')){ // read the first line until delimiter
        fieldindex++; // index counter for email and pass

        // stor email and pass when there index reached
        if(fieldindex==4){
           emailF=field;

        }
        if(fieldindex==7) {
                passwordF=field;

        }
    }

    // check if user input matches with emailf and passf
    if(inputemail == emailF && inputpassword == passwordF){
        found = true;
        // call load data
        load_data(inputemail);
        patient_dashboard();
        return;

    }
}
    file.close();

if(!found){
    cout<<"invalid email or password , try again:  ";
}

    // reenter fun needed
}while(!found);


}

void Patient::register_patient(){
    // patient profile registery function
    ifstream pat_data("patient_rec.txt",ios::in);
    string line;
    srand(time(0));

     int num = rand()%90+10;

    string conf_password;
    int choi;
    cout<<"=============== Patient Registration ===============\n"
        <<"Enter Details: ";
    cout<<endl;

    cout<<"Enter First Name : ";
    getline(cin,fName);
    cout<<"Enter Last Name : ";
    getline(cin,lName);

    if(isPatient_registered(fName,lName)){
        cout<<"Patient Already Registerd!";
        cout<<endl;
        return;
    }
    // calling form validation helper functions

    cout<<"Enter Your Email : ";
    do{
        getline(cin,email);
    if(!isValidemail(email))
        cout<<"Enter Valid Email: ";
    }while(!isValidemail(email));

cout<<"Enter Your Phone Number: ";
    do{
        getline(cin,phone);

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
cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do{
    getline(cin,password);
    if(!isValidpass(password)){
        cout<<"Enter valid Password: ";
    }
    }while(!isValidpass(password));

    do {
        cout << "Confirm Your password : ";

        getline(cin,conf_password);
        if(conf_password != password) {
            cout << "Passwords don't match! Try again." << endl;
        }

    }while(conf_password != password);
      cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"1. Edit Response \n"
        <<"2. Save Response \n"
        <<"3. Back to Menu \n"
        <<"4. Exit \n";
    cout<<"choose [1-4]: ";


    do{
    cin>>choi;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch(choi){
    case 1:
        register_patient();
        break;
    case 2:

        id = "PA"+to_string(num);
        save_patientrec();
        cout<<"Registration Succesfull"<<endl;
        return;
    case 3:
        patient_dashboard();
        break;
    case 4:
        exit(0);
    default:
        cout<<"invalid input"<<endl;
        break;


    }
    }while(choi!=4);

    // buffer problem


}

void Patient::save_patientrec(){
    // save patient response to file using | as delimiter to separate the files
    // ios::app , append text

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

    // function that parse patient data to object of the class
    // for future use
    ifstream file("patient_rec.txt");

    if(!file.is_open()){
        cout<<"Cannot open file"<<endl;

    }
string line;
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



    stringstream dateStream(dob);
    getline(dateStream, year, '-');
    getline(dateStream, month, '-');
    getline(dateStream, day, '-');

    getline(ss, password, '|');

     email = pat_email;
            break;
    }
}
file.close();


}




void Patient::show_profile(){

    // showing patient personal profile

    int choice;
    cout<<endl;
    cout<<"         USER PROFILE         \n"
        <<"-------------------------------\n"
        <<"ID:   "<<id<<"             \n"
        <<"First Name:   "<<fName<<"          \n"
        <<"Last Name:   "<<lName<<"           \n"
        <<"Email:   "<<email<<"           \n"
        <<"Phone Number:   "<<phone<<"        \n"
        <<"Password:   "<<password<<"         \n"
        <<"Birth Day:   " << year << "-" << month << "-" << day << "\n"
        <<"--------------------------------";
    cout<<endl;


    cout<<"1. Back to menu \n"
        <<"2. Exit \n"
        <<"Choose [1-3]: ";

    while(true){

    cin>>choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(choice){
    case 1:
        patient_dashboard();
        break;
    case 2:
        cout<<"Exiting Program , GoodBye "<<endl;
        exit(0);
    default:
        cout<<"Invalid choice :";
        break;
    }
};



}



void Patient::book_appointment() {

    // book appointment
    // get doctors data from doctors.txt and display let patient
    // pick their doctor

    const int MAX_DOCTORS = 100;
    const int MAX_APPOINTMENTS = 200;

    ifstream inputFile("doctors.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }



    // now using array fields to store doctors data and display

    string line;

    string ids[MAX_DOCTORS];
    string firstNames[MAX_DOCTORS];
    string lastNames[MAX_DOCTORS];
    string phones[MAX_DOCTORS];
    string email[MAX_DOCTORS];
    string slot[MAX_DOCTORS];
    string speciality[MAX_DOCTORS];
    string expr[MAX_DOCTORS];
    string room[MAX_DOCTORS];

    int count = 0; // count no of line

    while (getline(inputFile, line) && count < MAX_DOCTORS) {  //
        stringstream ss(line);
        string token;
        int fieldCount = 0; // count no fields

        while (getline(ss, token, '|')) {
            switch(fieldCount) {
                case 0: ids[count] = token; break;
                case 1: firstNames[count] = token; break;
                case 2: lastNames[count] = token; break;
                case 3: speciality[count] = token; break;
                case 4: email[count] = token; break;
                case 5: phones[count] = token; break;
                case 7: expr[count] = token; break;
                case 8: room[count] = token; break;
                case 9: slot[count] = token; break;
            }
            fieldCount++;
        }
        count++;
    }

    inputFile.close();

    // Display doctors
    cout << left;
    cout << setw(8) << "ID"
         << setw(15) << "Name"
         << setw(20) << "Department"
         << setw(25) << "Email"
         << setw(20) << "Phone"
         << setw(8) << "Exp"
         << setw(8) << "Room"
         << setw(10) << "Schedule" << endl;
    cout << string(120, '=') << endl;

    for(int i = 0; i < count; i++) {
        string fullName = firstNames[i] + " " + lastNames[i];

        cout << setw(8) << ids[i]
             << setw(15) << fullName
             << setw(20) << speciality[i]
             << setw(25) << email[i]
             << setw(20) << phones[i]
             << setw(8) << expr[i]
             << setw(8) << room[i]
             << setw(10) << slot[i] << endl;
    }

    // let user
    string doc_id;

    cout << "\nEnter Doctor ID to book appointment: ";


    cin>>doc_id;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for(auto& id: doc_id){
       id= toupper(id);
    }

    // Find the selected doctor
    int selectedIndex = -1;
    string selectedDoctorName ;
    string selectedDoctorSlot ;

    for(int i = 0; i < count; i++) {

        if(ids[i] == doc_id) {
            selectedIndex = i;
            selectedDoctorName = firstNames[i] + " " + lastNames[i];
            selectedDoctorSlot = slot[i];
            break;
        }
    }

    if(selectedIndex == -1) {
        cout << "Error: Doctor ID not found!" << endl;
        return;
    }

    // Check if doctor already has an appointment
    ifstream appointmentFile("appointment.txt");

    string patientId = Patient::id;

    if(appointmentFile.is_open()) {

        string appointmentLine;
        int appointmentCount = 0;
        string appointmentTokens[10][10];

        // Read all appointments
        while(getline(appointmentFile, appointmentLine) && appointmentCount < MAX_APPOINTMENTS) {

            stringstream ss(appointmentLine);
            string token;

            int fieldCount = 0;

            while(getline(ss, token, '|') && fieldCount < 10) {
                appointmentTokens[appointmentCount][fieldCount] = token;
                fieldCount++;
            }
            appointmentCount++;
        }

        appointmentFile.close();

        // Check if doctor is already booked
        bool doctorBooked = false;
        for(int i = 0; i < appointmentCount; i++) {
            // Check if doctor ID appears in appointment records (field index 2 for doctor ID)
            if(appointmentTokens[i][2] == doc_id) {
                doctorBooked = true;
                break;
            }
        }

        if(doctorBooked) {
            cout << "Error: This doctor already has an appointment booked!" << endl;
            cout << "Doctor " << selectedDoctorName << " is not available." << endl;

           int retry_choice;
                cout<<"1. Back to Menu \n"
                   <<"2. Exit \n"<<endl;

            cout<<"Choose [1-2]: "<<endl;
            do{
            cin>>retry_choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                switch(retry_choice){
                case 1:
                    patient_dashboard();
                    break;
                case 2:
                    exit(0);
                default:
                    cout<<"invalid input";
                    break;
                }


            }while(retry_choice!=3);

        }
    }

    // Store appointment in file append mode
    ofstream outFile("appointment.txt", ios::app);

    if(!outFile.is_open()) {
        cout << "Error: Cannot open appointment file for writing!" << endl;
        return;
    }

    string patientName = Patient::fName;
    string status;

    // store the patient and doctor to appointment.txt
    outFile << patientId << "|"
            << patientName << "|"
            << doc_id << "|"
            << selectedDoctorName << "|"
            << selectedDoctorSlot << "|"  // Doctor's slot becomes appointment time
            << status<<"Scheduled" << endl;

    outFile.close();

    cout << "\nAppointment booked successfully!" << endl;
    cout << "Doctor: " << selectedDoctorName << endl;
    cout << "Appointment Time: " << selectedDoctorSlot << endl;
    cout << "Status: Scheduled" << endl;
    cout<<"=====================================";
    cout<<endl;

    int choice;

    do{
    cout<<"1. Back to Menu \n"
        <<"2. Exit \n";
    cin>>choice;
       cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch(choice){
    case 1:
        patient_dashboard();
        break;
    case 2:
        cout<<"Goodbye , Exiting Program"<<endl;
        exit(0);
        break;
    default:
        cout<<"Invalid input"<<endl;
        break;

    }
    }while(choice!=3);


}

void Patient::show_medrecords(){

ifstream med_data("medical.txt");
string line;
bool found = false;

while(getline(med_data,line)){
    stringstream ss(line);
    string pat_id,pat_name,doc_id,doc_name,diagnosis,prescription,advice,apt;

    getline(ss,pat_id,'|');
    getline(ss,pat_name,'|');
    getline(ss,doc_id,'|');
    getline(ss,doc_name,'|');
    getline(ss,diagnosis,'|');
    getline(ss,prescription,'|');
    getline(ss,advice,'|');
    getline(ss,apt,'|');

    if(id==pat_id){
        cout<<pat_name<<"'S Medical Record"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Patient ID: "<<pat_id<<"\n"
            <<"Patient Name: "<<pat_name<<"\n"
            <<"Doctors ID: "<<doc_id<<"\n"
            <<"Doctors Name: "<<doc_name<<"\n"
            <<"Diagnosis Result: "<<diagnosis<<"\n"
            <<"Prescription Med: "<<prescription<<"\n"
            <<"Medical Advice: "<<advice<<"\n"
            <<"Scheduled UPon: "<<apt<<endl;
            found = true;
    }

  }
  if(!found){
    cout<<"No Medical Records"<<endl;
  }
  int choi;
    med_data.close();
   cout<<"1. Back to menu \n"
        <<"2. Exit \n"
        <<"Choose [1-3]: ";
  cin>>choi;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  switch(choi){
case 1:
    patient_dashboard();
    break;
case 2:
    exit(0);
default:
    cout<<"Insert Valid input"<<endl;
    break;



}

}


void Patient::show_appointment(){

// open file

ifstream apt("appointment.txt");

string line;
bool found = false;

while(getline(apt,line)){
    stringstream ss(line);
    string pat_id,pat_name,doc_id,doc_name,day,stat;

    getline(ss,pat_id,'|');
    getline(ss,pat_name,'|');
    getline(ss,doc_id,'|');
    getline(ss,doc_name,'|');
    getline(ss,day,'|');
    getline(ss,stat,'|');
    if(id==pat_id ){


        cout<<pat_name<<"'S Appointment"<<endl;
         cout<<"=================================="<<endl;
        cout<<"Patient ID: "<<pat_id<<"\n"
            <<"Patient Name: "<<pat_name<<"\n"
            <<"Doctors ID: "<<doc_id<<"\n"
            <<"Doctors Name: "<<doc_name<<"\n"
            <<"Schedule: "<<day<<"\n"
            <<"Status: "<<stat<<endl;

        found = true;
    }

    }

apt.close();
 if(!found){
        cout<<"NO Appointment Scheduled "<<endl;
    }
 cout<<endl;
        int choi;
 cout   <<"1. Back to menu \n"
        <<"2. Exit \n"
        <<"Choose [1-3]: ";
  cin>>choi;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  switch(choi){
case 1:
    patient_dashboard();
    break;
case 2:
    exit(0);
default:
    cout<<"Insert Valid input"<<endl;
    break;

  }


}









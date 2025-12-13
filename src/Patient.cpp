#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include "Patient.h"
#include "validation.h"


using namespace std;

// Constructor
Patient::Patient() {
    fName = "";
    lName = "";
    password = "";
    email = "";
    phone = "";
    id = "";
    year = 0;
    month = 0;
    day = 0;
}

void Patient::patient_dashboard(){
    int choice;

    do {
        cout << "\n------- PATIENT DASHBOARD -------\n"
             << "1. My Profile \n"
             << "2. Book Appointment \n"
             << "3. My Appointments \n"
             << "4. Medical Records \n"
             << "5. Logout \n"
             << "6. Exit \n"
             << "Choose [1-6]: ";

        cin >> choice;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch(choice){
        case 1:
            show_profile();
            break;
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
            cout << "Logging out..." << endl;
            return;
        case 6:
            cout << "Exiting Program, Goodbye" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please enter a number between 1-6." << endl;
            break;
        }
    } while(choice != 5 && choice != 6);
}



// Static function to login a patient from the array
int Patient::loginPatient(Patient patients[], int count){
    string inputemail, inputpassword;
    bool found = false;
    int patientIndex = -1;
    
    cout << "-------- Login ---------- \n";
    
    do {
        cout << "Email: ";
        cin >> inputemail;
        cout << "Password: ";
        cin >> inputpassword;
        
        // Search through the patient array
        for(int i = 0; i < count; i++) {
            if(patients[i].getEmail() == inputemail && 
               patients[i].getPassword() == inputpassword) {
                found = true;
                patientIndex = i;
                cout << "\nLogin successful! Welcome " << patients[i].getFullName() << endl;
                patients[i].patient_dashboard();
                return patientIndex;
            }
        }
        
        if(!found) {
            cout << "Invalid email or password. Please try again.\n" << endl;
        }
        
    } while(!found);
    
    return patientIndex;
}

// Static function to register a new patient and add to array
int Patient::registerPatient(Patient patients[], int currentCount, int maxSize){
    if(currentCount >= maxSize) {
        cout << "Maximum patient capacity reached!" << endl;
        return currentCount;
    }
    
    string fName, lName, email, phone, password;
    int year, month, day;
    string conf_password;
    int choi;
    
    cout << "---------- Patient Registration ------------- \n"
         << "Enter Details: " << endl;

    cout << "Enter First Name : ";
    cin >> fName;
    cout << "Enter Last Name : ";
    cin >> lName;
    cout << "Enter Your Email : ";

    // calling form validation helper functions
    do {
        cin >> email;
        
        // Check if email already exists in array
        bool emailExists = false;
        for(int i = 0; i < currentCount; i++) {
            if(patients[i].getEmail() == email) {
                cout << "Email already registered! Enter different email: ";
                emailExists = true;
                break;
            }
        }
        
        if(!emailExists && !isValidemail(email)) {
            cout << "Enter Valid Email: ";
        } else if(!emailExists) {
            break;
        }
    } while(true);

    cout << "Enter Your Phone Number: ";
    do {
        cin >> phone;
        if(!isValidphone(phone)){
            cout << "Enter Valid Phone: ";
        }
    } while(!isValidphone(phone));

    cout << "Enter Date of BirthDay: ";

    do {
        cout << "Enter Year: "; cin >> year;
        cout << "Enter Month: "; cin >> month;
        cout << "Enter Day: "; cin >> day;

        if(!isValiddob(year, month, day)){
            cout << "Enter valid birth day: ";
        }
    } while(!isValiddob(year, month, day));

    cout << "Enter Your Password : ";

    do {
        cin >> password;
        if(!isValidpass(password)){
            cout << "Enter valid password: ";
        }
    } while(!isValidpass(password));

    do {
        cout << "Confirm Your password : ";
        cin >> conf_password;

        if(conf_password != password) {
            cout << "Passwords don't match! Try again." << endl;
        }
    } while(conf_password != password);

    cout << endl;
    cout << "1. Edit Response \n"
         << "2. Save Response \n"
         << "3. Back to Menu \n"
         << "4. Exit " << endl;
    cout << "Choose [1-4]: ";
    cin >> choi;

    if(choi == 1){
        return registerPatient(patients, currentCount, maxSize);
    } else if(choi == 2){
        // Generate patient ID
        string id = "PA0" + to_string(currentCount + 1);
        
        // Add new patient to array
        patients[currentCount].setPatientData(fName, lName, email, phone, 
                                             year, month, day, password, id);
        
        cout << "Registration Successful! Patient ID: " << id << endl;
        
        // Save updated array to file
        savePatientsToFile(patients, currentCount + 1);
        
        return currentCount + 1;  // Return new count
    } else if(choi == 3){
        return currentCount;  // Don't add, return current count
    } else if(choi == 4){
        exit(0);
    }
    
    return currentCount;
}

// Static function to save all patients from array to file
void Patient::savePatientsToFile(Patient patients[], int count){
    ofstream data("patient_rec.txt", ios::out);  // Overwrite file
    
    if(!data.is_open()) {
        cout << "Error: Cannot open file for writing!" << endl;
        return;
    }
    
    for(int i = 0; i < count; i++) {
        data << patients[i].id << "|"
             << patients[i].fName << "|"
             << patients[i].lName << "|"
             << patients[i].email << "|"
             << patients[i].phone << "|"
             << patients[i].year << "-" << patients[i].month << "-" << patients[i].day << "|"
             << patients[i].password << endl;
    }
    
    data.close();
}

// Static function to load all patients from file into array
int Patient::loadPatientsFromFile(Patient patients[], int maxSize){
    ifstream file("patient_rec.txt");
    int count = 0;

    if(!file.is_open()){
        cout << "No existing patient records found. Starting fresh." << endl;
        return 0;
    }

    string line;
    while(getline(file, line) && count < maxSize){
        stringstream ss(line);
        string id, fName, lName, email, phone, dob, password;
        
        getline(ss, id, '|');
        getline(ss, fName, '|');
        getline(ss, lName, '|');
        getline(ss, email, '|');
        getline(ss, phone, '|');
        getline(ss, dob, '|');
        getline(ss, password, '|');
        
        // Parse date of birth
        stringstream dobss(dob);
        string yearStr, monthStr, dayStr;
        getline(dobss, yearStr, '-');
        getline(dobss, monthStr, '-');
        getline(dobss, dayStr, '-');
        
        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int day = stoi(dayStr);
        
        // Set patient data
        patients[count].setPatientData(fName, lName, email, phone, 
                                       year, month, day, password, id);
        count++;
    }
    
    file.close();
    cout << "Loaded " << count << " patients from file." << endl;
    return count;
}
void Patient::show_profile(){
    int choice;
    cout << "-------" << fName << " Profile -------- " << endl;
    cout << "ID: " << id << endl;
    cout << "First Name: " << fName << endl;
    cout << "Last Name:  " << lName << endl;
    cout << "Email:  " << email << endl;
    cout << "Phone:  " << phone << endl;
    cout << "Date of Birth: " << year << "-" << month << "-" << day << endl;
    cout << "Password: " << password << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Edit Profile \n"
         << "2. Back to menu \n"
         << "3. Exit \n"
         << "Choose [1-3]: ";

    cin >> choice;

    switch(choice){
    case 1:
        cout << "Edit Profile - Under Construction" << endl;
        break;
    case 2:
        return;
    case 3:
        exit(0);
    default:
        cout << "Invalid choice " << endl;
        break;
    }
}

// Setter method
void Patient::setPatientData(string fn, string ln, string em, string ph, 
                            int y, int m, int d, string pass, string patId){
    fName = fn;
    lName = ln;
    email = em;
    phone = ph;
    year = y;
    month = m;
    day = d;
    password = pass;
    id = patId;
}

// Getter methods
string Patient::getEmail() const {
    return email;
}

string Patient::getPassword() const {
    return password;
}

string Patient::getId() const {
    return id;
}

string Patient::getFullName() const {
    return fName + " " + lName;
}






void Patient::book_appointment(){
    // show available slots for patient .
    // display doctor name, specialty, experience, avail time
    cout << "Book Appointment - Under Construction" << endl;
}

void Patient::show_appointment(){
    cout << "Show Appointments - Under Construction" << endl;
}

void Patient::show_medrecords(){
    cout << "Show Medical Records - Under Construction" << endl;
}

// Static function to list all patients in the array
void Patient::listAllPatients(Patient patients[], int count){
    if(count == 0){
        cout << "\n========================================" << endl;
        cout << "No patients registered in the system." << endl;
        cout << "========================================\n" << endl;
        return;
    }
    
    cout << "\n============================================================" << endl;
    cout << "                  ALL REGISTERED PATIENTS                   " << endl;
    cout << "============================================================" << endl;
    cout << "Total Patients: " << count << endl;
    cout << "------------------------------------------------------------" << endl;
    
    for(int i = 0; i < count; i++){
        cout << "\nPatient #" << (i + 1) << ":" << endl;
        cout << "  ID:          " << patients[i].id << endl;
        cout << "  Name:        " << patients[i].fName << " " << patients[i].lName << endl;
        cout << "  Email:       " << patients[i].email << endl;
        cout << "  Phone:       " << patients[i].phone << endl;
        cout << "  DOB:         " << patients[i].year << "-" 
             << patients[i].month << "-" << patients[i].day << endl;
        cout << "------------------------------------------------------------" << endl;
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}


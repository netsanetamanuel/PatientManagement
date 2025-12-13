#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Doctor.h"

using namespace std;

void Doctor::doc_dashboard(Patient patients[], int patientCount){
    int choice;

    do {
        cout << "\n-------Doctor Dashboard -------- \n"
             << "1. Show Appointments \n"
             << "2. View All Patients \n"
             << "3. Show Profile \n"
             << "4. Appointment Management \n"
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
                cout << "Show Appointments - Under Construction" << endl;
                break;
            case 2:
                Patient::listAllPatients(patients, patientCount);
                break;
            case 3:
                cout << "Show Profile - Under Construction" << endl;
                break;
            case 4:
                cout << "Appointment Management - Under Construction" << endl;
                break;
            case 5:
                cout << "Logging out..." << endl;
                return;
            case 6:
                cout << "Closing Program, Goodbye" << endl;
                exit(0);
            default:
                cout << "Invalid choice " << endl;
                break;
        }
    } while(choice != 5 && choice != 6);
}

void Doctor::login(Patient patients[], int patientCount){
    string input_email, input_pwd;
    bool found = false;
    cout << "----------Login---------\n";
    do{
        cout << "Email: ";
        cin >> input_email;
        cout << "Password: ";
        cin >> input_pwd;

        // read data
        fstream data("doctors.txt", ios::in);
        if(!data.is_open()){
            cout << "Error Opening Data! " << endl;
        }

        string line;
        int line_num = 0;

        while(getline(data, line)){
            line_num++;

            // read whole line of text from file
            stringstream ss(line);
            string field_str;
            int field_index = 0;

            string emailf, pwdf;

            while(getline(ss, field_str, '|')){
                field_index++;
                if(field_index == 5) {
                    emailf = field_str;
                }
                if (field_index == 7) {
                    pwdf = field_str;
                }
            }
            if(emailf == input_email && pwdf == input_pwd){
                found = true;
                cout << "\nLogin successful! Welcome Doctor." << endl;
                doc_dashboard(patients, patientCount);
            }
        }
        data.close();
        if(!found){
            cout << "Invalid Input Please, try again" << endl;
        }
    }while(!found);
}

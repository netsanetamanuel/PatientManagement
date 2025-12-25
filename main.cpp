#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()
#include <limits>  // numeric limits
#include "Patient.h"
#include "Doctor.h"
#include "handle_rec.h"
#include "validation.h"


using namespace std;

// menu prototypes
void master_menu();
void doctor_menu();
void patient_menu();

int main()
{

    master_menu();
    return 0;

}

void master_menu(){  // master menu for both patient and doctor portal
     int msChoice;


    cout<<"======== Blaze Hospital ===============\n"
        <<"         1. Doctors Portal              \n"
        <<"         2. Patient Portal              \n"
        <<"         3. Exit                        \n"
        <<"=======================================\n"
        <<" Choose [1 - 3]: ";

do{
        cin>>msChoice;
        // input validation to clear the garbage value entered by user like string ,char ...
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');


    switch(msChoice){
        case 1:

            doctor_menu();
            break;
        case 2:

            patient_menu();
            break;
        case 3:

            cout<<"Exiting Program , GoodBye"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid choice , Please enter correct Choice: ";
            break;
    }
}while(msChoice!=3);


}





void patient_menu(){
    int pChoice;

    Patient newPatient;

    do{
    cout<<"=========== Patient Portal ============\n"
        <<"            1.Register               \n"
        <<"            2.Login                  \n"
        <<"            3.Back to Main Portal     \n"
        <<"            4.Exit               \n"
        <<"======================================\n"
        <<"Choose [1-4]: ";

        cin>>pChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch(pChoice){
            case 1:
                newPatient.register_patient();
                break;
            case 2:
                newPatient.login();
                return;

            case 3:
                master_menu();
                break;
            case 4:
                cout<<"Exiting Program , Goodbye"<<endl;
                exit(0);
                break;

            default:
                cout<<"Input valid choice"<<endl;
                break;

        }

    }while(pChoice!=4);


}

void doctor_menu(){
    int choice;
    Doctor newDoctor;


    do{
        cout<<"======== Doctor's Portal =======\n"
            <<"     1. Login \n"
            <<"     2. Back To Main Portal  \n"
            <<"     3. Exit \n"
            <<"================================\n"
            <<"Choose [1-3]: ";

        cin>>choice;

        cin.clear();
        cin.ignore(100,'\n');

        switch(choice){
        case 1:
            newDoctor.login();
            break;
        case 2:
            master_menu();
            break;
        case 3:
            cout<<"Exiting Program , Good bye"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid choice "<<endl;
            break;



        }

    }while(choice!=3);







}



#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include "Patient.h"

using namespace std;


class Doctor
{
    public:
        void login(Patient patients[], int patientCount);
        void doc_dashboard(Patient patients[], int patientCount);
        void load_data();
        void show_apt();
        void show_patientrec();
        void show_profile();
        void appt_mangmt();



    private:
        string fname,lname,id,speciality,email,phone,password,slot;
        int exprience, room;


};

#endif // DOCTOR_H

#ifndef PATIENT_H
#define PATIENT_H
#include <fstream>

using namespace std;



class Patient
{
    // class methods
    public:
        void register_patient();
        void login();
        void patient_dashboard();
        void load_data(const string&);
        void show_profile();
        void book_appointment();
        void show_appointment();
        void show_medrecords();
        void save_patientrec();

    private:
        // patient data members
         string fName ,lName, password,email,phone,id;
         string year , month , day;
         int pat_countr=0;



};

#endif // PATIENT_H

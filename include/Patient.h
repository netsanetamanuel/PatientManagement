#ifndef PATIENT_H
#define PATIENT_H
#include <fstream>

using namespace std;

// Maximum number of patients
const int MAX_PATIENTS = 100;

class Patient
{
    public:
        // Constructor
        Patient();
        
        // Array-based static functions
        static int loadPatientsFromFile(Patient patients[], int maxSize);
        static void savePatientsToFile(Patient patients[], int count);
        static int registerPatient(Patient patients[], int currentCount, int maxSize);
        static int loginPatient(Patient patients[], int count);
        static void listAllPatients(Patient patients[], int count);
        
        // Instance methods
        void patient_dashboard();
        void show_profile();
        void book_appointment();
        void show_appointment();
        void show_medrecords();
        
        // Setters
        void setPatientData(string fn, string ln, string em, string ph, 
                          int y, int m, int d, string pass, string patId);
        
        // Getters
        string getEmail() const;
        string getPassword() const;
        string getId() const;
        string getFullName() const;

    private:
         string fName, lName, password, email, phone, id;
         int year, month, day;
};

#endif // PATIENT_H

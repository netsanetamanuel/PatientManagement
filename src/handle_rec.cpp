#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include "handle_rec.h"
#include "Doctor.h"


using namespace std;

string line(30,'-');

void input_opt(int opt){

    Doctor doc_methods;

    cout<<"1. Back To Menu \n"
        <<"2. Exit \n"
        <<"Choose [1-2]: ";
    cin>>opt;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(opt){
    case 1:
        doc_methods.doc_dashboard();
    case 2:
        cout<<"Exiting Program ,Goodbyee"<<endl;
        exit(0);
    default:
        cout<<"Invalid Input: ";
        break;
    }
}

void to_upper(string& ids){
    for(auto& id: ids){
       id= toupper(id);
    }

}

void save_to_file(string filename,
                  string array[][10],
                  int rowsize,
                  int colsize) {

    ofstream file(filename, ios::out);

    for(int i = 0; i < rowsize; i++) {
        for(int j = 0; j < colsize; j++) {
            file << array[i][j];
            if(j < colsize - 1)
                file << "|";
        }
        file << endl;
    }

    file.close();
}

void view_allrec(string array[][10],int rowsize,int colsize){
    cout<<"         ALL PATIENT RECORDS         \n"
        <<line<<endl;
    for(int i=0;i<rowsize;i++){
        for(int j=0;j<colsize;j++){
            cout<<array[i][j];
        }
        cout<<endl;
    }
    cout<<line<<endl;

    int choice;
    input_opt(choice);

}

void del_rec(string array[][10], int rowsize , int colsize){
    string del_id;
cout<<"Enter Id to Delete"<<endl;
cin>>del_id;

cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
to_upper(del_id);


bool found = false;

for(int i=0;i<rowsize;i++){
    if(array[i][0]==del_id){
            found = true;
       for(int r=i;r<rowsize-1;r++){
        for(int c=0;c<colsize;c++){
            array[r][c]=array[r+1][c];
        }
       }
        for (int c = 0; c < colsize; c++) {
            array[rowsize - 1][c] = "";
          }
        rowsize--;
    }

}

save_to_file("patient_rec.txt",array,rowsize,colsize);


cout<<"Record Deleted Succesfully"<<endl;
if(!found){
    cout<<"ID Not Found"<<endl;
    return;
}

  int choice;
  input_opt(choice);
}



void sort_byname(string array[][10],int rowsize,int colsize){
    cout<<"         Sorted By Name          \n"
        <<line<<endl;

for(int i=0;i<rowsize-1;i++){
    for(int j=0;j<rowsize-i-1;j++){
        string name1 =  array[j][1];
        string name2 =  array[j+1][1];



        if(name1<name2){
            for(int k=0;k<colsize;k++){
                string temp = array[j][k];
                array[j][k]=array[j+1][k];
                array[j+1][k]=temp;
            }

        }


    }
}

    for(int i=0;i<rowsize;i++){
        for(int j=0;j<colsize;j++){
            cout<<array[i][j];
            if(j!=colsize-1) cout<<"|";
        }
        cout<<endl;
    }
    cout<<line<<endl;
      int choice;
    input_opt(choice);
}

void sort_byid(string array[][10],int rowsize,int colsize){
cout<<"             Sorted By ID In             \n";
cout<<line<<endl;


    for(int i=0;i<rowsize-1;i++){
    for(int j=0;j<rowsize-i-1;j++){

        string id1 = array[j][0].substr(2);
        string id2 = array[j+1][0].substr(2);

        int num1 = stoi(id1);
        int num2 = stoi(id2);

        if(num1<num2){
            // swap entire array

            for(int k=0; k<colsize;k++){
                string temp = array[j][k];
                array [j][k] =array[j+1][k];
                array[j+1][k]=temp;


            }

        }

    }

}

     for(int i=0;i<rowsize;i++){
        for(int j=0;j<colsize;j++){
            cout<<"|"<<array[i][j];

        }

        cout<<endl;
    }
cout<<line<<endl;
  int choice;
    input_opt(choice);
}

void search_byid(string array[][10], int rowsize, int colsize){
    string search_id;
    cout << "Enter Id: ";
    cin >> search_id;
    cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
    to_upper(search_id);

    bool found = false;

    for(int i = 0; i < rowsize; i++) {
        if(array[i][0] == search_id) {
                cout<<array[i][1]<<"'s Profile  \n"
                    <<line<<endl;
            for(int j = 0; j < colsize; j++) {
                cout << array[i][j];
                if(j != colsize - 1) cout << " |";
            }
            cout << endl;

            found = true;
            break;
        }
    }

    if(!found) {
        cout << "ID not found!" << endl;
    }
      int choice;
    input_opt(choice);
}

void search_byname(string array[][10], int rowsize, int colsize){
    string search_name;
    cout << "Enter Name: ";
     getline(cin,search_name);


    bool found = false;

    for(int i = 0; i < rowsize; i++) {
        if(array[i][1] == search_name) {
            for(int j = 0; j < colsize; j++) {
                cout<<array[i][1]<<"'s Profile  \n"
                    <<line<<endl;
                cout << array[i][j];
                if(j != colsize - 1) cout << "|";

            }
            cout << endl;

            found = true;
            break;
        }
    }

    if(!found) {
        cout << "ID not found!" << endl;
    }
      int choice;
    input_opt(choice);

}

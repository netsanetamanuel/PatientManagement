#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "handle_rec.h"


using namespace std;


void apt_mgt(string array[][6],int rowsize,int colsize,int doc_id){





}

void view_allrec(string array[][10],int rowsize,int colsize){

    for(int i=0;i<rowsize;i++){
        for(int j=0;j<colsize;j++){
            cout<<array[i][j];
        }
        cout<<endl;
    }

}

void del_rec(string array[][10], int rowsize , int colsize){
    string del_id;
cout<<"Enter Id to Delete"<<endl;
cin>>del_id;

bool found = false;

for(int i=0;i<rowsize;i++){
    if(array[i][0]==del_id){
       for(int r=i;r<rowsize-1;r++){
        for(int c=0;c<colsize;c++){
            array[r][c]=array[r+1][c];
        }
       }

    }

}


}

void sort_byname(string array[][10],int rowsize,int colsize){
cout<<"Sorted By Name Order \n";

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
        }
        cout<<endl;
    }
}

void sort_byid(string array[][10],int rowsize,int colsize){
cout<<"Sorted By ID In \n";

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
            cout<<array[i][j];
        }
        cout<<endl;
    }


}

void search_byid(string array[][10], int rowsize, int colsize){
    string search_id;
    cout << "Enter Id: ";
    cin >> search_id;

    bool found = false;

    for(int i = 0; i < rowsize; i++) {
        if(array[i][0] == search_id) {
            for(int j = 0; j < colsize; j++) {
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
}

void search_byname(string array[][10], int rowsize, int colsize){
    string search_name;
    cout << "Enter Id: ";
    cin >> search_name;


    bool found = false;

    for(int i = 0; i < rowsize; i++) {
        if(array[i][1] == search_name) {
            for(int j = 0; j < colsize; j++) {
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
}

#ifndef HANDLE_REC_H_INCLUDED
#define HANDLE_REC_H_INCLUDED


#include <string>
using namespace std;


void view_allrec(string array[][10], int rowsize, int colsize);
void sort_byid(string array[][10],int rowsize,int colsize);
void sort_byname(string array[][10], int rowsize, int colsize);
void search_byid(string array[][10], int rowsize, int colsize);
void search_byname(string array[][10], int rowsize, int colsize);
void del_rec(string array[][10], int rowsize, int colsize);
void apt_mgt(string array[][6],int rowsize, int colsize);

void save_to_file(string filename,string array[][10],int rowsize,int colsize);

void input_opt(int opt);
void to_upper(string& ids);













#endif // HANDLE_REC_H_INCLUDED

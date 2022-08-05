#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "UsersManage.h"
#include "BooksManage.h"
const int LEND = 0;
const int RETURN = 1;
typedef struct NotesHistory
{
	string id;
	string isbn;
	int L_R;
	int time[3];
	NotesHistory* next;	
}NotesNode;
class Notes
{
private:
	NotesNode* head;
	NotesNode* end;
	int NotesSize;
public:
	Notes();
	void ReadFile();
	void WriteFile();
	void ShowBook(string isbn);//管理用
	void ShowUser(string id);//管理用
	//void ShowAllBrief();
	void ShowAllDetailed(Users& users, Books& books);
	void ShowUser(int i, Users& users, Books& books);//读者用
	void AddNotes(string id,string isbn,int lr,int year,int month,int day);
	void DeleteNotes();
	void Clear();
};
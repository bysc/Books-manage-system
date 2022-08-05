#pragma once
#include <iostream>
using namespace std;
#include <string>
//#include "BooksManage.h"
//#include "UsersManage.h"
#include "Notes.h"
//#include <array>
class Time
{
private:
	static int MON[13];
	int year;
	int month;
	int day;
	int sub;
public:
	Time(int a=0,int b=0,int c=0,int d=0):year(a),month(b),day(c),sub(d){}
	void Change(int a, int b, int c, int d = 0);
	bool isLeapyear();
	int GetGap(Time& t);
	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
	int GetSub() { return sub; }
};

typedef struct
{
	string ISBN;
	Time Tl;
}SubLend;
typedef struct LendList
{
	string Id;
	vector<SubLend>Arr;
	struct LendList* next;
}Node;
class List
{
private:
	Node* head;
	Node* end;
	int ListSize;
public:
	List();
	void ReadFile();
	void WriteFile();
	void ShowReader(string id);
	void ShowReader(int i, Users& users, Books& books);
	void ShowISBN(string isbn);
	void ShowAll();
	void AddNode(Users&users,Books&books,Notes&notes);
	void DeleteNode(string isbn,Users&users,Books&books,Notes&notes);
	void Clear();
	void CaculateSub(Users&users,Books&books);//必须管理员使用
};
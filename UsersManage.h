#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
bool IsFigure(string str);
typedef struct UsersInformation
{
	string Name;
	string Id;
	string Keywords;
	int Sex;
	int Count;
	int Credit;
}UsersInf;
class Users
{
private:
	vector<UsersInf>Array;
public:
	void ReadFile();
	void WriteFile();
	int Find(string id) const;
	UsersInf& operator[](int i);
	string GetName(int i) const;
	string GetName(string id) const;
	void ShowInd(int i) const;
	void ShowAll() const;
	void AddUsers();
	void Delete(int i);
	bool CorrectKey(int i);
	void SortByCounts();
	void SortById();
	void Charge(string id);
};


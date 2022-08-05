#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
bool IsFigure(string str);
typedef struct BooksInformation
{
	string Name;
	string Field;
	string Writer;
	string ISBN;
	string Press;
	float Price;
	bool Islended;
	string Id;
}BooksInf;
class Books
{
private:
	vector<BooksInf>Array;
public:
	void ReadFile();
	void WriteFile();
	int Search(string isbn) const;
	//int Search(string name, string writer) const;
	BooksInf& operator[](int i);
	string GetName(int i) const;
	string GetName(string isbn) const;
	void ShowInd(int i) const;
	void ShowAll() const;
	void ShowWriter(string writer) const;
	void ShowField(string field) const;
	void ShowISBN(string isbn) const;
	void AddBooks();
	void DeleteBooks(int i);
	void SortByField();
	void SortByWriter();
	void SortByName();
	void SortByLR();
};
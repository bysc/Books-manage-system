#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
//#include <array>
//#include <stack>
//#include <queue>
//#include "UsersManage.h"
//#include "BooksManage.h"
#include "LendSystem.h"
//#include "Notes.h"
void MenuMain();
class Base
{
public:
	virtual void Menu()=0;
	virtual int Sign(Users&users) = 0;
	virtual void System(Users& users, Books& books, List& list, Notes& notes) = 0;
	virtual ~Base()=0;
};
class Manager:public Base
{
public:
	void Menu();
	int Sign(Users& users);
	void System(Users& users, Books& books, List& list, Notes& notes);
	~Manager() {}
};
class Reader :public Base
{
public:
	void Menu();
	int Sign(Users& users);
	void System(Users& users, Books& books, List& list, Notes& notes);
	~Reader(){}
};

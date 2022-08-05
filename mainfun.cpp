#include "mainfun.h"
void MenuMain()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "******************欢迎使用本系统******************" << endl;
	cout << "*******************1.管理员登录*******************" << endl;
	cout << "********************2.读者登录********************" << endl;
	cout << "********************3.读者注册********************" << endl;
	cout << "********************4.退出系统********************" << endl;
	cout << "**************************************************" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
Base::~Base() {}
void Manager::Menu()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "*******************************管理员界面*******************************" << endl;
	cout << "**===读者管理===-----|**===图书管理===--------|**===日志管理===-----==**" << endl;
	cout << "**==1.显示全部读者---|**==7.显示全部图书------|**17.显示全部借还记录==**" << endl;
	cout << "**==2.显示指定读者---|**==8.查找作者----------|**18.删除日志--------==**" << endl;
	cout << "**==3.添加读者 ------|**==9.查找领域----------|**19.跟踪用户--------==**" << endl;
	cout << "**==4.删除读者-------|**==10.按ISBN查找-------|**20.跟踪书籍--------==**" << endl;
	cout << "**==5.按借书数排序---|**==11.按作者名排序-----|**-------------------==**" << endl;
	cout << "**==6.按ID排序 ------|**==12.按领域名排序-----|**-------------------==**" << endl;
	cout << "**-------------------|**==13.按图书名排序-----|**-------------------==**" << endl;
	cout << "**-------------------|**==14.按未借出在前排序-|**-------------------==**" << endl;
	cout << "**-------------------|**==15.添加图书---------|**-------------------==**" << endl;
	cout << "**-------------------|**==16.删除图书---------|**-------------------==**" << endl;
	cout << "**==----------------------------借还管理----------------------------==**" << endl;
	cout << "**==------------------------21.显示借书信息-------------------------==**" << endl;
	cout << "**==------------------------22.显示详细信息-------------------------==**" << endl;
	cout << "**==------------------------23.收罚金-------------------------------==**" << endl;
	cout << "**==------------------------===========-----------------------------==**" << endl;
	cout << "**==------------------------24.修改密码-----------------------------==**" << endl;
	cout << "**==------------------------25.退出登录-----------------------------==**" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
int Manager::Sign(Users& users)
{
	cout << "请输入您的id：";
	string id;
	cin >> id;
	cout << "请输入您的密码：";
	string key;
	cin >> key;
	if (users[0].Id != id || users[0].Keywords != key)
	{
		cout << "您输入的账号或者密码不正确!" << endl;
		return -1;
	}
	else cout << "成功登录" << endl;
	return 0;
}
void Manager::System(Users& users, Books& books, List& list, Notes& notes)
{
	system("cls");
	if (Sign(users) == -1) return;
	list.CaculateSub(users,books);//管理员使用，不对学生开放
	int choose;
	while (1)
	{
		this->Menu();
		cin.clear();
		cin.ignore(99, '\n');
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			users.ShowAll();
			system("pause");
			system("cls");
		}
		break;
		case 2:
		{
			string id;
			cout << "请输入id：";
			cin >> id;
			int location = users.Find(id);
			if (location == -1) cout << "该读者不存在" << endl;
			else users.ShowInd(location);
			system("pause");
			system("cls");
		}
		break;
		case 3:
		{
			users.AddUsers();
			system("pause");
			system("cls");
		}
		break;
		case 4:
		{
			string id;
			cout << "请输入ID：";
			cin >> id;
			int location = users.Find(id);
			if (location == -1) cout << "该读者不存在" << endl;
			else if (users[location].Count > 0) cout << "该读者还未还完书" << endl;
			else if (users[location].Credit > 0) cout << "该读者还未缴清罚款" << endl;
			else users.Delete(location);
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
		}
		break;
		case 5:
		{
			users.SortByCounts();
			system("pause");
			system("cls");
		}
		break;
		case 6:
		{
			users.SortById();
			system("pause");
			system("cls");
		}
		break;
		case 7:
		{
			books.ShowAll();
			system("pause");
			system("cls");
		}
		break;
		case 8:
		{
			string writer;
			cout << "请输入作者名：";
			cin >> writer;
			books.ShowWriter(writer);
			system("pause");
			system("cls");
		}
		break;
		case 9:
		{
			string field;
			cout << "请输入领域名：";
			cin >> field;
			books.ShowField(field);
			system("pause");
			system("cls");
		}
		break;
		case 10:
		{
			string isbn;
			cout << "请输入ISBN：";
			cin >> isbn;
			books.ShowISBN(isbn);
			system("pause");
			system("cls");
		}
		break;
		case 11:
		{
			books.SortByWriter();
			system("pause");
			system("cls");
		}
		break;
		case 12:
		{
			books.SortByField();
			system("pause");
			system("cls");
		}
		break;
		case 13:
		{
			books.SortByName();
			system("pause");
			system("cls");
		}
		break;
		case 14:
		{
			books.SortByLR();
			system("pause");
			system("cls");
		}
		break;
		case 15:
		{
			books.AddBooks();
			system("pause");
			system("cls");
		}
		break;
		case 16:
		{
			string isbn;
			cout << "请输入ISBN：";
			cin >> isbn;
			int location = books.Search(isbn);
			if (location == -1) cout << "该书不存在" << endl;
			else if (books[location].Islended == 1) cout << "该书还在被借出" << endl;
			else books.DeleteBooks(location);
			system("pause");
			system("cls");
		}
		break;
		case 17:
		{
			notes.ShowAllDetailed(users, books);
			system("pause");
			system("cls");
		}
		break;
		case 18:
		{
			notes.DeleteNotes();
			system("pause");
			system("cls");
		}
		case 19:
		{
			string id;
			cout << "请输入ID：";
			cin >> id;
			notes.ShowUser(id);
			system("pause");
			system("cls");
		}
			break;
		case 20:
		{
			string isbn;
			cout << "请输入ISBN：";
			cin >> isbn;
			notes.ShowBook(isbn);
			system("pause");
			system("cls");
		}
			break;
		case 21:
		{
			list.ShowAll();
			system("pause");
			system("cls");
		}
			break;
		case 22:
		{
			string isbn;
			cout << "请输入ISBN：";
			cin >> isbn;
			list.ShowISBN(isbn);
			system("pause");
			system("cls");
		}
			break;
		case 23:
		{
			string id;
			cout << "请输入读者ID：";
			cin >> id;
			users.Charge(id);
			system("pause");
			system("cls");
		}
			break;
		case 24:
		{
			if (users.CorrectKey(0) == false) cout << "密码修改失败" << endl;
			else cout << "密码修改成功" << endl;
			system("pause");
			system("cls");
		}
		break;
		case 25:
		{
			system("pause");
			system("cls");
			return;
		}
		default:
		{
			cout << "您的输入不规范，请重新输入" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}
}
void Reader::Menu()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "===========------|读者界面|------===========" << endl;
	cout << "=====---------|1.显示全部图书|---------=====" << endl;
	cout << "=====---------|2.按作者名查询|---------=====" << endl;
	cout << "=====----------|3.按领域查询|----------=====" << endl;
	cout << "=====----------|4.按ISBN查询|----------=====" << endl;
	cout << "=====---------|5.显示个人信息|---------=====" << endl;
	cout << "=====-----------|6.修改密码|-----------=====" << endl;
	cout << "=====-------|7.显示当前借书信息|-------=====" << endl;
	cout << "=====-------|8.显示个人借还记录|-------=====" << endl;
	cout << "=====-------------|9.借书|-------------=====" << endl;
	cout << "=====------------|10.还书|-------------=====" << endl;
	cout << "=====--------|11.按作者名排序|---------=====" << endl;
	cout << "=====--------|12.按领域名排序|---------=====" << endl;
	cout << "=====--------|13.按图书名排序|---------=====" << endl;
	cout << "=====-----|14.按图书是否借出排序|------=====" << endl;
	cout << "=====----------|15.注销账号|-----------=====" << endl;
	cout << "=====----------|16.退出登录|-----------=====" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
int Reader::Sign(Users& users)
{
	cout << "请输入你的id：";
	string id;
	cin >> id;
	int location=users.Find(id);
	if (location == -1)
	{
		cout << "账号不正确" << endl;
		return -1;
	}
	cout << "请输入你的密码：";
	string key;
	cin >> key;
	if (users[location].Keywords != key)
	{
		cout << "密码不正确" << endl;
		return -1;
	}
	return location;
}
void Reader::System(Users& users, Books& books, List& list, Notes& notes)
{
	system("cls");
	int location = Sign(users);
	if (location == -1) return;
	int choose;
	while (1)
	{
		this->Menu();
		cin.clear();
		cin.ignore(99, '\n');
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			books.ShowAll();
			system("pause");
			system("cls");
		}
			break;
		case 2:
		{
			string writer;
			cout << "请输入作者姓名：";
			cin >> writer;
			books.ShowWriter(writer);
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			string field;
			cout << "请输入领域名称：";
			cin >> field;
			books.ShowField(field);
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			string isbn;
			cout << "请输入ISBN号：";
			cin >> isbn;
			books.ShowISBN(isbn);
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			users.ShowInd(location);
			system("pause");
			system("cls");
		}
			break;
		case 6:
		{
			users.CorrectKey(location);
			system("pause");
			system("cls");
		}
			break;
		case 7:
		{
			list.ShowReader(location, users, books);
			system("pause");
			system("cls");
		}
			break;
		case 8:
		{
			notes.ShowUser(location, users, books);
			system("pause");
			system("cls");
		}
			break;
		case 9:
		{
			list.AddNode(users, books, notes);
			system("pause");
			system("cls");
		}
		    break;
		case 10:
		{
			string isbn;
			cout << "请输入ISBN：";
			cin >> isbn;
			list.DeleteNode(isbn, users, books, notes);
			system("pause");
			system("cls");
		}
			break;
		case 11:
		{
			books.SortByWriter();
			system("pause");
			system("cls");
		}
			break;
		case 12:
		{
			books.SortByField();
			system("pause");
			system("cls");
		}
			break;
		case 13:
		{
			books.SortByName();
			system("pause");
			system("cls");
		}
			break;
		case 14:
		{
			books.SortByLR();
			system("pause");
			system("cls");
		}
			break;
		case 15:
		{
			if (users[location].Count > 0) cout << "请先归还图书" << endl;
			else if (users[location].Credit > 0) cout << "请先缴清罚款" << endl;
			else users.Delete(location);
			system("pause");
			system("cls");
			return;
		}
			break;
		case 16:
		{
			system("pause");
			system("cls");
			return;
		}
		default:
		{
			cout << "你的输入不规范，请重新输入" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}
}
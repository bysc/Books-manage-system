#include "mainfun.h"//test
int main()
{
	Users users;
	Books books;
	List list;
	Notes notes;
	users.ReadFile();
	books.ReadFile();
	list.ReadFile();
	notes.ReadFile();
	Base* base = NULL;
	Manager* ma = new Manager;
	Reader* re = new Reader;
	int choose_first = 1;
	while (1)//mainSystem
	{
		START:
		MenuMain();
		cin.clear();
		cin.ignore(99, '\n');
		cin >> choose_first;
		switch ((int)choose_first)
		{
		case 1: base = ma;
		    break;
		case 2:	base = re;
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
			users.WriteFile();
			books.WriteFile();
			list.WriteFile();
			notes.WriteFile();
			delete ma;
			delete re;
			notes.Clear();
			list.Clear();
			system("pause");
			system("cls");
			return 0;
		}
		    break;
		default:
		{
			cout << "您的输入不符合规范，请重新输入..." << endl;
			system("pause");
			system("cls");
			goto START;
		}
			break;
		}
		base->System(users,books,list,notes);
	}
	return 0;
}
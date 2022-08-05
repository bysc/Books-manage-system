#include "mainfun.h"
void MenuMain()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "******************��ӭʹ�ñ�ϵͳ******************" << endl;
	cout << "*******************1.����Ա��¼*******************" << endl;
	cout << "********************2.���ߵ�¼********************" << endl;
	cout << "********************3.����ע��********************" << endl;
	cout << "********************4.�˳�ϵͳ********************" << endl;
	cout << "**************************************************" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
Base::~Base() {}
void Manager::Menu()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "*******************************����Ա����*******************************" << endl;
	cout << "**===���߹���===-----|**===ͼ�����===--------|**===��־����===-----==**" << endl;
	cout << "**==1.��ʾȫ������---|**==7.��ʾȫ��ͼ��------|**17.��ʾȫ���軹��¼==**" << endl;
	cout << "**==2.��ʾָ������---|**==8.��������----------|**18.ɾ����־--------==**" << endl;
	cout << "**==3.��Ӷ��� ------|**==9.��������----------|**19.�����û�--------==**" << endl;
	cout << "**==4.ɾ������-------|**==10.��ISBN����-------|**20.�����鼮--------==**" << endl;
	cout << "**==5.������������---|**==11.������������-----|**-------------------==**" << endl;
	cout << "**==6.��ID���� ------|**==12.������������-----|**-------------------==**" << endl;
	cout << "**-------------------|**==13.��ͼ��������-----|**-------------------==**" << endl;
	cout << "**-------------------|**==14.��δ�����ǰ����-|**-------------------==**" << endl;
	cout << "**-------------------|**==15.���ͼ��---------|**-------------------==**" << endl;
	cout << "**-------------------|**==16.ɾ��ͼ��---------|**-------------------==**" << endl;
	cout << "**==----------------------------�軹����----------------------------==**" << endl;
	cout << "**==------------------------21.��ʾ������Ϣ-------------------------==**" << endl;
	cout << "**==------------------------22.��ʾ��ϸ��Ϣ-------------------------==**" << endl;
	cout << "**==------------------------23.�շ���-------------------------------==**" << endl;
	cout << "**==------------------------===========-----------------------------==**" << endl;
	cout << "**==------------------------24.�޸�����-----------------------------==**" << endl;
	cout << "**==------------------------25.�˳���¼-----------------------------==**" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
int Manager::Sign(Users& users)
{
	cout << "����������id��";
	string id;
	cin >> id;
	cout << "�������������룺";
	string key;
	cin >> key;
	if (users[0].Id != id || users[0].Keywords != key)
	{
		cout << "��������˺Ż������벻��ȷ!" << endl;
		return -1;
	}
	else cout << "�ɹ���¼" << endl;
	return 0;
}
void Manager::System(Users& users, Books& books, List& list, Notes& notes)
{
	system("cls");
	if (Sign(users) == -1) return;
	list.CaculateSub(users,books);//����Աʹ�ã�����ѧ������
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
			cout << "������id��";
			cin >> id;
			int location = users.Find(id);
			if (location == -1) cout << "�ö��߲�����" << endl;
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
			cout << "������ID��";
			cin >> id;
			int location = users.Find(id);
			if (location == -1) cout << "�ö��߲�����" << endl;
			else if (users[location].Count > 0) cout << "�ö��߻�δ������" << endl;
			else if (users[location].Credit > 0) cout << "�ö��߻�δ���巣��" << endl;
			else users.Delete(location);
			cout << "ɾ���ɹ�" << endl;
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
			cout << "��������������";
			cin >> writer;
			books.ShowWriter(writer);
			system("pause");
			system("cls");
		}
		break;
		case 9:
		{
			string field;
			cout << "��������������";
			cin >> field;
			books.ShowField(field);
			system("pause");
			system("cls");
		}
		break;
		case 10:
		{
			string isbn;
			cout << "������ISBN��";
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
			cout << "������ISBN��";
			cin >> isbn;
			int location = books.Search(isbn);
			if (location == -1) cout << "���鲻����" << endl;
			else if (books[location].Islended == 1) cout << "���黹�ڱ����" << endl;
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
			cout << "������ID��";
			cin >> id;
			notes.ShowUser(id);
			system("pause");
			system("cls");
		}
			break;
		case 20:
		{
			string isbn;
			cout << "������ISBN��";
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
			cout << "������ISBN��";
			cin >> isbn;
			list.ShowISBN(isbn);
			system("pause");
			system("cls");
		}
			break;
		case 23:
		{
			string id;
			cout << "���������ID��";
			cin >> id;
			users.Charge(id);
			system("pause");
			system("cls");
		}
			break;
		case 24:
		{
			if (users.CorrectKey(0) == false) cout << "�����޸�ʧ��" << endl;
			else cout << "�����޸ĳɹ�" << endl;
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
			cout << "�������벻�淶������������" << endl;
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
	cout << "===========------|���߽���|------===========" << endl;
	cout << "=====---------|1.��ʾȫ��ͼ��|---------=====" << endl;
	cout << "=====---------|2.����������ѯ|---------=====" << endl;
	cout << "=====----------|3.�������ѯ|----------=====" << endl;
	cout << "=====----------|4.��ISBN��ѯ|----------=====" << endl;
	cout << "=====---------|5.��ʾ������Ϣ|---------=====" << endl;
	cout << "=====-----------|6.�޸�����|-----------=====" << endl;
	cout << "=====-------|7.��ʾ��ǰ������Ϣ|-------=====" << endl;
	cout << "=====-------|8.��ʾ���˽軹��¼|-------=====" << endl;
	cout << "=====-------------|9.����|-------------=====" << endl;
	cout << "=====------------|10.����|-------------=====" << endl;
	cout << "=====--------|11.������������|---------=====" << endl;
	cout << "=====--------|12.������������|---------=====" << endl;
	cout << "=====--------|13.��ͼ��������|---------=====" << endl;
	cout << "=====-----|14.��ͼ���Ƿ�������|------=====" << endl;
	cout << "=====----------|15.ע���˺�|-----------=====" << endl;
	cout << "=====----------|16.�˳���¼|-----------=====" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}
int Reader::Sign(Users& users)
{
	cout << "���������id��";
	string id;
	cin >> id;
	int location=users.Find(id);
	if (location == -1)
	{
		cout << "�˺Ų���ȷ" << endl;
		return -1;
	}
	cout << "������������룺";
	string key;
	cin >> key;
	if (users[location].Keywords != key)
	{
		cout << "���벻��ȷ" << endl;
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
			cout << "����������������";
			cin >> writer;
			books.ShowWriter(writer);
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			string field;
			cout << "�������������ƣ�";
			cin >> field;
			books.ShowField(field);
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			string isbn;
			cout << "������ISBN�ţ�";
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
			cout << "������ISBN��";
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
			if (users[location].Count > 0) cout << "���ȹ黹ͼ��" << endl;
			else if (users[location].Credit > 0) cout << "���Ƚ��巣��" << endl;
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
			cout << "������벻�淶������������" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}
}
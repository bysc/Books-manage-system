#include "LendSystem.h"
int Time::MON[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void Time :: Change(int a, int b, int c, int d )
{
	year = a;
	month = b;
	day = c;
	sub = d;
}
bool Time::isLeapyear()
{
	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int Time::GetGap(Time& t)
{
	while (this->year < t.year || this->month < t.month || this->day < t.day)
	{
		this->day++;
		MON[2] = (this->isLeapyear() ? 29 : 28);
		if (this->day == Time::MON[this->month] + 1)
		{
			this->day = 1;
			this->month++;
		}
		if (this->month == 13)
		{
			this->month = 1;
			this->year++;
		}
		this->sub++;
	}
	return this->sub;
}
List::List()
{
	Node* p = new Node;
	p->Id = "000000";
	p->next = NULL;
	head = p;
	end = p;
	ListSize = 0;
}
void List::ReadFile()
{
	ifstream ifs("LendSystem.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʱ�ļ�LendSystem.txt��ʧ��" << endl;
		exit(0);
	}
	ifs >> ListSize;
	Node* p=NULL;
	for (int i = 0; i < ListSize; i++)
	{
		p = new Node;
		ifs >> p->Id;
		int ArraySize;
		ifs >> ArraySize;
		while (ArraySize--)
		{
			SubLend sublend;
			ifs >> sublend.ISBN;
			int year, month, day, sub;
			ifs >> year >> month >> day >> sub;
			sublend.Tl.Change(year, month, day, sub);
			p->Arr.push_back(sublend);
		}
		p->next = NULL;
		end->next = p;
		end = p;
	}
}
void List::WriteFile()
{
	ofstream ofs("LendSystem.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "д�ļ�ʱ�ļ�LendSystem.txtδ�ܳɹ���" << endl;
		exit(0);
	}
	ofs << ListSize << endl;
	Node* p = head->next;
	while (p)
	{
		ofs << p->Id << '\t' << p->Arr.size() << endl;
		for (int i = 0; i < (int)p->Arr.size(); i++)
		{
			ofs << p->Arr[i].ISBN << '\t' << p->Arr[i].Tl.GetYear() << '\t' << p->Arr[i].Tl.GetMonth()
				<< '\t' << p->Arr[i].Tl.GetDay() << '\t' << p->Arr[i].Tl.GetSub() << endl;
		}
		p = p->next;
	}
	ofs.close();
}

void List::ShowReader(string id)
{
	Node* p = head->next;
	while (p)
	{
		if (p->Id == id)
		{
			cout << "�û�id��" << id << endl;
			for (int i = 0; i < (int)(p->Arr.size()); i++)
				cout << "isbnΪ��" << p->Arr[i].ISBN <<"\t������"<<p->Arr[i].Tl.GetSub()<< endl;
		}
		p = p->next;
	}
}
void List::ShowReader(int i, Users& users, Books& books)
{
	cout << users[i].Name << "��" << endl;
	Node* p = head->next;
	while (p)
	{
		if (p->Id == users[i].Id)
		{
			for (int i = 0; i < (int)p->Arr.size(); i++)
			{
				cout << books.GetName(p->Arr[i].ISBN) << "\t������" << p->Arr[i].Tl.GetSub() << endl;
			}
		}
		p = p->next;
	}
}
void List::ShowISBN(string isbn)
{
	Node* p = head->next;
	while (p)
	{
		for (int i = 0; i < (int)p->Arr.size(); i++)
		{
			if (p->Arr[i].ISBN == isbn)
			{
				cout << p->Id << '\t' << p->Arr[i].ISBN <<"\t������"<<p->Arr[i].Tl.GetSub()<< endl;
				return;
			}
		}
		p = p->next;
	}
}
void List::ShowAll()
{
	Node* p = head->next;
	while (p)
	{
		cout << p->Id << "��" << endl;
		for (int i = 0; i < (int)p->Arr.size(); i++)
		{
			cout << p->Arr[i].ISBN << '\t' << "������" << p->Arr[i].Tl.GetSub() << endl;
		}
		p = p->next;
	}
}
void List::AddNode(Users& users, Books& books, Notes& notes)
{
	string id;
	string isbn;
	string key;
	int year, month, day;
	cout << "�������û�id��";
	cin >> id;
	cout << "������ͼ��ISBN�ţ�";
	cin >> isbn;
	cout << "���������룺";
	cin >> key;
	cout << "�����������գ��Կո��������Ҫ��ǰ���0��";
	cin >> year >> month >> day;
	int i = users.Find(id);
	int j = books.Search(isbn);
	if (i == -1) cout << "���û�������" << endl;
	else if (users[i].Keywords != key) cout << "�������" << endl;
	else if (users[i].Count == 10) cout << "���û��������Ѵ�����" << endl;
	else if (users[i].Credit > 0) cout << "���Ƚ��巣��" << endl;
	else if (j == -1) cout << "��ͼ�鲻����" << endl;
	else if (books[j].Islended == 1) cout << "�����Ѿ������" << endl;
	else if(users[i].Count==0)
	{
		
		Node* p = new Node;
		p->Id = id;
		SubLend tmp;
		tmp.ISBN = isbn;
		tmp.Tl.Change(year, month, day);
		p->Arr.push_back(tmp);
		p->next = NULL;
		end->next = p;
		end = p;
		ListSize++;
		users[i].Count++;
		books[j].Islended = 1;
		books[j].Id = id;
		notes.AddNotes(id, isbn, LEND, year, month, day);
		cout << "����ɹ�" << endl;
		return;
	}
	else
	{
		Node* p = head->next;
		while (p)
		{
			if (p->Id == id)
			{
				SubLend tmp;
				tmp.ISBN = isbn;
				tmp.Tl.Change(year, month, day);
				p->Arr.push_back(tmp);
				break;
			}
			p = p->next;
		}
		users[i].Count++;
		books[j].Islended = 1;
		books[j].Id = id;
		notes.AddNotes(id, isbn, LEND, year, month, day);
		cout << "����ɹ�" << endl;
		return;
	}
	cout << "����ʧ��" << endl;
}
void List::DeleteNode(string isbn,Users&users,Books&books,Notes&notes)
{
	cout << "�����뵱ǰʱ�䣬�����գ�";
	int year, month, day;
	cin >> year >> month >> day;
	Time tr(year, month, day);
	Node* p = head->next;
	while (p)
	{
		for (int i = 0; i < (int)(p->Arr.size()); i++)
		{
			if (p->Arr[i].ISBN == isbn)
			{
				int m = users.Find(p->Id);
				int n = books.Search(p->Arr[i].ISBN);
				int gap = p->Arr[i].Tl.GetGap(tr);
				if (gap > 60)
				{
					cout << "���鳬ʱ�黹,��������" << gap << endl;
				}
				users[m].Count--;
				books[n].Islended = false;
				books[n].Id = "00000000";
				notes.AddNotes(p->Id, p->Arr[i].ISBN, RETURN, year, month, day);
				p->Arr.erase(p->Arr.begin() + i);
				cout << "����ɹ�" << endl;
				if (p->Arr.size() == 0)
				{
					Node* left = head;
					while (left->next != p) left = left->next;
					if (p == end) end = left;
					left->next = p->next;
					delete p;
					ListSize--;
				}
				return;
			}
		}
		p = p->next;
	}
	cout << "����ʧ��" << endl;
}
void List::Clear()
{
	Node* p = head;
	Node* tmp;
	while (p)
	{
		tmp = p->next;
		delete p;
		p = tmp;
	}
	head = NULL;
	end = NULL;
	ListSize = 0;
}
void List::CaculateSub(Users&users,Books&books)
{
	int year, month, day;
	cout << "�����������գ�";
	cin >> year >> month >> day;
	Time tr(year, month, day);
	Node* p = head->next;
	while (p)
	{
		int location = users.Find(p->Id);
		users[location].Credit = 0;
		for (int i = 0; i < (int)p->Arr.size(); i++)
		{
			int sub=p->Arr[i].Tl.GetGap(tr);
			if (sub >60)
			{
				users[location].Credit++;
				cout << "�û���" << users[location].Name << "\tͼ�飺" << books.GetName(p->Arr[i].ISBN) << "\t��" << sub << "��" << endl;;
			}	
		}
		p = p->next;
	}
}
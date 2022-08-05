#include "BooksManage.h"
void Books::ReadFile()
{
	ifstream ifs("BooksManage.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʱδ�ܴ��ļ�BooksManage.txt" << endl;
		exit(0);
	}
	int size;
	ifs >> size;
	Array.reserve(size + 100);
	for (int i = 0; i < size; i++)
	{
		BooksInf cur;
		ifs >> cur.Name >> cur.Writer >> cur.ISBN >> cur.Field >> cur.Press >> cur.Price >> cur.Islended >> cur.Id;
		Array.push_back(cur);
	}
	ifs.close();
}
void Books::WriteFile()
{
	ofstream ofs("BooksManage.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "д�ļ�ʱδ�ܴ��ļ�BooksManage.txt" << endl;
		exit(0);
	}
	ofs << Array.size() << endl;
	for (int i = 0; i < (int)Array.size(); i++)
	{
		ofs << Array[i].Name << '\t' << Array[i].Writer << '\t' << Array[i].ISBN << '\t' << Array[i].Field
			<< '\t' << Array[i].Press << '\t' << Array[i].Price << '\t' << Array[i].Islended << '\t' << Array[i].Id << endl;
	}
	ofs.close();
}
int Books::Search(string isbn) const
{
	for (int i = 0; i < (int)Array.size(); i++)
	{
		if (Array[i].ISBN == isbn) return i;
	}
	return -1;
}
//int Books::Search(string name, string writer) const
//{
//	for (int i = 0; i < (int)Array.size(); i++)
//	{
//		if (Array[i].Name == name && Array[i].Writer == writer) return i;
//	}
//	return -1;
//}
BooksInf& Books::operator[](int i)
{
	return Array[i];
}
string Books::GetName(int i) const
{
	return Array[i].Name;
}
string Books::GetName(string isbn) const
{
	int tmp = Search(isbn);
	if (tmp == -1) return "��ɾ��";
	else return Array[tmp].Name;
}
void Books::ShowInd(int i) const
{
	cout << "������" << Array[i].Name << '\t' << "���ߣ�" << Array[i].Writer << '\t' << "����" << Array[i].Field << '\t' << "ISBN��"
		<< Array[i].ISBN << '\t' << "�����磺" << Array[i].Press << "������" << '\t' << "���ۣ�" << Array[i].Price << '\t';
	if (Array[i].Islended == 0) cout << "δ�����" << endl;
	else cout << "������" << Array[i].Id << "���" << endl;
}
void Books::ShowAll() const
{
	cout <<left<<setw(12)<< "������"<<setw(12)<<"���ߣ�"<<setw(12) << "����"<<setw(16)<<"ISBN��"<< "�����磺" << "\t���ۣ�\t״̬��\t" << endl;
	for (int i = 0; i < (int)Array.size(); i++)
	{
		cout <<left<<setw(12)<< Array[i].Name <<setw(12) << Array[i].Writer <<setw(12)<< Array[i].Field <<setw(16)<< Array[i].ISBN 
			<< Array[i].Press <<'\t'<< Array[i].Price << '\t';
		if (Array[i].Islended == 0) cout << "δ�����" << endl;
		else cout << "������" << Array[i].Id << "���" << endl;
	}
}
void Books::ShowWriter(string writer) const
{
	for (int i = 0; i < (int)Array.size(); i++)
	{
		if (Array[i].Writer == writer) ShowInd(i);
	}
}
void Books::ShowField(string field) const
{
	for (int i = 0; i < (int)Array.size(); i++)
	{
		if (Array[i].Field == field) ShowInd(i);
	}
}
void Books::ShowISBN(string isbn) const
{
	int i = Search(isbn);
	if (i == -1) cout << "��ͼ�鲻����" << endl;
	else ShowInd(i);
}

void Books::AddBooks()
{
	if (Array.size() == Array.capacity() - 1) Array.reserve(Array.size() + 100);
	string isbn;
	cout << "������isbn��" << endl;
	cin >> isbn;
	if (IsFigure(isbn) == false||isbn.size()!=13)
	{
		cout << "������13λ����" << endl;
		return;
	}
	int check = Search(isbn);
	if (check != -1)
	{
		cout << "�����Ѿ�¼��ϵͳ" << endl;
		return;
	}
	else
	{
		string name;
		string field;
		string writer;
		string press;
		float price;
		cout << "������������";
		cin >> name;
		cout << "����������";
		cin >> field;
		cout << "��������������";
		cin >> writer;
		cout << "�����������������Ҫ�ӳ����������֣���";
		cin >> press;
		cout << "�����뵥�ۣ�";
		cin >> price;
		BooksInf cur;
		cur.Name = name;
		cur.ISBN = isbn;
		cur.Field = field;
		cur.Writer = writer;
		cur.Press = press;
		cur.Price = price;
		cur.Islended = 0;
		cur.Id = "00000000";
		Array.push_back(cur);
	}
	cout << "��ӳɹ���" << endl;
}
void Books::DeleteBooks(int i)
{
	Array.erase(Array.begin()+i);
}
void Books::SortByField()
{
	for (int i = 0; i < (int)Array.size()-1; i++)
	{
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Field > Array[j + 1].Field)
			{
				BooksInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	}
}
void Books::SortByWriter()
{
	for (int i = 0; i < (int)Array.size() - 1; i++)
	{
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Writer > Array[j + 1].Writer)
			{
				BooksInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	}
}
void Books::SortByName()
{
	for (int i = 0; i < (int)Array.size() - 1; i++)
	{
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Name > Array[j + 1].Name)
			{
				BooksInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	}
}
void Books::SortByLR()
{
	for (int i = 0; i < (int)Array.size() - 1; i++)
	{
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Islended > Array[j + 1].Islended)
			{
				BooksInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	}
}
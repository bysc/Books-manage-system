#include "BooksManage.h"
void Books::ReadFile()
{
	ifstream ifs("BooksManage.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "读文件时未能打开文件BooksManage.txt" << endl;
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
		cout << "写文件时未能打开文件BooksManage.txt" << endl;
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
	if (tmp == -1) return "已删除";
	else return Array[tmp].Name;
}
void Books::ShowInd(int i) const
{
	cout << "书名：" << Array[i].Name << '\t' << "作者：" << Array[i].Writer << '\t' << "领域：" << Array[i].Field << '\t' << "ISBN："
		<< Array[i].ISBN << '\t' << "出版社：" << Array[i].Press << "出版社" << '\t' << "单价：" << Array[i].Price << '\t';
	if (Array[i].Islended == 0) cout << "未被借出" << endl;
	else cout << "被读者" << Array[i].Id << "借出" << endl;
}
void Books::ShowAll() const
{
	cout <<left<<setw(12)<< "书名："<<setw(12)<<"作者："<<setw(12) << "领域："<<setw(16)<<"ISBN："<< "出版社：" << "\t单价：\t状态：\t" << endl;
	for (int i = 0; i < (int)Array.size(); i++)
	{
		cout <<left<<setw(12)<< Array[i].Name <<setw(12) << Array[i].Writer <<setw(12)<< Array[i].Field <<setw(16)<< Array[i].ISBN 
			<< Array[i].Press <<'\t'<< Array[i].Price << '\t';
		if (Array[i].Islended == 0) cout << "未被借出" << endl;
		else cout << "被读者" << Array[i].Id << "借出" << endl;
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
	if (i == -1) cout << "该图书不存在" << endl;
	else ShowInd(i);
}

void Books::AddBooks()
{
	if (Array.size() == Array.capacity() - 1) Array.reserve(Array.size() + 100);
	string isbn;
	cout << "请输入isbn号" << endl;
	cin >> isbn;
	if (IsFigure(isbn) == false||isbn.size()!=13)
	{
		cout << "请输入13位数字" << endl;
		return;
	}
	int check = Search(isbn);
	if (check != -1)
	{
		cout << "该书已经录入系统" << endl;
		return;
	}
	else
	{
		string name;
		string field;
		string writer;
		string press;
		float price;
		cout << "请输入书名：";
		cin >> name;
		cout << "请输入领域：";
		cin >> field;
		cout << "请输入作者名：";
		cin >> writer;
		cout << "请输入出版社名（不要加出版社三个字）：";
		cin >> press;
		cout << "请输入单价：";
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
	cout << "添加成功！" << endl;
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
#include "Notes.h"
Notes::Notes()
{
	head = new NotesNode;
	head->id = "000000";
	head->isbn = "0000000000000";
	head->L_R = -1;
	head->time[0] = 0;
	head->time[1] = 0;
	head->time[2] = 0;
	head->next = NULL;
	end = head;
	NotesSize = 0;
}
void Notes::ReadFile()
{
	ifstream ifs("Notes.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "读文件时Notes.txt文件打开失败" << endl;
		exit(0);
	}
	ifs >> NotesSize;
	NotesNode* cur = NULL;
	for (int i = 0; i < NotesSize; i++)
	{
		cur = new NotesNode;
		ifs >> cur->id >> cur->isbn >> cur->L_R >> cur->time[0] >> cur->time[1] >> cur->time[2];
		cur->next = NULL;
		end->next = cur;
		end = cur;
	}
	ifs.close();
}
void Notes::WriteFile()
{
	ofstream ofs("Notes.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "写文件时Notes.txt未能打开";
		exit(0);
	}
	ofs << NotesSize << endl;
	NotesNode* p = head->next;
	while (p)
	{
		ofs << p->id << '\t' << p->isbn << '\t' << p->L_R << '\t' << p->time[0] << '\t' << p->time[1] << '\t' << p->time[2] << endl;
		p = p->next;
	}
	ofs.close();
}
void Notes::ShowBook(string isbn)
{
	NotesNode* p = head->next;
	while (p)
	{
		if (p->isbn == isbn) cout << "用户：" << p->id << (p->L_R ? "(还)" : "(借)") << '\t' << "时间：" << p->time[0] << "年" << p->time[1] << "月" << p->time[2] << "日" << endl;
		p = p->next;
	}
}
void Notes::ShowUser(string id)
{
	NotesNode* p = head->next;
	while (p)
	{
		if (p->id == id) cout << "ISBN：" << p->isbn << (p->L_R ? "(还)" : "(借)") << '\t' << "时间：" << p->time[0] << "年" << p->time[1] << "月" << p->time[2] << "日" << endl;
		p = p->next;
	}
}
void Notes::ShowUser(int i, Users& users, Books& books)
{
	NotesNode* p = head->next;
	while (p)
	{
		if (p->id == users[i].Id) cout << "时间：" << p->time[0] << "年" << p->time[1] << "月" << p->time[2] << "日"
			<< (p->L_R ? "(还)" : "(借)") << books.GetName(p->isbn) << endl;
		p = p->next;
	}
}
//void Notes::ShowAllBrief()
//{
//	NotesNode* p = head->next;
//	while (p)
//	{
//		cout << "用户：" << p->id << (p->L_R ? "(还)" : "(借)") << '\t' << "ISBN：" << p->isbn << '\t' << "时间："
//			<< p->time[0] << "年" << p->time[1] << "月" << p->time[2] << "日" << endl;
//		p = p->next;
//	}
//}
void Notes::ShowAllDetailed(Users& users, Books& books)
{
	NotesNode* p = head->next;
	while (p)
	{
		cout << "用户：" << users.GetName(p->id) << (p->L_R ? "(还)" : "(借)") << '\t' << "图书：" << books.GetName(p->isbn) << '\t' << "时间："
			<< p->time[0] << "年" << p->time[1] << "月" << p->time[2] << "日" << endl;
		p = p->next;
	}
}
void Notes::AddNotes(string id, string isbn,int lr,int year,int month,int day)
{
	NotesNode* p = new NotesNode;
	p->id = id;
	p->isbn = isbn;
	p->L_R = lr;
	p->time[0] = year;
	p->time[1] = month;
	p->time[2] = day;
	p->next = NULL;
	end->next = p;
	end = p;
	NotesSize++;
}
void Notes::DeleteNotes()
{
	int Nums;
	cout << "请输入您要删除的记录条数（共有" << NotesSize << "条）：";
	cin >> Nums;
	if (Nums > NotesSize||Nums<1)
	{
		cout << "输入不正确" << endl;
		return;
	}
	NotesSize -= Nums;
	NotesNode* p = head->next;
	while (Nums-- && p) p = p->next;
	NotesNode* left = head->next;
	NotesNode* right = NULL;
	while (left&&left!=p)
	{
		right = left->next;
		delete left;
		left = right;
	}
	head->next = p;
	if (NotesSize == 0) end = head;
}
void Notes::Clear()
{
	NotesNode* p = head;
	NotesNode* tmp = NULL;
	while (p)
	{
		tmp = p->next;
		delete p;
		p = tmp;
	}
	head = NULL;
	end = NULL;
	NotesSize = 0;
}
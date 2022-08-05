#include "UsersManage.h"
bool IsFigure(string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}
void Users::ReadFile()
{
	ifstream ifs("UsersManage.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "UsersManage读文件时打开失败" << endl;
		exit(0);
	}
	int size;
	ifs >> size;
	Array.reserve(size + 100);
	for (int i = 0; i < size; i++)
	{
		UsersInf cur;
		ifs >> cur.Name >> cur.Id >> cur.Keywords >> cur.Sex >> cur.Count >> cur.Credit;
		Array.push_back(cur);
	}
	ifs.close();
}
void Users::WriteFile()
{
	ofstream ofs("UsersManage.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "不能打开UsersManage文件";
		exit(0);
	}
	ofs << Array.size() << endl;
	for (int i = 0; i < (int)Array.size(); i++)
	{
		ofs << Array[i].Name << '\t' << Array[i].Id << '\t' << Array[i].Keywords << '\t' << Array[i].Sex << '\t' << Array[i].Count
			<< '\t' << Array[i].Credit << endl;
	}
	ofs.close();
}
int Users::Find(string id) const
{
	for (int i = 1; i < (int)Array.size(); i++)
	{
		if (id == Array[i].Id) return i;
	}
	return -1;
}
UsersInf& Users::operator[](int i)
{
	return Array[i];
}
string Users::GetName(int i) const
{
	return Array[i].Name;
}
string Users::GetName(string id) const
{
	int tmp = Find(id);
	if (tmp == -1) return "已注销";
	else return Array[tmp].Name;
}
void Users::ShowInd(int i) const
{
	cout << "姓名：" << Array[i].Name << '\t' << "性别：" << (Array[i].Sex ? "男" : "女") << '\t' << "学号：" << Array[i].Id
		<< '\t' << "借书数：" << Array[i].Count << '\t' << "当前违规书数：" << Array[i].Credit << endl;
}
void Users::ShowAll() const
{
	for (int i = 1; i < (int)Array.size(); i++)
	{
		ShowInd(i);
	}
}
void Users::AddUsers()
{
	if (Array.size() == Array.capacity() - 1) Array.reserve(Array.size() + 100);
	string id;
	cout << "请输入你的学号：";
	cin >> id;
	int tmp= Find(id);
	if (tmp != -1)
	{
		cout << "该学号已被注册";
		return;
	}
	if (id.size() != 8)
	{
		cout << "学号位数不正确" << endl;
		return;
	}
	if (IsFigure(id) == false)
	{
		cout << "请输入正确的学号" << endl;
		return;
	}
		string name;
		int sex;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入性别,1--男，0--女：";
		cin >> sex;
		string keywords;
		cout << "请输入密码：";
		cin >> keywords;
		string newkey;
		cout << "请确认密码：";
		while (1)
		{
			cin >> newkey;
			if (keywords == newkey) break;
			else cout << "密码有误,请重新输入：" << endl;
		}
		UsersInf cur;
		cur.Name = name;
		cur.Sex = sex;
		cur.Id = id;
		cur.Keywords = keywords;
		cur.Credit = 0;
		cur.Count = 0;
		Array.push_back(cur);
		cout << "注册成功!" << endl;
}
void Users::Delete(int i)
{
	Array.erase(Array.begin() + i);
}
bool Users::CorrectKey(int i)
{
	cout << "请输入原来的密码：";
	string lastkey;
	int nums = 3;
	while (nums--)
	{
		cin >> lastkey;
		if (lastkey == Array[i].Keywords) break;
		else
		{
			cout << "密码错误，请重新输入，目前还有" << nums << "次机会" << endl;
			if(nums==0) return false;
		}
	}
	string newkey;
	string checknewkey;
	cout << "请输入新密码：" ;
	cin >> newkey;
	cout << "请确认新密码：" ;
	while (1)
	{
		cin >> checknewkey;
		if (checknewkey == newkey)
		{
			Array[i].Keywords = newkey;
			return true;
		}
		else cout << "请重新确认输入新密码：";
	}
	return false;
}
void Users::SortByCounts()
{
	for(int i=1;i<(int)Array.size()-1;i++)
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Count < Array[j + 1].Count)
			{
				UsersInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	cout << "排序完成" << endl;
}
void Users::SortById()
{
	for (int i = 1; i < (int)Array.size() - 1; i++)
		for (int j = 0; j < (int)Array.size() - 1 - i; j++)
		{
			if (Array[j].Id > Array[j + 1].Id)
			{
				UsersInf tmp;
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	cout << "排序完成" << endl;
}
void Users::Charge(string id)
{
	int location = Find(id);
	if (location == -1)
	{
		cout << "该用户已还清罚款或未违规" << endl;
		return;
	}
	cout << "该读者共违规" << Array[location].Credit << "次" << endl;
	int check = 0;
	cout << "是否已经缴清罚款？1--是，0--否：";
	cin >> check;
	if (check == 1) Array[location].Credit = 0;
}
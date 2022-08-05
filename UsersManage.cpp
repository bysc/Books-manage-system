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
		cout << "UsersManage���ļ�ʱ��ʧ��" << endl;
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
		cout << "���ܴ�UsersManage�ļ�";
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
	if (tmp == -1) return "��ע��";
	else return Array[tmp].Name;
}
void Users::ShowInd(int i) const
{
	cout << "������" << Array[i].Name << '\t' << "�Ա�" << (Array[i].Sex ? "��" : "Ů") << '\t' << "ѧ�ţ�" << Array[i].Id
		<< '\t' << "��������" << Array[i].Count << '\t' << "��ǰΥ��������" << Array[i].Credit << endl;
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
	cout << "���������ѧ�ţ�";
	cin >> id;
	int tmp= Find(id);
	if (tmp != -1)
	{
		cout << "��ѧ���ѱ�ע��";
		return;
	}
	if (id.size() != 8)
	{
		cout << "ѧ��λ������ȷ" << endl;
		return;
	}
	if (IsFigure(id) == false)
	{
		cout << "��������ȷ��ѧ��" << endl;
		return;
	}
		string name;
		int sex;
		cout << "������������";
		cin >> name;
		cout << "�������Ա�,1--�У�0--Ů��";
		cin >> sex;
		string keywords;
		cout << "���������룺";
		cin >> keywords;
		string newkey;
		cout << "��ȷ�����룺";
		while (1)
		{
			cin >> newkey;
			if (keywords == newkey) break;
			else cout << "��������,���������룺" << endl;
		}
		UsersInf cur;
		cur.Name = name;
		cur.Sex = sex;
		cur.Id = id;
		cur.Keywords = keywords;
		cur.Credit = 0;
		cur.Count = 0;
		Array.push_back(cur);
		cout << "ע��ɹ�!" << endl;
}
void Users::Delete(int i)
{
	Array.erase(Array.begin() + i);
}
bool Users::CorrectKey(int i)
{
	cout << "������ԭ�������룺";
	string lastkey;
	int nums = 3;
	while (nums--)
	{
		cin >> lastkey;
		if (lastkey == Array[i].Keywords) break;
		else
		{
			cout << "����������������룬Ŀǰ����" << nums << "�λ���" << endl;
			if(nums==0) return false;
		}
	}
	string newkey;
	string checknewkey;
	cout << "�����������룺" ;
	cin >> newkey;
	cout << "��ȷ�������룺" ;
	while (1)
	{
		cin >> checknewkey;
		if (checknewkey == newkey)
		{
			Array[i].Keywords = newkey;
			return true;
		}
		else cout << "������ȷ�����������룺";
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
	cout << "�������" << endl;
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
	cout << "�������" << endl;
}
void Users::Charge(string id)
{
	int location = Find(id);
	if (location == -1)
	{
		cout << "���û��ѻ��巣���δΥ��" << endl;
		return;
	}
	cout << "�ö��߹�Υ��" << Array[location].Credit << "��" << endl;
	int check = 0;
	cout << "�Ƿ��Ѿ����巣�1--�ǣ�0--��";
	cin >> check;
	if (check == 1) Array[location].Credit = 0;
}
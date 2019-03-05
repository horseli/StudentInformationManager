#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"person.h"
using namespace std;
 manager::manager()
{
	 password = 123456;
}
 manager::~manager()
 {
	 cout << "管理员已析构" << endl;
 }
void manager::SetPassword()
{
L:
	cout << "请输入原密码" << endl;
	string s, s1, s2;
	cin >> s;
	if (s1.compare(s2) != 0)
	{
		cout << "密码错误！" << endl;
		goto L;
	}
	else
	{
		cout << "请输入新密码 建议密码中含有数字，字母和符号至少两种组合" << endl;
		cin >> s1;
		cout << "请再次确认密码" << endl;
		cin >> s2;
		while (s1 != s2)
		{
			cout << "两次输入密码不匹配！请重新输入。\n";
			cin >> s1;
			cout << "请再次确认密码" << endl;
			cin >> s2;
		}

	}
}
void manager::Filedo()
{

}
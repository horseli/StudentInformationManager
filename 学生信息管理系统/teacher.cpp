#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"person.h"
using namespace std;

teacher::teacher(string Name, string Id)
{
	name = Name;
	id = Id;
}

void teacher::SetPassword()
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



teacher:: teacher()
{
	id = "0";
	password = "0";
	name = "0";
}
teacher::teacher(string Name, string Id, string Password)
{
	name = Name;
	id = Id;
	password = Password;
}
teacher::~teacher()
{
	;
}
void teacher:: MakeTeacher(string Name, string Id, string Password)
{
	name = Name;
	id = Id;
	password = Password;
}
void SetPassword()
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
//输入课程信息

 void teacher::SetTeacher()//未检验
{
	 SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	 cout << "\n\t************初始化老师档案************\n ";
	 SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		 cout<<"请输入要初始化老师的人数" << endl;
	 int teacNum;
	 cin >> teacNum;
	 cout << "\t请先初始化一个教师登录密码\n\t\t初始密码为：";
	 string Password;
	 cin >> Password;
	

	 cout << "\t请输入老师的姓名和工号\n\n";
	 teacher*p ;
	 teacher*s;
	 
	 s = new teacher;
	 SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	 string Name, Id;
	 cout << "\t?姓名：\t" ;
	 cin >> Name;
	 cout << "\t?工号：\t";
		 cin>> Id;
		 cout << endl;
	 s->MakeTeacher(Name, Id, Password);
	 next = s;
	 p = s;
	 for (int i = 1; i < teacNum;i++)
	 {
		
		 s = new teacher;
		 cout << "\t?姓名：\t" ;
		 cin >> Name;
		 cout << "\t?工号：\t";
		 cin >> Id;
		 cout << endl;
		 s->MakeTeacher(Name, Id,Password);
		 p->next = s;
		 p = s;
		
	 }
	/* p = next;
	 while (p)
	 {
		 cout << p->getname() << '\t' << p->id << endl;
		 p = p->next;
	 }*/
}
 void teacher:: AddTeacher(teacher*p)
{
	 p->next = next;
	 next = p;
}
 void teacher::DeleteTeacher(teacher*p)
{
	 teacher *s = next;
	 next = p->next;
	 delete(p);
}
 void Regist(string Id, string Password, teacher A, teacher&p)
 {
 //L:
	// teacher*s = A.next;
	// while (s)
	// {
	//	 if (s->id.compare(Id) && s->getpass().compare(Password))
	//	 {
	//		 cout << s->getname() << "老师  您好,欢迎登录成绩管理系统!\n";
	//		 p = *s;
	//		 cout << "即将转入操作界面，";
	//		 system("pause");
	//		 system("cls");
	//		 return;
	//	 }
	//	 s = s->next;
	// }
	// if (!s)
	// {
	//	 cout << "密码或账号错误，请重新登录！\n即将转入登录界面，";
	//	 system("pause");
	//	 system("cls");
	//	 goto L;
	// }
 L:
	 { teacher*s = A.next;

	 while (s)
	 {
		 if (s->id == Id && s->getpass() == Password)
		 {

			 cout <<'\t'<< s->getname() << "老师 你好,欢迎登录学生成绩管理系统!\n\n";
			 p = *s;
			 if (Password == "123456")
			 {
				 cout << "\t第一次登陆管理系统，为保障你的账户安全，建议修改密码，是否修改？\n\t\t1.现在修改\n\t\t2.稍后再改\n";
				 int x;
				 cout << "\t请选择：\t";
				 cin >> x;
				 if (x != 1 && x != 2)
				 {
					 cout << "\t输入错误！\n";
					 goto L;
				 }
				 switch (x)
				 {
				 case 1:
				 {m:
					 cout << "请输入原密码" << endl;
					 string ss, s1, s2;
					 cin >> ss;
					 if (s1.compare(s2) != 0)
					 {
						 cout << "密码错误！" << endl;
						 goto m;
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
						 s->MakeTeacher(s1);
					 }
				 }
					 break;
				 case 2:
					 ;
				 }

			 }

			 cout << "\n即将转入操作界面，";
			 system("pause");
			 system("cls");
			 return;
		 }
		 s = s->next;
	 }
	 if (!s)
	 {
		 cout << "密码或账号错误，请重新登录！\n即将转入登录界面，";
		 system("pause");
		 system("cls");
		
		 p.id = "no";
	 }
	 }
 }
 void File_save(string file_teac, teacher*A)//dddddd
 {
	 fstream f(file_teac, ios::out | ios::binary);
	 teacher*p = A->next;
	 int stuNum = 0;
	 while (p)
	 {
		 stuNum++;
		 p = p->next;
	 }
	 p = A->next;
	 f.write((char*)&stuNum, sizeof(int));
	 while (p)
	 {
		 f.write((char*)&(*p), sizeof(teacher));
		 p = p->next;
	 }
 }
 void File_load(string file_teac, teacher*A)
 {
	 ifstream f(file_teac, ios::in);

	 teacher*p;
	 teacher *s;
	 int stuNum;
	 f.read((char*)&stuNum, sizeof(int));
	 s = new teacher;
	 f.read((char*)&(*s), sizeof(teacher));

	 (*A).next = s;
	 p = s;
	 for (int i = 1; i < stuNum; i++)
	 {
		 s = new teacher;
		 f.read((char*)&(*s), sizeof(teacher));
		 //cout << s->course << endl;
		 p->next = s;
		 p = s;
	 }
	 p = (*A).next;
 }
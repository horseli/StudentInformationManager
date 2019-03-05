//#include<iostream>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include <Windows.h>
#include< conio.h >
#include"person.h"
using namespace std;
const string studentDat = "studet.dat";
const string studentTxt = "student.txt";
const string teacherDat = "teacher.dat";
const string teacherTxt = "teacher.txt";
const string studentPhoneTxt = "studentPhone.txt";//通讯录文件

double stringToDouble(string num)
{
	bool minus = false;      //标记是否是负数  
	string real = num;       //real表示num的绝对值
	if (num.at(0) == '-')
	{
		minus = true;
		real = num.substr(1, num.size() - 1);
	}

	char c;
	int i = 0;
	double result = 0.0, dec = 10.0;
	bool isDec = false;       //标记是否有小数
	unsigned long size = real.size();
	while (i < size)
	{
		c = real.at(i);
		if (c == '.')
		{//包含小数
			isDec = true;
			i++;
			continue;
		}
		if (!isDec)
		{
			result = result * 10 + c - '0';
		}
		else
		{//识别小数点之后都进入这个分支
			result = result + (c - '0') / dec;
			dec *= 10;
		}
		i++;
	}

	if (minus == true) {
		result = -result;

	}

	return result;
}
 

class Paword//输入密码隐藏字符并以*回显
{
public:
	Paword()//构造函数用于初始化密码，使之为空  
	{psw = "";//初始化密码为空;  
		length = 0; //初始化密码长度  
	}
	void inputPassword()//用于输入并回显*为密码  
	{
		char temp_c;
		while (true)
		{
			temp_c = _getch();  //输入一个字符  
			if (temp_c != char(13))  //判断该字符是不为回车，如果是则退出while  
			{
				switch (temp_c)
				{
				case 8:
					if (length != 0)
					{
						cout << "/b /b";
						psw = psw.substr(0, length - 1);
						length--;
					}
					else;
					break;
				default:
					cout << "*"; //用*代替密码 
					psw += temp_c;//连成字符串；  
					length++;
					break;
				}
			}
			else break;
		}
	}
	string getPassword()//返回一个密码字符串，其实可以把密码再次加密，存在数据库中。  
	{return psw;}
private:
	string psw;//用于存密码的字符串；  
	int length;//密码长度  
};

 void PrintCenterAlign(char *pStr, int Len=100)
 {
	     int SpaceNum = (Len - strlen(pStr)) / 2;
	
		     printf("%*s\n", SpaceNum + strlen(pStr), pStr);
	 }
void PrintGodBless()
 {
	     PrintCenterAlign("_ooOoo_", 100);
	     PrintCenterAlign("o8888888o", 100);
	     PrintCenterAlign("88\" . \"88", 100);
	     PrintCenterAlign("(| -_- |)", 100);
	     PrintCenterAlign("O\\ = /O", 100);
	     PrintCenterAlign("____/'---'\\____", 100);
	     PrintCenterAlign(".' \\\\| |// '.", 100);
	     PrintCenterAlign("/ \\\\||| : |||// \\", 100);
	     PrintCenterAlign("/ _||||| -:- |||||- \\", 100);
	     PrintCenterAlign("| | \\\\\\ - /// | |", 100);
	     PrintCenterAlign("| \\_| ''\\---/'' |_/", 100);
	     PrintCenterAlign("\\ .-\\__ `-` ___/-. /", 100);
	     PrintCenterAlign("___`. .' /--.--\\ `. . __", 100);
	     PrintCenterAlign(".\"\" '< `.___\\_<|>_/___.' >'\"\".", 100);
	     PrintCenterAlign("| | : `- \\`.;`\\ _ /`;.`/ - ` : | |", 100);
	     PrintCenterAlign("\\ \\ `-. \\_ __\\ /__ _/ .-` / /", 100);
	     PrintCenterAlign("======`-.____`-.___\\_____/___.-`____.-'======", 100);
	     PrintCenterAlign("`=---='", 100);
	     printf("\n");
	     PrintCenterAlign("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^", 100);
		 PrintCenterAlign("  * 博学慎思         明辨笃行* ", 100);
		 /*PrintCenterAlign("  *佛祖保佑          永无bug* ", 100);*/
	     /*PrintCenterAlign("  *God Bless          Never Crash* ", 100);*/
	 }
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
void stuGui()
{
	R:
	string Name, id, Password;
	cout << "\n\n\n";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
	cout << "**********************欢迎来到学生登录界面!**********************\n\n";
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t\tid：\t";
	cin >> id;
	cout << endl;
	cout << "\t\tpassword：\t";
	
	Paword psw;
	psw.inputPassword();
	Password=psw.getPassword();
	cout << endl<<endl;
	student A;
	File_load(studentDat, &A);
	student p;
	Regist(id, Password, A, p);
	if (p.course == "no")
		goto R;
L:
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
	cout << "\n\t*******************欢迎来到学生操作界面!*******************\n\n";
	cout << "     \n\t请选择您想完成的操作\n\n";
	/*cout << "\n请选择您想完成的操作\n";*/
	cout << "\t1.全部成绩查询\n\t2.单科成绩查询\n\t3.修改联系方式\n\t4.修改密码\n\t5.退出\n";
	int x;
	cout << "\n\t温馨提示：同过正常退出操作才能实现文件的保存！\n";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n\t请输入：\t";
	cin >> x;
	cout << "\n\n";
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	if(x!=1&&x!=2&&x!=3&&x!=4&&x!=5)
	{
		cout << "输入错误！请重试\n";
		goto L;
	}
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	switch (x)
	{
	case 1:
	{student*ptemp = A.next;
	cout << setiosflags(ios::left) << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "班级" << setw(10);
	istringstream f(ptemp->course);
	string subjectt;
	int couNum;
	f >> couNum;
	for (int i = 0; i < couNum; i++)
	{
		f >> subjectt;
		cout << subjectt << setw(8);
		cout << "学分" << setw(10);
	}
	cout << setw(10) << "平均成绩\n";
	ShowScore_a_stu(&p);
	cout << "即将返回主界面,";
	system("pause");
	system("cls");
	goto L;; }
	case 2:
		Show_one(&A,&p);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 3:
	{PrintCenterAlign("*******修改联系方式*******\n");
	PrintCenterAlign("当前电话为为：");
	cout << setw(56) << p.getphonum()<<endl;
	PrintCenterAlign("请输入新的联系方式：");
	cout << setw(60) << "?";
	string ss="0";
	cin >> ss;
	p.MakeStudent(ss);
	PrintCenterAlign("修改成功！");
	cout << "即将返回主界面,";
	system("pause");
	system("cls");
	goto L; }
	case 4:
		p.SetPassword();
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 5:
		File_save(studentDat, &A);
		File_Phone(studentPhoneTxt, &A);
		cout << "\n\n\t文件保存成功！";
		system("pause");
		exit(0);
		
	}
}
void teachGui()
{
	R:
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	string Name, id, Password;
	cout << "\n\n\n";
	cout << "*******************欢迎来到教师登录界面!*******************\n\n";
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t\tid：\t";
	cin >> id;
	cout << endl;
	cout << "\t\tpassword：\t";
	Paword psw;
	psw.inputPassword();
	Password = psw.getPassword();
	cout << endl << endl;
	teacher A;
	File_load(teacherDat, &A);
	teacher p;
	Regist(id, Password, A, p);
	if (p.getid() == "no")
		goto R;
	student Astu;
	File_load(studentDat, &Astu);
	student pstu;
L:
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n\t*******************欢迎来到教师操作界面!*******************\n\n";
	cout << "     \n请选择您想完成的操作\n\n";
	cout << "\t学生成绩查询：\t\t1.全部学生全部成绩查询\n\t\t             \t2.全部学生单科成绩查询\n\t\t             \t3.单个学生成绩查询\n\n";
	cout << "\t学生信息修改：\t\t4.初始化学生信息\n\t\t             \t5.导入全部学生成绩\n\t\t             \t6.导入学生某科成绩\n\t\t             \t7.添加学生信息\n\t\t             \t8.删除学生信息\n\t\t             \t9.添加课程\n\t\t             \t10.删除课程\n\n";
	//cout<<"\t学生电话查看:\t\t11."
	cout << "\t其他:\n\t\t             \t11.修改密码\n\t\t             \t12.查看通讯录文件\n\t\t             \t13.退出\n";
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n\t温馨提示：通过正常退出操作才能实现文件的保存！\n";
	cout << "\t          导入成绩时暂时未知的成绩可直接输入“-”即可！\n";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	//cout << "\t1.全部学生全部成绩查询\n\t2.全部学生单科成绩查询\n\t3.单个学生成绩查询\n\t4.初始化学生信息\n\t5.导入全部学生成绩\n\t6.添加学生\n\t7.删除学生\n\t8.导入学生信息\n\t9.添加课程\n\t10.删除课程\n\t11.修改密码\n\t12.退出\n";
	int x;
	cout << "\n\n\t请选择：\t";
	cin >> x;
	if (x != 1 && x != 2 && x != 3&&x!=4&&x!=5 && x != 6 && x != 7 && x != 8 && x != 9 && x != 10 && x != 11 && x != 12&&x!=13)
	{
		cout << "输入错误！请重试\n";
		goto L;
	}
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	switch (x)
	{
	case 1:
	{
		ShowScore_all(&Astu);
		Show_all(&Astu);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	}
		
	case 2:
		ShowScore_one(&Astu);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 3:
	{
		cout << "\n\t请选择您要查看的学生的姓名\n\t";
	string Name;
	cout << "请输入：\t";
	cin >> Name;
	while (!Find_stu(Name, &Astu, &pstu))
	{
		cout << "\n查无此人，请重新输入！\n";
		cout << "\n\t请选择您要查看的学生的姓名\n\t";
		string Name;
		cout << "请输入：\t";
		cin >> Name;
		
	}
	student*ptemp = Astu.next;
	cout << setiosflags(ios::left) << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "班级" << setw(10);
	istringstream f(ptemp->course);
	string subjectt;
	int couNum;
	f >> couNum;
	for (int i = 0; i < couNum; i++)
	{
		f >> subjectt;
		cout << subjectt << setw(8);
		cout << "学分" << setw(10);
	}
	cout << setw(10) << "平均成绩\n";
	ShowScore_a_stu(&pstu);
	cout << "即将返回主界面,";
	system("pause");
	system("cls");
	goto L; 
	}
	case 4:
		system("cls");
		Astu.SetStudent();
		File_save(studentDat, &Astu);
		File_Phone(studentTxt, &Astu);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 5:
		SetScore_all(&Astu);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 7:
	{
		cout << "\n\t请输入添加的学生的学号，名字,班级和联系电话\n\n\t";
		string Idx, Namex, Classnamex, Phonumx;
		cin >> Idx >> Namex >> Classnamex >> Phonumx;
		pstu.MakeStudent(Idx, Namex, Classnamex, Phonumx);
	
		cout << "请依次输入各科成绩：\n";
		student*ps = Astu.next;
		pstu.course = ps->course;
		MakeStudent(ps,&pstu);
		istringstream f(ps->course);
		ostringstream h;
		string Course;
		double Score;
		int couNum;
		f >> couNum;
		for (int i = 0; i < couNum; i++)
		{
			f >> Course;
			cout << "?"<<Course << ":\t";
			cin >> Score;
			SetScore_one(&pstu, Course, Score);
			//cout << "@";
		}
		while (ps->next)
			ps = ps->next;
		ps->AddStudent(&pstu);
		cout << "\n\t添加成功！\n";
		cout << "\t即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	}
	case 8:
	{
		cout << "请输入删除的学生的学号\n";
		string Idx, Namex, Classnamex, Phonumx;
		cin >> Idx ;
		student*p1 = Astu.next;
		student*p0 = &Astu;
		while (p1 && p1->getid()!=Idx)
		{
			p0 = p0->next;
			p1 = p1->next;
			
		}
		
		p0->DeleteStudent(p1);
		//File_Phone(studentTxt, &Astu);
		cout << "删除成功！\n";
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	}
	case 6:
	{string Course, Name;

	student ps;


	cout << "\n\t请输入您要添加信息的学生名字";
	cout << "\t\t";
	cin >> Name;
	while (!Find_stu(Name, &Astu, &ps))
	{
		cout << "\n查无此人，请重新输入！\n";
		cout << "\n\t请选择您要添加的学生的姓名\n\t";
		string Name;
		cout << "请输入：\t";
		cin >> Name;

	}
	student*pm =Astu.next;
	while (pm)
	{
		if (pm->getname() == Name)
		{
			break;
			//cout << pst->course << endl;//

		}
		pm = pm->next;
	}
	cout << "\n\t请输入您要添加的课程名";
	cout << "\t\t";
	cin >> Course;
	cout << "\t\t请输入分数:";
	cout << "\t\t";

	double Score;
	cin >> Score;
	SetScore_one(&ps, Course, Score);
	*pm = ps;
	cout << "设置成功!\n";
	cout << "即将返回主界面,";
	system("pause");
	system("cls");
	goto L; }
	case 9:
		AddCourse(&Astu);
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 10:
		DeleteCourse(&Astu);
		
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 11:
		p.SetPassword();
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 13:
		File_save(studentDat,&Astu);
		File_Phone(studentPhoneTxt, &Astu);
		File_save(teacherDat, &A);
		cout << "\n\n\t文件保存成功！";
		system("pause");
		exit(0);
	case 12:
	{
		ifstream f(studentPhoneTxt, ios::in);
		char s[80];
		cout << "\n学生的通讯录文件为：\n\n";
		while (f.getline(s, 80))
			cout << s << endl<<endl;
		system("pause");
		system("cls");
		goto L;

	}
		
		
	}
}
void manageGui()
{
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	string Name, id, Password;
	cout << "\n\n\n";
	cout << "*******************欢迎来到管理员登录界面!*******************\n\n";
	/*cout << "id：\t";
	cin >> id;*/
	cout << "\tpassword：\t";
	Paword psw;
	psw.inputPassword();
	Password = psw.getPassword();
	cout << endl << endl;
	if (Password != "666")
	{
		cout << "\n非管理员勿扰！";
		system("pause");
		exit(0);
	}

	teacher A;
	File_load(teacherDat, &A);
	teacher p;
	//Regist(id, Password, A, p);
	student Astu;
	File_load(studentDat, &Astu);
	student pstu;
L:
	cout << "\n\t*******************欢迎来到管理员操作界面!*******************\n\n";
	cout << "     \n请选择您想完成的操作\n\n";
	
	cout << "\t1.初始化教师信息\t\t2.添加教师信息\n     ";
	cout << "\t3.删除教师信息\t\t4.退出\n";
	cout << "\n\t温馨提示：同过正常退出操作才能实现文件的保存！\n";
	int x;
	cout << "\n\n\t请选择：\t";
	cin >> x;
	if (x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
	{
		cout << "输入错误！请重试\n";
		goto L;
	}

		switch(x)
	{
	case 1:A.SetTeacher();
		cout << "即将返回主界面,";
		system("pause");
		system("cls");
		goto L;
	case 2:
	{cout << "\n\t请输入添加的老师的工号，名字\n\n\t";
	string Idxsx, Namexsx;
	cin >> Idxsx >> Namexsx;
	teacher*ps = A.next;
	while (ps->next)
		ps = ps->next;
	A.MakeTeacher(Idxsx, Namexsx, ps->getpass());
	A.AddTeacher(&p);
	system("pause");
	system("cls");
	goto L; }
	case 3:
	{cout << "请输入删除的教师的工号\n";
	string Idxssv;
	cin >> Idxssv;
	teacher*p1 = A.next;
	teacher*p0 = &A;
	while (p1 && p1->getid() != Idxssv)
	{
		p0 = p0->next;
		p1 = p1->next;

	}
	p0->DeleteTeacher(p1);
	A.DeleteTeacher(&p);
	system("pause");
	system("cls");
	goto L; }
	case 4:
		cout << "保存成功！";
		system("pause");
		exit(0);
	}
}
void maincpp()
{
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	PrintGodBless();
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\n\t\t\t     ********欢迎来到学生成绩管理系统********\n";
	cout << "\t\t\t\t\t请选择您的身份\n" << endl;
	cout << "\t\t\t\t\t1.学生\t2.老师\t3.管理员\n\n\t\t\t\t\t请输入:\t";
	int iden;
	cin >> iden;
	cout << "即将转入登录界面，";
	system("pause");
	system("cls");
	switch (iden)
	{
	case 1:
		stuGui();
		break;
	case 2:
		teachGui();
		break;
	case 3:
		manageGui();
		break;
	}
}

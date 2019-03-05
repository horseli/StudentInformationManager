#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
using namespace std;
class Base
{
protected:
	string name;//姓名
	string password;//密码
	
public:
	Base() ;
	Base(string na);
	string getname() { return name; }//返回名字
	string getpass() { return password; }//返回密码
	virtual ~Base();
	virtual void SetPassword() = 0;//虚函数 设置密码
};

class student:public Base
{
private:
	string id;//学号
	string className;//所在班级
	string phoNum;//通讯录
	string score;//分数
	string credit;//课程学分
	string grade;//课程总评成绩   
public:
	student*next;
	string course;//课程名称  头部有课程数
	student() ;
	void MakeStudent(string name, string id, string className, string Course, string Grade, string Score, string Credit, string Password);
	void MakeStudent(string Course, string Credit, string Password,int courNum,student *&s);//改变信息
	void MakeStudent(string id, string name, string classname, string phonum);
	void MakeStudent(string Pho) { phoNum = Pho; }
	void MakeStudent(string pass,int ss) { password = pass; }
	friend void MakeStudent(student*ps,student*p) { p->credit = ps->credit; 
	p->password = ps->password;
	}
	void SetPassword();//虚函数，设置密码
	string getid() { return id; }//类外得到id
	string getphonum() { return phoNum; }//类外得到电话号码
	//修改学生信息
	void SetStudent();//初始化学生信息
	void AddStudent(student *p);//增加学生
	void DeleteStudent(student*p);//删除学生，包括所有信息
	//修改课程
	friend void SetCourse(student*A);//设置科目
	friend void AddCourse(student*A);//添加科目
	friend void DeleteCourse(student*A);//删除科目
	//设置成绩
	friend void SetScore_all(student*A);//所有学生成绩设置
	friend void SetScore_one(student*A,string Course,double Score);//单个学生单科成绩设置
	//教师查看成绩
	friend void ShowScore_all(student*A);//全部   有成绩统计
	friend void ShowScore_class(student*A);//单班级输出成绩
	friend void ShowScore_one(student*A);//单科输出成绩 有 成绩统计
	friend void ShowScore_a_stu(student*A);//单人输出成绩
	//学生查看成绩
	friend void Show_all(student*A);//单人全部成绩，有单科最高分和排名，学科平均分和最高最低分（成绩分析）
	friend void Show_one(student*A,student*p);//单人单科成绩
	//文件操作
	friend void File_save(string file,student*A);//保存学生成绩信息
	friend void File_load(string file,student*A);//加载学生信息
	friend void File_Phone(string file, student*A);//保存通讯录文件
	friend void Regist(string id, string password,student A,student&P);//学生登陆判断
	friend bool Find_stu(string Name, student*A, student*p);//查找学生
};
class teacher:public Base
{
private:
	string id;//工号
public:
	teacher*next;
	teacher() ;
	teacher(string Name, string Id);
	teacher(string name, string id,string password);
	~teacher();
	//基本操作
	void MakeTeacher(string name, string id, string password);//改变信息
	void MakeTeacher(string pass) { password = pass; }
	string getid() { return id; }//得到id;
	void SetPassword();//虚函数 设置密码
	//输入课程信息
	void SetTeacher();//初始化设置教师
	 void AddTeacher(teacher*A);//添加教师
    void DeleteTeacher(teacher*A);//删除教师
	//文件操作
	friend void Regist(string id, string password, teacher A, teacher&P);//教师登陆
	friend void File_save(string file, teacher*A);//教师信息保存
	friend void File_load(string file,teacher*A);//加载教师信息
};
class manager:public Base
{
public:
	manager();
	~manager();
	void SetPassword();//虚函数 设置密码
	void Filedo();
};
double stringToDouble(string num);//string类型转换为double
void PrintCenterAlign(char *pStr, int Len);//打印位置居中
void PrintGodBless();//打印主界面图像
BOOL SetConsoleColor(WORD wAttributes);//字体颜色设置
void stuGui();//学生操作界面
void teachGui();//教师操作界面
void manageGui();//管理员操作界面
void maincpp();//主操作系统

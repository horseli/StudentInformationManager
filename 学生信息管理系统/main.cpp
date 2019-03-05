#include<iostream>
#include<fstream>
#include <Windows.h>
#include"person.h"
using namespace std;
//class student
//{
//	
//public:
//	int num;
//	void n()
//	{
//		cout << "cin num" << endl;
//		int a;
//		cin >> a;
//		num = a;
//	}
//};
using namespace std;
const string studentDat = "studet.dat";
const string studentTxt = "student.txt";
const string teacherDat = "teacher.dat";
const string teacherTxt = "teacher.txt";
const string studentPhoneTxt = "studentPhone.txt";//通讯录文件

int main()
{
	//teacher A;
	//teacher*p;
	///*A.SetTeacher();
	//File_save("teacher.dat",&A);*/
	//File_load("teacher.dat", &A);
	//p = A.next;
	//while (p)
	//{
	//	cout << p->getname() << p->id<<p->getpass() << endl;
	//	p = p->next;
	//}‘
	/*student A,*p;
	File_load(studentDat, &A);
	p = A.next;
	cout << p->course << endl;*/
	maincpp();
	//string m = "ab cd";
	//m += " sbv";
	//cout << m;
	//system("pause");
	/*string A1("111");
	string B1("222");
	A1 = B1;
	cout << A1 << endl;*/
//string m = "stu.dat";
//	student A;
//	/*A.SetStudent();
//	File_save(m,&A);*/
//	fstream f(m, ios::in);
//	student B;
//	
//	File_load(m, &B);
//	AddCourse(&B);
//	DeleteCourse(&B);
//	//SetScore_all(&B);
//	/*ShowScore_all(&B);
//	ShowScore_one(&B);*/
//	student*C = B. next;
//	
//	string couName="cs";
//	double Grade = 8.3;
//	SetScore_one(C,couName,Grade);
//
//	cout << C->className << " " << (*C).id << "\n" << (*C).course << "\n" << (*C).credit << "\n" << (*C).score << "\n" << (*C).grade << endl;
//	int stuNum;
//	f.read((char*)&stuNum, sizeof(int));
//	cout << stuNum<<endl;
//	f.read((char*)&B, sizeof(student));
//	cout  << B.className << " " << B.id << " " << B.course << "\n" << B.credit << "\n" << B.score << "\n" << B.grade << endl;
//	ShowScore_a_stu(&B);
//	cout << B.course << endl;
	//maincpp();

	//student A;
	//A.MakeStudent("li", "112324", "电科卓越", "2 cs ee", "168", "90 80", "3 4", "123");
	//ShowScore_a_stu(&A);
	//A.SetStudent();
	//
	//AddCourse(&A);
	//DeleteCourse(&A);
	///*A.SetPassword();*/
	
	system("pause");
}
//#include<iostream>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"person.h"

using namespace std;

const string studentDat = "studet.dat";
const string studentTxt = "student.txt";
const string teacherDat = "teacher.dat";
const string teacherTxt = "teacher.txt";
const string studentPhoneTxt = "studentPhone.txt";//通讯录文件
const student stuMark = {};
const teacher teachMark = {};
Base::Base()
{
	name = "0";
	password = "0";
}
Base::Base(string na)
{
	name = na;
}
Base::~Base()
{
	
}
static string course = "0";
student::student():Base()
{
	id = "0";
	className = "0";
	phoNum = "0";
	score = "0";
	credit = "0";
	grade = "0";
}
void student::SetPassword()
{
	L:
	cout << "请输入原密码" << endl;
	string s,s1,s2;
	cin >> s;
	if (s1.compare(s2)!=0)
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
		cout << "修改成功！\n";
	}
}
void student::MakeStudent(string Id, string Name, string Classname, string Phonum)
{
	id = Id;
	name = Name;
	className = Classname;
	phoNum = Phonum;
}
void student::MakeStudent(string Name, string Id, string ClassName, string Course, string Grade, string Score, string Credit, string Password)
{
	id = Id;
	className = ClassName;
	name = Name;
	course = Course;
	grade = Grade;
	score = Score;
	credit = Credit;
	password = Password;
}
void student::MakeStudent(string Course, string Credit, string PassWord, int courNum, student*&s)
{

	string Id, Name, ClassName, PhoNum, Grade, Score;

	cout << "\t?学号：\t";
	cin >> Id;
	cout << "\t?姓名：\t";
	cin >> Name;
	cout << "\t?班级：\t";
	cin >> ClassName;
	cout << "\t?联系电话：\t";
	cin >> PhoNum;
	cout << "\t?课程成绩：\n\n";
	istringstream input(Course);
	ostringstream output;
	ostringstream outputT;
	string x;
	double y;
	double GradeTemp = 0;//总分
	double CreditTemp = 0;//总学分
	input >> x;
	for (int i = 0; i < courNum; i++)
	{
		cout << "?";
		input >> x;
		cout << x << "\t";

		cin >> y;//输入成绩
		GradeTemp += y;
		output << y << " ";
	}
	Score = output.str();
	//
	istringstream fd(Score);
	int couNumIndeed = 0;
	string temp;
	for (; couNumIndeed < courNum; couNumIndeed++)
	{
		fd >> temp;
		if (temp != "-")
			couNumIndeed++;
	}
	outputT << GradeTemp / couNumIndeed;
	Grade = outputT.str();
	s->MakeStudent(Name, Id, ClassName, Course, Grade, Score, Credit, PassWord);
	//fdat.write((char*)&A,sizeof(student));

}


void student::SetStudent()//初始化学生
{
	//fstream fdat;
	//fstream ftxt(studentTxt, ios::out);//txt文本
	//fdat.open(studentDat, ios::out | ios::binary);
	cout << "\n\t*******************欢迎来到学生初始化界面!*******************\n\n";
	cout << "\n\t初始化创建学生档案，请输入要创建的学生人数和课程数目" << endl;
	int stuNum, courNum;
	cout << "\n\t学生数：\t";
	cin >> stuNum ;
	cout << "\n\t课程数：\t";
	cin >> courNum;
	cout << "\n\t请输入每科的科目名称和对应学分数" << endl;
	ostringstream f;
	string x;
	ostringstream h;
	string Course;
	string Credit;
	f << courNum << " ";
	for (int i = 0; i < courNum; i++)
	{
		cout << "\n\t科目：\t";
		cin >> x;
		
		f << x << " ";
		cout << "\t学分：\t";
		cin >> x;
		h << x << " ";
	}
	Course = f.str();
	Credit = h.str();
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n\t请初始化学生密码\t" ;
	string PassWord;
	cin >> PassWord;
	cout << "\n\n\t初始化创建学生档案，请依次输入学生学号，名字，班级,联系电话,课程成绩\n" << endl;
	student*p, *s;

	s = new student;
	s->MakeStudent(Course, Credit, PassWord, courNum, s);
	next = s;

	p = s;
	for (int i = 1; i < stuNum; i++)
	{
		s = new student;
		s->MakeStudent(Course, Credit, PassWord, courNum, s);
		p->next = s;
		p = s;


	}
	/*p = next;
	while (p)
	{
	cout << p->course << endl;
	p = p->next;
	}*/


}
void student::AddStudent(student*p)//后插
{
	p->next = next;
	next = p;
}
void student::DeleteStudent(student*p)//删除p
{
	
	next = p->next;
	
	free(p);

}
void Show_all(student*A)//教师存储之后再打 成绩统计
{
	cout << "\t******成绩统计******\n\n";
	student*p = A->next;
	string Course = p->course;
	int couNum;
	istringstream f(Course);
	f >> couNum;
	string temp;
	//cout << "请选择您要查看的科目" << endl;
	///*for (int i = 0; i < couNum; i++)
	//{
	//	f >> temp;
	//	cout << i + 1 << ". " << temp << endl;
	//}*/
	//int num;
	//cin >> num;
	double total = 0;
	double ave;
	double high;
	double low;
	int k = 0;//判断
	int stuNum = 0;
	int stuPass = 0;
	//system("cls");
	for (int num = 1; num < couNum+1; num++)
	{
		double total = 0;
		double ave;
		double high;
		double low;
		int k = 0;//判断
		int stuNum = 0;
		int stuPass = 0;
		p = A->next;
		
		for (int i = 0; i < num; i++)
		{
			f >> temp;
			
		}
		cout << "\t\t****" << temp << "****" << endl;
		
		while (p)
		{
			cout << endl;
			cout << setw(10) << p->id << setw(10);
			cout << p->name << setw(10);
			cout << p->className << setw(10);
			istringstream H(p->score);
			for (int j = 0; j < couNum; j++)
			{
				H >> temp;
				if (j == num - 1)
				{
					cout << temp << "\n";
					if (stringToDouble(temp) > 60)
						stuPass++;
					total += stringToDouble(temp);
					if (k == 0)
					{
						high = low = stringToDouble(temp);
						k = 1;
					}
					if (k == 1)
					{
						if (high < stringToDouble(temp))
							high = stringToDouble(temp);
						if (low > stringToDouble(temp))
							low = stringToDouble(temp);
					}
				}
			}
			cout << endl;
			p = p->next;
			stuNum++;
		}
		cout << endl;
		ave = total / stuNum;
		double passRate = double(stuPass) / stuNum;

		cout << "平均成绩为：" << ave << endl;
		cout << "及格率：" << setprecision(4) << passRate * 100 << "%" << endl;
		cout << "最高分：" << high << endl;
		cout << "最低分：" << low << endl<<endl;
	}
}
void Show_one(student*A,student*s)//学生查看单科成绩
{
	student*p = A->next ;
	string Course = p->course;
	int couNum;
	istringstream f(Course);
	f >> couNum;
	string temp;
	cout << "请选择您要查看的科目" << endl;
	for (int i = 0; i < couNum; i++)
	{
		f >> temp;
		cout << i + 1 << ". " << temp << endl;
	}
	int num;
	cin >> num;
	double total = 0;
	double ave;
	double high;
	double low;
	int k = 0;//判断
	int stuNum = 0;
	int stuPass = 0;
	//system("cls");
	int position = 1;
	string sos ;
	int m = 0;
	cout << setw(10) << setiosflags(ios::left) << "学号" << setw(10) << "姓名" << setw(10) << "班级";

	istringstream fs(Course);
	fs >> temp;
	for (int i = 0; i < couNum; i++)
	{
		fs >> temp;
		if (i == num - 1)
			cout <<setw(10)<< temp;
	}

	cout <<  endl;
	while (p)
	{
		
		if (p->id==s->id)
		{
			cout << setw(10)<<setiosflags(ios::left)<< p->id << setw(10);
			cout << p->name << setw(10);
			cout << p->className << setw(10);
			
		}
		istringstream H(p->score);
		for (int j = 0; j < couNum; j++)
		{
			H >> temp;
			if (j == num - 1)
			{
				if (m == 0)
				{
					cout << temp << "\n";
					sos = temp;
					m = 1;
				}
				if (stringToDouble(temp) > 60)
					stuPass++;
				total += stringToDouble(temp);
				if (k == 0)
				{
					high = low = stringToDouble(temp);
					k = 1;
				}
				if (k == 1)
				{
					if (high < stringToDouble(temp))
						high = stringToDouble(temp);
					if (low > stringToDouble(temp))
						low = stringToDouble(temp);
				}
				if (stringToDouble(sos) < stringToDouble(temp))
					position++;
			}
			
		}
		cout << endl;
		p = p->next;
		stuNum++;
	}
	cout << endl;
	ave = total / stuNum;
	double passRate = double(stuPass) / stuNum;
	cout << "本学科成绩基本信息如下,冷静分析下你的成绩吧~\n\n";
	cout << "平均成绩为：" << ave << endl;
	cout << "及格率：" << setprecision(4) << passRate * 100 << "%" << endl;
	cout << "最高分：" << high << endl;
	cout << "最低分：" << low << endl;
	cout << "我的排名：" << position <<"/"<<stuNum<< "\n\n";
}




void SetCourse(student*A)
{
	cout << "";
		while (A->next);

}
void AddCourse(student*A)
{
	student*p = A->next;
	cout << "增添课程，请输入您想增添的课程数" << endl;
	int n;
	cin >> n;
	istringstream r(p->course);
	int a;
	r >> a;
	
	a += n;

	ostringstream cou;
	cou << a;
	
	cout << "请依次输入您想增添的课程名及其学分" << endl;
	ostringstream f;
	ostringstream h;
	string addf;
string tempf;
string addh;
string temph;
for (int i = 0; i < n; i++)
{
	cin >> tempf >> temph;
	f << " " << tempf;
	h << " " << temph;
}
addf = f.str();
addh = h.str();
//istringstream put;

while (p)
{

	p->course += f.str();

	p->credit += h.str();
	p->score += "-";
	p->course.replace(0, 1, cou.str());
	//cout << p->course << endl;
	p = p->next;

}//krcshu
p = A->next;
 cout <<"现有科目数和各科目分别为:\t"<< p->course << endl;
}
void DeleteCourse(student*A)
{
	student*p;
	p = A->next;
	cout << "现有课程为：" << endl;
	string Course = A->next->course;
	string temp;
	istringstream input(Course);
	input >> temp;
	int courseNum = stringToDouble(temp);
	for (int i = 0; i < courseNum; i++)
	{
		input >> temp;
		cout << i + 1 << " " << temp << endl;
	}
	cout << "删除课程，请输入您想删除的课程数" << endl;
	int n;
	cin >> n;
	istringstream r(p->course);
	int a;
	r >> a;
	a -= n;
	ostringstream cou;
	cou << a;
	string couNum = cou.str();//z新课程数
	/*cout << "请选择您要删除的课程数" << endl;
	int delNum;
	cin >> delNum;*/
	cout << "请选择您要删除的课程 输入课程序号即可 例如 1 2 3\n";
	string dell;
	string del;
	for (int i = 0; i < n; i++)
	{
		
		cin >> del;
		dell += del+" ";
		
	}
	/*
	for (int i = 0; i < n; i++)
	{
		*/
		while (p)
		{
			
			string delet;
			int sizeall = 0;
			istringstream inputCou(Course);
			istringstream inputSco(p->score);
			istringstream inputCre(p->credit);
			ostringstream h,g,g1;
			
				inputCou >> temp;
				h << couNum << " ";
			
				istringstream put(dell);
				put >> temp;
				int t = stringToDouble(temp) - 1;
			for (int i = 0; i<courseNum; i++)
			{

				
					if (i != t) 
					{
					
						inputCou >> temp;
						h << temp << " ";
						inputSco >> temp;
						g << temp << " ";
						inputCre >> temp;
						g1 << temp << " ";
					
					}
					else
					{
						
						inputCou >> temp;
						h << "- ";
						inputSco >> temp;
						g << "- ";
						inputCre >> temp;
						g1 << "- ";
						put >> temp;
						t = stringToDouble(temp)-1;
						
					}
			}
			
			temp = h.str();
		
			p->course = temp;
			temp = g.str();
			p->score = temp;
			temp = g1.str();
			p->credit = temp;
			//input >> delet;
			//p->course.replace(0, 1, couNum);//更改课程数
			//p->course.replace(sizeall, sizeall + delet.size() + 1, " ");
			///*istringstream delCredit(p->credit);
			//istringstream delScore(p->score);*/
			//p->credit.replace(2 * (t - 1), 2 * (t - 1) + 3, " ");//待查证DAIMAI
			//p->score.replace(3 * (t - 1), 3 * (t - 1) + 4, " ");
			//put >> temp;
			

			p = p->next;
			//cout << p->credit<<endl;
		}
		p = A->next;
		cout << "现有科目数和各科目分别为:\t" << p->course << endl;
	/*int delNum;
	cin >> delNum;*/
	
}
void SetScore_all(student*A)//
{
	student*p = A->next;
	string Course = p->course;
	string temp;
	
	cout << "请输入每个学生的每门成绩" << endl;
	
	for (;p;p=p->next)
	{
		double total = 0;
		cout << endl << endl;
		cout << p->name << ":\n";
		ostringstream h;
		double goal;
		istringstream f(Course);

		int couNum;
		f >> couNum;
		for (int i = 0; i < couNum; i++)
		{

			f >> temp;
			cout << "?"<<temp<<"\t";
			cin >> goal;
			h << goal << " ";
			total += goal;
		}
		string sco = h.str();
		p->score = sco;
		//
		istringstream fd(p->score);
		int couNumIndeed = 0;
		for (; couNumIndeed < couNum; couNumIndeed++)
		{
			fd >> temp;
			if (temp != "-")
				couNumIndeed++;
		}
		//
		ostringstream m;
		m << total / couNumIndeed;
		sco = m.str();
		p->grade = sco;
	}

	
	/*while (p)
	{
		cout << p->score <<p->grade<< endl;
		p = p->next;
	}*/
}
void SetScore_one(student*A, string CouName, double Grade)//导入某位学生某门课程成绩    
{
	string Course = A->course;

	istringstream f(Course);
	string temp;
	int couNum ;
	f >> couNum;
	istringstream fd(A->score);
	int couNumIndeed = 0;
	for (; couNumIndeed < couNum; couNumIndeed++)
	{
		fd >> temp;
		if (temp != "-")
			couNumIndeed++;
	}
	//f >> temp;
	int i;
	
	for ( i = 0; temp!=CouName; i++)
	{
		//if(i>=1)
		f >> temp;
}

	/*istringstream F(Course);
	F >> temp;*/
	istringstream h(A->score);
	ostringstream H;
	double total=0;
	for (int j = 0;j<couNum; j++)
	{
		h >> temp;
		
		if (j == i-1)
		{
			H << Grade<<" ";
			total += Grade;
		}
		else { H << temp << " "; 
		total += stringToDouble(temp);
		}
		//cout << H.str();
	}
	
	temp = H.str();
	A->score =temp;
	ostringstream hs;
	
		hs<<(double)total / couNumIndeed;
		A->grade = hs.str();
	

	
}
//查看成绩
void ShowScore_all(student*A)//全部   有分析
{
	student*p = A->next;
	cout << setiosflags(ios::left)<< setw(10)<< "学号" << setw(10) << "姓名" << setw(10) << "班级" << setw(10);
	istringstream f(p->course);
	
	string subject;
	int couNum;
	f >> couNum;
	for (int i = 0; i < couNum; i++)
	{
		f >> subject;
		cout << subject << setw(8);
		cout << "学分" << setw(10);
	}
	cout << setw(10)<< "平均成绩\n ";
	double total = 0;
	cout << endl;
	ifstream fdat(studentDat, ios::in);
	int stuNum;
	fdat.read((char*)&stuNum, sizeof(int));
	while (p)//平均成绩  dai
	{
		ShowScore_a_stu(p);
		//cout << p->getpass();
		total+=stringToDouble(p->grade);
		p = p->next;
		cout << "\n";
	}
	
}
void ShowScore_class(student*A)//单班级  待定
 {
	student*p = A->next;
	while (p)
	{

	}
 }
void ShowScore_one(student*A)//教师查看单科 
{
	student*p = A->next;
	string Course = p->course;
	int couNum;
	istringstream f(Course);
	f >> couNum;
	string temp;
	cout << "请选择您要查看的科目" << endl;
	for (int i = 0; i < couNum; i++)
	{
		f >> temp;
		cout << i + 1 << ". " << temp << endl;
	}
	int num;
	cin >> num;
	double total=0;
	double ave;
	double high;
	double low;
	int k=0;//判断
	int stuNum=0;
	int stuPass = 0;
	int highs = 0;
	int mid = 0;
	int lows=0;
	//system("cls");
	while (p)
	{
		cout << endl;
		cout <<setw(10) << p->id << setw(10);
		cout << p->name << setw(10);
		cout << p->className << setw(10);
		istringstream H(p->score);
		for (int j = 0; j < couNum; j++)
		{
			H >> temp;
			if (j == num-1)
			{
				cout << temp << "\n";
				if (stringToDouble(temp) >= 60)
					stuPass++;
				if ((stringToDouble(temp) >= 90))
					highs++;
				if ((stringToDouble(temp) >= 70) && (stringToDouble(temp) < 90))
					mid++;
				if ((stringToDouble(temp) >= 60) && (stringToDouble(temp) < 70))
					lows++;
				total += stringToDouble(temp);
				if (k == 0)
				{
					high = low = stringToDouble(temp);
					k = 1;
			}
				if (k == 1)
				{
					if (high < stringToDouble(temp))
						high = stringToDouble(temp);
					if (low > stringToDouble(temp))
						low = stringToDouble(temp);
				}
			}
		}
		cout << endl;
		p = p->next;
		stuNum++;
	}
	cout << endl;
	ave = total / stuNum;
	double passRate = (double)stuPass / stuNum;

	cout << "平均成绩为：" << ave << endl;
	cout << "及格率：" <<setprecision(4)<<passRate*100<<"%"<< endl;
	cout << "最高分：" << high<<endl;
	cout << "最低分：" <<low<< endl;
	cout << "高分段人数（90分以上）：" << highs << endl;
	cout << "中等成绩人数（70-90）：" << mid << endl;
	cout << "及格线徘徊人数（60-70）：" <<lows<< endl<<endl;
}

 void ShowScore_a_stu(student*A)//单人
 {
	 string Course = A->course;
	 istringstream fcou(Course);
	 string temp;
	 int couNum;
	 fcou >> couNum;
	 istringstream fcre(A->credit);
	 istringstream fsco(A->score);
	 //cout << setiosflags(ios::left) << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "班级" << setw(10);
	 cout << setiosflags(ios::left)<< setw(10)<<A->id << setw(10);
	 cout << A->name << setw(10);
	 cout << A->className << setw(10);
	 for (int i = 0; i < couNum; i++)
	 {
		 fsco >>temp;
		 cout << temp << setw(8);
		fcre >> temp;
		 cout << temp << setw(10);
	 }
	 cout << A->grade << endl;
	/* double ave = stringToDouble(A->grade) / couNum;
	 cout << ave <<setprecision(4)<< setw(8)<<endl;*/
 }
bool Find_stu(string Name, student*A, student*pst)
 {
	student*p = A->next;
	while (p)
	{
		if (p->getname() == Name)
		{
			*pst = *p;
			//cout << pst->course << endl;//
			return true;
		}
		p = p->next;
	}
	return false;
 }

 void File_save(string file_stu,student*A)
 {
	 fstream f(file_stu,ios::out|ios::binary);
	 student*p = A->next;
	 int stuNum=0;
	 while (p)
	 {
		 stuNum++;
		 p = p->next;
	 }
	 p = A->next;
	 f.write((char*)&stuNum, sizeof(int));
	 while (p)
	 {
		 f.write((char*)&(*p), sizeof(student));
		 p =p ->next;
	 }
 }
 void File_load(string file_stu,student*A)
 {
	 ifstream f(file_stu, ios::in);

	 student*p ;
	 student *s;
	 int stuNum;
	 f.read((char*)&stuNum, sizeof(int));
	 s = new student;
	 f.read((char*)&(*s), sizeof(student));

	 (*A).next = s;
	 p = s;
	 for (int i = 1; i < stuNum; i++)
	 {
		 s = new student;
		 f.read((char*)&(*s), sizeof(student));
		 //cout << s->course << endl;
		 p->next = s;
		 p = s;
	 }
	 p = (*A).next;
	/* while (p)
	 {
		 cout << p->course << endl;
		 p = p->next;
	 }*/
 }
 void File_Phone(string file, student*A)
 {
	 student*p = A->next;
	 fstream f(file, ios::out);
	 f << setiosflags(ios::left) << setw(10) << "学号" << setw(10) << "姓名 " << setw(10) << "联系电话\n\n";
	 while (p)
	 {
		 f << setw(10) << p->getid() << setw(10) << p->getname() << setw(10) << p->getphonum() << "\n";
		 p = p->next;
	 }
	 f.close();
 }

void Regist(string Id, string Password,student A,student&p)
{
	L:
	student*s = A.next;
	while (s)
	{
		if (s->id == Id && s->getpass() == Password)
		{

			cout <<'\t'<< s->getname() << "同学 你好,欢迎登录学生成绩管理系统!\n\n";
			p = *s;
			if (p.getpass()=="123456")
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
				{ //s->SetPassword();
				n:
					cout << "请输入原密码" << endl;
					string ss, s1, s2;
					cin >> ss;
					if (s1.compare(s2) != 0)
					{
						cout << "密码错误！" << endl;
						goto n;
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
						s->MakeStudent(s1,0);
					}
				}
				case 2:
					;
				}
			
			}
			
			cout << "即将转入操作界面，";
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
		p.course = "no";
	}
}
#pragma once
class Lecture
{
private:
	static int last_num;
	int num = 0;
	string grade;		   //학년 
	string division;	   //분반
	string name;		   //과목명
	string classification; //이수구분
	string professor;	   //담당교수
	string day;			   //요일
	string time;		   //수업시간
	string remark;		   //기타
public:
	Lecture
	(string _grade, string _division, string _name, string _classification, string _professor, string _day, string _time, string _remark);
	~Lecture();
public:
	string getDivision()const { return division; }
	string getGrade()const { return grade; }
	string getName()const { return name; }
	string getClassification()const { return classification; }
	string getProfessor()const { return professor; }
	string getDay()const { return day; }
	string getTime()const { return time; }
	string getRemark()const { return remark; }
	int getNum()const { return num; }
	int getLastNum()const { return last_num; }
public:
	void print();
	void printInfo();
};


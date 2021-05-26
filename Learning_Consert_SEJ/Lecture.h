#pragma once
class Lecture
{
private:
	static int last_num;
	int num = 0;
	string grade;		   //�г� 
	string division;	   //�й�
	string name;		   //�����
	string classification; //�̼�����
	string professor;	   //��米��
	string day;			   //����
	string time;		   //�����ð�
	string remark;		   //��Ÿ
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


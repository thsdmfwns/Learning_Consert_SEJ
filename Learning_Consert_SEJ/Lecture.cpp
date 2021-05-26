#include "stdafx.h"

int Lecture::last_num;
Lecture::Lecture
(string _grade, string _division, string _name, string _classification, string _professor, string _day, string _time, string _remark)
{
	last_num++;
	num = last_num;
	grade = _grade;
	division = _division;
	name = _name;
	classification = _classification;
	professor = _professor;
	day = _day;
	time = _time;
	remark = _remark;
}
Lecture::~Lecture()
{
}

void Lecture::print()
{
	//xlsx: 학년 강의명 이수구분 담당교수 분반 요일 수업시간 기타
	cout << setw(3) << num << " " << setw(5) << utf8_to_ansi(getGrade().c_str()) << " " << setw(40) << utf8_to_ansi(getName().c_str()) << " "
		 << setw(10) << utf8_to_ansi(getClassification().c_str()) << " " << setw(20) << utf8_to_ansi(getProfessor().c_str()) << " "
		 << setw(5) << utf8_to_ansi(getDivision().c_str()) << " " << setw(5) << utf8_to_ansi(getDay().c_str()) << " "
		 << setw(15) << utf8_to_ansi(getTime().c_str()) << " " << setw(40) << utf8_to_ansi(getRemark().c_str()) << endl;
}
void Lecture::printInfo()
{
	//xlsx: 학년 강의명 이수구분 담당교수 분반 요일 수업시간 기타
	cout << "학년 : " << utf8_to_ansi(getGrade().c_str()) << endl;
	cout << "강의명 : " << utf8_to_ansi(getName().c_str()) << endl;
	cout << "이수구분 : " << utf8_to_ansi(getClassification().c_str()) << endl;
	cout << "교수님 : " << utf8_to_ansi(getProfessor().c_str()) << endl;
	cout << "분반 : " << utf8_to_ansi(getDivision().c_str()) << endl;
	cout << "요일 : " << utf8_to_ansi(getDay().c_str()) << endl;
	cout << "시간 : " << utf8_to_ansi(getTime().c_str()) << endl;
	cout << "기타 : " << utf8_to_ansi(getRemark().c_str()) << endl;
}
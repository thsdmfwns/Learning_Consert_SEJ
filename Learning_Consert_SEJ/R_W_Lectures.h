#pragma once
class R_W_Lectures
{
private:
	vector<Lecture*> Major_List;
	vector<Lecture*> General_List;
	vector<Lecture*> Select_List;
public:
	R_W_Lectures();
	~R_W_Lectures();
public:
	vector<Lecture*> get_Major_List()   { return Major_List; }
	vector<Lecture*> get_General_List() { return General_List; }
	vector<Lecture*> get_Select_List()  { return Select_List; }
public:
	int selectMenu();
	void run();
	void wrongMenu();
	string inputDay(int _day);
	void addMajor();
	void addGeneral();
	void listSelected();
	void deleteSelected();
	void writeSelected();
	void read_Major();
	void read_General();
	float cast_Selected();
	void listcategory();
	void listLectures(vector<Lecture*> _list); //all
	void listLectures(vector<Lecture*> _list, int _grade); //grade
	void listLectures(vector<Lecture*> _list, const string& day); //day
	void selectByNum(vector<Lecture*> _list, int _num);
	int getDay(const string& dow);
	int getOp(const string& start_time);
	int getEd(const string& end_time);
	int getCf(const string& classification);
	bool is_hasTime(const string& time, const string& day);
	void removeLecture(int _num);
	void writeXlsx();
};


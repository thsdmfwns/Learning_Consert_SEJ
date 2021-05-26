#include "stdafx.h"
#define MAJOR 1111
#define GENERAL 2222
#define TRACK 3333
#define MAJOR_E 1112
#define GENERAL_E 2223
R_W_Lectures::R_W_Lectures()
{
	Major_List.resize(0);
    General_List.resize(0);
	Select_List.resize(0);
}
R_W_Lectures::~R_W_Lectures()
{
	vector<Lecture*>::iterator start = Major_List.begin();
	vector<Lecture*>::iterator end = Major_List.end();
	Lecture* ML = 0;
	for (; start != end; ++start)
	{
		ML = *start;
		delete ML;
	}

	start = General_List.begin();
	end = General_List.end();
	ML = 0;
	for (; start != end; ++start)
	{
		ML = *start;
		delete ML;
	}

	start = Select_List.begin();
	end = Select_List.end();
	ML = 0;
	for (; start != end; ++start)
	{
		ML = *start;
		delete ML;
	}
}

void R_W_Lectures::wrongMenu() 
{
    cout << "�߸��� �޴��� �����߽��ϴ�." << endl;
    return;
}
string R_W_Lectures::inputDay(int _day)
{
    string day;
    switch (_day)
    {
    case 1:
        day = ansi_to_utf8("��");
        break;
    case 2:
        day = ansi_to_utf8("ȭ");
        break;
    case 3:
        day = ansi_to_utf8("��");
        break;
    case 4:
        day = ansi_to_utf8("��");
        break;
    case 5:
        day = ansi_to_utf8("��");
        break;
    default:
        wrongMenu();
        break;
    }
    return day;
}
int R_W_Lectures::selectMenu() {
    string _num;
    system("cls");
    cout << "��� ���� �ܼ�Ʈ  -   �ð�ǥ ������" << endl;
    cout << "   2020-06    <by - Team SEJ>" << endl;
    cout << endl;
    cout << "�ð�ǥ �����⿡ ���Ű��� ȯ���մϴ�!" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "�޴�" << endl;
    cout << endl;
    cout << "[1] >> ���� ���� �Է�" << endl;
    cout << endl;
    cout << "[2] >> ���� ���� �Է�" << endl;
    cout << endl;
    cout << "[3] >> �Էµ� ���� ���" << endl;
    cout << endl;
    cout << "[4] >> �Էµ� ���� ����" << endl;
    cout << endl;
    cout << "[5] >> �ð�ǥ ����" << endl;
    cout << endl;
    cout << "[6] >> ����" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "�޴��� �Է��Ͻÿ� : "; cin >> _num;
    int num = stoi(_num);
    return num;
}
void R_W_Lectures::run() {
    read_Major();
    read_General();
    int key;
    while ((key = selectMenu()) != 6)
    {
        switch (key)
        {
        case 1:
            addMajor();
            break;
        case 2:
            addGeneral();
            break;
        case 3:
            listSelected();
            break;
        case 4:
            deleteSelected();
            break;
        case 5:
            writeSelected();
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            wrongMenu();
            key = 0;
            system("pause");
            break;
        }
    }
}

void R_W_Lectures::addMajor()
{
    string day;
    int _grade = 0;
    int _num = 0;

    system("cls");
    cout << "[1] >> ���� ���� �Է�" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "�г��� �Է� �Ͻÿ�(2 ~ 4) : "; cin >> _grade;
    while (_num != 9999)
    {
        if (_num > 10000)
        {
            _grade = _num - 10000;
        }
        system("cls");
        cout << "[1] >> ���� ���� �Է�" << endl;
        cout << "------------------------------------------------------------------" << endl;
        listLectures(Major_List, _grade);
        //cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "    �޴�" << endl;
        cout << " -----------------------------------------------------------------------------" << endl;
        cout << "|   [9999] >> ����   [10002] >> 2�г�   [10003] >> 3�г�   [10004] >> 4�г�   |" << endl;
        cout << " -----------------------------------------------------------------------------" << endl;
        cout << "�Է��� �޴� �Ǵ� ������ ��ȣ�� �Է��Ͻÿ� : "; cin >> _num;
        selectByNum(Major_List, _num);
    }
}
void R_W_Lectures::addGeneral()
{
    int _day = 0;
    string day;
    int _num = 0;

    system("cls");
    cout << "[2] >> ���� ���� �Է�" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "[1] >> ��   [2] >> ȭ    [3] >> ��   [4] >> ��   [5] >> ��" << endl;
    cout << endl;
    cout << "������ �Է� �Ͻÿ�(1 ~ 5) : "; cin >> _day;
    while (_num != 9999)
    {
        if (_num > 10000)
        {
            _day = _num - 10000;
        }
        day = inputDay(_day);
        system("cls");
        cout << "[2] >> ���� ���� �Է�" << endl;
        cout << "------------------------------------------------------------------" << endl;
        listLectures(General_List, day);
        cout << endl;
        cout << "    �޴�" << endl;
        cout << " ----------------------------------------------------------------------------------------------------" << endl;
        cout << "|   [9999] >> ����   [10001] >> ��   [10002] >> ȭ   [10003] >> ��   [10004] >> ��   [10005] >> ��   |" << endl;
        cout << " ----------------------------------------------------------------------------------------------------" << endl;
        cout << "�Է��� �޴� �Ǵ� ������ ��ȣ�� �Է��Ͻÿ� : "; cin >> _num;
        selectByNum(General_List, _num);
    }
}
void R_W_Lectures::listSelected()
{
    system("cls");
    cout << "[3] >> �Էµ� ���� ���" << endl;
    cout << "------------------------------------------------------------------" << endl;
    listLectures(Select_List);
    float grades = cast_Selected();
    cout << endl;
    cout << "���������� " << grades << "�� �Դϴ�." << endl;
    system("pause");
}
void R_W_Lectures::deleteSelected()
{
    int _num = 0;
    while (_num != 9999)
    {
        system("cls");
        cout << "[4] >> �Էµ� ���� ����" << endl;
        cout << "------------------------------------------------------------------" << endl;
        listLectures(Select_List);
        cout << endl;
        cout << "    �޴�" << endl;
        cout << " --------------------" << endl;
        cout << "|   [9999] >> ����   |" << endl;
        cout << " --------------------" << endl;

        cout << "�޴� �Ǵ� ������ ������ ��ȣ�� �Է��Ͻÿ� : "; cin >> _num;
        removeLecture(_num);
    }
}
void R_W_Lectures::writeSelected()
{
    system("cls");
    cout << "[5] >> �ð�ǥ ����" << endl;
    cout << "------------------------------------------------------------------" << endl;
    writeXlsx();
    system("pause");
}


void R_W_Lectures::read_Major()
{
    string _grade;			   //�г� 
    string _division;		   //�й�
    string _name;		   //�����
    string _classification; //�̼�����
    string _professor;	   //��米��
    string _day;			   //����
    string _time;		   //�����ð�
    string _remark;         //��Ÿ
    xlnt::workbook wb;
    wb.load("major.xlsx");
    auto ws = wb.active_sheet();
    std::cout << "���� �д���" << std::endl;
    std::vector< std::vector<std::string> > MajorSpreadSheet;
    for (auto row : ws.rows(false))
    {
        std::vector<std::string> aSingleRow;
        for (auto cell : row)
        {
            aSingleRow.push_back(cell.to_string());
        }
        MajorSpreadSheet.push_back(aSingleRow);
    }
    for (int rowInt = 5; rowInt < MajorSpreadSheet.size(); rowInt++)
    {
        for (int colInt = 0; colInt < MajorSpreadSheet.at(rowInt).size(); colInt++)
        {
            if (!MajorSpreadSheet.at(rowInt).at(colInt).compare("") && colInt != 8)
            {
                MajorSpreadSheet.at(rowInt).at(colInt) = MajorSpreadSheet.at(rowInt - 1).at(colInt);
            }
        }
    }
    std::cout << "�۾��Ϸ�" << std::endl;

    std::cout << "������ �Է���" << std::endl;
    for (int rowInt = 5; rowInt < MajorSpreadSheet.size(); rowInt++)
    {
        for (int colInt = 0; colInt < MajorSpreadSheet.at(rowInt).size(); colInt++)
        {
            switch (colInt)
            {
            case 0:
                _grade = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 1:
                _name = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 3:
                _classification = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 4:
                _professor = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 5:
                _division = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 6:
                _day = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 7:
                _time = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            case 8:
                _remark = MajorSpreadSheet.at(rowInt).at(colInt);
                break;
            default:
                break;
            }
        }
        Lecture* ML = new Lecture(_grade, _division, _name, _classification, _professor, _day, _time, _remark);
        Major_List.push_back(ML);
    }
    std::cout << "�۾��Ϸ�" << std::endl;
}
void R_W_Lectures::read_General()
{
    string _grade ;			   //�г� 
    string _division ;		   //�й�
    string _name ;		   //�����
    string _classification ; //�̼�����
    string _professor;	   //��米��
    string _day;			   //����
    string _time ;		   //�����ð�
    string _remark ;         //��Ÿ
    string _daytime;
    std::cout << "���� �д���" << std::endl;
    xlnt::workbook wb;
    wb.load("general.xlsx");
    auto ws = wb.sheet_by_index(0); //�����ʼ�
    vector< vector<string> > GneralSpreadSheet;
    for (auto row : ws.rows(false))
    {
        vector<string> aSingleRow;
        for (auto cell : row)
        {
            aSingleRow.push_back(cell.to_string());
        }
        GneralSpreadSheet.push_back(aSingleRow);
    }
    std::cout << "�۾��Ϸ�" << std::endl;

    std::cout << "������ �Է���" << std::endl;
    for (int rowInt = 2; rowInt < GneralSpreadSheet.size(); rowInt++)
    {
        _grade = "";			   //�г� 
        _division = "";		   //�й�
        _name = "";		   //�����
        _classification = ""; //�̼�����
        _professor = "";	   //��米��
        _day = "";			   //����
        _time = "";		   //�����ð�
        _remark = "";         //��Ÿ
        _daytime = "";      //���� + �ð�
        for (int colInt = 0; colInt < GneralSpreadSheet.at(rowInt).size(); colInt++)
        {
            switch (colInt)
            {
            case 0:
                _division = GneralSpreadSheet.at(rowInt).at(colInt);
                break;
            case 1:
                _name = GneralSpreadSheet.at(rowInt).at(colInt);
                break;
            case 2:
                _professor = GneralSpreadSheet.at(rowInt).at(colInt);
                break;
            case 3:
                if (GneralSpreadSheet.at(rowInt).at(colInt).compare(""))
                {
                    _daytime = GneralSpreadSheet.at(rowInt).at(colInt);
                    _day = _daytime.substr(0, 3);
                    _time = _daytime.substr(4, 11);
                }
                break;
            case 4:
                if (GneralSpreadSheet.at(rowInt).at(colInt).compare(""))
                {
                    _remark += ansi_to_utf8("�����а�:") + GneralSpreadSheet.at(rowInt).at(colInt) + " ";
                }
                break;
            case 5:
                if (GneralSpreadSheet.at(rowInt).at(colInt).compare(""))
                {
                    _name += "(" + GneralSpreadSheet.at(rowInt).at(colInt);
                }
                
                break;
            case 6:
                if (GneralSpreadSheet.at(rowInt).at(colInt).compare(""))
                {
                    _name += "-" + GneralSpreadSheet.at(rowInt).at(colInt) + ")";
                }
                break;
            case 7:
                if (GneralSpreadSheet.at(rowInt).at(colInt).compare(""))
                {
                    _remark += ansi_to_utf8("��������:") + GneralSpreadSheet.at(rowInt).at(colInt);
                }
                break;
            default:
                break;
            }

        }
        if (!_division.compare("")) //�й��� �������� ������
        {
            break;
        }
        _grade = ansi_to_utf8("����");
        _classification = ansi_to_utf8("���� �ʼ�");
        Lecture* GL = new Lecture(_grade, _division, _name, _classification, _professor, _day, _time, _remark);
        General_List.push_back(GL);
    }
}

float R_W_Lectures::cast_Selected()
{
    int op = 0;
    int ed = 0;
    float grades = 0.0;
    vector<Lecture*>::iterator start = Select_List.begin();
    vector<Lecture*>::iterator end = Select_List.end();
    Lecture* lecture = 0;
    for (; start != end; ++start)
    {
        lecture = *start;
        op = getOp(lecture->getTime().c_str());
        ed = getEd(lecture->getTime().c_str());
        ed++;
        grades += (float)ed - (float)op;
    }
    return grades * 0.5;
}
void R_W_Lectures::listcategory()
{
    cout << setw(3) <<"��ȣ"<< setw(5) << "�г�" << " " << setw(40) << "���Ǹ�" << " "
        << setw(10) << "�̼�����" << " " << setw(20) << "��米��" << " "
        << setw(5) << "�й�" << " " << setw(5) << "����" << " "
        << setw(15) << "�����ð�" << " " << setw(40) << "��Ÿ" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
void R_W_Lectures::listLectures(vector<Lecture*> _list)
{   
    vector<Lecture*>::iterator start = _list.begin();
    vector<Lecture*>::iterator end = _list.end();
    Lecture* Lecture = 0;
    listcategory();
    for (; start != end; ++start)
    {
        Lecture = *start;
        Lecture->print();
    }
}
void R_W_Lectures::listLectures(vector<Lecture*> _list, int _grade)
{
    vector<Lecture*>::iterator start = _list.begin();
    vector<Lecture*>::iterator end = _list.end();
    Lecture* Lecture = 0;
    listcategory();
    for (; start != end; ++start)
    {
        Lecture = *start;
        if (stoi(Lecture->getGrade()) == _grade)
        {
            Lecture->print();
        }
    }
}
void R_W_Lectures::listLectures(vector<Lecture*> _list, const string& day)
{
    vector<Lecture*>::iterator start = _list.begin();
    vector<Lecture*>::iterator end = _list.end();
    Lecture* Lecture = 0;
    listcategory();
    for (; start != end; ++start)
    {
        Lecture = *start;
        if (!Lecture->getDay().compare(day))
        {
            Lecture->print();
        }
    }
}

int R_W_Lectures::getDay(const string& dow)
{
    if (!dow.compare(ansi_to_utf8("��")))
    {
        return 2;
    }
    else if (!dow.compare(ansi_to_utf8("ȭ")))
    {
        return 3;
    }
    else if (!dow.compare(ansi_to_utf8("��")))
    {
        return 4;
    }
    else if (!dow.compare(ansi_to_utf8("��")))
    {
        return 5;
    }
    else if (!dow.compare(ansi_to_utf8("��")))
    {
        return 6;
    }
    else
    {
        cout << " day ��ǥ ����" << endl;
        return -1;
    }
}
int R_W_Lectures::getOp(const string& time)
{
    string start_time = time.substr(0, 5);
    if (!start_time.compare("09:00"))
    {
        return 2;
    }
    else if (!start_time.compare("09:30"))
    {
        return 3;
    }
    else if (!start_time.compare("10:00"))
    {
        return 4;
    }
    else if (!start_time.compare("10:30"))
    {
        return 5;
    }
    else if (!start_time.compare("11:00"))
    {
        return 6;

    }
    else if (!start_time.compare("11:30"))
    {
        return 7;
    }
    else if (!start_time.compare("12:00"))
    {
        return 8;
    }
    else if (!start_time.compare("12:30"))
    {
        return 9;
    }
    else if (!start_time.compare("13:00"))
    {
        return 10;
    }
    else if (!start_time.compare("13:30"))
    {
        return 11;
    }
    else if (!start_time.compare("14:00"))
    {
        return 12;
    }
    else if (!start_time.compare("14:30"))
    {
        return 13;
    }
    else if (!start_time.compare("15:00"))
    {
        return 14;
    }
    else if (!start_time.compare("15:30"))
    {
        return 15;
    }
    else if (!start_time.compare("16:00"))
    {
        return 16;
    }
    else if (!start_time.compare("16:30"))
    {
        return 17;
    }
    else if (!start_time.compare("17:00"))
    {
        return 18;
    }
    else if (!start_time.compare("17:30"))
    {
        return 19;
    }
    else if (!start_time.compare("18:00"))
    {
        return 20;
    }
    else
    {
        cout << "op ��ǥ ����" << endl;
        return -1;
    }
}
int R_W_Lectures::getEd(const string& time)
{
    string end_time = time.substr(6);
    if (!end_time.compare("09:30"))
    {
        return 2;
    }
    else if (!end_time.compare("10:00"))
    {
        return 3;
    }
    else if (!end_time.compare("10:30"))
    {
        return 4;
    }
    else if (!end_time.compare("11:00"))
    {
        return 5;

    }
    else if (!end_time.compare("11:30"))
    {
        return 6;
    }
    else if (!end_time.compare("12:00"))
    {
        return 7;
    }
    else if (!end_time.compare("12:30"))
    {
        return 8;
    }
    else if (!end_time.compare("13:00"))
    {
        return 9;
    }
    else if (!end_time.compare("13:30"))
    {
        return 10;
    }
    else if (!end_time.compare("14:00"))
    {
        return 11;
    }
    else if (!end_time.compare("14:30"))
    {
        return 12;
    }
    else if (!end_time.compare("15:00"))
    {
        return 13;
    }
    else if (!end_time.compare("15:30"))
    {
        return 14;
    }
    else if (!end_time.compare("16:00"))
    {
        return 15;
    }
    else if (!end_time.compare("16:30"))
    {
        return 16;
    }
    else if (!end_time.compare("17:00"))
    {
        return 17;
    }
    else if (!end_time.compare("17:30"))
    {
        return 18;
    }
    else if (!end_time.compare("18:00"))
    {
        return 19;
    }
    else if (!end_time.compare("18:30"))
    {
        return 20;
    }
    else
    {
        cout << "ed ��ǥ ����" << endl;
        return -1;
    }
}
int R_W_Lectures::getCf(const string& clf)
{
    if (!clf.compare(ansi_to_utf8("���� �ʼ�")))
    {
        return GENERAL;
    }
    else if (!clf.compare(ansi_to_utf8("Ʈ��")))
    {
        return TRACK;
    }
    else if (!clf.compare(ansi_to_utf8("���� �ʼ�")))
    {
        return MAJOR;
    }
    else if (!clf.compare(ansi_to_utf8("���� ����")))
    {
        return MAJOR_E;
    }
    else if (!clf.compare(ansi_to_utf8("���� ����")))
    {
        return GENERAL_E;
    }
    else
    {
        cout << "cf ��ǥ ����" << endl;
        return -1;
    }
}

void R_W_Lectures::selectByNum(vector<Lecture*> _list, int _num)
{
    vector<Lecture*>::iterator start = _list.begin();
    vector<Lecture*>::iterator end = _list.end();
    Lecture* lecture = 0;
    string day;
    for (; start != end; ++start)
    {
        lecture = *start;
        if (_num == lecture->getNum() 
            && is_hasTime(lecture->getTime().c_str(), lecture->getDay().c_str()) == false)
        {
            Select_List.push_back(lecture);
            return;
        }
    }
    if (_num >= 9999)
    {
        return;
    }
    cout << "��� ����" << endl;
    system("pause");
}
bool R_W_Lectures::is_hasTime(const string& time, const string& day)
{
    int _op = getOp(time);  int _ed = getEd(time);
    int op;                 int ed;
    vector<Lecture*>::iterator start = Select_List.begin();
    vector<Lecture*>::iterator end = Select_List.end();
    Lecture* lecture = 0;
    for (; start != end; ++start)
    {
        op = 0;
        ed = 0;
        lecture = *start;
        op = getOp(lecture->getTime().c_str());
        ed = getEd(lecture->getTime().c_str());
        if ((ed >= _op) && (op <= _ed) && !lecture->getDay().compare(day))
        {
            cout << "�ش� ���´�" <<utf8_to_ansi(lecture->getName())<< "�� �ߺ��˴ϴ�." << endl;
            return true;
        }
    }
    return false;
}

void R_W_Lectures::removeLecture(int _num)
{
    vector<Lecture*>::iterator start = Select_List.begin();
    vector<Lecture*>::iterator end = Select_List.end();
    Lecture* lecture = 0;
    for (; start != end; ++start)
    {
        lecture = *start;
        if (_num == lecture->getNum())
        {
            delete lecture;
            Select_List.erase(start);
            return;
        }
    }
    if (_num >= 9999)
    {
        return;
    }
    cout << "���� ����" << endl;
    system("pause");
}

void R_W_Lectures::writeXlsx()
{
    xlnt::workbook wb;
    wb.load("output.xlsx");
    auto ws = wb.active_sheet();

    int op;
    int ed;
    int day;
    int cf;

    xlnt::font font_schedule;
    font_schedule.bold(true);
    font_schedule.name("Malgun Gothic");
    font_schedule.size(12);
    xlnt::alignment alignment;
    alignment.horizontal(xlnt::horizontal_alignment::center);
    alignment.vertical(xlnt::vertical_alignment::center);
    alignment.wrap(true);

    Lecture* lecture = 0;
    vector<Lecture*>::iterator start = Select_List.begin();
    vector<Lecture*>::iterator end = Select_List.end();
    cout << "���� �۾���" << endl;
    for (; start != end; ++start)
    {
        lecture = *start;
        op = 0;
        ed = 0;
        day = 0;
        cf = 0;

        day = getDay(lecture->getDay().c_str());
        op = getOp(lecture->getTime().c_str());
        ed = getEd(lecture->getTime().c_str());
        cf = getCf(lecture->getClassification().c_str());

        ws.merge_cells(xlnt::range_reference(day, op, day, ed));
        ws.cell(xlnt::cell_reference(day, op)).value(lecture->getName());
        ws.cell(xlnt::cell_reference(day, op)).font(font_schedule);
        ws.cell(xlnt::cell_reference(day, op)).alignment(alignment);
        switch (cf)
        {
        case TRACK:
            ws.cell(xlnt::cell_reference(day, op)).fill(xlnt::fill::solid(xlnt::rgb_color("ffCCCCFF")));
            break;
        case GENERAL:
            ws.cell(xlnt::cell_reference(day, op)).fill(xlnt::fill::solid(xlnt::rgb_color("ffCCFFCC")));
            break;
        case MAJOR:
            ws.cell(xlnt::cell_reference(day, op)).fill(xlnt::fill::solid(xlnt::rgb_color("ffD9E7FD")));
            break;
        case MAJOR_E:
            ws.cell(xlnt::cell_reference(day, op)).fill(xlnt::fill::solid(xlnt::rgb_color("ffFFCCFF")));
            break;
        case GENERAL_E:
            ws.cell(xlnt::cell_reference(day, op)).fill(xlnt::fill::solid(xlnt::rgb_color("ffCCFFFF")));
            break;
        }
    }
    cout << "�۾��Ϸ�" << endl;
    wb.save("output.xlsx");
    cout << "���� �۾��Ϸ�" << endl;
}


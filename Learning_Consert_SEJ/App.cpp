#include "stdafx.h"
App::App()
{
	RW = new R_W_Lectures;
}
App::~App()
{
}

void App::make_Xlsx()
{
    xlnt::workbook wb;
    auto ws = wb.active_sheet();

    //테두리
    xlnt::border::border_property prop;
    prop.style(xlnt::border_style::medium);
    xlnt::border border_left;
    border_left.side(xlnt::border_side::start, prop); // left
    xlnt::border border_right;
    border_right.side(xlnt::border_side::end, prop); // right
    xlnt::border border_top;
    border_top.side(xlnt::border_side::top, prop); // top
    xlnt::border border_bottom;
    border_bottom.side(xlnt::border_side::bottom, prop); // bottom
    xlnt::border border_top_left;
    border_top_left.side(xlnt::border_side::top, prop);   // top
    border_top_left.side(xlnt::border_side::start, prop); // left
    xlnt::border border_top_right;
    border_top_right.side(xlnt::border_side::top, prop); // top
    border_top_right.side(xlnt::border_side::end, prop); // right
    xlnt::border border_bottom_left;
    border_bottom_left.side(xlnt::border_side::bottom, prop); // bottom
    border_bottom_left.side(xlnt::border_side::start, prop);  // left
    xlnt::border border_bottom_right;
    border_bottom_right.side(xlnt::border_side::bottom, prop); // bottom
    border_bottom_right.side(xlnt::border_side::end, prop);    // right

    ws.cell(xlnt::cell_reference(1, 1)).border(border_top_left);
    ws.cell(xlnt::cell_reference(6, 1)).border(border_top_right);
    ws.cell(xlnt::cell_reference(1, 20)).border(border_bottom_left);
    ws.cell(xlnt::cell_reference(6, 20)).border(border_bottom_right);
    ws.range("B1:E1").border(border_top);
    ws.range("B21:E21").border(border_top);
    ws.range("A2:A19").border(border_left);
    ws.range("G2:G19").border(border_left);

    //너비, 높이 조절
    for (auto col = 1; col < 7; col++) //너비
    {
        ws.column_properties(col).width = 17;
        ws.column_properties(col).custom_width = true;
    }
    for (auto row = 1; row < 21; row++) //높이
    {
        ws.row_properties(row).height = 28.25;
        ws.row_properties(row).custom_height = true;
    }

    //글자 폰트
    xlnt::font font;
    font.bold(true);
    font.name("Malgun Gothic");
    font.size(14);
    ws.range("A1:A20").font(font);
    ws.range("B1:F1").font(font);
    // xlnt::font font_schedule;
    // font_schedule.bold(true);
    // font_schedule.name("Malgun Gothic");
    // font_schedule.size(12);
    // ws.range("B2:F20").font(font_schedule);
    xlnt::alignment alignment;
    alignment.horizontal(xlnt::horizontal_alignment::center);
    alignment.vertical(xlnt::vertical_alignment::center);
    alignment.wrap(true);
    ws.range("A1:F1").alignment(alignment);
    ws.range("A1:A20").alignment(alignment);

    //색 넣기
    ws.cell(xlnt::cell_reference(1, 1)).fill(xlnt::fill::solid(xlnt::rgb_color("ffB7B7B7")));
    ws.range("B1:F1").fill(xlnt::fill::solid(xlnt::rgb_color("ffFFE599")));
    ws.range("A2:A20").fill(xlnt::fill::solid(xlnt::rgb_color("ffC9DAF8")));

    //데이터 입력
    for (int col = 2; col < 7; col++)
    {
        string dow; //day of weeks
        switch (col)
        {
        case 2:
            dow = ansi_to_utf8("월");
            break;
        case 3:
            dow = ansi_to_utf8("화");
            break;
        case 4:
            dow = ansi_to_utf8("수");
            break;
        case 5:
            dow = ansi_to_utf8("목");
            break;
        case 6:
            dow = ansi_to_utf8("금");
            break;
        }
        ws.cell(xlnt::cell_reference(col, 1)).value(dow);
    }
    for (int row = 2; row < 21; row++)
    {
        string time;
        switch (row)
        {
        case 2:
            time = "09:00 ~ 09:30";
            break;
        case 3:
            time = "09:30 ~ 10:00";
            break;
        case 4:
            time = "10:00 ~ 10:30";
            break;
        case 5:
            time = "10:30 ~ 11:00";
            break;
        case 6:
            time = "11:00 ~ 11:30";
            break;
        case 7:
            time = "11:30 ~ 12:00";
            break;
        case 8:
            time = "12:00 ~ 12:30";
            break;
        case 9:
            time = "12:30 ~ 13:00";
            break;
        case 10:
            time = "13:00 ~ 13:30";
            break;
        case 11:
            time = "13:30 ~ 14:00";
            break;
        case 12:
            time = "14:00 ~ 14:30";
            break;
        case 13:
            time = "14:30 ~ 15:00";
            break;
        case 14:
            time = "15:00 ~ 15:30";
            break;
        case 15:
            time = "15:30 ~ 16:00";
            break;
        case 16:
            time = "16:00 ~ 16:30";
            break;
        case 17:
            time = "16:30 ~ 17:00";
            break;
        case 18:
            time = "17:00 ~ 17:30";
            break;
        case 19:
            time = "17:30 ~ 18:00";
            break;
        case 20:
            time = "18:00 ~ 18:30";
            break;
        }
        ws.cell(xlnt::cell_reference(1, row)).value(time);
    }
    wb.save("output.xlsx");
}
void App::logo() {
    cout << "*******************************************************" << endl;
    cout << "                  우송 러닝 콘서트" << endl;
    cout << endl;
    cout << "                   시간표 생성기" << endl;
    cout << endl;
    cout << "                      2020-06 " << endl;
    cout << endl;
    cout << "                   by - Team SEJ" << endl;
    cout << "*******************************************************" << endl;
    system("pause");
}
void App::ending() {
    system("cls");
    cout << "*******************************************************" << endl;
    cout << "                  프로그램 종료" << endl;
    cout << endl;
    cout << "                   감사합니다" << endl;
    cout << "*******************************************************" << endl;
}

void App::run() 
{
    make_Xlsx();
    RW->run();
}
void App::init() 
{
    logo();
}
void App::exit() 
{
    ending();
}
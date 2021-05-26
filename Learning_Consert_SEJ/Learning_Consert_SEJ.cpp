#include "stdafx.h"

int main()
{
    system(" mode  con lines=30   cols=180 ");
    App* app = new App;
    app->init();
    app->run();
    app->exit();
    //RW->listLectures(RW->get_Major_List());
    //RW->listLectures(RW->get_General_List(), ansi_to_utf8("월"));
}



#include "stdafx.h"

string utf8_to_ansi(const string& utf8)
{
    WCHAR unicode[1500];
    char ansi[1500];

    memset(unicode, 0, sizeof(unicode));
    memset(ansi, 0, sizeof(ansi));

    ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, unicode, sizeof(unicode));
    ::WideCharToMultiByte(CP_ACP, 0, unicode, -1, ansi, sizeof(ansi), NULL, NULL);

    return std::string(ansi);
}

string ansi_to_utf8(const string& ansi)
{
    WCHAR unicode[1500];
    char utf8[1500];

    memset(unicode, 0, sizeof(unicode));
    memset(utf8, 0, sizeof(utf8));

    ::MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), -1, unicode, sizeof(unicode));
    ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, utf8, sizeof(utf8), NULL, NULL);

    return string(utf8);
}

string trim(const string& _str)
{
    string str = _str;
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}
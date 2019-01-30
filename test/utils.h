#pragma once
#include <string>
using namespace std;

char* wide_to_mtbytes(int c, const wchar_t* pWideText);
wchar_t* mtbytes_to_wide(int c, const char* pText);

wstring utf8_to_wide(const char* pText);
string utf8_to_local(const char* pText);

string local_to_utf8(const char* pText);
string wide_to_utf8(const wchar_t* pText);
#pragma once
#include "CppSQLite3.h"
#include <string>
#include <map>
using namespace std;

class CSQLite3Helper : public CppSQLite3DB
{
public:
    CSQLite3Helper(void);
    ~CSQLite3Helper(void);

    bool Open(const char* utf8path,const char* pass = NULL,int passlen = 0);

    // 如果指定了解密文件路径，则将解密后的数据库文件输出到目标路径
    // 否则直接自解密
    bool DecryptFile(const char* localOutpath);

    // 对CppSQLite3Statement做了次缓存，不用每次都编译出来
    CppSQLite3Statement* GetStatements(const string& sql);

    int SetBegin();
    int SetCommit();
    int SetRollBack();

private:
    map<string, CppSQLite3Statement*> m_mapStatements;
};

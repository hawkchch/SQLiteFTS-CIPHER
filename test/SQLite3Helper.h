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

    // ���ָ���˽����ļ�·�����򽫽��ܺ�����ݿ��ļ������Ŀ��·��
    // ����ֱ���Խ���
    bool DecryptFile(const char* localOutpath);

    // ��CppSQLite3Statement���˴λ��棬����ÿ�ζ��������
    CppSQLite3Statement* GetStatements(const string& sql);

    int SetBegin();
    int SetCommit();
    int SetRollBack();

private:
    map<string, CppSQLite3Statement*> m_mapStatements;
};

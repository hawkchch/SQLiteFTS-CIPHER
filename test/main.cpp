// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SQLite3Helper.h"
#include "utils.h"
int _tmain(int argc, _TCHAR* argv[])
{
    try
    {
        CSQLite3Helper db;
        if (db.Open("test.db", "pass", 4))
        {
            // ����ȫ��������
            string sql = "CREATE VIRTUAL TABLE IF NOT EXISTS foo USING fts3(author, document, tokenize=mmicu)";
            db.execDML(sql.c_str());

            // ��������
            string insertSql = "INSERT INTO foo (author, document) VALUES (?,?)";
            CppSQLite3Statement stat = db.compileStatement(insertSql.c_str());

            // insert first record
            stat.bind(1, local_to_utf8("Tom").c_str());
            stat.bind(2, local_to_utf8("���Ǹ��漣").c_str());
            stat.execDML();

            // insert second record
            stat.bind(1, local_to_utf8("Jerry").c_str());
            stat.bind(2, local_to_utf8("�漣֮ҹ����������").c_str());
            stat.execDML();

            // insert third record
            stat.bind(1, local_to_utf8("Jay").c_str());
            stat.bind(2, local_to_utf8("�����ţ��ǵ���").c_str());
            stat.execDML();

            // ��ѯ
            CppSQLite3Query q = db.execQuery(local_to_utf8("SELECT * FROM foo WHERE foo MATCH '�漣'").c_str());
            while (!q.eof())
            {
                printf("%s|%s\n", 
                    utf8_to_local(q.getStringField(0)).c_str(), 
                    utf8_to_local(q.getStringField(1)).c_str());
                q.nextRow();
            }

            // ���ݿ����
            if(db.DecryptFile("test����.db"))
            {
                printf("decrypt success!");
            }
        }
    }
    catch (CppSQLite3Exception& e)
    {
        printf("%s\n", e.errorMessage());
    }
    system("pause");
	return 0;
}


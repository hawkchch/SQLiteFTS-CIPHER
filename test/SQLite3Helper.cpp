#include "StdAfx.h"
#include "SQLite3Helper.h"
#include "utils.h"

CSQLite3Helper::CSQLite3Helper(void)
{

}

CSQLite3Helper::~CSQLite3Helper(void)
{
    for (map<string, CppSQLite3Statement*>::iterator it=m_mapStatements.begin(); it!=m_mapStatements.end(); ++it)
    {
        delete(it->second);
    }

    m_mapStatements.clear();
}

bool CSQLite3Helper::Open( const char* utf8path,const char* pass,int passlen )
{
    try
    {
        int nRet = sqlite3_open(utf8path, &mpDB);

        if (nRet != SQLITE_OK)
        {
            const char* szError = sqlite3_errmsg(mpDB);
            throw CppSQLite3Exception(nRet, (char*)szError, false);
        }

        if(pass && passlen)
        {
            nRet = sqlite3_key(mpDB, pass, passlen);
            if (nRet != SQLITE_OK)
            {
                const char* szError = sqlite3_errmsg(mpDB);
                sqlite3_close(mpDB);
                mpDB = NULL;
                throw CppSQLite3Exception(nRet, (char*)szError, false);
            }
        }

        execDML("PRAGMA page_size = 4096;");
        execDML("PRAGMA synchronous = OFF;");
        execDML("PRAGMA journal_mode = WAL;");

        setBusyTimeout(mnBusyTimeoutMs);
        return true;
    }
    catch(CppSQLite3Exception& e)
    {
        return false;
    }
}

bool CSQLite3Helper::DecryptFile(const char* localOutpath )
{
    // 先将wal文件中数据合并到主库中，然后再解密
    // 否则如果之前有未合并的数据在wal中，解密后，关闭数据库连接时，数据会合并到文件中，然后会导致数据库错乱
    if(sqlite3_wal_checkpoint(mpDB, NULL) != SQLITE_OK) 
        return false;
    return SQLITE_OK == sqlite3_decypt_file(mpDB, localOutpath, NULL, NULL);
}

CppSQLite3Statement* CSQLite3Helper::GetStatements( const string& sql )
{
    map<string, CppSQLite3Statement*>::iterator it = m_mapStatements.find(sql);
    if (it != m_mapStatements.end())
    {
        return it->second;
    }

    CppSQLite3Statement* stat = new CppSQLite3Statement;
    *stat = compileStatement(sql.c_str());
    m_mapStatements[sql] = stat;
    return stat;
}

int CSQLite3Helper::SetBegin()
{
    try
    {
        return execDML("begin;");
    }
    catch (CppSQLite3Exception& e)
    {

    }

    return 0;
}

int CSQLite3Helper::SetCommit()
{
    try
    {
        return execDML("commit;");
    }
    catch (CppSQLite3Exception& e)
    {

    }

    return 0;
}

int CSQLite3Helper::SetRollBack()
{
    try
    {
        return execDML("rollback;");
    }
    catch (CppSQLite3Exception& e)
    {

    }

    return 0;
}


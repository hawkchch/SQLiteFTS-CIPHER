#include "utils.h"
#include <assert.h>
#include <wtypes.h>

char* wide_to_mtbytes(int c, const wchar_t* pWideText)
{
    assert(pWideText);

    int size = WideCharToMultiByte(c, 0, (LPCWSTR)pWideText, -1, NULL, 0, NULL, NULL);
    if (size == 0) {
        assert(false);
        return NULL;
    }
    char* pText = new char[size+1];
    if (WideCharToMultiByte(c, 0, (LPCWSTR)pWideText, -1, pText, size, NULL, NULL) == 0) {
        delete []pText;
        assert(false);
        return NULL;
    }
    pText[size] = '\0';
    return pText;
}

///convert multibytes to wide chars
wchar_t* mtbytes_to_wide(int c, const char* pText)
{
    assert(pText);

    wchar_t* pWideText=NULL;
    int size = MultiByteToWideChar(c, 0, pText, -1, NULL, 0);
    if (size == 0) {
        assert(false);
        return pWideText;
    } else {
        pWideText = new wchar_t[size+1];
        if (MultiByteToWideChar(c, 0, pText, -1, (LPWSTR)pWideText, size) == 0) {
            delete []pWideText;
            pWideText = NULL;
            assert(false);
            return pWideText;
        } else {
            pWideText[size] = 0;
            return pWideText;
        }
    }
}
wstring utf8_to_wide(const char* pText)
{
    assert(pText);
    wchar_t* pWide = mtbytes_to_wide(CP_UTF8, pText);
    assert(pWide);
    wstring s = (wchar_t*)pWide;
    delete []pWide;
    return s;
}

string utf8_to_local(const char* pText)
{
    assert(pText);

    wstring ws = utf8_to_wide(pText);
    char* pANSI = wide_to_mtbytes(CP_ACP, ws.c_str());
    if (pANSI == NULL) {        
        assert(false);
        return "";
    }

    string r = pANSI;
    delete []pANSI;
    return r;    
}

string local_to_utf8(const char* pText)
{
    assert(pText);

    wchar_t* pWideText = mtbytes_to_wide(CP_ACP, pText);
    if (pWideText == NULL) {
        assert(false);
        return "";
    }
    char* pUTF8 = wide_to_mtbytes(CP_UTF8, pWideText);
    if (pUTF8 == NULL) {
        assert(false);
        delete []pWideText;
        return "";
    }
    string r = pUTF8;
    delete []pUTF8;
    delete []pWideText;
    return r;
}

string wide_to_utf8(const wchar_t* pText)
{
    assert(pText);
    char* pUTF8 = wide_to_mtbytes(CP_UTF8, pText);
    if (pUTF8 == NULL) {
        assert(false);
        return "";
    } else {
        string r = pUTF8;
        delete []pUTF8;
        return r;
    }
}
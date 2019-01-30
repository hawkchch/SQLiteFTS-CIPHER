if not exist "..\sdk". (md "..\sdk".)
if not exist "..\sdk\include". (md "..\sdk\include".)
if not exist "..\sdk\lib". (md "..\sdk\lib".)
if not exist "..\sdk\bin". (md "..\sdk\bin".)
if not exist "..\sdk\pdb". (md "..\sdk\pdb".)

copy .\sqlite3.h ..\sdk\include
copy ..\release\sqlite3.pdb ..\sdk\pdb
copy ..\release\sqlite3.lib ..\sdk\lib
copy ..\release\sqlite3.dll ..\sdk\bin

if not exist "..\sdk\bin\icudt57.dll". (copy "..\dependency\icu\bin\icudt57.dll" ..\sdk\bin\)
if not exist "..\sdk\bin\icuin57.dll". (copy "..\dependency\icu\bin\icuin57.dll" ..\sdk\bin\)
if not exist "..\sdk\bin\icuuc57.dll". (copy "..\dependency\icu\bin\icuuc57.dll" ..\sdk\bin\)
if not exist "..\sdk\bin\libeay32.dll". (copy "..\dependency\openssl\bin\libeay32.dll" ..\sdk\bin\)
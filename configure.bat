@echo off

if not exist "debug". (md "debug".)
if not exist "release". (md "release".)

if not exist "debug\icudt57.dll" (copy "dependency\icu\bin\icudt57.dll" "debug".)
if not exist "debug\icuin57.dll" (copy "dependency\icu\bin\icuin57.dll" "debug".)
if not exist "debug\icuuc57.dll" (copy "dependency\icu\bin\icuuc57.dll" "debug".)
if not exist "debug\libeay32.dll" (copy "dependency\openssl\bin\libeay32.dll" "debug".)

if not exist "release\icudt57.dll" (copy "dependency\icu\bin\icudt57.dll" "release".)
if not exist "release\icuin57.dll" (copy "dependency\icu\bin\icuin57.dll" "release".)
if not exist "release\icuuc57.dll" (copy "dependency\icu\bin\icuuc57.dll" "release".)
if not exist "release\libeay32.dll" (copy "dependency\openssl\bin\libeay32.dll" "release".)
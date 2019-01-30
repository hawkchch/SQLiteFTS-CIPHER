该程序生成sqlite3.dll，支持mmicu分词，icu分词，simple分词，porter分词
同时支持加密

pragma key='pass';或者使用sqlite3_key接口

CREATE VIRTUAL TABLE IF NOT EXISTS foo USING fts3(tokenize=icu zh-cn);
INSERT INTO foo VALUES('Hello World, Welcome to China!');
SELECT * FROM foo WHERE content MATCH 'Welcome';


CREATE VIRTUAL TABLE IF NOT EXISTS mmfoo USING fts3(tokenize=mmicu);
INSERT INTO mmfoo VALUES('你好，中国，520，thank you');
SELECT * FROM mmfoo WHERE content MATCH '好国';

这种方式需要修改sqlite3.c源码，主要是把mm_tokenizer.c代码添加到文件尾，
然后修改函数SQLITE_PRIVATE int sqlite3Fts3Init(sqlite3 *db)的实现，同时需要
将需要的函数声明

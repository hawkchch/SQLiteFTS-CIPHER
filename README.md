# SQLiteFTS-CIPHER
一个关于SQLite全文搜索+加密的项目

目前仅对VS2005支持。不过可以根据自己需要进行修改。

该程序生成sqlite3shell.exe，支持mmicu分词，icu分词，simple分词，porter分词，同时支持加密。

```
pragma key='pass';

CREATE VIRTUAL TABLE IF NOT EXISTS foo USING fts3(tokenize=icu zh-cn);
INSERT INTO foo VALUES('Hello World, Welcome to China!');
SELECT * FROM foo WHERE content MATCH 'Welcome';

CREATE VIRTUAL TABLE IF NOT EXISTS mmfoo USING fts3(tokenize=mmicu);
INSERT INTO mmfoo VALUES('你好，中国，520，thank you');
INSERT INTO mmfoo VALUES('hello?');
INSERT INTO mmfoo VALUES('whats wrong with you?');
SELECT * FROM mmfoo WHERE content MATCH '中国';
```

具体看test工程。

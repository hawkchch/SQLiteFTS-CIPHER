�ó�������sqlite3shell.exe��֧��mmicu�ִʣ�icu�ִʣ�simple�ִʣ�porter�ִ�
ͬʱ֧�ּ���

pragma key='pass';

CREATE VIRTUAL TABLE IF NOT EXISTS foo USING fts3(tokenize=icu zh-cn);
INSERT INTO foo VALUES('Hello World, Welcome to China!');
SELECT * FROM foo WHERE content MATCH 'Welcome';


CREATE VIRTUAL TABLE IF NOT EXISTS mmfoo USING fts3(tokenize=mmicu);
INSERT INTO mmfoo VALUES('��ã��й���520��thank you');
INSERT INTO mmfoo VALUES('hello?');
INSERT INTO mmfoo VALUES('whats wrong with you?');
SELECT * FROM mmfoo WHERE content MATCH '�ù�';

���ַ�ʽ��Ҫ�޸�sqlite3.cԴ�룬��Ҫ�ǰ�mm_tokenizer.c������ӵ��ļ�β��
Ȼ���޸ĺ���SQLITE_PRIVATE int sqlite3Fts3Init(sqlite3 *db)��ʵ�֣�ͬʱ��Ҫ
����Ҫ�ĺ�������

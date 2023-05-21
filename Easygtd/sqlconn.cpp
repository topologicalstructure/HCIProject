#include "sqlconn.h"

SqliteOperator::SqliteOperator()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");//建立数据库连接
        database.setDatabaseName("DataBase.db");//设置数据库文件名
    }
    database.open();//打开数据库
    QSqlQuery sqlQuery;
    sqlQuery.exec(QString("select * from sqlite_master where type = 'table' and name='todaywork'"));
    //若尚未建表，则进行建表
    if(!sqlQuery.next()){
        CreatTable();
    }
}

SqliteOperator::~SqliteOperator()
{
    database.close();
}

void SqliteOperator::UpdateTable()
{
    QSqlQuery sqlQuery;
    //首先将所有昨天添加但未完成的任务复制到yesterdaywork表中
    sqlQuery.prepare("insert into yesterdaywork(creatdate,content,complete) select creatdate,content,complete from todaywork where todaywork.creatdate=date('now','-1 day') and todaywork.complete=0");
    sqlQuery.exec();
    sqlQuery.prepare("insert into yesterdaywork(creatdate,content,complete) select creatdate,content,complete from expectedwork where expectedwork.creatdate=date('now','-1 day')");
    sqlQuery.exec();
    //再将所有非今天的数据从todaywork表中删除
    sqlQuery.prepare("delete from todaywork where creatdate<date('now')");
    sqlQuery.exec();
    //删除yesterday中的多余数据
    sqlQuery.prepare("delete from yesterdaywork where creatdate<date('now','-1 day')");
    sqlQuery.exec();
    //再将所有预约到今天的任务移动到todaywork表中
    sqlQuery.prepare("insert into todaywork(creatdate,content,complete) select creatdate,content,complete from expectedwork where expectedwork.creatdate=date('now')");
    sqlQuery.exec();
    sqlQuery.prepare("delete from expectedwork where creatdate<=date('now')");
    sqlQuery.exec();
    //处理延期的长期任务
    sqlQuery.prepare("insert into extendedwork(startdate,enddate,content,complete) select startdate,enddate,content,complete from longtermwork where longtermwork.enddate<date('now') and longtermwork.complete=0");
    sqlQuery.exec();
    sqlQuery.prepare("delete from longtermwork where enddate<date('now')");
    sqlQuery.exec();
}

void SqliteOperator::CreatTable()
{
    QSqlQuery sqlQuery;
    //创建数据库的sql语句字符串
    QString createSql = QString("create table todaywork (\
                                id integer primary key AUTOINCREMENT,\
                                creatdate date not null,\
                                content text not null,\
                                complete integer not null)");
                        sqlQuery.prepare(createSql);
    if(!sqlQuery.exec())//执行sql语句
    {
        qDebug() << "Error: Fail to create today table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "today table created!";
    }
    createSql = QString("create table yesterdaywork (\
                        id integer primary key AUTOINCREMENT,\
                        creatdate date not null,\
                        content text not null,\
                        complete integer not null)");
                sqlQuery.prepare(createSql);
    if(!sqlQuery.exec())//执行sql语句
    {
        qDebug() << "Error: Fail to create yesterday table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "yesterday table created!";
    }
    createSql = QString("create table expectedwork (\
                        id integer primary key AUTOINCREMENT,\
                        creatdate date not null,\
                        content text not null,\
                        complete integer not null)");
                sqlQuery.prepare(createSql);
    if(!sqlQuery.exec())//执行sql语句
    {
        qDebug() << "Error: Fail to create expected table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "expected table created!";
    }
    createSql = QString("create table longtermwork (\
                        id integer primary key AUTOINCREMENT,\
                        startdate date not null,\
                        enddate date not null,\
                        content text not null,\
                        complete integer not null)");
                sqlQuery.prepare(createSql);
    if(!sqlQuery.exec())//执行sql语句
    {
        qDebug() << "Error: Fail to create longterm table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "longterm table created!";
    }
    createSql = QString("create table extendedwork (\
                        id integer primary key AUTOINCREMENT,\
                        startdate date not null,\
                        enddate date not null,\
                        content text not null,\
                        complete integer not null)");
                sqlQuery.prepare(createSql);
    if(!sqlQuery.exec())//执行sql语句
    {
        qDebug() << "Error: Fail to create extended table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "extended table created!";
    }
}

void SqliteOperator::AddToday(QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("insert into todaywork values(null,date('now'),?,0)");
    sqlQuery.addBindValue(content);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "add data success!";
    }
}

void SqliteOperator::FinishToday(int id,int finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update todaywork set complete=? where id=?");
    sqlQuery.addBindValue(finish);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::ChangeToday(int id,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update todaywork set content=? where id=?");
    sqlQuery.addBindValue(content);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::DeleteToday(int id)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from todaywork where id=?");
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "delete data success!";
    }
}

void SqliteOperator::FinishYester(int id,int finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update yesterdaywork set complete=? where id=?");
    sqlQuery.addBindValue(finish);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::ChangeYester(int id,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update testerdaywork set content=? where id=?");
    sqlQuery.addBindValue(content);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::DeleteYester(int id)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from yesterdaywork where id=?");
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "delete data success!";
    }
}

void SqliteOperator::AddExpected(QString date,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("insert into expectedwork values(null,?,?,0)");
    sqlQuery.addBindValue(date);
    sqlQuery.addBindValue(content);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "add data success!";
    }
}

void SqliteOperator::ChangeExpected(int id,QString date,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update expectedwork set creatdate=?,content=? where id=?");
    sqlQuery.addBindValue(date);
    sqlQuery.addBindValue(content);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::DeleteExpected(int id)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from expectedwork where id=?");
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "delete data success!";
    }
}

void SqliteOperator::AddLongterm(QString sdate,QString edate,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("insert into longtermwork values(null,?,?,?,0)");
    sqlQuery.addBindValue(sdate);
    sqlQuery.addBindValue(edate);
    sqlQuery.addBindValue(content);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "add data success!";
    }
}

void SqliteOperator::FinishLongterm(int id,int finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update longtermwork set complete=? where id=?");
    sqlQuery.addBindValue(finish);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::ChangeLongterm(int id,QString sdate,QString edate,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update longtermwork set startdate=?,enddate=?,content=? where id=?");
    sqlQuery.addBindValue(sdate);
    sqlQuery.addBindValue(edate);
    sqlQuery.addBindValue(content);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::DeleteLongterm(int id)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from longtermwork where id=?");
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "delete data success!";
    }
}

void SqliteOperator::FinishExtended(int id,int finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("update extendedmwork set complete=? where id=?");
    sqlQuery.addBindValue(finish);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "change data success!";
    }
}

void SqliteOperator::DeleteExtended(int id)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from extendedwork where id=?");
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "delete data success!";
    }
}

int SqliteOperator::GetDeadline(QString date)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from longtermwork where enddate=?");
    sqlQuery.addBindValue(date);
    sqlQuery.exec();
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

int* SqliteOperator::GetTodayList(int* n)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from todaywork");
    sqlQuery.exec();
    sqlQuery.next();
    int* list;
    *n=sqlQuery.value(0).toInt();
    list=new int[*n];
    sqlQuery.prepare("select id from todaywork");
    sqlQuery.exec();
    int i=0;
    while(sqlQuery.next()){
        list[i++]=sqlQuery.value(0).toInt();
    }
    return list;
}

void SqliteOperator::GetToday(int id,QString& content,int& finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select * from todaywork where id=?");
    sqlQuery.addBindValue(id);
    sqlQuery.exec();
    sqlQuery.next();
    content=sqlQuery.value(2).toString();
    finish=sqlQuery.value(3).toInt();
}

int* SqliteOperator::GetYesterList(int* n)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from yesterdaywork");
    sqlQuery.exec();
    sqlQuery.next();
    *n=sqlQuery.value(0).toInt();
    int* list;
    list=new int[*n];
    sqlQuery.prepare("select id from yesterdaywork");
    sqlQuery.exec();
    int i=0;
    while(sqlQuery.next()){
        list[i++]=sqlQuery.value(0).toInt();
    }
    return list;
}

void SqliteOperator::GetYesterday(int id,QString& content,int& finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select * from yesterdaywork where id=?");
    sqlQuery.addBindValue(id);
    sqlQuery.exec();
    sqlQuery.next();
    content=sqlQuery.value(2).toString();
    finish=sqlQuery.value(3).toInt();
}

int* SqliteOperator::GetExpectedList(int* n)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from expectedwork");
    sqlQuery.exec();
    sqlQuery.next();
    *n=sqlQuery.value(0).toInt();
    int* list;
    list=new int[*n];
    sqlQuery.prepare("select id from expectedwork");
    sqlQuery.exec();
    int i=0;
    while(sqlQuery.next()){
        list[i++]=sqlQuery.value(0).toInt();
    }
    return list;
}

void SqliteOperator::GetExpected(int id,QString& date,QString& content,int& finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select * from expectedwork where id=?");
    sqlQuery.addBindValue(id);
    sqlQuery.exec();
    sqlQuery.next();
    date=sqlQuery.value(1).toString();
    content=sqlQuery.value(2).toString();
    finish=sqlQuery.value(3).toInt();
}

int* SqliteOperator::GetLongtermList(int* n)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from longtermwork");
    sqlQuery.exec();
    sqlQuery.next();
    *n=sqlQuery.value(0).toInt();
    int* list;
    list=new int[*n];
    sqlQuery.prepare("select id from longtermwork");
    sqlQuery.exec();
    int i=0;
    while(sqlQuery.next()){
        list[i++]=sqlQuery.value(0).toInt();
    }
    return list;
}

void SqliteOperator::GetLongterm(int id,QString& sdate,QString& edate,QString& content,int& finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select * from longtermwork where id=?");
    sqlQuery.addBindValue(id);
    sqlQuery.exec();
    sqlQuery.next();
    sdate=sqlQuery.value(1).toString();
    edate=sqlQuery.value(2).toString();
    content=sqlQuery.value(3).toString();
    finish=sqlQuery.value(4).toInt();
}

int* SqliteOperator::GetExtendedList(int* n)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select count(*) from extendedwork");
    sqlQuery.exec();
    sqlQuery.next();
    *n=sqlQuery.value(0).toInt();
    int* list;
    list=new int[*n];
    sqlQuery.prepare("select id from extendedwork");
    sqlQuery.exec();
    int i=0;
    while(sqlQuery.next()){
        list[i++]=sqlQuery.value(0).toInt();
    }
    return list;
}

void SqliteOperator::GetExtended(int id,QString& sdate,QString& edate,QString& content,int& finish)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("select * from extendedwork where id=?");
    sqlQuery.addBindValue(id);
    sqlQuery.exec();
    sqlQuery.next();
    sdate=sqlQuery.value(1).toString();
    edate=sqlQuery.value(2).toString();
    content=sqlQuery.value(3).toString();
    finish=sqlQuery.value(4).toInt();
}


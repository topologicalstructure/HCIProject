#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
using namespace std;

class SqliteOperator//该类用来对数据库进行各种操作
{
public:
    QSqlDatabase database;
    SqliteOperator();
    ~SqliteOperator();
    void UpdateTable();//用来更新表的内容
    void AddToday(QString content);//添加今日任务的函数，参数为具体内容
    void FinishToday(int id,int finish);//完成或取消完成该id的今日任务
    void ChangeToday(int id,QString content);//修改今日任务的信息
    void FinishYester(int id,int finish);//完成或取消完成该id的昨日任务
    void ChangeYester(int id,QString content);//修改昨日任务的信息

private:
    void CreatTable();
};

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

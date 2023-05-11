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
    void AddToday(QString date,QString content);//添加今日任务的函数，两个参数分别为添加日期和具体内容，日期应当按照"xxxx-xx-xx"的形式

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
        qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
}

void SqliteOperator::AddToday(QString date,QString content)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("insert into todaywork values(null,?,?,0)");
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






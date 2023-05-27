#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>
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
    void DeleteToday(int id);//删除今日任务
    int* GetTodayList(int* n);//获取今日任务列表，n为项数，用完以后需要释放
    void GetToday(int id,QString& content,int& finish);//获取今日任务
    void FinishYester(int id,int finish);//完成或取消完成该id的昨日任务
    void ChangeYester(int id,QString content);//修改昨日任务的信息
    void DeleteYester(int id);//删除昨日任务
    int* GetYesterList(int* n);//获取昨日任务列表
    void GetYesterday(int id,QString& content,int& finish);//获取昨日任务
    void AddExpected(QString date,QString content);//添加预定任务
    void ChangeExpected(int id,QString date,QString content);//修改预定任务
    void DeleteExpected(int id);//删除预定任务
    int* GetExpectedList(int* n);//获取预定任务列表
    void GetExpected(int id,QString& date,QString& content,int& finish);//获取预定任务
    void AddLongterm(QString sdate,QString edate,QString content);//添加长期任务
    void FinishLongterm(int id,int finish);//完成或取消完成该id的长期任务
    void ChangeLongterm(int id,QString sdate,QString edate,QString content);//修改长期任务
    void DeleteLongterm(int id);//删除长期任务
    int* GetLongtermList(int* );//获取长期任务列表
    int* GetLongtermList_by_edate(int* n, const QDate& edate);
    void GetLongterm(int id,QString& sdate,QString& edate,QString& content,int& finish);//获取长期任务
    void FinishExtended(int id,int finish);//完成或取消完成该id的延期任务
    void DeleteExtended(int id);//删除延期任务
    int* GetExtendedList(int* n);//获取延期任务列表
    void GetExtended(int id,QString& sdate,QString& edate,QString& content,int& finish);//获取延期任务
    int GetDeadline(QString date);//查询某一日期的截止任务数量，"xxxx-xx-xx"

private:
    void CreatTable();
};


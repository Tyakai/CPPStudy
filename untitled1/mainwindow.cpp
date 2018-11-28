#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    char test[32]/*={0}*/;
    qDebug()<<QString("sizeof(test):%1").arg(sizeof(test));
    char* test_2 = (char*)malloc(32*sizeof(char));
    qDebug()<<QString("sizeof(test_2):%1").arg(sizeof(test_2));

#if 0
    char *temp = "\0NULL";
    int a = strlen(temp);
    qDebug()<<QString("strlen:%1").arg(a);

    ui->setupUi(this);
    unsigned long long a=0;
    --a;
    qDebug()<<QString("sizeof(a):%1,max:%2").arg(sizeof(a)).arg(a);


//    char spCharList[] = "`~!@#$%^&*()+=|{}':;\"\\,[].<>/?";
//    char *ch = spCharList;
    printf("--------------------------------------------start----------------------------------------------------\r\n");

    for(int i=0;i<strlen(spCharList);++i)
    {
        char ch = spCharList[i];
//        qDebug()<<QString("ch=%1 ==  %2").arg(ch).arg((int)ch);
//        qDebug()<<QString("update t_mon_dev set s_dev_name=replace(s_dev_name,char(%1),'');").arg((int)ch);
//        qDebug()<<QString("update t_mon_user set s_user_alias=replace(s_user_alias,char(%1),'');").arg((int)ch);
//        qDebug()<<QString("update t_mon_user_dev_catalog set s_node_name=replace(s_node_name,char(%1),'');").arg((int)ch);
//        qDebug()<<QString("update t_mon_user_friend set s_friend_memo_name=replace(s_friend_memo_name,char(%1),'');").arg((int)ch);
//        qDebug()<<QString("update t_mon_user_share_dev set s_share_name=replace(s_share_name,char(%1),'');").arg((int)ch);
//        qDebug()<<QString("update t_mon_user_nologin_devs set s_dev_name=replace(s_dev_name,char(%1),'');").arg((int)ch);
//        printf("update t_mon_dev set s_dev_name=replace(s_dev_name,char(%d),'_');\r\n",(int)ch);
//        printf("update t_mon_user set s_user_alias=replace(s_user_alias,char(%d),'_');\r\n",(int)ch);
//        printf("update t_mon_user_dev_catalog set s_node_name=replace(s_node_name,char(%d),'_');\r\n",(int)ch);
//        printf("update t_mon_user_friend set s_friend_memo_name=replace(s_friend_memo_name,char(%d),'_');\r\n",(int)ch);
//        printf("update t_mon_user_share_dev set s_share_name=replace(s_share_name,char(%d),'_');\r\n",(int)ch);
//        printf("update t_mon_user_nologin_devs set s_dev_name=replace(s_dev_name,char(%d),'_');\r\n",(int)ch);
//        printf("\r\n\r\n");


    }
    printf("--------------------------------------------ende----------------------------------------------------\r\n");
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

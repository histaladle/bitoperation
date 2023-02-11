#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
void midbit(char *src,char *dst,int start_bit,int end_bit);
void movebit(char *src,int src_bit_ofs,char *dst,int dst_bit_ofs,int bit_width);
void swap_bit(char *data1,int bit1,char *data2,int bit2);
void reverse_bit_order(char *data,int start_bit,int end_bit);
void reverse_byte_order(char *data,int start_byte,int end_byte);
void movebyte(char *data,int start_byte,int end_byte,int offset);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString s1,s2;
    uchar src[8]={0x01,0x82,0x03,0x04,0x05,0x06,0x07,0x08};
    uchar dst[8]={0};
    midbit(reinterpret_cast<char*>(src),reinterpret_cast<char*>(dst),1,63);
    s1.clear();
    s2.clear();
    for(int i=0;i<int(sizeof(src));i++) {
        for(int j=0;j<8;j++) {
            s1.append(src[i]&(1<<j)?"1":"0");
            s2.append(dst[i]&(1<<j)?"1":"0");
        }
    }
//    movebit(reinterpret_cast<char*>(src),8,reinterpret_cast<char*>(dst),0,16);
//    s1.clear();
//    s2.clear();
//    for(int i=0;i<int(sizeof(src));i++) {
//        for(int j=0;j<8;j++) {
//            s1.append(src[i]&(1<<j)?"1":"0");
//            s2.append(dst[i]&(1<<j)?"1":"0");
//        }
//    }
//    movebyte(reinterpret_cast<char*>(src),0,3,1);
//    s1.clear();
//    s2.clear();
//    for(int i=0;i<int(sizeof(src));++i) {
//        s1.append(QString::number(int(src[i])&0xff,16));
//        s1.append(" ");
//    }
//    movebyte(reinterpret_cast<char*>(src),1,4,-1);
//    s1.clear();
//    s2.clear();
//    for(int i=0;i<int(sizeof(src));++i) {
//        s1.append(QString::number(int(src[i])&0xff,16));
//        s1.append(" ");
//    }
    qDebug() << s1;
    qDebug() << s2;
    qDebug() << "debug10";
}

MainWindow::~MainWindow()
{
    delete ui;
}

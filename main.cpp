#include <QCoreApplication>
#include <iostream>
#include "average.h"

#define SIZESAMPLE 1000000

struct TEST
{
    int width[6];
};

TEST test =
{
    4, 8, 16, 32, 64, 128
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Average average;
    QString str;

    for(int i=0; i<6; i++)
    {
        str = QString("Type float, window %1").arg(test.width[i]) + ", time " + QString::number(average.CalcFloat(SIZESAMPLE, test.width[i]),'g',6) + " sample/sec";
        std::cout << str.toStdString() << std::endl;

        str = QString("Type float, window %1").arg(test.width[i]) + ", time " + QString::number(average.CalcDouble(SIZESAMPLE, test.width[i]),'g',6) + " sample/sec";
        std::cout << str.toStdString() << std::endl;
    }


    return a.exec();
}

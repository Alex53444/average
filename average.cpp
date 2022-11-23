#include <QVector>
#include "average.h"
#include "QDebug"

Average::Average()
{
}

double Average::CalcFloat(unsigned int size, unsigned int width_window)
{
    QVector<float> inData;
    QVector<float> outData;
    double summ=0;
    inData.resize(size);
    outData.resize(size-width_window);
    for(unsigned int i=0; i < size; i++)
        inData[i] = (qrand() % ((HIGH_DATA + 1) - LOW_DATA) + LOW_DATA);

    QTime time;
    time.start();

    for(unsigned int i=0; i < width_window; i++)
        summ += inData[i];

    outData[0] = summ;

    for(unsigned int i=1; i < size - width_window; i++)
    {
        summ = summ - inData[i-1] + inData[i-1+width_window];
        outData[i] = summ/width_window;
    }


    double sec = time.elapsed()/1000.;
    if(sec == 0)
        return -1;
    else
        return size/sec;
}

double Average::CalcDouble(unsigned int size, unsigned int width_window)
{
    QVector<double> inData;
    QVector<double> outData;
    double summ=0;
    inData.resize(size);
    outData.resize(size-width_window);
    for(unsigned int i=0; i < size; i++)
        inData[i] = (qrand() % ((HIGH_DATA + 1) - LOW_DATA) + LOW_DATA);

    QTime time;
    time.start();

    for(unsigned int i=0; i < width_window; i++)
        summ += inData[i];

    outData[0] = summ;

    for(unsigned int i=1; i < size - width_window; i++)
    {
        summ = summ - inData[i-1] + inData[i-1+width_window];
        outData[i] = summ/width_window;
    }


    double sec = time.elapsed()/1000.;
    if(sec == 0)
        return -1;
    else
        return size/sec;
}


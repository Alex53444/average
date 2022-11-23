#include <QVector>
#include "average.h"

Average::Average()
{
}

double Average::CalcFloat(unsigned int size, unsigned int width_window)
{
    QVector<float> inData;
    QVector<float> outData;
    inData.resize(size);
    outData.resize(size-width_window);
    for(unsigned int i=0; i < size; i++)
        inData[i] = (qrand() % ((HIGH_DATA + 1) - LOW_DATA) + LOW_DATA);

    QTime time;
    time.start();

    for(unsigned int i=0; i < size - width_window; i++)
    {
        summ = 0;
        for(unsigned int j=0; j < width_window; j++)
            summ += inData[i+j];

        outData[i] = summ/width_window;
    }

    double sec = time.elapsed()/1000.;
    if(sec == 0)
        return 0;
    else
        return size/sec;
}

double Average::CalcDouble(unsigned int size, unsigned int width_window)
{
    QVector<double> inData;
    QVector<double> outData;
    inData.resize(size);
    outData.resize(size-width_window);
    for(unsigned int i=0; i < size; i++)
        inData[i] = (qrand() % ((HIGH_DATA + 1) - LOW_DATA) + LOW_DATA);

    QTime time;
    time.start();

    for(unsigned int i=0; i < size - width_window; i++)
    {
        summ = 0;
        for(unsigned int j=0; j < width_window; j++)
            summ += inData[i+j];

        outData[i] = summ/width_window;
    }

    double sec = time.elapsed()/1000.;
    if(sec == 0)
        return 0;
    else
        return size/sec;
}


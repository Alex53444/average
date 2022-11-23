#ifndef AVERAGE_H
#define AVERAGE_H

#include <QObject>
#include <QVector>
#include <QTime>

#define HIGH_DATA 1000
#define LOW_DATA -1000

class Average: public QObject
{
    Q_OBJECT
public:
    Average();
    double CalcFloat(unsigned int size, unsigned int window);
    double CalcDouble(unsigned int size, unsigned int window);

private:
    float summ;
};

#endif // AVERAGE_H

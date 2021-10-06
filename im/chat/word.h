#ifndef WORD_H
#define WORD_H

#include <QObject>

class Word : public QObject
{
    Q_OBJECT
public:
    explicit Word(QObject *parent = nullptr);

    int add(int a, int b){
        return a+b;
    }

    int add1(int a, int b){
        return a+b;
    }


signals:

};

#endif // WORD_H

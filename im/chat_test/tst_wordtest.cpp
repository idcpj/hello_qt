#include <QtTest>

// add necessary includes here

#include <QDebug>
#include "../chat/word.h"


class WordTest : public QObject
{
    Q_OBJECT

public:
    WordTest();
    ~WordTest();

private slots:
    void test_case1();
    void initTestCase();

};

WordTest::WordTest()
{

}

WordTest::~WordTest()
{

}

void WordTest::test_case1()
{
       Word word;
       int res = word.add(1,2);
       QTRY_COMPARE(res,3);
}

void WordTest::initTestCase()
{
    qDebug()<<"asd";
}

QTEST_APPLESS_MAIN(WordTest)

#include "tst_wordtest.moc"

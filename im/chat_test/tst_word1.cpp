#include <QtTest>

// add necessary includes here



class TestQString : public QObject
{
    Q_OBJECT

public:
    TestQString();
    ~TestQString();

private slots:
    void toUpper_data();
    void toUpper();

};

TestQString::TestQString()
{
}

TestQString::~TestQString()
{

}

void TestQString::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestQString::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QTest


    QCOMPARE(string.toUpper(), result);
}


//QTEST_APPLESS_MAIN(TestQString)

#include "tst_word1.moc"

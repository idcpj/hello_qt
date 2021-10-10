#include "tst_word1.cpp"
#include "tst_wordtest.cpp"

int main(int argc, char *argv[])
{
    WordTest tc;
    QTest::qExec(&tc, argc, argv);


    TestQString str;
    QTest::qExec(&str, argc, argv);


    QTEST_SET_MAIN_SOURCE_PATH
    return 0;
}

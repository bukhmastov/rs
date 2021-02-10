#ifndef STATIC_H
#define STATIC_H

#include <QString>
#include <QLayout>
#include <tuple>

class Static {
public:
    static QString worktype; // "Лабораторная работа" "Практическое занятие"
    static QString worktypeShort; // "ЛР" "ПЗ"
    static bool allowSelectVariant; // true false
    static int scoreInitial;
    static int score4quetion;
    static int score4task;
    static QString messageAnswerRight;
    static QString messageAnswerWrong;
    //                            m    i    pi(x)    F0       Ep       Fe       Fu       Ee       F1 (inf)
    static std::vector<std::tuple<int, int, QString, QString, QString, QString, QString, QString, QString>> variants;

    static std::tuple<int, int, QString, QString, QString, QString, QString, QString, QString> getVariant(QString);
    static int getVm(QString);
    static int getVi(QString);
    static QString getVpix(QString);
    static QString getVf0(QString);
    static QString getVep(QString);
    static QString getVfe(QString);
    static QString getVfu(QString);
    static QString getVee(QString);
    static QString getVf1(QString);

    static QString getReadablePolynom(QString);

    static void clearLayout(QLayout*);

    static std::vector<int> getAlphaTable(QString h);
    static std::vector<int> getBetaTable(QString h, int vi);

    // t1 - поле Галуа
    static std::vector<QString> getGaluaField1(QString h);

    // t2 - расширенное поле Галуа
    static std::vector<QString> getGaluaFieldI(QString h, int i);

    // t3 - таблица сложения
    static std::vector<std::vector<int>> getAdditionTable(QString h, int i);
    static std::vector<std::vector<int>> getMultiplicationTable();

    // t4 - образующий полином
    static std::vector<int> getFormingPolynom(QString h, int i, int m);
    static QString getFormingPolynomAns(QString h, int i, int m);

    // t5 - проверочная матрица
    static std::vector<std::vector<int>> getCheckMatrix(int m);

    // t6 - закодированная кодовая комбинация
    static std::vector<int> getCodedCombination(QString h, int i, int m, QString f0);
    static QString getCodedCombinationAns(QString h, int i, int m, QString f0);

    // t7 - искаженная кодовая комбинация
    static std::vector<int> getDistortedCodedCombination(QString h, int i, int m, QString f0, QString ep);
    static QString getDistortedCodedCombinationAns(QString h, int i, int m, QString f0, QString ep);

    // t8 - синдром
    static std::vector<int> getSyndrome(QString h, int i, int m, QString fe);
    static QString getSyndromeAns(QString h, int i, int m, QString fe);

    // t9 - полином локаторов
    static std::vector<int> getLocatorPolynom(QString h, int i, QString ee);
    static QString getLocatorPolynomAns(QString h, int i, QString ee);

    // t10 - полином величин ошибок
    static std::vector<int> getErrorPolynom(QString h, int i, int m, QString fe, QString ee);
    static QString getErrorPolynomAns(QString h, int i, int m, QString fe, QString ee);

    // t11 - корни полинома локаторов
    static std::vector<int> getErrorLocatorPolynom(QString h, int i, QString ee);

    // t12 - локаторы ошибок
    static std::vector<int> getErrorLocators(QString ee);

    // t13 - величины ошибок
    static std::vector<int> getErrorValues(QString ee);

    // t14 - найденный полином ошибок
    static QString getFoundedErrorPolynom(QString ee);
    // t14 - исправленная КК
    static QString getCorrectedCodeCombination(QString fu);

    // t15 - информация
    static QString getInforamtionSeq(QString f1);

private:
    static int intLength(int number);
    static QString fillZeroBefore(int number, int size);
};

#endif // STATIC_H

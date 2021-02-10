#include "static.h"
#include <QString>
#include <QLayout>
#include <QWidget>
#include <QChar>

QString Static::worktype = "Лабораторная работа"; // "Лабораторная работа" "Практическое занятие"
QString Static::worktypeShort = "ЛР"; // "ЛР" "ПЗ"
bool Static::allowSelectVariant = true; // true false

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";
//                     m    i    pi(x)    F0       Ep       Fe       Fu       Ee       F1 (inf)
std::vector<std::tuple<int, int, QString, QString, QString, QString, QString, QString, QString>> Static::variants;

std::tuple<int, int, QString, QString, QString, QString, QString, QString, QString> Static::getVariant(QString v) {
    if (Static::variants.size() < 50) {
        Static::variants.clear();
        Static::variants.push_back(std::make_tuple(0, 2, "1101", "665", "0000420", "4036434", "4027434", "0052000", "544"));
        Static::variants.push_back(std::make_tuple(0, 3, "1101", "036", "0010006", "1403336", "1203036", "0500300", "226"));
        Static::variants.push_back(std::make_tuple(0, 4, "1101", "627", "0007400", "0570215", "0570256", "0000061", "066"));
        Static::variants.push_back(std::make_tuple(0, 5, "1101", "607", "0002400", "4214644", "4214243", "0000101", "503"));
        Static::variants.push_back(std::make_tuple(0, 6, "1101", "246", "0300020", "5066452", "5666152", "0600300", "662"));
        Static::variants.push_back(std::make_tuple(6, 1, "1101", "043", "0430000", "2574160", "2474060", "0700100", "760"));
        Static::variants.push_back(std::make_tuple(1, 1, "1101", "245", "0000047", "3010064", "3630064", "0670000", "724"));
        Static::variants.push_back(std::make_tuple(1, 2, "1101", "226", "0207000", "2123372", "2723374", "0300001", "604"));
        Static::variants.push_back(std::make_tuple(2, 3, "1101", "647", "0050070", "3166237", "3166134", "0000606", "324"));
        Static::variants.push_back(std::make_tuple(2, 4, "1101", "715", "0000011", "5023272", "5005272", "0022000", "522"));
        Static::variants.push_back(std::make_tuple(2, 5, "1101", "075", "5050000", "6031644", "6121644", "0170000", "664"));
        Static::variants.push_back(std::make_tuple(2, 6, "1101", "277", "0700001", "3227661", "7227161", "2000200", "771"));
        Static::variants.push_back(std::make_tuple(3, 5, "1101", "321", "2000050", "2065614", "2062611", "0004003", "571"));
        Static::variants.push_back(std::make_tuple(3, 1, "1101", "153", "0021000", "1471057", "1426057", "0065000", "407"));
        Static::variants.push_back(std::make_tuple(3, 2, "1101", "352", "0000202", "2146623", "2546624", "0600006", "504"));
        Static::variants.push_back(std::make_tuple(3, 3, "1101", "511", "0300200", "7006157", "7105157", "0103000", "327"));
        Static::variants.push_back(std::make_tuple(4, 3, "1101", "403", "0030070", "1714226", "1514222", "0100001", "732"));
        Static::variants.push_back(std::make_tuple(4, 5, "1101", "726", "0000760", "2761415", "2761345", "0000130", "115"));
        Static::variants.push_back(std::make_tuple(4, 6, "1101", "327", "4000050", "4160665", "4260605", "0600060", "335"));
        Static::variants.push_back(std::make_tuple(4, 2, "1101", "553", "0000307", "3161346", "3121341", "0070005", "251"));
        Static::variants.push_back(std::make_tuple(5, 1, "1101", "045", "0000706", "6156247", "6656240", "0500007", "140"));
        Static::variants.push_back(std::make_tuple(5, 2, "1101", "760", "0005070", "4213762", "1313762", "2500000", "372"));
        Static::variants.push_back(std::make_tuple(5, 3, "1101", "473", "0007400", "0765242", "4365242", "4200000", "632"));
        Static::variants.push_back(std::make_tuple(6, 4, "1101", "544", "0060050", "2135415", "2637415", "0504000", "755"));
        Static::variants.push_back(std::make_tuple(6, 5, "1101", "323", "0050010", "4416041", "5416044", "2000003", "304"));
        Static::variants.push_back(std::make_tuple(0, 1, "1011", "201", "6030000", "4117302", "4117006", "0000301", "576"));
        Static::variants.push_back(std::make_tuple(0, 2, "1011", "703", "0000250", "5322727", "0322737", "5000070", "047"));
        Static::variants.push_back(std::make_tuple(0, 3, "1011", "231", "0450000", "2610410", "2210414", "0700004", "354"));
        Static::variants.push_back(std::make_tuple(1, 4, "1011", "325", "1300000", "7702417", "7742412", "0040003", "432"));
        Static::variants.push_back(std::make_tuple(1, 5, "1011", "417", "4000300", "3207220", "6707220", "4600000", "320"));
        Static::variants.push_back(std::make_tuple(1, 6, "1011", "543", "4005000", "3505750", "4505770", "6000040", "170"));
        Static::variants.push_back(std::make_tuple(2, 3, "1011", "063", "0000310", "3674260", "3674763", "0000603", "323"));
        Static::variants.push_back(std::make_tuple(2, 1, "1011", "646", "1070000", "1526562", "1126362", "0700600", "132"));
        Static::variants.push_back(std::make_tuple(2, 2, "1011", "460", "2007000", "3467201", "5367201", "6100000", "541"));
        Static::variants.push_back(std::make_tuple(2, 3, "1011", "153", "4200000", "5746264", "7746064", "4000200", "754"));
        Static::variants.push_back(std::make_tuple(3, 4, "1011", "215", "0007006", "5205536", "7201536", "1007000", "306"));
        Static::variants.push_back(std::make_tuple(3, 5, "1011", "740", "5000400", "7044554", "7045574", "0007040", "364"));
        Static::variants.push_back(std::make_tuple(3, 6, "1011", "633", "0005070", "4623161", "3622161", "6005000", "601"));
        Static::variants.push_back(std::make_tuple(3, 3, "1011", "312", "5000004", "2422006", "2672006", "0360000", "546"));
        Static::variants.push_back(std::make_tuple(4, 1, "1011", "041", "0064000", "5252444", "0252445", "5000002", "015"));
        Static::variants.push_back(std::make_tuple(4, 2, "1011", "703", "0700001", "4670211", "4600711", "0070300", "321"));
        Static::variants.push_back(std::make_tuple(4, 3, "1011", "266", "0600002", "6015704", "6011714", "0006010", "574"));
        Static::variants.push_back(std::make_tuple(4, 4, "1011", "252", "0600300", "0237123", "0737223", "0300600", "063"));
        Static::variants.push_back(std::make_tuple(5, 5, "1011", "621", "0002200", "1452203", "1452271", "0000077", "331"));
        Static::variants.push_back(std::make_tuple(5, 6, "1011", "322", "0007070", "3155304", "7155344", "1000040", "204"));
        Static::variants.push_back(std::make_tuple(5, 2, "1011", "724", "2000005", "6305770", "6306270", "0003300", "170"));
        Static::variants.push_back(std::make_tuple(5, 1, "1011", "707", "0005020", "3543140", "1543146", "4000006", "326"));
        Static::variants.push_back(std::make_tuple(6, 2, "1011", "421", "0600700", "1641655", "1641345", "0000520", "625"));
        Static::variants.push_back(std::make_tuple(6, 3, "1011", "317", "6005000", "4237262", "4237142", "0000430", "262"));
        Static::variants.push_back(std::make_tuple(6, 4, "1011", "102", "7000004", "4472372", "3475372", "1004000", "132"));
    }
    return Static::variants.at(v.toInt());
}

int Static::getVm(QString v) {
    return std::get<0>(Static::getVariant(v));
}

int Static::getVi(QString v) {
    return std::get<1>(Static::getVariant(v));
}

QString Static::getVpix(QString v) {
    return std::get<2>(Static::getVariant(v));
}

QString Static::getVf0(QString v) {
    return std::get<3>(Static::getVariant(v));
}

QString Static::getVep(QString v) {
    return std::get<4>(Static::getVariant(v));
}

QString Static::getVfe(QString v) {
    return std::get<5>(Static::getVariant(v));
}

QString Static::getVfu(QString v) {
    return std::get<6>(Static::getVariant(v));
}

QString Static::getVee(QString v) {
    return std::get<7>(Static::getVariant(v));
}

QString Static::getVf1(QString v) {
    return std::get<8>(Static::getVariant(v));
}

QString Static::getReadablePolynom(QString poly) {
    QString readable = "";
    int size = poly.size();
    for (int i = 0; i < size; i++) {
        if (poly.at(i) != QChar('0')) {
            if (!readable.isEmpty()) {
                readable += "+";
            }
            if (i == 0) {
                readable += poly.at(i);
            } else if (poly.at(i) != QChar('1')) {
                readable += poly.at(i);
            }
            if (i == 1) {
                readable += "x";
            }
            if (i > 1) {
                readable += "x<sup>" + QString::number(i) + "</sup>";
            }
        }
    }
    return readable;
}

void Static::clearLayout(QLayout* layout) {
    QLayoutItem *wItem;
    while ((wItem = layout->takeAt(0)) != 0) {
        if (wItem->widget()) wItem->widget()->setParent(NULL);
        delete wItem;
    }
}

std::vector<int> Static::getAlphaTable(QString h) {
    int p = h == "1101" ? 11 : 13;
    std::vector<int> alpha = { 1 };
    for (int i = 1; i < 7; i++) {
        alpha.push_back(alpha.at(i - 1) * 2);
        if (alpha.at(i) > 7) {
            alpha.at(i) = alpha.at(i) ^ p;
        }
    }
    return alpha;
}

std::vector<int> Static::getBetaTable(QString h, int vi) {
    int p = h == "1101" ? 11 : 13;
    std::vector<int> alpha = getAlphaTable(h);
    std::vector<int> beta = { 1 };
    for (int i = 1; i < 7; i++) {
        beta.push_back(alpha.at((vi * i) % 7));
        if (beta.at(i) > 7) {
            beta.at(i) = beta.at(i) ^ p;
        }
    }
    return beta;
}

// t1 - поле Галуа
std::vector<QString> Static::getGaluaField1(QString h) {
    std::vector<QString> table;
    int a2, a1, a0;
    std::vector<int> alpha = getAlphaTable(h);
    for (int i = 0; i < 7; i++) {
        a2 = (alpha.at(i) / 4) % 10;
        if (alpha.at(i) == 2 || alpha.at(i) == 3 || alpha.at(i) == 6 || alpha.at(i) == 7) {
            a1 = 1;
        } else {
            a1 = 0;
        }
        if (alpha.at(i) % 2 == 0) {
            a0 = 0;
        } else {
            a0 = 1;
        }
        table.push_back(QString::number(a2) + QString::number(a1) + QString::number(a0));
    }
    return table;
}

// t2 - расширенное поле Галуа
std::vector<QString> Static::getGaluaFieldI(QString h, int i) {
    std::vector<QString> table;
    int a2, a1, a0;
    std::vector<int> beta = getBetaTable(h, i);
    for (int i = 0; i < 7; i++) {
        a2 = (beta.at(i) / 4) % 10;
        if (beta.at(i) == 2 || beta.at(i) == 3 || beta.at(i) == 6 || beta.at(i) == 7) {
            a1 = 1;
        } else {
            a1 = 0;
        }
        if (beta.at(i) % 2 == 0) {
            a0 = 0;
        } else {
            a0 = 1;
        }
        table.push_back(QString::number(a2) + QString::number(a1) + QString::number(a0));
    }
    return table;
}

// t3 - таблица сложения
std::vector<std::vector<int>> Static::getAdditionTable(QString h, int i) {
    std::vector<std::vector<int>> table;
    std::vector<int> beta = getBetaTable(h, i);
    for (int i = 0; i < 8; i++) table.push_back({0, 0, 0, 0, 0, 0, 0, 0});
    for (int i = 1; i < 8; i++) {
        for (int f = 1; f < 8; f++) {
            int n = beta.at(i - 1) ^ beta.at(f - 1);
            for (int r = 0; r < 7; r++) {
                if (n == beta.at(r)) {
                    table.at(i).at(f) = r + 1;
                    table.at(f).at(i) = r + 1;
                }
            }
            if (n == 0) {
                table.at(i).at(f) = 0;
            }
        }
        table.at(0).at(i) = i;
        table.at(i).at(0) = i;
    }
    return table;
}

std::vector<std::vector<int>> Static::getMultiplicationTable() {
    std::vector<std::vector<int>> table;
    for (int i = 0; i < 8; i++) table.push_back({0, 0, 0, 0, 0, 0, 0, 0});
    for (int i = 1; i < 8; i++) {
        for (int f = i; f < 8; f++) {
            table.at(i).at(f) = (i - 1 + f - 1) % 7 + 1;
            table.at(f).at(i) = (i - 1 + f - 1) % 7 + 1;
        }
    }
    return table;
}

// t4 - образующий полином
std::vector<int> Static::getFormingPolynom(QString h, int i, int m) {
    std::vector<int> polynom = {0, 0, 0, 0, 0};
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    polynom.at(0) = (4 * m + 6) % 7 + 1;
    polynom.at(1) = summ.at(
       summ.at((3 * m + 3) % 7 + 1).at((3 * m + 6) % 7 + 1)
    ).at(
       summ.at((3 * m + 5) % 7 + 1).at((3 * m + 4) % 7 + 1)
    );
    polynom.at(2) = summ.at(
        summ.at((2 * m + 2) % 7 + 1).at((2 * m + 1) % 7 + 1)
    ).at(
        summ.at((2 * m + 5) % 7 + 1).at((2 * m + 4) % 7 + 1)
    );
    polynom.at(3) = summ.at(
        summ.at(m + 1).at((m + 1) % 7 + 1)
    ).at(
        summ.at((m + 2) % 7 + 1).at((m + 3) % 7 + 1)
    );
    polynom.at(4) = 1;
    return polynom;
}

QString Static::getFormingPolynomAns(QString h, int i, int m) {
    std::vector<int> poly = getFormingPolynom(h, i, m);
    QString ans = "";
    for (int i = 0; i < 5; i++) {
        ans += QString::number(poly.at(i));
    }
    return ans;
}

// t5 - проверочная матрица
std::vector<std::vector<int>> Static::getCheckMatrix(int m) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < 7; i++) matrix.push_back({0, 0, 0, 0});
    matrix.at(0).at(0) = 1;
    matrix.at(0).at(1) = 1;
    matrix.at(0).at(2) = 1;
    matrix.at(0).at(3) = 1;
    matrix.at(1).at(0) = (m + 0) % 7 + 1;
    matrix.at(1).at(1) = (m + 1) % 7 + 1;
    matrix.at(1).at(2) = (m + 2) % 7 + 1;
    matrix.at(1).at(3) = (m + 3) % 7 + 1;
    for (int i = 2; i < 7; i++) {
        for (int f = 0; f < 4; f++) {
            matrix.at(i).at(f) = ((matrix.at(i - 1).at(f) + matrix.at(1).at(f) + 5) % 7) + 1;
        }
    }
    return matrix;
}

// t6 - закодированная кодовая комбинация
std::vector<int> Static::getCodedCombination(QString h, int i, int m, QString f0) {
    std::vector<int> combination;
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<std::vector<int>> mu = getMultiplicationTable();
    std::vector<int> k = { QString(f0.at(0)).toInt(), QString(f0.at(1)).toInt(), QString(f0.at(2)).toInt() };
    std::vector<int> g = getFormingPolynom(h, i, m);
    combination.push_back(
        mu.at(k.at(0)).at(g.at(0))
    );
    combination.push_back(
        summ.at(
            mu.at(k.at(0)).at(g.at(1))
        ).at(
            mu.at(k.at(1)).at(g.at(0))
        )
    );
    combination.push_back(
        summ.at(
            summ.at(
                mu.at(k.at(0)).at(g.at(2))
            ).at(
                mu.at(k.at(1)).at(g.at(1))
            )
        ).at(
            mu.at(k.at(2)).at(g.at(0))
        )
    );
    combination.push_back(
        summ.at(
            summ.at(
                mu.at(k.at(0)).at(g.at(3))
            ).at(
                mu.at(k.at(1)).at(g.at(2))
            )
        ).at(
            mu.at(k.at(2)).at(g.at(1))
        )
    );
    combination.push_back(
        summ.at(
            summ.at(
                mu.at(k.at(0)).at(g.at(4))
            ).at(
                mu.at(k.at(1)).at(g.at(3))
            )
        ).at(
            mu.at(k.at(2)).at(g.at(2))
        )
    );
    combination.push_back(
        summ.at(
            mu.at(k.at(1)).at(g.at(4))
        ).at(
            mu.at(k.at(2)).at(g.at(3))
        )
    );
    combination.push_back(
        mu.at(k.at(2)).at(g.at(4))
    );
    return combination;
}

QString Static::getCodedCombinationAns(QString h, int i, int m, QString f0) {
    std::vector<int> cc = getCodedCombination(h, i, m, f0);
    int fx = cc.at(6) + 10 * cc.at(5) + 100 * cc.at(4) + 1000 * cc.at(3) +
            10000 * cc.at(2) + 100000 * cc.at(1) + 1000000 * cc.at(0);
    return fillZeroBefore(fx, 7);
}

// t7 - искаженная кодовая комбинация
std::vector<int> Static::getDistortedCodedCombination(QString h, int i, int m, QString f0, QString ep) {
    std::vector<int> fr = {0, 0, 0, 0, 0, 0, 0};
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<int> cc = getCodedCombination(h, i, m, f0);
    for (int i = 0; i < 7; i++) {
        fr.at(i) = summ.at(cc.at(i)).at(QString(ep.at(i)).toInt());
    }
    return fr;
}

QString Static::getDistortedCodedCombinationAns(QString h, int i, int m, QString f0, QString ep) {
    std::vector<int> fr = getDistortedCodedCombination(h, i, m, f0, ep);
    int frx = fr.at(6) + 10 * fr.at(5) + 100 * fr.at(4) + 1000 * fr.at(3) +
            10000 * fr.at(2) + 100000 * fr.at(1) + 1000000 * fr.at(0);
    return fillZeroBefore(frx, 7);
}

// t8 - синдром
std::vector<int> Static::getSyndrome(QString h, int i, int m, QString fe) {
    std::vector<int> syndrome = {0, 0, 0, 0};
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<std::vector<int>> mu = getMultiplicationTable();
    std::vector<std::vector<int>> matrix = getCheckMatrix(m);
    for (int i = 0; i < 4; i++) {
        syndrome.at(i) = summ.at(
            mu.at(matrix.at(0).at(i)).at(QString(fe.at(0)).toInt())
        ).at(
            mu.at(matrix.at(1).at(i)).at(QString(fe.at(1)).toInt())
        );
        for (int j = 2; j < 7; j++) {
            syndrome.at(i) = summ.at(syndrome.at(i)).at(
                mu.at(matrix.at(j).at(i)).at(QString(fe.at(j)).toInt())
            );
        }
    }
    return syndrome;
}

QString Static::getSyndromeAns(QString h, int i, int m, QString fe) {
    std::vector<int> si = getSyndrome(h, i, m, fe);
    int sx = si.at(3) + 10 * si.at(2) + 100 * si.at(1) + 1000 * si.at(0);
    return fillZeroBefore(sx, 4);
}

// t9 - полином локаторов
std::vector<int> Static::getLocatorPolynom(QString h, int i, QString ee) {
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<int> el = getErrorLocators(ee);
    int e1 = el.at(0);
    int e2 = el.at(1);
    return /* sigma */ {
        // 0
        1,
        // 1
        summ.at(e1 + 1).at(e2 + 1),
        // 2
        (e1 + e2) % 7 + 1
    };
}

QString Static::getLocatorPolynomAns(QString h, int i, QString ee) {
    std::vector<int> sigma = getLocatorPolynom(h, i, ee);
    int sigmax = sigma.at(2) + 10 * sigma.at(1) + 100 * sigma.at(0);
    return fillZeroBefore(sigmax, 3);
}

// t10 - полином величин ошибок
std::vector<int> Static::getErrorPolynom(QString h, int i, int m, QString fe, QString ee) {
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<std::vector<int>> mu = getMultiplicationTable();
    std::vector<int> sigma = getLocatorPolynom(h, i, ee);
    std::vector<int> syndrome = getSyndrome(h, i, m, fe);
    return /* w */ {
        // 0
        mu.at(sigma.at(0)).at(syndrome.at(0)),
        // 1
        summ.at(
            mu.at(sigma.at(0)).at(syndrome.at(1))
        ).at(
            mu.at(sigma.at(1)).at(syndrome.at(0))
        )
    };
}

QString Static::getErrorPolynomAns(QString h, int i, int m, QString fe, QString ee) {
    std::vector<int> w = getErrorPolynom(h, i, m, fe, ee);
    int wx = w.at(1) + 10 * w.at(0);
    return fillZeroBefore(wx, 2);
}

// t11 - корни полинома локаторов
std::vector<int> Static::getErrorLocatorPolynom(QString h, int i, QString ee) {
    std::vector<int> sig = {0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<std::vector<int>> summ = getAdditionTable(h, i);
    std::vector<int> sigma = getLocatorPolynom(h, i, ee);
    sig.at(0) = 1;
    sig.at(1) = summ.at(
        summ.at(
            ((sigma.at(2) - 1) % 7) + 1
        ).at(
            ((sigma.at(1) - 1) % 7) + 1
        )
    ).at(1);
    sig.at(2) = summ.at(
        summ.at(
            ((sigma.at(2) + 1) % 7) + 1
        ).at(
            ((sigma.at(1) + 0) % 7) + 1
        )
    ).at(1);
    sig.at(3) = summ.at(
        summ.at(
            ((sigma.at(2) + 3) % 7) + 1
        ).at(
            ((sigma.at(1) + 1) % 7) + 1
        )
    ).at(1);
    sig.at(4) = summ.at(
        summ.at(
            ((sigma.at(2) + 5) % 7) + 1
        ).at(
            ((sigma.at(1) + 2) % 7) + 1
        )
    ).at(1);
    sig.at(5) = summ.at(
        summ.at(
            ((sigma.at(2) + 0) % 7) + 1
        ).at(
            ((sigma.at(1) + 3) % 7) + 1
        )
    ).at(1);
    sig.at(6) = summ.at(
        summ.at(
            ((sigma.at(2) + 2) % 7) + 1
        ).at(
            ((sigma.at(1) + 4) % 7) + 1
        )
    ).at(1);
    sig.at(7) = summ.at(
        summ.at(
            ((sigma.at(2) + 4) % 7) + 1
        ).at(
            ((sigma.at(1) + 5) % 7) + 1
        )
    ).at(1);
    return sig;
}

// t12 - локаторы ошибок
std::vector<int>Static:: getErrorLocators(QString ee) {
    int e1, e2;
    for (int i = 0; i < 7; i++) {
        if (QString(ee.at(i)).toInt() != 0) {
            e1 = i;
            break;
        }
    }
    for (int i = 6; i >= 0; i--) {
        if (QString(ee.at(i)).toInt() != 0) {
            e2 = i;
            break;
        }
    }
    return { e1, e2 };
}

// t13 - величины ошибок
std::vector<int> Static::getErrorValues(QString ee) {
    std::vector<int> el = getErrorLocators(ee);
    int e1 = el.at(0);
    int e2 = el.at(1);
    return {
        QString(ee.at(e1)).toInt(),
        QString(ee.at(e2)).toInt()
    };
}

// t14 - найденный полином ошибок
QString Static::getFoundedErrorPolynom(QString ee) {
    return ee;
}

// t14 - исправленная КК
QString Static::getCorrectedCodeCombination(QString fu) {
    return fu;
}

// t15 - информация
QString Static::getInforamtionSeq(QString f1) {
    return f1;
}

// private

int Static::intLength(int number) {
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

QString Static::fillZeroBefore(int number, int size) {
    QString str = QString::number(number);
    int len = intLength(number);
    for (int i = 0; i < size - len; i++) {
        str = "0" + str;
    }
    return str;
}




















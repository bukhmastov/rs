#include "core.h"
#include "screen/screenwelcome.h"
#include "screen/screenabout.h"
#include "screen/screendescription.h"
#include "screen/screenquestion.h"
#include "screen/screensummary.h"
#include "task/screentask0.h"
#include "task/screentask1.h"
#include "task/screentask2.h"
#include "task/screentask3.h"
#include "task/screentask4.h"
#include "task/screentask5.h"
#include "task/screentask6.h"
#include "task/screentask7.h"
#include "task/screentask8.h"
#include "task/screentask9.h"
#include "task/screentask10.h"
#include "task/screentask11.h"
#include "task/screentask12.h"
#include "task/screentask13.h"
#include "task/screentask14.h"
#include "task/screentask15.h"

#include <iostream>
#include <chrono>
#include <algorithm>

Core::Core() {}

void Core::init(WindowController *window) {
    this->window = window;
}

void Core::generate() {
    std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    generate(msec.count());
}

void Core::generate(unsigned int seed) {
    // clear questions
    for (Question* question : this->questions) {
        delete question;
    }
    this->questions.clear();
    // clear tasks
    for (Task* task : this->tasks) {
        delete task;
    }
    this->tasks.clear();
    // reset progress
    this->questionsOrder.clear();
    this->currentTask = 0;
    this->showedTask = 0;
    this->score = Static::scoreInitial;
    this->seed = seed;
    ScreenController::clean();
    ScreenController::srnd(seed);
    // ------------------------------
    // HERE GOES DEFINITIONS OF QUESTIONS
    // EVERY QUESTION SHOULD BE ADDED TO QUESTIONS VECTOR BELOW
    // SHOULD BE MINIMUM 10 QUESTIONS
    // ------------------------------
    questions.push_back(new Question("Минимальное Хэммингово расстояние (кодовое расстояние) d<sub>min</sub>?", std::vector<QString>{"Наименьшее расстояние по Хэммингу между различными парами разрешенных кодовых комбинаций", "Наименьшее расстояние по Хэммингу между нулевой и остальными кодовыми комбинациями", "Наименьшее расстояние по Хэммингу между разрешенными и запрещенными кодовыми комбинациями", "Наименьшее расстояние по Хэммингу между нулевой и запрещенными кодовыми комбинациями"}));
    questions.push_back(new Question("Чему равно число разрешенных КК двоичного (15,7) кода?", std::vector<QString>{"128", "255", "256", "127"}));
    questions.push_back(new Question("Чему равно число запрещенных КК для блочного кода (7,3)?", std::vector<QString>{"120", "64", "32", "8"}));
    questions.push_back(new Question("Чему равна исправляющая способность двоичного кода, если d<sub>min</sub>=8?", std::vector<QString>{"3", "2", "4", "1"}));
    questions.push_back(new Question("Чему равна обнаруживающая способность кода с d<sub>min</sub>=10 в комбинированном режиме, если он исправляет двойные ошибки?", std::vector<QString>{"7", "6", "5", "4"}));
    questions.push_back(new Question("Выражение для энергетического выигрыша от кодирования (n,k)-кодом", std::vector<QString>{"W = 10lg(h<sup>2</sup>)<sub>онк</sub> - 10lg(h<sup>2</sup>)<sub>ок</sub> - 10lg(n/k)", "W = 10lg(h<sup>2</sup>)<sub>ок</sub> - 10lg(h<sup>2</sup>)<sub>онк</sub> - 10lg(n/k)", "W = 10lg(h<sup>2</sup>)<sub>онк</sub> - 10lg(h<sup>2</sup>)<sub>ок</sub> - 10lg(k/n)", "W = 10lg(h<sup>2</sup>)<sub>ок</sub> - 10lg(h<sup>2</sup>)<sub>онк</sub> - 10lg(k/n)"}));
    questions.push_back(new Question("Какой код называется циклическим кодом?", std::vector<QString>{"Если при циклическом сдвиге разрешенной КК также получаются РКК данного кода", "Если при циклическом сдвиге разрешенной КК получаются все возможные РКК данного кода", "Если при циклическом сдвиге разрешенной КК получаются все линейно независимые РКК данного кода", "Если при циклическом сдвиге разрешенной КК получаются все ненулевые РКК данного кода"}));
    questions.push_back(new Question("Какой (n,k)-код называется систематическим кодом?", std::vector<QString>{"Если информационные символы стоят на первых k позициях", "Если информационные символы стоят на первых r позициях", "Если информационные и проверочные символы невозможно отделить друг от друга", "Если проверочные символы стоят на первых k позициях"}));
    questions.push_back(new Question("Каким из перечисленных свойств обладает образующая матрица G группового кода?", std::vector<QString>{"Строки матрицы G являются линейно-независимыми", "Столбцы матрицы G являются линейно-независимыми", "Размерность матрицы G равна [k*r]", "Столбцы матрицы G образуют разрешенные КК"}));
    questions.push_back(new Question("Каким из перечисленных свойств обладает проверочная матрица H группового кода?", std::vector<QString>{"Матрица H имеет r строк и n столбцов", "Произведение разрешенной КК на матрицу H равно 0", "Размерность матрицы H равна [k*n]", "Столбцы и строки матрицы H являются линейно-независимыми"}));
    questions.push_back(new Question("Чему равна размерность единичной матрицы, входящей в состав образующей матрицы систематического вида для кода (15,7)?", std::vector<QString>{"(7*7)", "(8*8)", "(15*15)", "(7*8)"}));
    questions.push_back(new Question("Чему равна размерность единичной матрицы, входящей в состав проверочной матрицы систематического вида для кода (15,7)?", std::vector<QString>{"(8*8)", "(7*7)", "(8*7)", "(7*8)"}));
    questions.push_back(new Question("Сколько строк содержит проверочная матрица кода (15,8)?", std::vector<QString>{"7", "8", "15", "10"}));
    questions.push_back(new Question("Определение синдрома в теории помехоустойчивого кодирования", std::vector<QString>{"Это скалярное произведение принятой (разрешенной F или запрещенной F<sub>ρ</sub>) КК на транспонированную проверочную матрицу H<sup>т</sup>", "Это скалярное произведение принятой (разрешенной F или запрещенной F<sub>ρ</sub>) КК на проверочную матрицу H", "Это скалярное произведение принятой (разрешенной F или запрещенной F<sub>ρ</sub>) КК на транспонированную образующую матрицу G<sup>т</sup>", "Это скалярное произведение транспонированной проверочной матрицы H<sup>т</sup> на принятую (разрешенную F или запрещенную F<sub>ρ</sub>) комбинацию"}));
    questions.push_back(new Question("При каком условии циклический код исправляет ошибки кратности t<sub>и</sub>?", std::vector<QString>{"Для исправления ошибок кратности tи необходимо и достаточно, чтобы образующий полином имел 2t<sub>и</sub> последовательных корней", "Для исправления ошибок кратности tи необходимо и достаточно, чтобы проверочный полином имел 2t<sub>и</sub> последовательных корней", "Для исправления ошибок кратности tи необходимо и достаточно, чтобы образующий полином имел 2t<sub>и</sub>-1 последовательных корней", "Для исправления ошибок кратности tи необходимо и достаточно, чтобы проверочный полином имел 2t<sub>и</sub>-1 последовательных корней"}));
    questions.push_back(new Question("Первая строка матрицы Hc двоичного (7,4)-кода Хэмминга имеет вид 1011100. Записать уравнение для первого проверочного символа.", std::vector<QString>{"С<sub>4</sub> = С<sub>0</sub>+С<sub>2</sub>+С<sub>3</sub>", "С<sub>4</sub> = С<sub>0</sub>+С<sub>1</sub>+С<sub>2</sub>", "С<sub>4</sub> = С<sub>1</sub>+С<sub>2</sub>+С<sub>3</sub>", "С<sub>4</sub> = С<sub>0</sub>+С<sub>1</sub>+С<sub>3</sub>"}));
    questions.push_back(new Question("Чему равно число ячеек регистра сдвига при кодировании методом умножения на образующий полином циклического (15,5) кода?", std::vector<QString>{"10", "15", "5", "8"}));
    questions.push_back(new Question("В какой матрице строка соответствует разрешенной кодовой комбинации?", std::vector<QString>{"В образующей матрице", "В проверочной матрице", "В транспонированной образующей матрице", "В транспонированной проверочной матрице"}));
    questions.push_back(new Question("Сколько ненулевых синдромов может быть в двоичном циклическом (15,7) коде?", std::vector<QString>{"255", "127", "8", "7"}));
    questions.push_back(new Question("В циклическом коде значности n = 15 число разрешенных КК равно 128. Чему равна степень образующего полинома?", std::vector<QString>{"8", "7", "6", "5"}));
    questions.push_back(new Question("Выражение для образующего полинома g(x) примитивного кода БЧХ над полем GF(2<sup>s</sup>), имеющего длину n = 2<sup>s-1</sup> и исправляющего t ошибок (корнями g(x) являются элементы a<sup>1</sup>, a<sup>2</sup>,…, a<sup>2t</sup>, где a – примитивный элемент расширенного поля GF(p<sup>s</sup>))", std::vector<QString>{"g(x) = НОК[m<sub>1</sub>(x), m<sub>2</sub>(x),…, m<sub>2t</sub>(x)], где m<sub>i</sub>(x) – минимальный полином для элемента а<sup>i</sup>", "g(x) = НОК[m<sub>1</sub>(x), m<sub>2</sub>(x),…, m<sub>t</sub>(x)], где m<sub>i</sub>(x) – минимальный полином для элемента а<sup>i</sup>", "g(x) = НОК[m<sub>1</sub>(x), m<sub>2</sub>(x),…, m<sub>2t-2</sub>(x)], где m<sub>i</sub>(x) – минимальный полином для элемента а<sup>i</sup>", "g(x) = НОК[m<sub>0</sub>(x), m<sub>1</sub>(x),…, m<sub>2t-1</sub>(x)], где m<sub>i</sub>(x) – минимальный полином для элемента а<sup>i</sup>"}));
    questions.push_back(new Question("Дан образующий полином g(x)=x<sup>4</sup>+a<sup>3</sup> x<sup>3</sup>+x<sup>2</sup>+ax+a<sup>3</sup> кода РС (7,3) над полем GF(2<sup>3</sup>). Чему равен свободный коэффициент в сопряженном полиноме?", std::vector<QString>{"a<sup>4</sup>", "a<sup>3</sup>", "1", "a"}));
    questions.push_back(new Question("Чему равно минимальное кодовое расстояние для кода Рида-Соломона?", std::vector<QString>{"d<sub>min</sub> = r+1", "d<sub>min</sub> = k+1", "d<sub>min</sub> = r-1", "d<sub>min</sub> = k-1"}));
    questions.push_back(new Question("Чему равна степень образующего полинома кода Рида-Соломона, исправляющего тройные ошибки?", std::vector<QString>{"6", "9", "3", "12"}));
    questions.push_back(new Question("Чему равна исправляющая способность кода Рида-Соломона, образующий полином которого имеет степень 8?", std::vector<QString>{"4", "8", "6", "2"}));
    questions.push_back(new Question("Образующий полином РС-кода равен g(x)=x<sup>r</sup>+g<sub>r–1</sub>x<sup>r–1</sup>+...+g<sub>1</sub>x+g<sub>0</sub>, где g<sub>i</sub>  GF(p<sup>s</sup>). Определить выражение для сопряженного полинома.", std::vector<QString>{"g*(x) = x<sup>r</sup> g<sub>0</sub><sup>-1</sup> g(x<sup>-1</sup>)", "g*(x) = x<sup>r</sup> g<sub>0</sub> g(x^(-1))", "g*(x) = x<sup>k</sup> g<sub>0</sub><sup>-1</sup> g(x<sup>-1</sup>)", "g*(x) = x<sup>k</sup> g<sub>0</sub><sup>-1</sup> g(x<sup>-1</sup>)"}));
    questions.push_back(new Question("С какой строки начинается проверочная матрица (7,3) РС-кода с образующим полиномом g(x)=(x–a<sup>3</sup>)(x–a<sup>4</sup>)(x–a<sup>5</sup>)(x–a<sup>6</sup>)?", std::vector<QString>{"a<sup>0</sup> a<sup>3</sup> a<sup>6</sup> a<sup>2</sup> a<sup>5</sup> a<sup>1</sup> a<sup>4</sup>", "a<sup>0</sup> a<sup>3</sup> a<sup>4</sup> a<sup>5</sup> a<sup>6</sup> a<sup>1</sup> a<sup>2</sup>", "a<sup>0</sup> a<sup>1</sup> a<sup>2</sup> a<sup>3</sup> a<sup>4</sup> a<sup>5</sup> a<sup>6</sup>", "a<sup>0</sup> a<sup>3</sup> a<sup>2</sup> a<sup>1</sup> a<sup>6</sup> a<sup>5</sup> a<sup>4</sup>"}));
    questions.push_back(new Question("Чему равно число компонент синдрома для кода РС (15, 7)?", std::vector<QString>{"8", "7", "128", "256"}));
    questions.push_back(new Question("Чему равно число ненулевых синдромов для кода РС (15, 7)?", std::vector<QString>{"2<sup>32</sup> - 1", "2<sup>8</sup> - 1", "2<sup>15</sup> - 1", "2<sup>28</sup> - 1"}));
    questions.push_back(new Question("Определить вторую строку (начиная с нулевой) матрицы ФМС-преобразования для поля GF(2<sup>3</sup>)", std::vector<QString>{"a<sup>0</sup> a<sup>2</sup> a<sup>4</sup> a<sup>6</sup> a<sup>1</sup> a<sup>3</sup> a<sup>5</sup>", "a<sup>0</sup> a<sup>1</sup> a<sup>2</sup> a<sup>3</sup> a<sup>4</sup> a<sup>5</sup> a<sup>6</sup>", "a<sup>0</sup> a<sup>2</sup> a<sup>4</sup> a<sup>6</sup> a<sup>2</sup> a<sup>4</sup> a<sup>6</sup>", "a<sup>0</sup> a<sup>2</sup> a<sup>4</sup> a<sup>8</sup> a<sup>1</sup> a<sup>3</sup> a<sup>5</sup>"}));
    questions.push_back(new Question("Определить выражение для ключевого уравнения, связывающего синдромный полином S(x), полином локаторов ошибок Q(x) и полином величин ошибок w(х)", std::vector<QString>{"S(x)Q(x) = w(x)mod x<sup>r</sup>", "S(x)w(x) = Q(x)mod x<sup>r</sup>", "S(x)Q(x) = w(x)mod x<sup>k</sup>", "S(x)w(x) = Q(x)mod x<sup>k</sup>"}));
    questions.push_back(new Question("Чему равна максимальная степень полинома локаторов ошибок для кода РС (15, 5)?", std::vector<QString>{"5", "4", "6", "3"}));
    questions.push_back(new Question("Задан код РС (15, 7). На каких позициях произошли ошибки, если корнями полинома локаторов ошибок являются элементы b<sup>5</sup>, b<sup>0</sup>, b<sup>7</sup>, b<sup>2</sup>?", std::vector<QString>{"10, 0, 8, 13", "5, 0, 7, 2", "10, 0, 7, 2", "2, 7, 5, 0"}));
    questions.push_back(new Question("Определить производную по x по mod 2 для полинома A(x)=a<sup>4</sup> x<sup>8</sup>+a<sup>3</sup> x<sup>6</sup>+a x<sup>5</sup>+a<sup>2</sup> x<sup>4</sup>+a<sup>3</sup> x<sup>2</sup>+a<sup>6</sup>", std::vector<QString>{"ax<sup>4</sup>", "ax", "a<sup>3</sup>x<sup>4</sup>", "a<sup>3</sup>x"}));
    questions.push_back(new Question("Чему равна максимальная степень полинома локаторов ошибок для кода РС (15, 7)?", std::vector<QString>{"4", "7", "8", "2"}));
    questions.push_back(new Question("Чему равна максимальная степень полинома величин ошибок для кода РС (15, 7)?", std::vector<QString>{"3", "4", "7", "2"}));
    questions.push_back(new Question("Задан код РС (15, 7) Чему равно число различных ненулевых синдромов?", std::vector<QString>{"(2<sup>4</sup>)<sup>8</sup> - 1 = 2<sup>32</sup> - 1", "(2<sup>7</sup>)<sup>8</sup> - 1 = 2<sup>56</sup> - 1", "(2<sup>4</sup>)<sup>7</sup> - 1 = 2<sup>28</sup> - 1", "(2<sup>4</sup>)<sup>15</sup> - 1 = 2<sup>60</sup> - 1"}));
    questions.push_back(new Question("Чему равно число элементов, отличных от единицы, в матрице ФМС-преобразования над полем GF(2<sup>4</sup>)?", std::vector<QString>{"196", "128", "256", "64"}));
    // ------------------------------
    unsigned int size = questions.size() < 10 ? questions.size() : 10;
    while (true) {
        int current = rand() % questions.size();
        if (!(std::find(questionsOrder.begin(), questionsOrder.end(), current) != questionsOrder.end())) {
            questionsOrder.push_back(current);
        }
        if (questionsOrder.size() >= size) {
            break;
        }
    }
    // ------------------------------
    // HERE GOES DEFINITIONS OF TASKS
    // EVERY TASK SHOULD BE ADDED TO TASKS VECTOR BELOW
    // EVERY TASK SHOULD HAVE ITS OWN TASK BUTTON AT MainWindow.ui/h/cpp
    // TASK'S VIEWS DEFINES AT Core::getView(int id)
    // ------------------------------
    // intro part
    tasks.push_back(new Task(0,  0,  Static::worktype));
    tasks.push_back(new Task(1,  0,  Static::worktype));
    tasks.push_back(new Task(2,  0,  Static::worktype));
    // questions part
    tasks.push_back(new Task(3,  1,  "Входной контрольный опрос: вопрос 1",  false));
    tasks.push_back(new Task(4,  2,  "Входной контрольный опрос: вопрос 2",  false));
    tasks.push_back(new Task(5,  3,  "Входной контрольный опрос: вопрос 3",  false));
    tasks.push_back(new Task(6,  4,  "Входной контрольный опрос: вопрос 4",  false));
    tasks.push_back(new Task(7,  5,  "Входной контрольный опрос: вопрос 5",  false));
    tasks.push_back(new Task(8,  6,  "Входной контрольный опрос: вопрос 6",  false));
    tasks.push_back(new Task(9,  7,  "Входной контрольный опрос: вопрос 7",  false));
    tasks.push_back(new Task(10, 8,  "Входной контрольный опрос: вопрос 8",  false));
    tasks.push_back(new Task(11, 9,  "Входной контрольный опрос: вопрос 9",  false));
    tasks.push_back(new Task(12, 10, "Входной контрольный опрос: вопрос 10", false));
    // variant definition part
    tasks.push_back(new Task(13, 0,  "Исходные данные"));
    // tasks part
    tasks.push_back(new Task(14, 1,  "Построение основного расширенного поля"));
    tasks.push_back(new Task(15, 2,  "Построение автоморфизма основного поля"));
    tasks.push_back(new Task(16, 3,  "Построение таблицы сложения элементов"));
    tasks.push_back(new Task(17, 4,  "Формирование образующего полинома"));
    tasks.push_back(new Task(18, 5,  "Построение проверочной матрицы"));
    tasks.push_back(new Task(19, 6,  "Кодирование исходной последовательности"));
    tasks.push_back(new Task(20, 7,  "Искажение кодовой комбинации"));
    tasks.push_back(new Task(21, 8,  "Вычисление синдрома"));
    tasks.push_back(new Task(22, 9,  "Определение полинома локаторов"));
    tasks.push_back(new Task(23, 10, "Определение полинома величин ошибок"));
    tasks.push_back(new Task(24, 11, "Определение полинома локаторов ошибок"));
    tasks.push_back(new Task(25, 12, "Определение позиций ошибок"));
    tasks.push_back(new Task(26, 13, "Определение величин ошибок"));
    tasks.push_back(new Task(27, 14, "Исправление ошибок"));
    tasks.push_back(new Task(28, 15, "Получение исходной информационной последовательности"));
    // summary part
    tasks.push_back(new Task(99, 0, "Результат", false));
    // ------------------------------
    window->setNextEnabled(true);
    window->setResetEnabled(true);
}

ScreenController* Core::getView(int id) {
    // ------------------------------
    // HERE GOES VIEWS OF TASKS
    // EVERY TASK VIEW SHOULD BE ADDED BELOW
    // ------------------------------
    switch (id) {
        // intro part
        case 0:  return new ScreenWelcome; break;
        case 1:  return new ScreenAbout; break;
        case 2:  return new ScreenDescription; break;
        // questions part
        case 3:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(0))); break;
        case 4:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(1))); break;
        case 5:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(2))); break;
        case 6:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(3))); break;
        case 7:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(4))); break;
        case 8:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(5))); break;
        case 9:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(6))); break;
        case 10: return ScreenQuestion::get(this, questions.at(questionsOrder.at(7))); break;
        case 11: return ScreenQuestion::get(this, questions.at(questionsOrder.at(8))); break;
        case 12: return ScreenQuestion::get(this, questions.at(questionsOrder.at(9))); break;
        // variant definition part
        case 13: return new ScreenTask0;  break;
        // tasks part
        case 14: return new ScreenTask1;  break;
        case 15: return new ScreenTask2;  break;
        case 16: return new ScreenTask3;  break;
        case 17: return new ScreenTask4;  break;
        case 18: return new ScreenTask5;  break;
        case 19: return new ScreenTask6;  break;
        case 20: return new ScreenTask7;  break;
        case 21: return new ScreenTask8;  break;
        case 22: return new ScreenTask9;  break;
        case 23: return new ScreenTask10; break;
        case 24: return new ScreenTask11; break;
        case 25: return new ScreenTask12; break;
        case 26: return new ScreenTask13; break;
        case 27: return new ScreenTask14; break;
        case 28: return new ScreenTask15; break;
        // summary part
        case 99: return ScreenSummary::get(this); break;
        default: return NULL;
    }
    // ------------------------------
}

void Core::next() {
    next(false);
}

void Core::next(bool force) {
    QString message;
    if (showedTask == 0 || window->getWidget() == nullptr || window->getWidget()->validate(this, &message)) {
        if (force || (score >= 0 && showedTask < tasks.size())) {
            showedTask++;
            show(message);
        } else {
            showedTask = tasks.size() - 1;
            next(true);
        }
    }
}

void Core::back() {
    if (showedTask > 0) {
        showedTask--;
        show("");
    }
}

void Core::back(int task) {
    showedTask = task + 1;
    show("");
}

void Core::reset() {
    generate();
    next();
}

void Core::changeScore(int delta) {
    this->score += delta;
}

int Core::getScore() {
    return score;
}

void Core::show(QString message) {
    if (currentTask < showedTask) {
        currentTask = showedTask;
    }
    Task *task = tasks.at(showedTask - 1);
    window->setStep(task->getNumber(), task->getTitle());
    window->setCurrentTask(showedTask - 1, currentTask - 1);
    window->setScore(score);
    window->setMessage(message);
    window->setWidget(getView(task->getId())->init(task->getId(), currentTask != showedTask));
    window->setNextEnabled(currentTask == showedTask ? task->getNextButtonActive() : false);
}

unsigned int Core::getSeed() {
    return seed;
}

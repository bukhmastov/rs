#ifndef SCREENTASK10_H
#define SCREENTASK10_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask10;
}

class ScreenTask10 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10(QWidget *parent = 0);
    ~ScreenTask10();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask10 *ui;
};

#endif // SCREENTASK10_H

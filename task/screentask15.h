#ifndef SCREENTASK15_H
#define SCREENTASK15_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask15;
}

class ScreenTask15 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask15(QWidget *parent = 0);
    ~ScreenTask15();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask15 *ui;
};

#endif // SCREENTASK15_H

#ifndef SCREENTASK14_H
#define SCREENTASK14_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask14;
}

class ScreenTask14 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask14(QWidget *parent = 0);
    ~ScreenTask14();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask14 *ui;
};

#endif // SCREENTASK14_H

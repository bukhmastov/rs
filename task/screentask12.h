#ifndef SCREENTASK12_H
#define SCREENTASK12_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask12;
}

class ScreenTask12 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask12(QWidget *parent = 0);
    ~ScreenTask12();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask12 *ui;
};

#endif // SCREENTASK12_H

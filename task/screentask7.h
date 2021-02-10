#ifndef SCREENTASK7_H
#define SCREENTASK7_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask7;
}

class ScreenTask7 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask7(QWidget *parent = 0);
    ~ScreenTask7();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask7 *ui;
};

#endif // SCREENTASK7_H

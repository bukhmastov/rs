#ifndef SCREENTASK13_H
#define SCREENTASK13_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask13;
}

class ScreenTask13 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask13(QWidget *parent = 0);
    ~ScreenTask13();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask13 *ui;
};

#endif // SCREENTASK13_H

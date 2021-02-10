#ifndef SCREENTASK0_H
#define SCREENTASK0_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask0;
}

class ScreenTask0 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask0(QWidget *parent = 0);
    ~ScreenTask0();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask0 *ui;
    QString labelM;
    QString labelI;
    QString labelPIX;
    QString labelF0;
    QString labelEp;
    QString labelFe;

private slots:
    void variantSelected(int index);
};

#endif // SCREENTASK0_H

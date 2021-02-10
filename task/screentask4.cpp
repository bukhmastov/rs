#include "screentask4.h"
#include "ui_screentask4.h"

ScreenTask4::ScreenTask4(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask4){
    ui->setupUi(this);
}

ScreenTask4::~ScreenTask4() {
    delete ui;
}

void ScreenTask4::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    if (readOnly) {
        QString polynom = Static::getFormingPolynomAns(h, i, m);
        ui->input->setText(polynom);
    }
}

bool ScreenTask4::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString polynom = Static::getFormingPolynomAns(h, i, m);
    if (ui->input->text() == polynom) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

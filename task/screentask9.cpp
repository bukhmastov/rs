#include "screentask9.h"
#include "ui_screentask9.h"

ScreenTask9::ScreenTask9(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask9){
    ui->setupUi(this);
}

ScreenTask9::~ScreenTask9() {
    delete ui;
}

void ScreenTask9::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    QString ee = Static::getVee(variant);
    if (readOnly) {
        QString polynom = Static::getLocatorPolynomAns(h, i, ee);
        ui->input->setText(polynom);
    }
}

bool ScreenTask9::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    QString ee = Static::getVee(variant);
    QString polynom = Static::getLocatorPolynomAns(h, i, ee);
    if (ui->input->text() == polynom) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

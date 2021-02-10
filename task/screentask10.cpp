#include "screentask10.h"
#include "ui_screentask10.h"

ScreenTask10::ScreenTask10(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10){
    ui->setupUi(this);
}

ScreenTask10::~ScreenTask10() {
    delete ui;
}

void ScreenTask10::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString fe = Static::getVfe(variant);
    QString ee = Static::getVee(variant);
    if (readOnly) {
        QString polynom = Static::getErrorPolynomAns(h, i, m, fe, ee);
        ui->input->setText(polynom);
    }
}

bool ScreenTask10::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString fe = Static::getVfe(variant);
    QString ee = Static::getVee(variant);
    QString polynom = Static::getErrorPolynomAns(h, i, m, fe, ee);
    if (ui->input->text() == polynom) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

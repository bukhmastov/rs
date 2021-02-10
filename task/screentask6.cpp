#include "screentask6.h"
#include "ui_screentask6.h"

ScreenTask6::ScreenTask6(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask6){
    ui->setupUi(this);
}

ScreenTask6::~ScreenTask6() {
    delete ui;
}

void ScreenTask6::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString f0 = Static::getVf0(variant);
    if (readOnly) {
        QString coded = Static::getCodedCombinationAns(h, i, m, f0);
        ui->input->setText(coded);
    }
}

bool ScreenTask6::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString f0 = Static::getVf0(variant);
    QString coded = Static::getCodedCombinationAns(h, i, m, f0);
    if (ui->input->text() == coded) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

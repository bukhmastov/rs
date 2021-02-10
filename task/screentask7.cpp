#include "screentask7.h"
#include "ui_screentask7.h"

ScreenTask7::ScreenTask7(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask7){
    ui->setupUi(this);
}

ScreenTask7::~ScreenTask7() {
    delete ui;
}

void ScreenTask7::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString f0 = Static::getVf0(variant);
    QString ep = Static::getVep(variant);
    if (readOnly) {
        QString coded = Static::getDistortedCodedCombinationAns(h, i, m, f0, ep);
        ui->input->setText(coded);
    }
}

bool ScreenTask7::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString f0 = Static::getVf0(variant);
    QString ep = Static::getVep(variant);
    QString coded = Static::getDistortedCodedCombinationAns(h, i, m, f0, ep);
    if (ui->input->text() == coded) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

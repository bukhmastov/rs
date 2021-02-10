#include "screentask15.h"
#include "ui_screentask15.h"

ScreenTask15::ScreenTask15(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask15){
    ui->setupUi(this);
}

ScreenTask15::~ScreenTask15() {
    delete ui;
}

void ScreenTask15::init() {
    QString variant = ScreenController::store["variant"];
    QString f1 = Static::getVf1(variant);
    if (readOnly) {
        QString seq = Static::getInforamtionSeq(f1);
        ui->input->setText(seq);
    }
}

bool ScreenTask15::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString f1 = Static::getVf1(variant);
    QString seq = Static::getInforamtionSeq(f1);
    if (ui->input->text() == seq) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

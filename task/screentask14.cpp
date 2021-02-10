#include "screentask14.h"
#include "ui_screentask14.h"

ScreenTask14::ScreenTask14(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask14){
    ui->setupUi(this);
}

ScreenTask14::~ScreenTask14() {
    delete ui;
}

void ScreenTask14::init() {
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    QString fu = Static::getVfu(variant);
    if (readOnly) {
        QString found = Static::getFoundedErrorPolynom(ee);
        QString corrected = Static::getCorrectedCodeCombination(fu);
        ui->input0->setText(found);
        ui->input1->setText(corrected);
    }
}

bool ScreenTask14::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    QString fu = Static::getVfu(variant);
    QString found = Static::getFoundedErrorPolynom(ee);
    QString corrected = Static::getCorrectedCodeCombination(fu);
    if (
        ui->input0->text() == found &&
        ui->input1->text() == corrected
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

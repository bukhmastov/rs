#include "screentask12.h"
#include "ui_screentask12.h"

ScreenTask12::ScreenTask12(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask12){
    ui->setupUi(this);
}

ScreenTask12::~ScreenTask12() {
    delete ui;
}

void ScreenTask12::init() {
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    if (readOnly) {
        std::vector<int> locator = Static::getErrorLocators(ee);
        ui->input0->setText(QString::number(locator.at(0)));
        ui->input1->setText(QString::number(locator.at(1)));
    }
}

bool ScreenTask12::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    std::vector<int> locator = Static::getErrorLocators(ee);
    if (
        ui->input0->text() == QString::number(locator.at(0)) &&
        ui->input1->text() == QString::number(locator.at(1))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

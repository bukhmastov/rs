#include "screentask13.h"
#include "ui_screentask13.h"

ScreenTask13::ScreenTask13(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask13){
    ui->setupUi(this);
}

ScreenTask13::~ScreenTask13() {
    delete ui;
}

void ScreenTask13::init() {
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    if (readOnly) {
        std::vector<int> values = Static::getErrorValues(ee);
        ui->input0->setText(QString::number(values.at(0)));
        ui->input1->setText(QString::number(values.at(1)));
    }
}

bool ScreenTask13::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString ee = Static::getVee(variant);
    std::vector<int> values = Static::getErrorValues(ee);
    if (
        ui->input0->text() == QString::number(values.at(0)) &&
        ui->input1->text() == QString::number(values.at(1))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

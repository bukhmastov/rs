#include "screentask1.h"
#include "ui_screentask1.h"

ScreenTask1::ScreenTask1(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask1) {
    ui->setupUi(this);
}

ScreenTask1::~ScreenTask1() {
    delete ui;
}

void ScreenTask1::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    ui->title->setText(ui->title->text().replace("%h%", Static::getReadablePolynom(h)));
    if (readOnly) {
        std::vector<QString> field = Static::getGaluaField1(h);
        ui->inputA0->setText(field.at(0));
        ui->inputA1->setText(field.at(1));
        ui->inputA2->setText(field.at(2));
        ui->inputA3->setText(field.at(3));
        ui->inputA4->setText(field.at(4));
        ui->inputA5->setText(field.at(5));
        ui->inputA6->setText(field.at(6));
        ui->inputA0->setReadOnly(true);
        ui->inputA1->setReadOnly(true);
        ui->inputA2->setReadOnly(true);
        ui->inputA3->setReadOnly(true);
        ui->inputA4->setReadOnly(true);
        ui->inputA5->setReadOnly(true);
        ui->inputA6->setReadOnly(true);
    }
}

bool ScreenTask1::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    std::vector<QString> field = Static::getGaluaField1(h);
    if (
        ui->inputA0->text() == field.at(0) &&
        ui->inputA1->text() == field.at(1) &&
        ui->inputA2->text() == field.at(2) &&
        ui->inputA3->text() == field.at(3) &&
        ui->inputA4->text() == field.at(4) &&
        ui->inputA5->text() == field.at(5) &&
        ui->inputA6->text() == field.at(6)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

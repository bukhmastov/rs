#include "screentask2.h"
#include "ui_screentask2.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    ui->title->setText(ui->title->text()
       .replace("%h%", Static::getReadablePolynom(h))
       .replace("%i%", QString::number(i))
    );
    if (readOnly) {
        std::vector<QString> field = Static::getGaluaFieldI(h, i);
        ui->inputB0->setText(field.at(0));
        ui->inputB1->setText(field.at(1));
        ui->inputB2->setText(field.at(2));
        ui->inputB3->setText(field.at(3));
        ui->inputB4->setText(field.at(4));
        ui->inputB5->setText(field.at(5));
        ui->inputB6->setText(field.at(6));
        ui->inputB0->setReadOnly(true);
        ui->inputB1->setReadOnly(true);
        ui->inputB2->setReadOnly(true);
        ui->inputB3->setReadOnly(true);
        ui->inputB4->setReadOnly(true);
        ui->inputB5->setReadOnly(true);
        ui->inputB6->setReadOnly(true);
    }
}

bool ScreenTask2::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    std::vector<QString> field = Static::getGaluaFieldI(h, i);
    if (
        ui->inputB0->text() == field.at(0) &&
        ui->inputB1->text() == field.at(1) &&
        ui->inputB2->text() == field.at(2) &&
        ui->inputB3->text() == field.at(3) &&
        ui->inputB4->text() == field.at(4) &&
        ui->inputB5->text() == field.at(5) &&
        ui->inputB6->text() == field.at(6)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

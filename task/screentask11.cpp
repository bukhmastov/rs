#include "screentask11.h"
#include "ui_screentask11.h"

ScreenTask11::ScreenTask11(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask11){
    ui->setupUi(this);
}

ScreenTask11::~ScreenTask11() {
    delete ui;
}

void ScreenTask11::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    QString ee = Static::getVee(variant);
    if (readOnly) {
        std::vector<int> sigma = Static::getErrorLocatorPolynom(h, i, ee);
        ui->input0->setText(QString::number(sigma.at(0)));
        ui->input1->setText(QString::number(sigma.at(1)));
        ui->input2->setText(QString::number(sigma.at(2)));
        ui->input3->setText(QString::number(sigma.at(3)));
        ui->input4->setText(QString::number(sigma.at(4)));
        ui->input5->setText(QString::number(sigma.at(5)));
        ui->input6->setText(QString::number(sigma.at(6)));
        ui->input7->setText(QString::number(sigma.at(7)));
    }
}

bool ScreenTask11::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    QString ee = Static::getVee(variant);
    std::vector<int> sigma = Static::getErrorLocatorPolynom(h, i, ee);
    if (
        ui->input0->text() == QString::number(sigma.at(0)) &&
        ui->input1->text() == QString::number(sigma.at(1)) &&
        ui->input2->text() == QString::number(sigma.at(2)) &&
        ui->input3->text() == QString::number(sigma.at(3)) &&
        ui->input4->text() == QString::number(sigma.at(4)) &&
        ui->input5->text() == QString::number(sigma.at(5)) &&
        ui->input6->text() == QString::number(sigma.at(6)) &&
        ui->input7->text() == QString::number(sigma.at(7))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

#include "screentask8.h"
#include "ui_screentask8.h"

ScreenTask8::ScreenTask8(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8){
    ui->setupUi(this);
}

ScreenTask8::~ScreenTask8() {
    delete ui;
}

void ScreenTask8::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString fe = Static::getVfe(variant);
    ui->title->setText(ui->title->text().replace("%fe%", fe));
    if (readOnly) {
        QString syndrome = Static::getSyndromeAns(h, i, m, fe);
        ui->input->setText(syndrome);
    }
}

bool ScreenTask8::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    int m = Static::getVm(variant);
    QString fe = Static::getVfe(variant);
    QString syndrome = Static::getSyndromeAns(h, i, m, fe);
    if (ui->input->text() == syndrome) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

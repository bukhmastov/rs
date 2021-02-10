#include "screentask5.h"
#include "ui_screentask5.h"

ScreenTask5::ScreenTask5(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask5){
    ui->setupUi(this);
}

ScreenTask5::~ScreenTask5() {
    delete ui;
}

void ScreenTask5::init() {
    QString variant = ScreenController::store["variant"];
    int m = Static::getVm(variant);
    if (readOnly) {
        std::vector<std::vector<int>> matrix = Static::getCheckMatrix(m);
        ui->input11->setText(QString::number(matrix.at(0).at(0)));
        ui->input12->setText(QString::number(matrix.at(1).at(0)));
        ui->input13->setText(QString::number(matrix.at(2).at(0)));
        ui->input14->setText(QString::number(matrix.at(3).at(0)));
        ui->input15->setText(QString::number(matrix.at(4).at(0)));
        ui->input16->setText(QString::number(matrix.at(5).at(0)));
        ui->input17->setText(QString::number(matrix.at(6).at(0)));
        ui->input21->setText(QString::number(matrix.at(0).at(1)));
        ui->input22->setText(QString::number(matrix.at(1).at(1)));
        ui->input23->setText(QString::number(matrix.at(2).at(1)));
        ui->input24->setText(QString::number(matrix.at(3).at(1)));
        ui->input25->setText(QString::number(matrix.at(4).at(1)));
        ui->input26->setText(QString::number(matrix.at(5).at(1)));
        ui->input27->setText(QString::number(matrix.at(6).at(1)));
        ui->input31->setText(QString::number(matrix.at(0).at(2)));
        ui->input32->setText(QString::number(matrix.at(1).at(2)));
        ui->input33->setText(QString::number(matrix.at(2).at(2)));
        ui->input34->setText(QString::number(matrix.at(3).at(2)));
        ui->input35->setText(QString::number(matrix.at(4).at(2)));
        ui->input36->setText(QString::number(matrix.at(5).at(2)));
        ui->input37->setText(QString::number(matrix.at(6).at(2)));
        ui->input41->setText(QString::number(matrix.at(0).at(3)));
        ui->input42->setText(QString::number(matrix.at(1).at(3)));
        ui->input43->setText(QString::number(matrix.at(2).at(3)));
        ui->input44->setText(QString::number(matrix.at(3).at(3)));
        ui->input45->setText(QString::number(matrix.at(4).at(3)));
        ui->input46->setText(QString::number(matrix.at(5).at(3)));
        ui->input47->setText(QString::number(matrix.at(6).at(3)));
    }
}

bool ScreenTask5::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    int m = Static::getVm(variant);
    std::vector<std::vector<int>> matrix = Static::getCheckMatrix(m);
    if (
        ui->input11->text() == QString::number(matrix.at(0).at(0)) &&
        ui->input12->text() == QString::number(matrix.at(1).at(0)) &&
        ui->input13->text() == QString::number(matrix.at(2).at(0)) &&
        ui->input14->text() == QString::number(matrix.at(3).at(0)) &&
        ui->input15->text() == QString::number(matrix.at(4).at(0)) &&
        ui->input16->text() == QString::number(matrix.at(5).at(0)) &&
        ui->input17->text() == QString::number(matrix.at(6).at(0)) &&
        ui->input21->text() == QString::number(matrix.at(0).at(1)) &&
        ui->input22->text() == QString::number(matrix.at(1).at(1)) &&
        ui->input23->text() == QString::number(matrix.at(2).at(1)) &&
        ui->input24->text() == QString::number(matrix.at(3).at(1)) &&
        ui->input25->text() == QString::number(matrix.at(4).at(1)) &&
        ui->input26->text() == QString::number(matrix.at(5).at(1)) &&
        ui->input27->text() == QString::number(matrix.at(6).at(1)) &&
        ui->input31->text() == QString::number(matrix.at(0).at(2)) &&
        ui->input32->text() == QString::number(matrix.at(1).at(2)) &&
        ui->input33->text() == QString::number(matrix.at(2).at(2)) &&
        ui->input34->text() == QString::number(matrix.at(3).at(2)) &&
        ui->input35->text() == QString::number(matrix.at(4).at(2)) &&
        ui->input36->text() == QString::number(matrix.at(5).at(2)) &&
        ui->input37->text() == QString::number(matrix.at(6).at(2)) &&
        ui->input41->text() == QString::number(matrix.at(0).at(3)) &&
        ui->input42->text() == QString::number(matrix.at(1).at(3)) &&
        ui->input43->text() == QString::number(matrix.at(2).at(3)) &&
        ui->input44->text() == QString::number(matrix.at(3).at(3)) &&
        ui->input45->text() == QString::number(matrix.at(4).at(3)) &&
        ui->input46->text() == QString::number(matrix.at(5).at(3)) &&
        ui->input47->text() == QString::number(matrix.at(6).at(3))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}


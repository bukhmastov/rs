#include "screentask3.h"
#include "ui_screentask3.h"

ScreenTask3::ScreenTask3(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask3){
    ui->setupUi(this);
}

ScreenTask3::~ScreenTask3() {
    delete ui;
}

void ScreenTask3::init() {
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    if (readOnly) {
        std::vector<std::vector<int>> summ = Static::getAdditionTable(h, i);
        ui->input11->setText(QString::number(summ.at(1).at(1)));
        ui->input12->setText(QString::number(summ.at(1).at(2)));
        ui->input13->setText(QString::number(summ.at(1).at(3)));
        ui->input14->setText(QString::number(summ.at(1).at(4)));
        ui->input15->setText(QString::number(summ.at(1).at(5)));
        ui->input16->setText(QString::number(summ.at(1).at(6)));
        ui->input17->setText(QString::number(summ.at(1).at(7)));
        ui->input21->setText(QString::number(summ.at(2).at(1)));
        ui->input22->setText(QString::number(summ.at(2).at(2)));
        ui->input23->setText(QString::number(summ.at(2).at(3)));
        ui->input24->setText(QString::number(summ.at(2).at(4)));
        ui->input25->setText(QString::number(summ.at(2).at(5)));
        ui->input26->setText(QString::number(summ.at(2).at(6)));
        ui->input27->setText(QString::number(summ.at(2).at(7)));
        ui->input31->setText(QString::number(summ.at(3).at(1)));
        ui->input32->setText(QString::number(summ.at(3).at(2)));
        ui->input33->setText(QString::number(summ.at(3).at(3)));
        ui->input34->setText(QString::number(summ.at(3).at(4)));
        ui->input35->setText(QString::number(summ.at(3).at(5)));
        ui->input36->setText(QString::number(summ.at(3).at(6)));
        ui->input37->setText(QString::number(summ.at(3).at(7)));
        ui->input41->setText(QString::number(summ.at(4).at(1)));
        ui->input42->setText(QString::number(summ.at(4).at(2)));
        ui->input43->setText(QString::number(summ.at(4).at(3)));
        ui->input44->setText(QString::number(summ.at(4).at(4)));
        ui->input45->setText(QString::number(summ.at(4).at(5)));
        ui->input46->setText(QString::number(summ.at(4).at(6)));
        ui->input47->setText(QString::number(summ.at(4).at(7)));
        ui->input51->setText(QString::number(summ.at(5).at(1)));
        ui->input52->setText(QString::number(summ.at(5).at(2)));
        ui->input53->setText(QString::number(summ.at(5).at(3)));
        ui->input54->setText(QString::number(summ.at(5).at(4)));
        ui->input55->setText(QString::number(summ.at(5).at(5)));
        ui->input56->setText(QString::number(summ.at(5).at(6)));
        ui->input57->setText(QString::number(summ.at(5).at(7)));
        ui->input61->setText(QString::number(summ.at(6).at(1)));
        ui->input62->setText(QString::number(summ.at(6).at(2)));
        ui->input63->setText(QString::number(summ.at(6).at(3)));
        ui->input64->setText(QString::number(summ.at(6).at(4)));
        ui->input65->setText(QString::number(summ.at(6).at(5)));
        ui->input66->setText(QString::number(summ.at(6).at(6)));
        ui->input67->setText(QString::number(summ.at(6).at(7)));
        ui->input71->setText(QString::number(summ.at(7).at(1)));
        ui->input72->setText(QString::number(summ.at(7).at(2)));
        ui->input73->setText(QString::number(summ.at(7).at(3)));
        ui->input74->setText(QString::number(summ.at(7).at(4)));
        ui->input75->setText(QString::number(summ.at(7).at(5)));
        ui->input76->setText(QString::number(summ.at(7).at(6)));
        ui->input77->setText(QString::number(summ.at(7).at(7)));
    }
}

bool ScreenTask3::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    QString variant = ScreenController::store["variant"];
    QString h = Static::getVpix(variant);
    int i = Static::getVi(variant);
    std::vector<std::vector<int>> summ = Static::getAdditionTable(h, i);
    if (
        ui->input11->text() == QString::number(summ.at(1).at(1)) &&
        ui->input12->text() == QString::number(summ.at(1).at(2)) &&
        ui->input13->text() == QString::number(summ.at(1).at(3)) &&
        ui->input14->text() == QString::number(summ.at(1).at(4)) &&
        ui->input15->text() == QString::number(summ.at(1).at(5)) &&
        ui->input16->text() == QString::number(summ.at(1).at(6)) &&
        ui->input17->text() == QString::number(summ.at(1).at(7)) &&
        ui->input21->text() == QString::number(summ.at(2).at(1)) &&
        ui->input22->text() == QString::number(summ.at(2).at(2)) &&
        ui->input23->text() == QString::number(summ.at(2).at(3)) &&
        ui->input24->text() == QString::number(summ.at(2).at(4)) &&
        ui->input25->text() == QString::number(summ.at(2).at(5)) &&
        ui->input26->text() == QString::number(summ.at(2).at(6)) &&
        ui->input27->text() == QString::number(summ.at(2).at(7)) &&
        ui->input31->text() == QString::number(summ.at(3).at(1)) &&
        ui->input32->text() == QString::number(summ.at(3).at(2)) &&
        ui->input33->text() == QString::number(summ.at(3).at(3)) &&
        ui->input34->text() == QString::number(summ.at(3).at(4)) &&
        ui->input35->text() == QString::number(summ.at(3).at(5)) &&
        ui->input36->text() == QString::number(summ.at(3).at(6)) &&
        ui->input37->text() == QString::number(summ.at(3).at(7)) &&
        ui->input41->text() == QString::number(summ.at(4).at(1)) &&
        ui->input42->text() == QString::number(summ.at(4).at(2)) &&
        ui->input43->text() == QString::number(summ.at(4).at(3)) &&
        ui->input44->text() == QString::number(summ.at(4).at(4)) &&
        ui->input45->text() == QString::number(summ.at(4).at(5)) &&
        ui->input46->text() == QString::number(summ.at(4).at(6)) &&
        ui->input47->text() == QString::number(summ.at(4).at(7)) &&
        ui->input51->text() == QString::number(summ.at(5).at(1)) &&
        ui->input52->text() == QString::number(summ.at(5).at(2)) &&
        ui->input53->text() == QString::number(summ.at(5).at(3)) &&
        ui->input54->text() == QString::number(summ.at(5).at(4)) &&
        ui->input55->text() == QString::number(summ.at(5).at(5)) &&
        ui->input56->text() == QString::number(summ.at(5).at(6)) &&
        ui->input57->text() == QString::number(summ.at(5).at(7)) &&
        ui->input61->text() == QString::number(summ.at(6).at(1)) &&
        ui->input62->text() == QString::number(summ.at(6).at(2)) &&
        ui->input63->text() == QString::number(summ.at(6).at(3)) &&
        ui->input64->text() == QString::number(summ.at(6).at(4)) &&
        ui->input65->text() == QString::number(summ.at(6).at(5)) &&
        ui->input66->text() == QString::number(summ.at(6).at(6)) &&
        ui->input67->text() == QString::number(summ.at(6).at(7)) &&
        ui->input71->text() == QString::number(summ.at(7).at(1)) &&
        ui->input72->text() == QString::number(summ.at(7).at(2)) &&
        ui->input73->text() == QString::number(summ.at(7).at(3)) &&
        ui->input74->text() == QString::number(summ.at(7).at(4)) &&
        ui->input75->text() == QString::number(summ.at(7).at(5)) &&
        ui->input76->text() == QString::number(summ.at(7).at(6)) &&
        ui->input77->text() == QString::number(summ.at(7).at(7))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}

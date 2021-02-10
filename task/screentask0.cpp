#include "screentask0.h"
#include "ui_screentask0.h"

ScreenTask0::ScreenTask0(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask0) {
    ui->setupUi(this);
}

ScreenTask0::~ScreenTask0() {
    delete ui;
}

void ScreenTask0::init() {

    labelM = ui->labelM->text();
    labelI = ui->labelI->text();
    labelPIX = ui->labelPIX->text();
    labelF0 = ui->labelF0->text();
    labelEp = ui->labelEp->text();
    labelFe = ui->labelFe->text();

    for (int i = 1; i <= 50; i++) {
        ui->variant->addItem(QString::number(i));
    }

    if (Static::allowSelectVariant) {
        if (readOnly) {
            int variant = ScreenController::store["variant"].toInt();
            ui->variant->setCurrentIndex(variant);
            ui->variant->setEnabled(false);
            variantSelected(variant);
        } else {
            QObject::connect(ui->variant, SIGNAL(currentIndexChanged(int)), this, SLOT(variantSelected(int)));
            ui->variant->setCurrentIndex(0);
            variantSelected(0);
        }
    } else {
        int variant = rnd() % 50;
        variantSelected(variant);
        ui->variant->setCurrentIndex(variant);
        ui->variant->setEnabled(false);
        Static::clearLayout(ui->variantChooserContainerContent);
        Static::clearLayout(ui->variantChooserContainer);
    }
}

void ScreenTask0::variantSelected(int index) {
    QString variant = QString::number(index);
    ScreenController::store["variant"] = variant;
    ui->labelM->setText(QString(labelM).replace("%m%",QString::number(Static::getVm(variant))));
    ui->labelI->setText(QString(labelI).replace("%i%", QString::number(Static::getVi(variant))));
    ui->labelPIX->setText(QString(labelPIX).replace("%pix%", Static::getVpix(variant)));
    ui->labelF0->setText(QString(labelF0).replace("%f0%", Static::getVf0(variant)));
    ui->labelEp->setText(QString(labelEp).replace("%ep%", Static::getVep(variant)));
    ui->labelFe->setText(QString(labelFe).replace("%fe%", Static::getVfe(variant)));
}

bool ScreenTask0::validate(Core*, QString*) {
    return true;
}

#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QLineEdit>
//std::srand(static_cast<unsigned int>(time(nullptr)));
int mojiBrojevi[] = {0};
int randNumber[7];
int j,i;
//srand(time(NULL));
int selectedCount ;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->Button1, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button2, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button3, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button4, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button5, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button6, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button7, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button8, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button9, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button10, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button11, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button12, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button13, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button14, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button15, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button16, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button17, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button18, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button19, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button20, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button21, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button22, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button23, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button24, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button25, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button26, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button27, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button28, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button29, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button30, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button31, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button32, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button33, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button34, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button35, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button36, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button37, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button38, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button39, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button40, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button41, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button42, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button43, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button44, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button45, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button46, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button47, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
    connect(ui->Button48, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(on_resetButton_clicked()));
}

void Dialog::onRadioButtonClicked(bool checked)
{
    QRadioButton* radioButton = qobject_cast<QRadioButton*>(sender());

    if (radioButton) {
        int buttonNumber = radioButton->objectName().remove("Button").toInt();
        if (buttonNumber >= 1 && buttonNumber <= 48) {
            if (checked) {
//                 Dugme je pritisnuto
                if (selectedCount < 7) {
                    mojiBrojevi[selectedCount] = buttonNumber;
                    selectedCount++;
                }
                else {
                    radioButton->setChecked(false);
                    QMessageBox::warning(this, "Upozorenje", "Možete odabrati samo 7 brojeva.");
                }

            }
            else {
                // Dugme je odkliknuto
                for (int i = 0; i < selectedCount; i++) {
                    if (mojiBrojevi[i] == buttonNumber) {
                        // Pronađen broj u nizu, pomaknite preostale brojeve unazad
                        for (int j = i; j < selectedCount - 1; j++) {
                            mojiBrojevi[j] = mojiBrojevi[j - 1];
                        }
                        mojiBrojevi[selectedCount - 1] = 0; // Postavite poslednji element na 0
                            selectedCount--;
                        break;
                    }
                }
            }
        }
    }
}

Dialog::~Dialog()
{
    delete ui;
}






void Dialog::on_pushButton_clicked()
{

    if (selectedCount < 7) {
            // Manje od 7 brojeva je odabrano, prikaži poruku
            QMessageBox::warning(this, "Upozorenje", "Odaberite tačno 7 brojeva.");
        }
        else if (selectedCount == 7)
    {
           // Tačno 7 brojeva je odabrano, izvrši funkcionalnost

            // Pre izvršenja funkcionalnosti, možete onemogućiti radio dugmad
            for (int i = 0; i < 48; ++i) {
                QRadioButton* radioButton = findChild<QRadioButton*>(QString("Button%1").arg(i + 1));
                if (radioButton) {
                    radioButton->setEnabled(false);
                }
            }
            // Blokiramo startButton i izbacuje poruku da je izabrano 7 brojeva
            ui->startButton->setEnabled(false);
            QMessageBox::warning(this, "Upozorenje", "izabrali ste tačno 7 brojeva.");

           for(int i = 0; i < 7; i++)
            {
                int randNum;
                bool unique;
              do
              {
                    unique = true;
                    randNum = (rand() %48) + 1;


                    for(int j = 0; j < i ; j++)
                    {
                        if(randNumber[j] == randNum)
                        {
                            unique = false;
                            break;
                        }
                    }
                }while(!unique);

                randNumber[i] = randNum;
             }
           for(int i = 0; i < 7; i++)
           {
               QString lineEditName = QString("lineEdit%1").arg(i + 1);
               QLineEdit* lineEdit = findChild<QLineEdit*>(lineEditName);

               if(lineEdit)
               {
                   lineEdit->setText(QString::number(randNumber[i]));
               }
           }

      this->repaint();
    }


}





void Dialog::on_resetButton_clicked()
{
    // Omogući ponovno korišćenje radio dugmadi
       for (int i = 0; i < 48; ++i) {
           QRadioButton* radioButton = findChild<QRadioButton*>(QString("Button%1").arg(i + 1));
           if (radioButton) {
               radioButton->setEnabled(true);
               radioButton->setChecked(false);
           }
       }

       for(int i = 0; i < 7; i++)
       {
           QString lineEditName = QString("lineEdit%1").arg(i + 1);
           QLineEdit* lineEdit = findChild<QLineEdit*>(lineEditName);

           if(lineEdit)
           {
               lineEdit->clear();
           }
       }

       ui->startButton->setEnabled(true);

       // Resetuj selectedCount na 0
       selectedCount = 0;

}

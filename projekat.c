// dialog.cpp

#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

int mojiBrojevi[] = {0};
int randNumber[7];
int j,i;
srand(time(NULL));


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Povežite svako radio dugme sa odgovarajućim slotom
    for (int i = 0; i < 48; ++i) {
        QRadioButton* radioButton = findChild<QRadioButton*>(QString("radioButton%1").arg(i + 1));
        if (radioButton) {
            connect(radioButton, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClicked(bool)));
        }
    }

    // Povežite dugme "Start" sa slotom za provjeru brojeva
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));

    // 

    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(onResetButtonClicked()));

    // Inicijalizujte niz mojiBrojevi na 0

}

void Dialog::onRadioButtonClicked(bool checked)
{
    QRadioButton* radioButton = qobject_cast<QRadioButton*>(sender());

    if (radioButton) {
        int buttonNumber = radioButton->objectName().remove("radioButton").toInt();
        if (buttonNumber >= 1 && buttonNumber <= 48) {
            if (checked) {
                // Dugme je pritisnuto
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

void Dialog::onStartButtonClicked()
{
    if (selectedCount < 7) {
        // Manje od 7 brojeva je odabrano, prikaži poruku
        QMessageBox::warning(this, "Upozorenje", "Odaberite tačno 7 brojeva.");
    }
    else if (selectedCount == 7) {
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
        //ui->messageLabel->setText("Izabrano 7 brojeva. Možete nastaviti sa funkcionalnošću.");
        
        for(int i = 0; i < 7; i++)
        {
            randNumber[i] = (rand() % 48) + 1;
            for(int j = 0; j < 7; i++)
            {
              if(randNumber[i] == randNumber[j])
              {
                randNumber[i] = (rand() % 48) + 1;
                j = 0;
              }
            }
        }
        
        
        
    }


void Dialog::onResetButtonClicked()
{
    // Omogući ponovno korišćenje radio dugmadi
    for (int i = 0; i < 48; ++i) {
        QRadioButton* radioButton = findChild<QRadioButton*>(QString("Button%1").arg(i + 1));
        if (radioButton) {
            radioButton->setEnabled(true);
        }
    }
    
    ui->startButton->setEnabled(true);
    
    // Resetuj selectedCount na 0
    selectedCount = 0;

    // Očistite poruku (ako postoji)
    ui->messageLabel->clear();
}

}

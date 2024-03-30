#include "heading.hpp"

void HealthPotion(Potions& potion, Warrior& warrior, Wizard& wizard, Healer& healer) {
    unsigned int ChoiceCharacterForHeal;

    if (potion.NumsOfPotions > 0) {
        cout << "==========";
        cout << "Choose a character to treat: " << endl; // choice character fo heal
        cout << "(1) Warrior" << endl;
        cout << "(2) Wizard" << endl; 
        cout << "(3) Healer" << endl;
        cout << "==========" << endl;
        cout << "Your choice: ";
        cin >> ChoiceCharacterForHeal;

        if (ChoiceCharacterForHeal == 1) {
            if (warrior.WarriorHealth > 0) {
                cout << "Treatment of Warrior..." << endl; // Warrior heal
                warrior.WarriorHealth += 100;
                cout << "Warrior health: " << warrior.WarriorHealth << endl;
                --potion.NumsOfPotions;
            }
            else if (warrior.WarriorHealth <= 0) {
                cout << "Not treatment fo death characters" << endl;
            }
            else {
                cout << "Error! Restart game and check program code pls... Error code 9!" << endl; // if code error
            }
        }
        else if (ChoiceCharacterForHeal == 2) {
            if (wizard.WizardHealth > 0) {
                cout << "Treatment of Wizard..." << endl; // Wizard heal 
                wizard.WizardHealth += 100;
                cout << "Wizard health: " << wizard.WizardHealth << endl;
                --potion.NumsOfPotions;
            }
            else if (wizard.WizardHealth <= 0) {
                cout << "Not treatment fo death characters" << endl;
            }
            else {
                cout << "Error! Restart game and check program code pls... Error code 9!" << endl; // if code error
            }
        }
        else if (ChoiceCharacterForHeal == 3) {
            if (healer.HealerHealth > 0) {
                cout << "Treatment of Healer..." << endl; // Healer heal
                healer.HealerHealth += 100;
                cout << "Healer health: " << healer.HealerHealth << endl;
                --potion.NumsOfPotions;
            }
            else if (healer.HealerHealth <= 0) {
                cout << "Not treatment fo death characters" << endl;
            }
            else {
                cout << "Error! Restart game and check program code pls... Error code 9!" << endl; // if code error
            }
        }
        else {
            cout << "Wrong Input! Error code 8!" << endl;
        }
    }
}

void Bomb(Tower& tower) {
    unsigned int RandDamage;

    srand(time(NULL));
    RandDamage = rand() % 2;

    if (tower.NumOfBombs > 0) {
        cout << "The bomb is flying into the Tower!" << endl;

        if (RandDamage == 0) {
            cout << "Bomb hit the Tower with 1000 damage" << endl;
            tower.TowerHealth -= 1000;
            cout << "Number of bombs -1" << endl;
            --tower.NumOfBombs;
        }
        else if (RandDamage == 1) {
            cout << "Bomb hit the Tower with 500 damage" << endl;
            tower.TowerHealth -= 500;
            cout << "Number of bombs -1" << endl;
            --tower.NumOfBombs;
        }
        else if (RandDamage == 2) {
            cout << "Missed!" << endl;
            cout << "Number of bombs -1" << endl;
            --tower.NumOfBombs;
        }
        else {
            cout << "Error! Restart game and check program code pls... Error code 9" << endl;
        }
    }
    else {
        cout << "We're out of bombs!" << endl;
    }
}
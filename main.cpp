#include "heading.hpp"

int Score = 0;
int ChoiceGame;
int choiceGame2;
int choiceCharacter;

void AddScore() {
    string NewGameName;
    string line;

    cout << "Enter name of game (No spaces! This will cause a critical error!): " << endl;
    cin >> NewGameName;

    cout << "Attention! The file must be open, otherwise the record will not be written!" << endl;

    ofstream ScoreFile("score.txt", ios_base::app);

    if (ScoreFile.is_open()) {
        line = "Name of game: " + NewGameName + " Score: " + to_string(Score);
        ScoreFile << line;
        ScoreFile.close();
    }
    else {
        cout << "Unable to open the file for writing. Error code 1!" << endl;
    }
}

void ViewScore() {
    string line;

    ifstream readFile("score.txt");

    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open the file for reading. Error code 1!" << endl;
    }
}

int main() {
    for (;;) {
        cout << "Welcome to HellRain!"<< endl;
        cout << "(1) Start Game" << endl;
        cout << "(2) View Score" << endl;
        cout << "(3) Credits" << endl;
        cout << "(4) Backpack" << endl;
        cout << "(5) exit" << endl; 
        cin >> ChoiceGame;

        if (ChoiceGame == 1) {
            cout << "Start New Game?" << endl;
            cout << "(1) yes!" << endl;
            cout << "(2) no, close game!" << endl;
            cin >> choiceGame2;

            if (choiceGame2 == 1) {
                cout << "HellRain!" << " Your task is to destroy the tower, for this you have 3 characters..." << endl;
                cout << "Warrior, Wizard and Healer!" << endl;
                cout << "And Items!" << endl;
                cout << "Good luck!" << endl;
                Tower tower;
                Warrior warrior;
                Wizard wizard;
                Healer healer;
                Potions potion;
                int step = 0;

                while (true) {
                    step = step + 1;
                    cout << "Step: " << step << endl;
                    cout << "Your step: " << endl;

                    cout << "Choice character or item for action: " << endl;
                    cout << "(1) Warrior" << endl;
                    cout << "(2) Wizard" << endl;
                    cout << "(3) Healer" << endl;
                    cout << "(4) Items" << endl;
                    cin >> choiceCharacter;

                    if (choiceCharacter == 1) {
                        WarriorAction(tower, warrior, wizard, healer);
                        Score = Score += 40;
                        cout << "Your score: " << Score << endl;
                        cout << "Warrior health: " << warrior.WarriorHealth << endl;
                        cout << "Tower health: " << tower.TowerHealth << endl;

                        TowerAction(tower, warrior, wizard, healer);

                        if (warrior.WarriorHealth <= 0) {
                            Score -= 50;
                            cout << "Your score: " << Score << endl;
                            WarriorDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (wizard.WizardHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            WizardDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (healer.HealerHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            HealerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (tower.TowerHealth <= 0) { // if kill tower
                            Score += 1000;
                            cout << "Your score: " << Score << endl;
                            TowerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }
                    }
                    else if (choiceCharacter == 2) {
                        if (wizard.WizardMana > 0) {
                            WizardAction(tower, warrior, wizard, healer);
                            --wizard.WizardMana;
                            Score = Score += 10;
                            cout << "Your score: " << Score << endl;
                            cout << "Wizard health: " << wizard.WizardHealth << endl;
                            cout << "Tower health: " << tower.TowerHealth << endl;
                            TowerAction(tower, warrior, wizard, healer);
                        }
                        else {
                            cout << "You don't have enough mana!" << endl;
                            TowerAction(tower, warrior, wizard, healer);
                        }

                        if (warrior.WarriorHealth <= 0) {
                            Score -= 50;
                            cout << "Your score: " << Score << endl;
                            WarriorDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (wizard.WizardHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            WizardDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (healer.HealerHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            HealerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (tower.TowerHealth <= 0) { // if kill tower
                            Score += 1000;
                            cout << "Your score: " << Score << endl;
                            TowerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }
                    }
                    else if (choiceCharacter == 3) {
                        HealerAction(tower, warrior, wizard, healer);
                        Score = Score += 20;
                        cout << "Your score: " << Score << endl;

                        TowerAction(tower, warrior, wizard, healer);

                        if (warrior.WarriorHealth <= 0) {
                            Score -= 50;
                            cout << "Your score: " << Score << endl;
                            WarriorDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (wizard.WizardHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            WizardDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (healer.HealerHealth <= 0) {
                            Score -= 30;
                            cout << "Your score: " << Score << endl;
                            HealerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }

                        if (tower.TowerHealth <= 0) { // if kill tower
                            Score += 1000;
                            cout << "Your score: " << Score << endl;
                            TowerDeathStep(tower, warrior, wizard, healer);
                            break;
                        }
                    }
                    else if (choiceCharacter == 4) {
                        unsigned int ChoiceItems;

                        cout << "Choice items: " << endl;
                        cout << "(1) Bomb." << endl;
                        cout << "(2) Heal potion." << endl;
                        cout << "(3) Mana potion." << endl;
                        cout << "We do not recommend it for the first pass! But you can try..." << endl;
                        cout << "(4) Hardcore Totem." << endl;
                        cin >> ChoiceItems;

                        switch (ChoiceItems)
                        {
                        case 1:
                            Bomb(tower);

                            if (tower.TowerHealth <= 0) { // if kill tower
                                Score += 1000;
                                cout << "Your score: " << Score << endl;
                                TowerDeathStep(tower, warrior, wizard, healer);
                                break;
                            }

                            continue;
                        case 2:
                            HealthPotion(potion, warrior, wizard, healer);
                            continue;
                        case 3:
                            ManaPotion(wizard, potion);
                            continue;
                        case 4:
                            HardcoreTotem(tower, warrior, wizard, healer, potion);
                            Score += 2000;

                            if (warrior.WarriorHealth <= 0) {
                                Score -= 50;
                                cout << "Your score: " << Score << endl;
                                WarriorDeathStep(tower, warrior, wizard, healer);
                                break;
                            }

                            if (wizard.WizardHealth <= 0) {
                                Score -= 30;
                                cout << "Your score: " << Score << endl;
                                WizardDeathStep(tower, warrior, wizard, healer);
                                break;
                            }

                            if (healer.HealerHealth <= 0) {
                                Score -= 30;
                                cout << "Your score: " << Score << endl;
                                HealerDeathStep(tower, warrior, wizard, healer);
                                break;
                            }
                            
                            continue;
                        default:
                            cout << "Wrong Input! Error code 4!" << endl;
                            continue;
                        }
                    }
                    else {
                        cout << "Wrong Input! Error code 4!" << endl;
                    }
                }
            }
            else if (choiceGame2 == 2) {
                cout << "Bye Bye!" << endl;
            }
            else {
                cout << "Wrong Input! Error code 3!" << endl;
            }
        }
        else if (ChoiceGame == 2) {
            ViewScore();
        }
        else if (ChoiceGame == 3) {
            cout << "prod. by Rodion Buzov (*_*)" << endl;     
        }
        else if (ChoiceGame == 4) {
            cout << "Items: " << endl;
            cout << "3 bombs." << endl;
            cout << "3 heal potions." << endl;
            cout << "3 mana potions." << endl;
            cout << "1 Hardcore Totem." << endl;
        }
        else if (ChoiceGame == 5) {
            break;
        }
        else {
            cout << "Wrong Input! Error code 2! Critical Error!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
#pragma once
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
using namespace std;

void AddScore();
void ViewScore();

class Character { // virtual class
public:
    virtual void death() = 0; // virtual func
};

class Warrior : public Character { // Warrior 
public: 
    int WarriorHealth = 600; // Warrior health
    int WarriorDamage = 100; // Damage per hit
    
    void death() override {
        cout << "Warrior has been destroyed!" << endl; // death function
        cout << "you won!" << endl;
    }
};

class Wizard : public Character { // Wizard 
public: 
    int WizardHealth = 300; // Wizard health
    int WizardDamage = 300; // Damage per hit

    void death() override { // death func
        cout << "Wizard has been destroyed!" << endl; // death function 
        cout << "you won!" << endl;
    }
};

class Healer : public Character { // Healer, no attack, only heal
public: 
    int HealerHealth = 200; // Health
    int HealerHeal = 100; // heal

    void death() override {
        cout << "Healer has been destroyed!" << endl; // death function
        cout << "you won!" << endl;
    }
};

class Tower : public Character {
public:
    int TowerHealth = 3000; // Tower health
    int TowerDamage = 100;   // Damage per hit

    // TowerDeath function: A function that gets called when the tower's health reaches 0 or below.
    void death() override {
        cout << "Tower has been destroyed!" << endl;
        cout << "Your win! Congratulations!" << endl;
    }
};

void WarriorAction(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void WizardAction(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void HealerAction(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void TowerAction(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);

void WarriorDeathStep(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void WizardDeathStep(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void HealerDeathStep(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
void TowerDeathStep(Tower& tower, Warrior& warrior, Wizard& wizard, Healer& healer);
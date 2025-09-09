#include <iostream>
#include <string>

#pragma once

class Moves {
    std::string name;
    int power;
    int accuracy;
    std::string type;
    std::string category; // Physical, Special, Status
    std::string effect; // e.g., "Burn", "Paralyze", etc.
public:
    Moves(std::string n, int p, int a, std::string t, std::string c, std::string e) : name(n), power(p), accuracy(a), type(t), category(c), effect(e) {}
    Moves() {}
 
    void printMove(int i) {
        std::cout << "Move " << i << ": " << name << "\nPower: " << power << "\nAccuracy: " << accuracy << "\nType: " << type << "\nCategory: " << category << "\nEffect: " << effect << std::endl;
    }
};

class Pokemon {
    std::string name;
    int level;
    std::string type[2];
    enum Status { Healthy, Fainted, Paralyzed, Poisoned, Asleep } status;
    Moves moves[4];
public:
    Pokemon(std::string n, int l, std::string t1, std::string t2) : name(n), level(l) {
        type[0] = t1;
        type[1] = t2;
    }

    Pokemon() {
        name = "Pikachu";
        level = 5;
        type[0] = "Electric";
        type[1] = "";
        status = Healthy;
        moves[0] = Moves("Thunder Shock", 40, 100, "Electric", "Special", "Paralyze");
        moves[1] = Moves("Quick Attack", 40, 100, "Normal", "Physical", "");
        moves[2] = Moves("Tail Whip", 0, 100, "Normal", "Status", "Lower Defense");
        moves[3] = Moves("Growl", 0, 100, "Normal", "Status", "Lower Attack");
    }

    void printPokemon() {
        std::cout << "Name: " << name << "\nLevel: " << level << "\nType: " << type[0];
        if (!type[1].empty()) std::cout << "/" << type[1];
        std::cout << "\nStatus: ";
        switch (status) {
            case Healthy: std::cout << "Healthy"; break;
            case Fainted: std::cout << "Fainted"; break;
            case Paralyzed: std::cout << "Paralyzed"; break;
            case Poisoned: std::cout << "Poisoned"; break;
            case Asleep: std::cout << "Asleep"; break;
        }
        for (int i = 0; i < 4; ++i) {
            moves[i].printMove(i + 1);
        }
    }
};

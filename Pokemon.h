#include <iostream>
#include <string>
#include <vector>

#pragma once

class Type {
    std::string typeName;
    std::vector<std::string> typeWeakness;
    std::vector<std::string> typeEffective;
    std::string typeImmunity;
public:
    Type() { typeName = ""; typeWeakness = {}; typeEffective = {}; typeImmunity = "";}
    Type(std::string &s, std::vector<std::string> &tw, std::vector<std::string> &te, std::string &ti) {
        typeName = s;
        typeWeakness = tw;
        typeEffective = te;
        typeImmunity = ti;
    }
    void setTypeName(std::string s) {
        typeName = s;
    }
    void setWeakness(std::vector<std::string> &sv) {
        typeWeakness.clear();
        for (auto s : sv) {
            typeWeakness.push_back(s);
        }
    }
    void setEffective(std::vector<std::string> &sv) {
        typeEffective.clear();
        for (auto s: sv) {
            typeEffective.push_back(s);
        }
    }
    void setImmunity(std::string &s) {
        typeImmunity = s;
    }
    void const printType() {
        std::cout << "Type: " << typeName << std::endl;
    }
    void const printWeakness() {
        for (int i = 0; i < typeWeakness.size(); i++) {
            std::cout << "Weak against: " << typeWeakness.at(i) << " ";
        } std::cout << std::endl;
    }
    void const printEffective() {
        for (int i = 0; i < typeEffective.size(); i++) {
            std::cout << "Effect against: " << typeEffective.at(i) << " ";
        } std::cout << std::endl;
    }
    void const printImmunity() {
        if(typeImmunity != "") {
            std::cout << "Immunity is: " << typeImmunity << std::endl;
        } else {
            std::cout << "No type immunity" << std::endl;
        }
    }
    bool const isEmpty() {
        return typeName == "";
    }
};

class Moves {
    std::string name;
    int movePower;
    int moveAccuracy;
    Type moveType;
    std::string moveCategory; // Physical, Special, Status
    std::string moveEffect; // e.g., "Burn", "Paralyze", etc.
public:
    Moves() {name = ""; movePower = 0; moveAccuracy = 0; moveCategory = ""; moveEffect = ""; moveType = Type();}
    Moves(std::string &n, int mp, int ma, std::string &mc, std::string &me, Type &mt) {
        name = n;
        movePower = mp;
        moveAccuracy = ma;
        moveCategory = mc;
        moveEffect = me;
        moveType = mt;
    }
    void printMove(int i) {
        std::cout << "Move " << i << ": " << name << "\nPower: " << movePower << "\nAccuracy: " << moveAccuracy 
                  << "\nCategory: " << moveCategory << "\nEffect: " << moveEffect << std::endl;
        moveType.printType();
    }
};

class Pokemon {
    std::string name;
    int level;
    Type type[2];
    enum Status { Healthy, Fainted, Paralyzed, Poisoned, Asleep } status;
    Moves moves[4];
public:
    Pokemon() {
        name = "";
        level = 1;
        type[0] = Type();
        type[1] = Type();
        status = Healthy;
        for (int i = 0; i < 4; ++i) {
            moves[i] = Moves();
        }
    }
    Pokemon(std::string n, int l, Type t1, Type t2, Status s, Moves m1, Moves m2, Moves m3, Moves m4) 
        : name(n), level(l), status(s) {
            type[0] = t1;
            type[1] = t2;
            moves[0] = m1;
            moves[1] = m2;
            moves[2] = m3;
            moves[3] = m4;
    }

    void printPokemon() {
        std::cout << "Name: " << name << "\nLevel: " << level << "\nType: "; type[0].printType();
        if (!type[1].isEmpty()) { 
            std::cout << "/"; type[1].printType();
            std::cout << "\nStatus: ";
        }
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

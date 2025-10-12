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
    Type(const std::string &s, 
         const std::vector<std::string> &tw, 
         const std::vector<std::string> &te, 
         const std::string &ti) {
            typeName = s;
            typeWeakness = tw;
            typeEffective = te;
            typeImmunity = ti;
    }
    Type(const Type &t) {
        typeName = t.typeName;
        typeWeakness = t.typeWeakness;
        typeEffective = t.typeEffective;
        typeImmunity = t.typeImmunity;
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
    Moves(const std::string &n, int mp, int ma, 
         const std::string &mc, const std::string &me, 
         const Type &mt) {
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
    bool const isMoveEmpty() {
        return name == "";
    }
};

class Pokemon {
    std::string name;
    int level;
    Type type[2];
    Moves moves[4];
    enum Status { Healthy, Fainted, Paralyzed, Poisoned, Asleep } status;
    int hp;
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
        hp = 100;
    }
    Pokemon(const std::string &n, int l, const Type &t1, const Type &t2, int h,
        int s, const Moves &m1, const Moves &m2, const Moves &m3, const Moves &m4) {
        type[0] = t1;
        type[1] = t2;
        moves[0] = m1;
        moves[1] = m2;
        moves[2] = m3;
        moves[3] = m4;
        name = n;
        level = l;
        hp = h;
        status = static_cast<Status>(s);
    }

    void printPokemon() {
        std::cout << "Name: " << name << "\nLevel: " 
        << level << std::endl; 
        type[0].printType();
        if (!type[1].isEmpty()) { 
            type[1].printType();
        } 
        std::cout << "\nStatus: ";
        switch (status) {
            case Healthy: std::cout << "Healthy\n"; break;
            case Fainted: std::cout << "Fainted\n"; break;
            case Paralyzed: std::cout << "Paralyzed\n"; break;
            case Poisoned: std::cout << "Poisoned\n"; break;
            case Asleep: std::cout << "Asleep\n"; break;
        }
        std::cout << "HP: " << hp << std::endl;
        for (int i = 0; i < 4; ++i) {
            if (!moves[i].isMoveEmpty()){
                moves[i].printMove(i + 1);
            }
        }
    }
};

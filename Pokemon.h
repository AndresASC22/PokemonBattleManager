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

    std::string getTypeName() const { return typeName; }
    std::vector<std::string> getWeakness() const { return typeWeakness; }
    std::vector<std::string> getEffective() const { return typeEffective; }
    std::string getImmunity() const { return typeImmunity; }

    void printType() const {
        std::cout << "Type: " << typeName << std::endl;
    }
    void printWeakness() const {
        for (int i = 0; i < typeWeakness.size(); i++) {
            std::cout << "Weak against: " << typeWeakness.at(i) << " ";
        } std::cout << std::endl;
    }
    void printEffective() const {
        for (int i = 0; i < typeEffective.size(); i++) {
            std::cout << "Effect against: " << typeEffective.at(i) << " ";
        } std::cout << std::endl;
    }
    void printImmunity() const {
        if(typeImmunity != "") {
            std::cout << "Immunity is: " << typeImmunity << std::endl;
        } else {
            std::cout << "No type immunity" << std::endl;
        }
    }
    bool isEmpty() const {
        return typeName == "";
    }
};

class Move { 
    std::string moveName;
    int movePower;
    int moveAccuracy;
    Type moveType;
    std::string moveCategory; // Physical, Special, Status
    std::string moveEffect; // e.g., "Burn", "Paralyze", etc.
    std::string description;
    int powerPoints;
public:
    Move() {moveName = ""; movePower = 0; moveAccuracy = 0; moveCategory = ""; moveEffect = ""; moveType = Type(); description = ""; powerPoints = 0;}
    Move(const std::string &n, int mp, int ma, 
         const std::string &mc, const std::string &me, 
         const Type &mt, const std::string &desc, int pp) {
        moveName = n;
        movePower = mp;
        moveAccuracy = ma;
        moveCategory = mc;
        moveEffect = me;
        moveType = mt;
        description = desc;
        powerPoints = pp;
    }

    std::string getMoveName() const { return moveName; }
    int getMovePower() const { return movePower; }
    int getMoveAccuracy() const { return moveAccuracy; }
    Type getMoveType() const { return moveType; }
    std::string getMoveCategory() const { return moveCategory; }
    std::string getMoveEffect() const { return moveEffect; }
    std::string getDescription() const { return description; }
    int getPowerPoints() const { return powerPoints; }

    void setMoveName(const std::string &n) { moveName = n; }
    void setMovePower(int mp) { movePower = mp; }
    void setMoveAccuracy(int ma) { moveAccuracy = ma; }
    void setMoveType(const Type &mt) { moveType = mt; }
    void setMoveCategory(const std::string &mc) { moveCategory = mc; }
    void setMoveEffect(const std::string &me) { moveEffect = me; }
    void setDescription(const std::string &desc) { description = desc; }
    void setPowerPoints(int pp) { powerPoints = pp; }
    
    void usePP() { if(powerPoints > 0) powerPoints--; }
    void restorePP(int amount) { powerPoints += amount; }
    
    void printMove(int i) const {
        std::cout << "Move " << i << ": " << moveName << "\nPower: " << movePower << "\nAccuracy: " << moveAccuracy 
                  << "\nCategory: " << moveCategory << "\nEffect: " << moveEffect << "\nDescription: " << description 
                  << "\nPower Points: " << powerPoints << std::endl;
        moveType.printType();
    }
    bool isMoveEmpty() const {
        return moveName == "";
    }
};

class Pokemon {
    std::string name;
    int level;
    Type type[2];
    Move moves[4];
    int hp;
public:
    enum Status { Healthy, Fainted, Paralyzed, Poisoned, Asleep } status;
    Pokemon() {
        name = "";
        level = 1;
        type[0] = Type();
        type[1] = Type();
        status = Healthy;
        for (int i = 0; i < 4; ++i) {
            moves[i] = Move();
        } 
        hp = 100;
    }
    Pokemon(const std::string &n, int l, const Type &t1, const Type &t2, int h,
        int s, const Move &m1, const Move &m2, const Move &m3, const Move &m4) {
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
    Pokemon(const Pokemon &p) {
        name = p.name;
        level = p.level;
        type[0] = p.type[0];
        type[1] = p.type[1];
        moves[0] = p.moves[0];
        moves[1] = p.moves[1];
        moves[2] = p.moves[2];
        moves[3] = p.moves[3];
        hp = p.hp;
        status = p.status;
    }

    std::string getName() const { return name; }
    int getLevel() const { return level; }
    Type getType(int index) const { 
        if(index == 0 || index == 1) return type[index];
        return Type(); // return empty type if index out of bounds
    }
    Move getMove(int index) const {
        if(index >= 0 && index < 4) return moves[index];
        return Move();
    }
    int getHP() const { return hp; }
    Status getStatus() const { return status; }
    bool isFainted() const { return status == Fainted || hp <= 0; }

    void setName(const std::string &n) { name = n; }
    void setLevel(int l) { level = l; }
    void setType(int index, const Type &t) { if(index == 0 || index == 1) type[index] = t; }
    void setMove(int index, const Move &m) { if(index >= 0 && index < 4) moves[index] = m; }
    void setHP(int newHP) { hp = newHP; if(hp <= 0) status = Fainted; }
    void setStatus(Status s) { status = s; }
    
    void takeDamage(int damage) { 
        hp -= damage; 
        if(hp <= 0) {
            hp = 0;
            status = Fainted;
        }
    }
    void heal(int amount) { 
        hp += amount; 
        if(status == Fainted && hp > 0) status = Healthy;
    }
    void restoreAllPP() {
        for(int i = 0; i < 4; i++) {
            // Ideally you'd restore to max PP, but we don't store max PP.
            // For simplicity, set to 30 as a default max.
            // You may want to store maxPP separately.
            moves[i].setPowerPoints(30);
        }
    }
    
    void printPokemon() const {
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
            } std::cout << std::endl;
        }
    }
};

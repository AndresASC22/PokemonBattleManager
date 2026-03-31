#pragma once

#include "Pokemon.h"
#include "TypeDeclarations.h"
#include <vector>
#include <stdexcept>

class Team {
private:
    std::vector<Pokemon> members;
    int activeIndex;

public:
    Team() : activeIndex(-1) {}
    
    explicit Team(const std::vector<Pokemon>& initialMembers) : activeIndex(-1) {
        for (const auto& p : initialMembers) {
            addPokemon(p);
        }
        if (!members.empty()) {
            activeIndex = 0;  // first Pokémon becomes active
        }
    }
    
    // Team management
    bool addPokemon(const Pokemon& p) {
        if (members.size() >= 6) return false;
        members.push_back(p);
        if (activeIndex == -1) activeIndex = 0;
        return true;
    }
    
    bool removePokemon(int index) {
        if (index < 0 || index >= members.size()) return false;
        members.erase(members.begin() + index);
        if (members.empty()) {
            activeIndex = -1;
        } else if (activeIndex >= index) {
            activeIndex = (activeIndex > 0) ? activeIndex - 1 : 0;
        }
        return true;
    }
    
    // Accessors
    Pokemon& getActivePokemon() {
        if (activeIndex < 0 || activeIndex >= members.size()) {
            throw std::runtime_error("No active Pokémon in team");
        }
        return members[activeIndex];
    }
    
    const Pokemon& getActivePokemon() const {
        if (activeIndex < 0 || activeIndex >= members.size()) {
            throw std::runtime_error("No active Pokémon in team");
        }
        return members[activeIndex];
    }
    
    Pokemon& getPokemon(int index) {
        if (index < 0 || index >= members.size()) {
            throw std::out_of_range("Invalid Pokémon index");
        }
        return members[index];
    }
    
    const Pokemon& getPokemon(int index) const {
        if (index < 0 || index >= members.size()) {
            throw std::out_of_range("Invalid Pokémon index");
        }
        return members[index];
    }
    
    int getActiveIndex() const { return activeIndex; }
    int size() const { return members.size(); }
    bool isEmpty() const { return members.empty(); }
    bool isFull() const { return members.size() >= 6; }
    
    // Battle actions
    bool switchTo(int newIndex) {
        if (newIndex < 0 || newIndex >= members.size()) return false;
        if (members[newIndex].isFainted()) return false;
        activeIndex = newIndex;
        return true;
    }
    
    bool isDefeated() const {
        for (const auto& p : members) {
            if (!p.isFainted()) return false;
        }
        return true;
    }
    
    // Returns indices of non-fainted Pokémon that can be sent out (excluding the current active)
    std::vector<int> getAvailableReplacements() const {
        std::vector<int> available;
        for (int i = 0; i < members.size(); ++i) {
            if (!members[i].isFainted() && i != activeIndex) {
                available.push_back(i);
            }
        }
        return available;
    }
    
    // Utility – heal all Pokémon in team (e.g., after battle)
    void healAll() {
        for (auto& p : members) {
            p.setHP(100);        // You may want to store max HP per Pokémon
            p.setStatus(Pokemon::Healthy);
            p.restoreAllPP();
        }
    }
};
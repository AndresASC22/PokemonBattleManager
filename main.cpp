#include "Pokemon.h"

int main() {
    Type fireType("Fire", {"Water", "Ground", "Rock"}, {"Grass", "Ice", "Bug", "Steel"}, "");
    Type normalType("Normal", {"Fighting"}, {}, "Ghost");
    Type flyingType("Flying", {"Electric", "Ice", "Rock"}, {"Grass", "Fighting", "Bug"}, "Ground");
    Moves flamethrowerMove("Flamethrower", 90, 100, "Special", "Burn", fireType);
    Moves flyMove("Fly", 90, 95, "Physical", "None", flyingType);
    Moves slashMove("Slash", 70, 100, "Physical", "None", normalType);
    Moves fireBlastMove("Fire Blast", 110, 85, "Special", "Burn", fireType);
    Pokemon charizard("Charizard", 36, fireType, flyingType, 150, 0, flamethrowerMove, flyMove, slashMove, fireBlastMove);
    charizard.printPokemon();

    return 0;
}

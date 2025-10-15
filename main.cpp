#include "TypeDeclarations.h"

int main() {
    Move flamethrowerMove("Flamethrower", 90, 100, "Special", "Burn", fireType, "A powerful fire attack that may inflict a burn.");
    Move flyMove("Fly", 90, 95, "Physical", "None", flyingType, "Flies up high on the first turn, then strikes on the second turn.");
    Move slashMove("Slash", 70, 100, "Physical", "None", normalType, "A quick, slashing attack with a high critical-hit ratio.");
    Move fireBlastMove("Fire Blast", 110, 85, "Special", "Burn", fireType, "A fiery blast that scorches all. May also leave the target with a burn.");
    Pokemon charizard("Charizard", 36, fireType, flyingType, 150, 0, flamethrowerMove, flyMove, slashMove, fireBlastMove);
    charizard.printPokemon();

    Move hydroPumpMove("Hydro Pump", 110, 80, "Special", "None", waterType, "Blasts water at high power to damage the opponent.");
    Move surfMove("Surf", 90, 100, "Special", "None", waterType, "A wave crashes down on the target.");
    Move biteMove("Bite", 60, 100, "Physical", "Flinch", darkType, "Bites the target.");
    Move iceBeamMove("Ice Beam", 90, 100, "Special", "Freeze", iceType, "Fires a beam of ice at the target.");
    Pokemon blastoise("Blastoise", 36, waterType, Type(), 155, 0, hydroPumpMove, surfMove, biteMove, iceBeamMove);
    blastoise.printPokemon();

    return 0;
}

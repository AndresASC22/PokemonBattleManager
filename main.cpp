#include "Pokemon.h"

int main() {
    Type waterType("Water", {"Electric", "Grass"}, {"Fire", "Rock", "Ground"}, "");
    Moves surfMove("Surf", 90, 100, "Special", "None", waterType);
    Pokemon squirtle("Squirtle", 5, waterType, Type(), 100, 0, surfMove, Moves(), Moves(), Moves());
    squirtle.printPokemon();

    return 0;
}
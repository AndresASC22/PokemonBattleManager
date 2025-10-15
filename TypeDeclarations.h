#include "Pokemon.h"

#pragma once

Type fireType("Fire", {"Water", "Ground", "Rock"}, {"Grass", "Ice", "Bug", "Steel"}, "");
Type waterType("Water", {"Electric", "Grass"}, {"Fire", "Ground", "Rock"}, "");
Type grassType("Grass", {"Fire", "Ice", "Poison", "Flying", "Bug"}, {"Water", "Ground", "Rock"}, "");
Type electricType("Electric", {"Ground"}, {"Water", "Flying"}, "");
Type normalType("Normal", {"Fighting"}, {}, "Ghost");
Type flyingType("Flying", {"Electric", "Ice", "Rock"}, {"Grass", "Fighting", "Bug"}, "Ground");
Type fightingType("Fighting", {"Flying", "Psychic", "Fairy"}, {"Normal", "Ice", "Rock", "Dark", "Steel"}, "");
Type poisonType("Poison", {"Ground", "Psychic"}, {"Grass", "Fairy"}, "Steel");
Type groundType("Ground", {"Water", "Grass", "Ice"}, {"Fire", "Electric", "Poison", "Rock", "Steel"}, "Flying");
Type rockType("Rock", {"Water", "Grass", "Fighting", "Ground", "Steel"}, {"Fire", "Ice", "Flying", "Bug"}, "");
Type bugType("Bug", {"Fire", "Flying", "Rock"}, {"Grass", "Psychic", "Dark"}, "");
Type ghostType("Ghost", {"Ghost", "Dark"}, {"Psychic", "Ghost"}, "Normal");
Type steelType("Steel", {"Fire", "Fighting", "Ground"}, {"Ice", "Rock", "Fairy"}, "Poison");
Type iceType("Ice", {"Fire", "Fighting", "Rock", "Steel"}, {"Grass", "Ground", "Flying", "Dragon"}, "");
Type dragonType("Dragon", {"Ice", "Dragon", "Fairy"}, {"Dragon"}, "");
Type darkType("Dark", {"Fighting", "Bug", "Fairy"}, {"Psych ic", "Ghost"}, "");
Type psychicType("Psychic", {"Bug", "Ghost", "Dark"}, {"Fighting", "Poison"}, "");
Type fairyType("Fairy", {"Poison", "Steel"}, {"Fighting", "Dragon", "Dark"}, "Dragon");

#include "TypeDeclarations.h"

#pragma once

// For testing purposes I'm only including gen 1 moves
// Format is moveName->movePower->moveAccuracy->moveCategory->moveEffect->moveType->description->powerpoints

// Normal Type Moves
Move barrageMove("Barrage", 15, 85, "Physical", "None", normalType, "Hits the target 2-5 times in one turn.", 20);
Move bideMove("Bide", 0, 100, "Physical", "None", normalType, "Endures attacks for two turns, then strikes back double the damage taken.", 10);
Move bindMove("Bind", 15, 85, "Physical", "None", normalType, "Traps the target and squeezes for 4-5 turns.", 15);
Move bodySlamMove("Body Slam", 85, 100, "Physical", "Paralyze", normalType, "A full-body slam that may also paralyze the target.", 15);
Move cometPunchMove("Comet Punch", 18, 85, "Physical", "None", normalType, "Hits the target 2-5 times in one turn.", 15);
Move constrictMove("Constrict", 10, 100, "Physical", "None", normalType, "May lower opponent's Speed by one stage.", 35); 
Move conversionMove("Conversion", 0, 100, "Status", "None", normalType, "Changes user's type to that of its first move.", 30);
Move cutMove("Cut", 50, 95, "Physical", "None", normalType, "", 30);
Move defenseCurlMove("Defense Curl", 0, 100, "Status", "None", normalType, "Raises user's defense", 40);

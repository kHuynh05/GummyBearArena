#pragma once
#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "Gummy.h"

using namespace std;

class SaveLoad{
    public:
        static void saveGame(string& filename, Gummy& gummy);
        static void loadGame(string filename, Gummy& gummy);
};

#endif
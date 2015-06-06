//
//  brain.h
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#ifndef __alice__brain__
#define __alice__brain__

#include "neuron.h"
#include "main.h"


using namespace std;

class neuron;


class brain {
    
private:
    vector<neuron*> neurons;
    int xDim;
    int yDim;
    int zDim;
public:
    brain(int xd, int yd, int zd);
    neuron* getNeuronAt(int x, int y, int z);
    neuron* getNeuronAt(int i);
    void write(ostream& out);
    void stimulate(int x, int y, int z);
    void process();
    void think(int cycles, int xre, int yre, int zre);
    void dopamineFlood();
    void reward(int x, int y, int z);
};

#endif /* defined(__alice__brain__) */

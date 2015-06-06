//
//  neuron.h
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#ifndef __alice__neuron__
#define __alice__neuron__

#include "main.h"
#include "dendrite.h"
#include "location.h"


using namespace std;

class brain;
class dendrite;

class neuron {
    
private:
    vector<dendrite*> dendrites;
    vector<dendrite*> activatorDendrites;
    vector<dendrite*> inhibitorDendrites;
    location here;
    int currentState;              //1 or 0
    int lastState;
    bool refractory;
    int effect;       //1 activate, 0 inhibit
public:
    void lastEqualsCurrentState();
    int getLastState();
    int getCurrentState();
    int getEffect();
    int getDendrites();
    void processDopamineFlood();
    void updateDendrites(bool activator, bool strengthen);
    void process();
    void stimulate();
    neuron(int x, int y, int z);
    void addDendrites(brain& b, float weight);
    
};

#endif /* defined(__alice__neuron__) */

//
//  dendrite.h
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#ifndef __alice__dendrite__
#define __alice__dendrite__

#include "main.h"
#include "neuron.h"

using namespace std;

class neuron;

class dendrite {
    
private:
    float weight;
    neuron *pre;
    neuron *post;
    int causalityCounter;     //max of 5
public:
    neuron* getPost();
    float getWeight();
    int getCausalityCounter();
    void updateWeight(bool strengthen);
    void decrementCausalityCouter();
    dendrite(float w, neuron* m, neuron* t);
};

#endif /* defined(__alice__dendrite__) */

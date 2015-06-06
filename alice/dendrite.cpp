//
//  dendrite.cpp
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#include "dendrite.h"

dendrite::dendrite(float w, neuron* m, neuron* t)
{
    weight = w;
    pre = m;
    post = t;
}

neuron* dendrite::getPost()
{
    return post;
}

float dendrite::getWeight()
{
    return weight;
}
int dendrite::getCausalityCounter()
{
    return causalityCounter;
}

void dendrite::updateWeight(bool strengthen)
{
    if(strengthen){
        weight += 0.2;
        causalityCounter = 5;
        
    }
    else
    {
        weight -= 0.2;
    }
    
}

void dendrite::decrementCausalityCouter()
{
    if(causalityCounter > 0)
    {
        causalityCounter--;
    }
    
}

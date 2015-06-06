//
//  neuron.cpp
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#include "neuron.h"
#include "constants.h"


neuron::neuron(int x, int y, int z) : here(x,y,z), dendrites(numberofDendritesPerNeuron), activatorDendrites(numberofDendritesPerNeuron), inhibitorDendrites(numberofDendritesPerNeuron)
{
    float t;
    refractory      = false;
    currentState    = 0;
    lastState       = 0;
    t               = rand() *100.0/RAND_MAX;
    ///set effect
    if(t < 35)
    {
        effect      = 1;         //activator
    }
    else if(t < 45)
    {
        effect      = -0.2;         //inhibitor
    }
    else if(t < 60)
    {
        effect      = 1;
    }
    else if(t < 75)
    {
        effect      = -0.2;
    }
    else if(t < 85)
    {
        effect      = 1;
    }
    else if(t < 95)
    {
        effect      = -0.2;
    }
    else
    {
        effect      = 1;
    }
}

void neuron::addDendrites(brain& b, float weight)
{
    ///make dendrites
    int ix, iy, iz, nx, ny, nz, i = 0;
    nx = here.getX();
    ny = here.getY();
    nz = here.getZ();
    
    for(ix = nx - 1 ;  ix - 1 <= nx ;ix++){
        
        for(iy = ny - 1 ; iy - 1 <= ny ; iy++){
            
            for(iz = nz - 1 ; iz - 1 <= nz ; iz++){
                
                if(ix != nx || iy != ny || iz != nz){
                    
                    dendrite* ptr;
                    ptr = new dendrite(weight, this, b.getNeuronAt(ix, iy, iz));
                    dendrites[i] = ptr;
                    i++;
                }
            }
        }
    }
}

void neuron::updateDendrites(bool activator, bool strengthen)
{
    int d = 0;
    if(activator){
        while(activatorDendrites[d])
        {
            activatorDendrites[d]->updateWeight(strengthen);
            d++;
        }
    }
    else
    {
        while(inhibitorDendrites[d])
        {
            inhibitorDendrites[d]->updateWeight(strengthen);
            d++;
        }
    }
}

int neuron::getLastState()
{
    return lastState;
}

int neuron::getCurrentState()
{
    return currentState;
}

void neuron::lastEqualsCurrentState()
{
    lastState = currentState;
}

float neuron::getEffect()
{
    return effect;
}

int neuron::getDendrites()
{
    return dendrites.size();
}

void neuron::stimulate()
{
    currentState = 1;
    effect = 3;
}

void neuron::process()
{
    if((currentState == 0)&&(refractory == false)){
        float sum = 0;
        int d = 0;
        
        for(int i = 0; i < 26 ; i++){
            
            dendrite* dptr = dendrites[i];
            
            neuron* nptr = dptr->getPost();
            
            
            
            if(dptr != NULL && nptr != NULL){
                
                sum += (nptr->getLastState()) * (nptr->getEffect()) * (dptr->getWeight());
                
                dptr->decrementCausalityCouter();
                
                if(((nptr->getLastState()) * (nptr->getEffect()) * (dptr->getWeight())) > 0){
                    activatorDendrites[d] = dptr;
                    d++;
                }
                if(((nptr->getLastState()) * (nptr->getEffect()) * (dptr->getWeight())) < 0){
                    inhibitorDendrites[d] = dptr;
                    d++;
                }
            }
        }
        
        if(sum > 0.5)
        {
            currentState = 1;
            updateDendrites(true, true);
        }
        else
        {
            updateDendrites(false, true);
        }
    }else if(currentState == 1){
        currentState = 0;
        refractory = true;
    }else{
        refractory = false;
    }
}

void neuron::processDopamineFlood()
{
    for(int d = 0 ; d < numberofDendritesPerNeuron ; d++){

        if(dendrites[d]->getCausalityCounter() > 0){
            dendrites[d]->updateWeight(true);
        }
    }
}

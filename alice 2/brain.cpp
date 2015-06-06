//
//  brain.cpp
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#include "brain.h"
#include "constants.h"


brain::brain(int xd, int yd, int zd) : neurons(xd*yd*zd)
{
    xDim = xd;
    yDim = yd;
    zDim = zd;
    
    //Create Neurons
    for(int iz = 0 ; iz < zDim ; iz++){
        for(int iy = 0 ; iy < yDim ; iy++ ){
            for(int ix = 0 ; ix < xDim ; ix++){
                neuron* ptr;
                ptr = new neuron(ix, iy, iz);
                neurons[iz*xDim*yDim + iy*xDim + ix] = ptr;
                
                
            }
        }
    }
    
    //Add Dendrites
    for(int iz = 0 ; iz < zDim ; iz++){
        for(int iy = 0 ; iy < yDim ; iy++ ){
            for(int ix = 0 ; ix < xDim ; ix++){
                neurons[iz*xDim*yDim + iy*xDim + ix]->addDendrites(*this, defaultWeight);
            }
        }
    }
}

neuron* brain::getNeuronAt(int x, int y, int z)
{
    if(x >= xDim || x < 0 || y >= yDim || y < 0 || z >= zDim || z < 0)
    {
        return NULL;
    }else{
        return neurons[z*xDim*yDim + y*xDim + x];
    }
}

neuron* brain::getNeuronAt(int i)
{
    if(i >= neurons.size())
    {
        return NULL;
    }else{
        return neurons[i];
    }
}

void brain::stimulate(int x, int y, int z)
{
    getNeuronAt(x, y, z)->stimulate();
}

void brain::process()
{
    for(int i = 0 ; i < neurons.size() ; i++){
        neurons[i]->lastEqualsCurrentState();
    }
    for(int i = 0 ; i < neurons.size() ; i++){
        neurons[i]->process();
    }
}

void brain::think(int cycles, int xre, int yre, int zre)
{
    for(int i = 0; i < cycles ; i++){
        process();
        cout << "cycle" << i + 1;
        reward(xre, yre, zre);
        write(cout);
    }
}

void brain::write(ostream& out)
{
    for(int iz = 0 ; iz < zDim ; iz++){
        for(int iy = 0 ; iy < yDim ; iy++ ){
            for(int ix = 0 ; ix < xDim ; ix++){
                //cout << "(e = " << neurons[iz*xDim*yDim + iy*xDim + ix]->getEffect() <<  ", s = " << neurons[iz*xDim*yDim + iy*xDim + ix]->getCurrentState()<< ") ";
                cout << neurons[iz*xDim*yDim + iy*xDim + ix]->getCurrentState();
            }
            cout << endl;
        }
        cout << endl;
    }
    
}
void brain::dopamineFlood()
{
    //all dendrites with causality counter > 0 --> increase weight
    for(int i = 0 ; i < neurons.size() ; i++){
            getNeuronAt(i)->processDopamineFlood();
    }
}

void brain::reward(int x, int y, int z)
{
    neuron* nptr = getNeuronAt(x, y, z);
    if(nptr->getCurrentState() == 1)
    {
        dopamineFlood();
        cout << "     HIT"<< endl;
    }
    else
    {
        cout << endl;
    }
    
}

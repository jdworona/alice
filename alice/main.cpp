//
//  main.cpp
//  alice
//
//  Created by Jordan Worona on 2015-03-31.
//  Copyright (c) 2015 apollo. All rights reserved.
//


#include "main.h"

using namespace std;


int main(int argc, char *argv[])
{
    int xd, yd, zd, xs, ys, zs, c, xr, yr, zr;
    cout << "Enter x dimension: ";
    cin >> xd;
    cout << "Enter y dimension: ";
    cin >> yd;
    cout << "Enter z dimension: ";
    cin >> zd;
    brain troy(xd,yd,zd);
    troy.write(cout);
    
    cout << "Reward:" << endl << "Enter x: ";
    cin >> xr;
    cout << "Enter y: ";
    cin >> yr;
    cout << "Enter z: ";
    cin >> zr;
    
    while(1){
        cout << "Stimulate:" << endl << "Enter x: ";
        cin >> xs;
        cout << "Enter y: ";
        cin >> ys;
        cout << "Enter z: ";
        cin >> zs;
        cout << "Enter cycles: ";
        cin >> c;
        
        troy.stimulate(xs, ys, zs);
        troy.write(cout);
        troy.think(c, xr, yr, zr);
    }
    return EXIT_SUCCESS;
}
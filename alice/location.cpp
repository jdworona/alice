//
//  location.cpp
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#include "location.h"


#pragma mark
#pragma mark - Location Implementation
#pragma mark

location::location(int xn, int yn, int zn)
{
    x = xn;
    y = yn;
    z = zn;
}
int location::getX()
{
    return x;
}
int location::getY()
{
    return y;
}
int location::getZ()
{
    return z;
}
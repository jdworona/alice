//
//  location.h
//  alice
//
//  Created by Jordan Worona on 2015-06-03.
//  Copyright (c) 2015 apollo. All rights reserved.
//

#ifndef __alice__location__
#define __alice__location__

#include <stdio.h>



class location {
    
private:
    int x;
    int y;
    int z;
public:
    int getX();
    int getY();
    int getZ();
    location(int xn, int yn, int zn);
};


#endif /* defined(__alice__location__) */

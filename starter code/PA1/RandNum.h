#pragma once
#ifndef RAND_NUM_H
#define RAND_NUM_H

#include <cstdlib> 
#include <ctime> 

using namespace std;

//this class returns a random number based on a system time seed
class RandNum
{
private:
	int _num;

public:

    RandNum()
    {
        srand((unsigned)time(0));
    }

    int returnRandNum()
    {
        int lowest = -10, highest = 10;
        int range = (highest - lowest) + 1;
        _num = lowest + int(range*(rand()/(RAND_MAX + 1.0)));

        return _num;
    }

};

#endif // !RAND_NUM_H

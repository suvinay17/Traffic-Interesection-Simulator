#ifndef __ROADWAYS_H__
#define __ROADWAYS_H__

#include "Intersection.h"
#include "Road.h"

public class Roadways{
    public:

        Roadways();

        void advance();

    private:
        Intersection intersection;
};
#endif

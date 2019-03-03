#ifndef STATISTICS_H
#define STATISTICS_H

#include <math.h>

class Statistics {
    public:
        Statistics();
        /*
         * Calculate cumulative probability density for value x in a normal
         * distribution.
         */
        double Norm(double x);
    private:
};

#endif

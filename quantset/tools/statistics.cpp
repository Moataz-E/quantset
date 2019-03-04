#include "statistics.h"

Statistics::Statistics() { }

/*
 * Calculate cumulative probability density for value x in a normal
 * distribution.
 */
double Statistics::Norm(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

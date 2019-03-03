#include "statistics.h"

Statistics::Statistics() { }

/*
 * Calculate cumulative probability density for value x in a normal
 * distribution.
 */
double Statistics::Norm(double x) {
    return 0.5 * erfc(-x / sqrt(2));
}

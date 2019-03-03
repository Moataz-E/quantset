#include <math.h>
#include "timespan.h"

Timespan::Timespan() {}

Timespan::Timespan(int weeks, int days, int hours, int minutes,
                  long int seconds)
{
    internal_seconds_ = 0.0;
    internal_seconds_ += WeeksToSeconds(weeks);
    internal_seconds_ += DaysToSeconds(days);
    internal_seconds_ += HoursToSeconds(hours);
    internal_seconds_ += MinutesToSeconds(minutes);
    internal_seconds_ += seconds;
}

long int Timespan::WeeksToSeconds(int weeks) {
    return DaysToSeconds(weeks * 7);
}

long int Timespan::DaysToSeconds(int days) {
    return HoursToSeconds(days * 24);
}

long int Timespan::HoursToSeconds(int hours) {
    return MinutesToSeconds(hours * 60);
}

long int Timespan::MinutesToSeconds(int minutes) {
    return minutes * 60;
}

double Timespan::ApproximateYears() {
    return internal_seconds_ / 60.0 / 60.0 / 24.0 / 365.25;
}

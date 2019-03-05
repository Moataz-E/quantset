#ifndef TIMESPAN_H
#define TIMESPAN_H


class Timespan {
    public:
        // should be able to construct directly or using expiry date.
        Timespan();
        Timespan(int weeks, int days = 0, int hours = 0,
                 int minutes = 0, long int seconds = 0);
        double ApproximateYears();

        // getters
        long int SecondsSpan() const {return internal_seconds_;}

    private:
        long int seconds_;
        int minutes_;
        int hours_;
        int days_;
        int weeks_;
        long int internal_seconds_;
        long int WeeksToSeconds(int weeks);
        long int DaysToSeconds(int days);
        long int HoursToSeconds(int hours);
        long int MinutesToSeconds(int minutes);
};

#endif // TIMESPAN_H

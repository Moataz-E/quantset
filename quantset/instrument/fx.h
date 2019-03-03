#ifndef FX_H
#define FX_H

enum class CurrencyPair : int {
    EURUSD, GBPUSD, USDJPY, EURCHF, AUDUSD, USDCAD, NZDUSD, EURNOK, EURSEK,
    USDHKD, USDCNY, USDSGD, USDMXN, USDTRY, USDZAR, USDBRL
};

class FX {
    public:
        // constructor
        FX();
        explicit FX(CurrencyPair ccy_pair, double spot, double notional);
        // getters
        CurrencyPair CcyPair() const {return ccy_pair_;}
        double Spot() const {return spot_;}
        double Notional() const {return notional_;}

    private:
        CurrencyPair ccy_pair_;
        double spot_;
        double notional_;
};

#endif

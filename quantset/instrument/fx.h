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
        explicit FX(CurrencyPair ccy_pair, double spot, double spot_vol,
                    double ccy1_r, double ccy2_r);

        // getters
        CurrencyPair CcyPair() const {return ccy_pair_;}
        double Spot() const {return spot_;}
        double SpotVol() const {return spot_vol_;}
        double Ccy1Rate() const {return ccy1_r_;}
        double Ccy2Rate() const {return ccy2_r_;}

    private:
        CurrencyPair ccy_pair_;
        double spot_;
        double spot_vol_;
        double ccy1_r_;
        double ccy2_r_;
};

#endif

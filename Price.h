//  header guards
#ifndef __Price_h__
#define __Price_h__

//  mathematical functions
#include <cmath>
//  string strem processing
#include <sstream>
//  standard exceptions
#include <stdexcept>

//  sets entire std namespace scope
using namespace std;

// encapsulates class and functions 
namespace PPBOOK {

    template<class S>
    //  price of financial instrument
    class Price {

    public:
    // constructor initializes and validates price
        Price(double p) : p_(p){check(p);}
    // constructor initializes price with value of another Price object
        Price(const Price<S>& p) : p_(p.p_){}
    // member function definition
        double price() const {return p_;}

    // assignment operator for double price 
        Price<S>& operator=(double p)
            {check(p); p_ = p; return *this;}
        Price<S>& operator=(const Price<S>& p)
            {p_ = p.p_; return *this;}

    private:
    // stores price value
        double p_;
    // validate price value
        static void check(double p)
        {
            // price can not be negative
            if(p <= 0.0) {
                ostringstream s;
                s << S::name() << " price " << p
                << " must be positive.";
                throw invalid_argument(s.str());
            }
            // number of ticks corresponding to price value using tick size from Spec.h
            double nt = p / S::tick();
            // checks for whole number ticks
            if(fabs(floor(nt) * S::tick() - p) > 1.0e-8 && fabs(ceil(nt) * S::tick() - p) > 1.0e-8) {
                ostringstream s;
                s << S::name() << " price " << p
                << " must be a whole number of ticks " << S::tick();
                throw invalid_argument(s.str());
            }
        }
    };
// Only for illustration
//template<class S>
//double
//operator-(const Price<S>& lhs, const Price<S>& rhs)
//{
// return lhs.price() - rhs.price();
//}
} // PPBOOK
#endif /* __Price_h__ */ // closes header guard
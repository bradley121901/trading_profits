#include <vector>
#include <iostream>
using namespace std;
#include "Spec.h"
#include "Price.h"
using namespace PPBOOK;

typedef Price<SpecGC> GoldPrice;
typedef vector<GoldPrice> GoldPrices;
typedef Price<SpecCO> CrudeOilPrice;
typedef vector<CrudeOilPrice> CrudeOilPrices;

int main(int, char*[])
{
    try {
        GoldPrices gp;
        gp.push_back(449.10);
        CrudeOilPrices co;
        co.push_back(661.74);
    }
    catch(const exception& e) {
        cerr << e.what() << endl;
    }
    catch(...) {
        cerr << "Unknown exception" << endl;
    }
    return 0;
}

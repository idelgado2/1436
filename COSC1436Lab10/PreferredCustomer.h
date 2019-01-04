#ifndef PreferredCustomer_H
#define PreferredCustomer_H
#include "CustomerData.h"

class PreferredCustomer : public CustomerData{
private:
        double purchasesAmount;
        double discountLevel;
    
public:
    //accesor and mutator functions
    void setPurchasesAmount(double);
    void setDiscountLevel(double);
    
    double getPurchasesAmount();
    double getDiscountLevel();

    
};


#endif


#include "PreferredCustomer.h"

void PreferredCustomer::setPurchasesAmount(double purchases)
//purpose:  to set the memeber variable purchasesAmount with parameter and set the discountLevel
//pre-condition: passed string for initializing member variable
//post-condition: memebre variable is initialized and the correct pararmeter is passed to setDiscountLevel
{
    purchasesAmount = purchases;
    
    if (purchases >= 2000) {
        setDiscountLevel(10.0);
    }
    else if (purchases >= 1500){
        setDiscountLevel(7.0);
    }
    else if (purchases >= 1000){
        setDiscountLevel(6.0);
    }
    else if (purchases >= 500){
        setDiscountLevel(5.0);
    }
    else
        setDiscountLevel(0.0);
    
}
void PreferredCustomer::setDiscountLevel(double discount)
//purpose:  to set the memeber variable discountLevel with parameter
//pre-condition: passed string for initializing member variable
//post-condition: memebre variable is initialized
{
    discountLevel = discount;
}

double PreferredCustomer::getPurchasesAmount(){
    return purchasesAmount;
}

double PreferredCustomer::getDiscountLevel(){
    return discountLevel;
}



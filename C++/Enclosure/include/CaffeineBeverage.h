/*
 * @description 
 */

#ifndef CAFFEINEBEVERAGE_H_
#define CAFFEINEBEVERAGE_H_


class CaffeineBeverage//: public SOMECLASS
{
private: 


public: 
	CaffeineBeverage();
    virtual	~CaffeineBeverage();
    virtual void brew();
    virtual void addCondiments();
    void boilWater();
    void pourInCup();
    virtual void prepareRecipe() final;
};


#endif

/*
 * @description 
 */

#ifndef STATE_H_
#define STATE_H_


class State//: public SOMECLASS
{
private: 


public: 
    virtual void  insertQuarter() = 0;
    virtual void  ejectQuarter()  = 0;
    virtual void  turnCrank()     = 0;
    virtual void  dispense()      = 0;
};


#endif

#ifndef _BIG_U_INT_H_
#define _BIG_U_INT_H_

#include "BigUInt_Inf.h"
#include	<string>

class BigUInt {
private:
    BigUInt_Inf *bui;
public:
    BigUInt();
    BigUInt(const std::string&);
    BigUInt operator+(const BigUInt &);
    BigUInt operator-(const BigUInt &);
    BigUInt operator*(const BigUInt &);
    BigUInt operator/(const BigUInt &);
    BigUInt operator<<(const BigUInt &);
    BigUInt operator>>(const BigUInt &);
    BigUInt operator&(const BigUInt &);
    BigUInt operator|(const BigUInt &);
    BigUInt operator^(const BigUInt &);
    BigUInt operator~();
    bool operator==(const BigUInt &); 
    ~BigUInt();

private:
    void SetBui(BigUInt_Inf *);
};

#endif //_BIG_U_INT_H_

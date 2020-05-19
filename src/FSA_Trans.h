///************************************************************************/
/*!
@file FSA_Trans.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief CTrans class stores the next state to go and the function used
        to validate the state changing
*/
/**************************************************************************/

#ifndef FSA_Trans_h
#define FSA_Trans_h

#include <functional>

class CState;

class CTrans {
    
public:
    CTrans(const CState &nextSt,std::function<bool()> fct);
    bool isValid();
    void setInhib(bool bInhib);
    bool getInhib() const;
    CState* getNext() const;
    
private:
    std::function<bool()> _fct;
    CState & _nextSt;
    bool _bInhib;
};

#endif /* FSA_Trans_h */

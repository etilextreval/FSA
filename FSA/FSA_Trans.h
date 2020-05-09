///************************************************************************/
/*!
@file FSA_Trans.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#ifndef FSA_Trans_h
#define FSA_Trans_h
#include <functional>

class CState;

class CTrans {
    
public:
    CTrans(CState &nextSt,std::function<bool()> fct);
    bool isValid();
    
private:
    std::function<bool()> _fct;
    CState &_nextSt;
};

#endif /* FSA_Trans_h */

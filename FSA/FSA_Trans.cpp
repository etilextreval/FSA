///************************************************************************/
/*!
@file FSA_Trans.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include <stdio.h>
#include "FSA_Trans.h"
#include "FSA_State.h"

CTrans::CTrans(CState &nextSt,std::function<bool()> fct):
    _nextSt(nextSt),
    _fct(fct){
    
}

bool CTrans::isValid() {
    return _fct();
}

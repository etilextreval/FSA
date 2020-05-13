///************************************************************************/
/*!
@file FSA_Trans.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include "FSA_Trans.h"
#include "FSA_State.h"
#include <stdio.h>

/*!
 @brief Constructor
 @param nextSt reference,fct function pointer to validation function
 */
CTrans::CTrans(const CState &nextSt,std::function<bool()> fct):
    _nextSt((CState&)nextSt),
    _fct(fct){    
}

/*!
 @brief validation function
 */
bool CTrans::isValid() {
    
    return _fct();
}

/*!
 @brief get the next state to go
 @return _nextSt pointer
 */
CState* CTrans::getNextState() {
    
    return &_nextSt;
}


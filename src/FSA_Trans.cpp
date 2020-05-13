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
 @param nextSt : reference to next state if trans is valid
 @param fct : function used to valid trans
 */
CTrans::CTrans(const CState &nextSt,std::function<bool()> fct):
    _nextSt((CState&)nextSt),
    _fct(fct){    
}

/*!
 @brief Validation function
 @return _fct() return value
 */
bool CTrans::isValid() {
    
    return _fct();
}

/*!
 @brief Get the next state to go
 @return _nextSt : pointer to next state
 */
CState* CTrans::getNext() {
    
    return &_nextSt;
}


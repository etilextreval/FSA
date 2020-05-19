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
//#include "FSA_State.h"
#include <stdio.h>

/*!
 @brief Constructor
 @param nextSt : reference to next state if trans is valid
 @param fct : function used to valid trans
 */
CTrans::CTrans(const CState &nextSt,std::function<bool()> fct):
    _nextSt((CState&)nextSt),
    _fct(fct),
    _bInhib(false)
{
}

/*!
 @brief Validation function
 @return _fct() return value
 */
bool CTrans::isValid() {
    
    return (!_bInhib) ? _fct() : false;
}

/*!
 @brief Set the value of trans inhibition
 @param bInhib : the value to set (bool)
 */
void CTrans::setInhib(bool bInhib) {
    
    _bInhib = bInhib;
}

/*!
 @brief Get the current value of trans inhibition
 @return _bInhib : the value
 */
bool CTrans::getInhib() const {

    return _bInhib;
}

/*!
 @brief Get the next state to go
 @return _nextSt : pointer to next state
 */
CState* CTrans::getNext() const {
    
    return &_nextSt;
}


///************************************************************************/
/*!
@file FSA_State.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include "FSA_State.h"

#include "FSA_Ctx.h"
#include <stdio.h>

/*!
 @brief Constructor
 @param ctx : context for the state, last : true if state must be the last
 */
CState::CState(CStateCtx &ctx,bool last):
    _ctx(ctx),
    _isLast(last)
{
}

/*!
 @brief Copy constructor
 @param st : state to copy
 */
CState::CState(const CState &st):
    _ctx(st._ctx),
    _isLast(st._isLast)
{
}


/*!
 @brief equal operator override
 @param st : state to copy
 @return : *this reference
 */
CState& CState::operator=(CState &st) {
    
    _ctx = st._ctx;
    _isLast = st._isLast;
    return *this;
}

/*!
 @brief Destructor
 */
CState::~CState() {
    
}

/*!
 @brief Executes entering operations
 */
void CState::runEnter() const {
    
    _ctx.runEnter();
}

/*!
 @brief Executes progressing operations
 */
void CState::runProgress() const {
    
    _ctx.runProgress();
}

/*!
 @brief Executes exiting operations
 */
void CState::runExit() const {
    
    _ctx.runExit();
}

/*!
 @brief get the last state status
 @return status (_isLast bool member)
 */
bool CState::isLast() {
    
    return _isLast;
}

/*!
 @brief Gets next state to go if a valid transition was found
 @return the next state ptr
 */
CState* CState::getNextState() const {

    return _ctx.getNextState();
}

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
 @param ctx reference
 */
CState::CState(CStateCtx &ctx,bool last):
    _ctx(ctx),
    _last(last)
{
}

CState::CState(const CState &st):
    _ctx(st._ctx),
    _last(st._last)
{
}

CState& CState::operator=(CState &st) {
    
    _ctx = st._ctx;
    _last = st._last;
    return *this;
}

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

bool CState::isLast() {
    
    return _last;
}

/*!
 @brief Gets next state to go if a valid transition was found
 @return the next state ptr
 */
CState* CState::getNextState() const {

    return _ctx.getNextState();
}

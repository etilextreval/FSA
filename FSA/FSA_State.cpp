///************************************************************************/
/*!
@file FSA_State.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include <stdio.h>
#include "FSA_State.h"
#include "FSA_Ctx.h"

CState::CState(CStateCtx &ctx):
    _ctx(ctx) {
}

CState::~CState() {
    
}


void CState::runEnter() {

    _ctx.runEnter();
}

/*!
 @brief Executes progressing operation
 */

void CState::runProgress() {
    
    _ctx.runProgress();
}

/*!
 @brief Executes exiting operation
 */

void CState::runExit() {
    
    _ctx.runExit();
}

/*!
 @brief Gets next state to go if a valid transition was found
 @return the next state ptr
 */

CState* CState::getNextState() {

    return _ctx.getNextState();
}

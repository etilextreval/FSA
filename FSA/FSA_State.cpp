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

/*!
 @brief Constructor
 @param ctx reference
 */
CState::CState(CStateCtx &ctx):

    _ctx(ctx) {
}

CState::~CState() {
}

/*!
 @brief Executes entering operations
 */
void CState::runEnter() {

    _ctx.runEnter();
}

/*!
 @brief Executes progressing operations
 */
void CState::runProgress() {
    
    _ctx.runProgress();
}

/*!
 @brief Executes exiting operations
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

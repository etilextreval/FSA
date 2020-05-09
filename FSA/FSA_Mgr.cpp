///************************************************************************/
/*!
@file FSA_Mgr.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include <stdio.h>
#include "FSA_Mgr.h"
#include "FSA_State.h"

CAbstractMgr::CAbstractMgr(CState& startSt) :
    _bEnterSt(true),
    _bProgressSt(false),
    _curSt(&startSt),
    _nextSt(nullptr)
{};

CAbstractMgr::~CAbstractMgr() {
    delete _nextSt;
}

void CAbstractMgr::run(void) {
    
    _pre();
    
    if(_bEnterSt) {                                    // on entering the current state
        _bEnterSt = false;
        _bProgressSt = true;
        _curSt->runEnter();                             // do entering actions once
    }
    
    if(_bProgressSt)
        _curSt->runProgress();                          // do progress actions (only if previously entered)
    
    _nextSt = _curSt->getNextState();                 // get the next state if a transition is true
    
    if(_nextSt != NULL) {                             // if next state was found
        _curSt->runExit();                              // do exit actions
        _curSt = _nextSt;                               // change for next state
        _bProgressSt = false;
        _bEnterSt = true;
    }
    
    _post();
}

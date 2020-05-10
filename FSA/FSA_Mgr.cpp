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

/*!
@brief Constructor
@param startSt reference (initial state to start the machine)
*/
CAbstractMgr::CAbstractMgr(CState& startSt) :
    _bEnter(true),
    _bProgress(false),
    _curSt(&startSt),
    _nextSt(nullptr)
{};

/*!
@brief Destructor
*/
CAbstractMgr::~CAbstractMgr() {
    //delete _curSt;
    //delete _nextSt;
}

/*!
@brief main function of the machine to manage
        _pre() is pre treatment on each loop (virtual)
        _post() is post treatment on each loop (virtual)
        run...() executes each state routine
*/
void CAbstractMgr::run() {
    
    _pre();
    
    if(_bEnter) {                                    // on entering the current state
        _bEnter = false;
        _bProgress = true;
        _curSt->runEnter();                             // do entering actions once
    }
    
    if(_bProgress)
        _curSt->runProgress();                          // do progress actions (only if previously entered)
    
    _nextSt = _curSt->getNextState();                 // get the next state if a transition is true
    
    if(_nextSt != nullptr) {                             // if next state was found
        _curSt->runExit();                              // do exit actions
        _curSt = _nextSt;                               // change for next state
        _bProgress = false;
        _bEnter = true;
    }

    _post();
}

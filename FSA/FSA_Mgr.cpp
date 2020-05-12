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
#include "FSA_Ctx.h"

/*!
@brief Constructor
@param startSt reference (initial state to start the machine)
*/
CAbstractMgr::CAbstractMgr(const CState& startSt) :
    _bEnter(true),
    _bProgress(false),
    _bExit(false),
    _curSt(nullptr),
    _nextSt(nullptr)            // will be known and created in manage method
{
    _curSt = new CState(startSt);
}

/*!
 @brief Copy constructor
 @param mgr reference
 */
CAbstractMgr::CAbstractMgr(const CAbstractMgr &mgr):
    _bEnter(mgr._bEnter),
    _bProgress(mgr._bProgress),
    _bExit(mgr._bExit),
    _curSt(nullptr),
    _nextSt(nullptr)
{
    CState *pCur = mgr._curSt;
    CState *pNext = mgr._nextSt;
    if(pCur != nullptr)
        _curSt = new CState(*(mgr._curSt));
    if(pNext != nullptr)
        _nextSt = new CState(*(mgr._nextSt));
}

/*!
 @brief = operator override
 @param mgr reference
 @return *this
 */
CAbstractMgr& CAbstractMgr::operator=(const CAbstractMgr &mgr) {

    _bEnter = mgr._bEnter;
    _bProgress = mgr._bProgress;
    _curSt = nullptr;
    _nextSt = nullptr;
    CState *pCur = mgr._curSt;
    CState *pNext = mgr._nextSt;
    if(pCur != nullptr)
        _curSt = new CState(*pCur);
    if(pNext != nullptr)
        _nextSt = new CState(*pCur);

    return *this;
}

/*!
@brief Destructor
*/
CAbstractMgr::~CAbstractMgr() {
    
    delete _curSt;
    delete _nextSt;
}

void CAbstractMgr::run() {
    
    _activity = RUN;
}

void CAbstractMgr::stop() {
    
    _activity = STOP;
}

/*!
@brief managing function of the machine
        _pre() is pre process on each loop (virtual)
        _post() is post process on each loop (virtual)
        run...() executes each current state routine
 */
void CAbstractMgr::manage() {
    
    if(_activity == RUN) {
        
        _pre();

        if(_bEnter) {
            _bEnter = false;
            _bProgress = true;
            _curSt->runEnter();
        }

        if(_bProgress)
            _curSt->runProgress();

        if(_curSt->isLast()) {
            _bExit = true;
            _nextSt = nullptr;
        }
        else {
            CState *st = _curSt->getNextState();        // test transitions
            if(st != nullptr) {                         // if a valid transition was found
                _bExit = true;
                _nextSt = new CState(*st);
            }
            else {
                _bExit = false;
                _nextSt = nullptr;
            }
        }
        
        if(_bExit) {
            _curSt->runExit();
            if(_nextSt != nullptr) {
                _curSt = _nextSt;
                _nextSt = nullptr;
            }
            _bEnter = true;
            _bProgress = false;
            _bExit = false;
        }
    
        _post();
    }

    if(_curSt->isLast())
        _activity = STOP;
}

bool CAbstractMgr::isRun() {
    
    return(_activity == RUN);
}



///************************************************************************/
/*!
@file FSA_Mgr.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include "FSA_Mgr.h"
#include "FSA_Ctx.h"
#include "FSA_State.h"
#include <stdio.h>

CMgr::CMgr() :
    _bEnter(true),
    _bProgress(false),
    _bExit(false),
    _initSt(nullptr),
    _curSt(nullptr),
    _nextSt(nullptr)   
{}

/*!
@brief Constructor
@param startSt reference (initial state to start the machine)
*/
CMgr::CMgr(const CState& startSt) :
    _bEnter(true),
    _bProgress(false),
    _bExit(false),
    _initSt(nullptr),
    _curSt(nullptr),
    _nextSt(nullptr)            // will be known and created in manage method
{
    _curSt = new CState(startSt);
    _initSt = _curSt;
}

/*!
 @brief Copy constructor
 @param mgr reference
 */
CMgr::CMgr(const CMgr &mgr) :
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
 @return *this reference
 */
CMgr& CMgr::operator=(const CMgr &mgr) {

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
CMgr::~CMgr() {
    
    delete _curSt;
    delete _nextSt;
}

void CMgr::setInitState(const CState &startSt) {
    _curSt = new CState(startSt);
    _initSt = _curSt;
};

/*!
 @brief Set the current mode of manager
 @param mode : enum mgrMode
 */
void CMgr::setMode(mgrMode mode) {
    
    _mode = mode;
    if(_mode == STOP) {
        _reset();
    }
}

/*!
@brief managing function of the machine
        _pre() is pre process on each loop (virtual)
        _post() is post process on each loop (virtual)
        run...() executes each current state routine
 */
void CMgr::manage() {
    
    if(_mode == RUN) {
        
        _bProgress = !_bEnter && !_bExit;
        
        _pre();

        if(_bEnter) {
            _bEnter = false;
            _curSt->runEnter();
            return;
        }

        if(_bProgress)
            _curSt->runProgress();

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
        else {
            if(_curSt->isLast()) {
                _bExit = true;
                _nextSt = nullptr;
                return;
            }
            else {
                CState *st = _curSt->getNextState();        // test transitions
                if(st != nullptr) {                         // if a valid transition was found
                    _bExit = true;
                    _nextSt = new CState(*st);
                    return;
                }
                else {
                    _bExit = false;
                    _nextSt = nullptr;
                    return;
                }
            }
        }
    
        _post();
    }

    if(_curSt->isLast())
        _mode = STOP;
}

/*!
 @brief Get the current running mode of the manager
 @return true only if is running
 */
bool CMgr::isRun() {
    
    return(_mode == RUN);
}

/*!
 @brief Restore the initial state of manager (created in constructor)
 */
void CMgr::_reset() {
    
    _curSt = _initSt;
    _nextSt = nullptr;
    _bEnter = true;
    _bProgress = false;
    _bExit = false;
}

///************************************************************************/
/*!
@file FSA_Mgr.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
 @brief CAbstractMgr abstract class :
            - Stores the current state pointer
            - Stores the next state to go for a valid trans
            - Manage execution of runXXX methods of current state
            - Can be runned / stopped / paused
            - Has _pre() and _post() virtual methods for cyclic operations
                in derived classes
*/
/**************************************************************************/

#ifndef FSA_Mgr_h
#define FSA_Mgr_h

#include "FSA_State.h"

class CState;

class CMgr {
    
public:
    CMgr();
    CMgr(const CState &startSt);
    CMgr(const CMgr &mgr);
    CMgr& operator=(const CMgr &mgr);
    virtual ~CMgr();
    enum mgrMode {  STOP,
                    RUN,
                    PAUSE};
    void setInitState(const CState &startSt);
    void setMode(mgrMode mode);
    void manage();
    bool isRun();
    
protected:
    virtual void _pre(){};
    virtual void _post(){};
    
private:
    mgrMode _mode;
    bool _bEnter;
    bool _bProgress;
    bool _bExit;
    CState *_initSt;
    CState *_curSt;
    CState *_nextSt;
    void _reset();
};


#endif /* FSA_Mgr_h */

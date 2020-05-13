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
        CMgr derived class of CAbstractMgr :
            - Has _pre() and _post() methods for permanent treatms
*/
/**************************************************************************/

#ifndef FSA_Mgr_h
#define FSA_Mgr_h

class CState;

class CAbstractMgr {
    
public:
    CAbstractMgr(const CState &startSt);
    CAbstractMgr(const CAbstractMgr &mgr);
    CAbstractMgr& operator=(const CAbstractMgr &mgr);
    virtual ~CAbstractMgr();
    enum mgrMode {STOP,RUN,PAUSE};
    void setMode(mgrMode mode);
    void manage();
    bool isRun();
    
protected:
    virtual void _pre()=0;
    virtual void _post()=0;
    
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

class CMgr : public CAbstractMgr {
    
public:
    CMgr(const CState& startSt):
    CAbstractMgr(startSt)
    {};
    
    void _pre() override;
    void _post() override;
};

#endif /* FSA_Mgr_h */

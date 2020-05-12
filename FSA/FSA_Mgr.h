///************************************************************************/
/*!
@file FSA_Mgr.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
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
    void run();
    void stop();
    void manage();
    bool isRun();
    
protected:
    virtual void _pre()=0;
    virtual void _post()=0;
    
private:
    enum : short {STOP,RUN} _activity;
    bool _bEnter;
    bool _bProgress;
    bool _bExit;
    CState *_curSt;
    CState *_nextSt;
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

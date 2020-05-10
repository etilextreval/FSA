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
    CAbstractMgr(CState& startSt);
    virtual ~CAbstractMgr();
    void run();
    
protected:
    virtual void _pre()=0;
    virtual void _post()=0;
    
private:
    bool _bEnter;
    bool _bProgress;
    CState *_curSt;
    CState *_nextSt;
};

class CMgr : public CAbstractMgr {
    
public:
    CMgr(CState& startSt):
    CAbstractMgr(startSt)
    {};
    ~CMgr(){};
    void _pre() override;
    void _post() override;
};


#endif /* FSA_Mgr_h */

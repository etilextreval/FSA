///************************************************************************/
/*!
@file FSA_Ctx.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
 @brief  CStateCtx class used to :
    - Creates and stores CTrans objects in vector
    - Executes runXXXX methods (of derived classes)
    - Manage CTrans objects validation by their functions

 */
/**************************************************************************/

#ifndef FSA_Ctx_h
#define FSA_Ctx_h

#include "FSA_Trans.h"
#include <functional>
#include <vector>

class CState;
class CMgr;

class CStateCtx {
    
public:
    CStateCtx();
    CStateCtx(const CStateCtx &ctx);
    CStateCtx& operator=(const CStateCtx &ctx);
    virtual ~CStateCtx();
    virtual void runEnter(){};
    virtual void runProgress(){};
    virtual void runExit(){};
    template<class T> CTrans* setTrans(const CState &nextSt,std::function<bool(T&)> fct);
    CTrans* setTrans(const CState &nextSt,std::function<bool()> fct);
    CTrans* getValidTrans() const;
    CState* getNextState() const;
    void inhibAllTrans(bool bInhib) const;
    void test(){};
    
protected:
    std::vector<CTrans*> _lstTrans;
};

template<class T> CTrans* CStateCtx::setTrans(const CState &nextSt,std::function<bool(T&)> fct){
    
    std::function<bool()> _fct = std::bind(fct,std::ref((T&)*this));
    CTrans *tr = new CTrans(nextSt,_fct);
    if(tr != nullptr)
        _lstTrans.push_back(tr);
    return tr;
}

#endif

/* FSA_Ctx_h */

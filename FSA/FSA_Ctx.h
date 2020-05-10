///************************************************************************/
/*!
@file FSA_Ctx.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#ifndef FSA_Ctx_h
#define FSA_Ctx_h

#include <functional>
#include <vector>
#include "FSA_Trans.h"

class CState;
class CTrans;

class CStateCtx {
    
public:
    CStateCtx(){};
    virtual ~CStateCtx();
    virtual void runEnter(){};
    virtual void runProgress(){};
    virtual void runExit(){};
    template<class T> CTrans* setTrans(CState &nextSt,std::function<bool(T&)> fct);
    CTrans* setTrans(CState &nextSt,std::function<bool()> fct);
    CTrans* getValidTrans();
    CState* getNextState();
    
protected:
    std::vector<CTrans*> _lstTrans;
};

template<class T>
CTrans* CStateCtx::setTrans(CState &nextSt,std::function<bool(T&)> fct){
    
    std::function<bool()> _fct = std::bind(fct,std::ref((T&)*this));
    CTrans *tr = new CTrans(nextSt,_fct);
    if(tr != nullptr)
        _lstTrans.push_back(tr);
    return tr;
}


#endif /* FSA_Ctx_h */

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
    void runEnter(){};
    void runProgress(){};
    void runExit(){};
    CState* getNextState(){ return nullptr;};
    template<class T> CTrans* setTrans(CState &nextSt,std::function<bool(T&)> fct);
    CTrans* setTrans(CState &nextSt,std::function<bool()> fct);
    CTrans* getValidTrans();
    
protected:
    std::vector<CTrans*> _lstTrans;
};

template<class T>
CTrans* CStateCtx::setTrans(CState &nextSt,std::function<bool(T&)> fct){
    
    std::function<bool()> _fct = std::bind(fct,(T&)*this);
    CTrans *tr = new CTrans(nextSt,_fct);
    if(tr != nullptr)
        _lstTrans.push_back(tr);
    tr->isValid();          //TEST
    return tr;
}


#endif /* FSA_Ctx_h */

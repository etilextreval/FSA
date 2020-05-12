///************************************************************************/
/*!
@file FSA_Ctx.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include <stdio.h>
#include "FSA_Ctx.h"

#include "FSA_State.h"
#include "FSA_Trans.h"


CStateCtx::CStateCtx() {
    
}

CStateCtx::CStateCtx(const CStateCtx &ctx) {
    
    _lstTrans = ctx._lstTrans;
}
/*
CStateCtx& CStateCtx::operator=(const CStateCtx &ctx) {
    
    _lstTrans.erase(_lstTrans.begin(),_lstTrans.end());
    _lstTrans = ctx._lstTrans;
    return *this;
}*/

/*!
 @brief Destructor : deletes each trans of _lstTrans and vector
 */
CStateCtx::~CStateCtx(){
    
    for(std::vector<CTrans*>::iterator tr=_lstTrans.begin();tr != _lstTrans.end();++tr)
        delete (*tr);
    _lstTrans.clear();
}

/*!
 @brief Creates CTrans object with next state to go and function pointer to validate
        Puts CTrans object into vector
 @param nextSt reference,fct pointer
 @return CTrans pointer
 */
CTrans* CStateCtx::setTrans(const CState &nextSt,std::function<bool()> fct) {
 
    CTrans *tr = new CTrans(nextSt,fct);
    if(tr != nullptr)
        _lstTrans.push_back(tr);
    return tr;
}

/*!
 @brief Gets the first valid trans in vector
 @return CTrans pointer
 */
CTrans* CStateCtx::getValidTrans() const {

    for(std::vector<CTrans*>::const_iterator it = _lstTrans.begin(); it!=_lstTrans.end() ; ++it)
        if((*it)->isValid())
            return *it;
    return nullptr;
}

/*!
 @brief Gets the next state to go for the first valid trans in vector
 @return CState pointer
 */
CState* CStateCtx::getNextState() const {
    
    CTrans *tr = getValidTrans();
    if(tr != nullptr)
        return tr->getNextState();
    return nullptr;
}

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

CStateCtx::~CStateCtx(){

    for(std::vector<CTrans*>::iterator tr=_lstTrans.begin();tr != _lstTrans.end();++tr)
        delete (*tr);
    _lstTrans.clear();
}

CTrans* CStateCtx::setTrans(CState &nextSt,std::function<bool()> fct) {
 
    CTrans *tr = new CTrans(nextSt,fct);
    if(tr != nullptr)
        _lstTrans.push_back(tr);
    tr->isValid();          //TEST
    return tr;
}

CTrans* CStateCtx::getValidTrans() {

    for(std::vector<CTrans*>::iterator it = _lstTrans.begin(); it!=_lstTrans.end() ; ++it)
        if((*it)->isValid())
            return *it;
    return nullptr;
}


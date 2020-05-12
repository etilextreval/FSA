///************************************************************************/
/*!
@file main.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include "main.hpp"

void CWaitCtx::runEnter(){
    _i = 0;
    std::cout << "Entering wait state" << std::endl;
};

void CWaitCtx::runProgress(){
    std::cout << "Progressing wait state" << std::endl;
};

void CWaitCtx::runExit(){
    std::cout << "Exiting wait state" << std::endl;
};

bool CWaitCtx::toMenu(){
    _i++;
    if(_i >=10)
        std::cout << "toMenu transition" << std::endl;
    
    return (_i >= 10);
};

void CMenuCtx::runEnter(){
    _i = 0;
    std::cout << "Entering menu state" << std::endl;
};

void CMenuCtx::runProgress(){
    std::cout << "Progressing menu state" << std::endl;
};

void CMenuCtx::runExit(){
    std::cout << "Exiting menu state" << std::endl;
};

bool CMenuCtx::toWait(){
    _i++;
    if(_i >= 5)
        std::cout << "toWait transition" << std::endl;
    
    return (_i >= 5);
};

void CMgr::_pre() {
    
}

void CMgr::_post() {
    
}

int main(int argc, const char * argv[]) {
    
    CWaitCtx ctxWait;
    CState stWait(ctxWait);
    
    CMenuCtx ctxMenu;
    CState stMenu(ctxMenu,true); // last state will stop mgr
    
    CMgr mgr(stWait);
    
    ctxWait.setTrans<CWaitCtx>(stMenu,&CWaitCtx::toMenu);
    ctxMenu.setTrans<CMenuCtx>(stWait,&CMenuCtx::toWait);
    
    mgr.run();
    
    while(mgr.isRun()) {
        mgr.manage();
    } 
 
    return 0;
}

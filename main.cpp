///************************************************************************/
/*!
@file main.cpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#include <iostream>
#include <functional>
#include <vector>
#include "main.hpp"
#include "FSA.h"

class CWaitCtx : public CStateCtx {
    
public:
    CWaitCtx():
    _i(0)
    {};
    bool toMenu();
    void runEnter();
    
private:
    int _i;
};

void CWaitCtx::runEnter(){
    _i = 0;
    std::cout << "Entering wait state" << std::endl;
};

bool CWaitCtx::toMenu(){
    _i++;
    std::cout << "toMenu transition" << std::endl;
    
    return (_i >= 10);
};

class CMenuCtx : public CStateCtx {
    
public:
    CMenuCtx():
    _i(0)
    {};
    bool toWait();
    void runEnter();
    
private:
    int _i;
};

void CMenuCtx::runEnter(){
    _i = 0;
    std::cout << "Entering menu state" << std::endl;
};

bool CMenuCtx::toWait(){
    _i++;
    std::cout << "toWait transition" << std::endl;
    
    return (_i >= 5);
};

void CMgr::_pre() {
    
}

void CMgr::_post() {
    
}

int main(int argc, const char * argv[]) {
    
    // a derived class for context
    CWaitCtx wait;
    CState stWait(wait);
    
    // a simple instance of CStateCtx for context
    CMenuCtx menu;
    CState stMenu(menu);
    
    // the manager
    CMgr mgr(stWait);
    
    // attach a member function to a trans for the context
    wait.setTrans<CWaitCtx>(stMenu,&CWaitCtx::toMenu);
    
    menu.setTrans<CMenuCtx>(stWait,&CMenuCtx::toWait);
    
    int i = 0;
    while(i < 100) {
        mgr.run();
        ++i;
    }
    /*
     // use a lambda expression for trans
     wait.setTrans(stMenu,[]()->bool{
     std::cout << "test lambda" << std::endl;
     return false;
     });
     
     // use a lambda expression for trans (return type can be ommitted
     menu.setTrans(stWait,[](){
     std::cout << "test lambda CStateCtx" << std::endl;
     return false;
     });
     */
    return 0;
}

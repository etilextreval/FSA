///************************************************************************/
/*!
@file main.hpp
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#ifndef main_hpp
#define main_hpp

#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include "FSA.h"

class CWaitCtx : public CStateCtx {
    
public:
    CWaitCtx():
    _i(0)
    {};
    bool toMenu();
    void runEnter() override;
    void runProgress() override;
    void runExit() override;
    
private:
    int _i;
};

class CMenuCtx : public CStateCtx {
    
public:
    CMenuCtx():
    _i(0)
    {};
    bool toWait();
    void runEnter() override;
    void runProgress() override;
    void runExit() override;
    
private:
    int _i;
};

#endif /* main_hpp */

///************************************************************************/
/*!
@file FSA_State.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
 @brief CState class :
            - Stores a unique context (CStateCtx object or derived)
            - Executes context methods runXXX
            - Access next states of context vector of trans
*/
/**************************************************************************/

#ifndef FSA_State_h
#define FSA_State_h

#include "FSA_Mgr.h"
#include "FSA_Ctx.h"

class CState {
    
public:
    CState(CStateCtx &ctx,bool last = false);
    CState(const CState &st);
    CState& operator=(CState &st);
    ~CState();
    void runEnter() const;
    void runProgress() const;
    void runExit() const ;
    bool isLast();
    CState* getNextState() const;
    CStateCtx& getCtx() const {
        return _ctx;
    };
    
private:
    CStateCtx &_ctx;
    bool _isLast;
};


#endif /* FSA_State_h */

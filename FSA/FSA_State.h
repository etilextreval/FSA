///************************************************************************/
/*!
@file FSA_State.h
Original source by Alex Livrette (aka. etilextreval)
released to the public domain
License: MIT (see LICENSE)
@brief
*/
/**************************************************************************/

#ifndef FSA_State_h
#define FSA_State_h

class CStateCtx;

class CState {
public:
    CState(CStateCtx &ctx);
    ~CState();
    void runEnter();
    void runProgress();
    void runExit();
    CState* getNextState();
    
private:
    CStateCtx &_ctx;
};


#endif /* FSA_State_h */

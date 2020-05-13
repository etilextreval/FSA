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
    CState(CStateCtx &ctx,bool last = false);
    CState(const CState &st);
    CState& operator=(CState &st);
    ~CState();
    void runEnter() const;
    void runProgress() const;
    void runExit()const ;
    bool isLast();
    CState* getNextState() const;
    
private:
    CStateCtx &_ctx;
    bool _isLast;
};


#endif /* FSA_State_h */

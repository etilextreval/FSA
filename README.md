# FSA
A C++ library to implement FSM (Finite State Machine) on Arduino / Espressif plateforms

You can use directly several classes or derived them to manage complete Finite State Machine into your device 

## Installation

- Download and unzip the file into the *Library* folder of your sketchbook path
- Restart Arduino IDE
    or
- Use the *Importing a .zip Library* directly into the Arduino IDE

For more informations please follow the Arduino.cc tutorial : [Importing a .zip Library](https://www.arduino.cc/en/guide/libraries#toc4)

## Quick start

### Context class declaration 

Create a derived class of *CStateCtx* (the context for a state) here named for example *CWaitCtx*. 

```c++
class CWaitCtx : public CStateCtx {

public:
    CWaitCtx()
    {};
};
```

### State methods declaration 

Implement in your *CWaitCtx* derived class the following 3 methods : 

- *runEnter()* will be executed only when entering state
- *runProgress()* will be executed on every cycle of the machine for the state
- *runExit()* will be executed only when exiting state 

Note that the signature of these methods must be *void runXXXX()*

```c++
class CWaitCtx : public CStateCtx {

public:
    CWaitCtx()
    {};
    void runEnter() override;
    void runProgress() override;
    void runExit() override;
};
```

### Transition methods declaration 

Implement at least a transition method in your derived class (choose any name for it, here *toMenu* was choosed).

Note that the transition method toMenu() must have a *bool xxxx()* signature

```c++
class CWaitCtx : public CStateCtx {

public:
    CWaitCtx()
    {};
    bool toMenu();                          //a transition method
    void runEnter() override;
    void runProgress() override;
    void runExit() override;
};
```

### Methods definition 

Once it's done you will have to define all of the methods previously declared in the *CWaitCtx* class.


### Create an instance of your derived class *CWaitCtx* for example in the setup function : 

```c++

void setup() {

    CWaitCtx ctxWait;   // a CWaitCtx instance
}
```

### Create an instance of *CState* class : 

Note that the *CState* instance must receive a *CStateCtx* instance (here the CWaitCtx instance previously defined).

```c++

void setup() {

    CWaitCtx ctxWait;   
    CState stWait(ctxWait); // a CState instance (with context instance parameter)
}
```
### Create an instance of  *CMgr* class (the machine itself) :

```c++

void setup() {

    CMgr mgr;           // a CMgr manager instance
}
```




## Usage




## Changelog

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

### Instanciate a *CMgr* (the machine itself)

```C++
// a manager instance
CMgr mgr;
```

### Create a derived class of *CStateCtx* (the context for a state)

### Implements in your derived class the *runEnter()*, *runProgress()* and *runExit()* methods (used respect. to do actions for entering, progressing and exiting a state)

### Implement at least a transition method in your derived class (choose any name for it)


## Usage




## Changelog

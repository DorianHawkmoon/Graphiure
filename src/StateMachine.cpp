/* 
 * File:   StateMachine.cpp
 * Author: dorian
 * 
 * Created on 9 de marzo de 2015, 21:16
 */

#include <stdlib.h>

#include "StateMachine.h"

StateMachine::StateMachine(int numberTransitions): transitions(numberTransitions) {
    for(int i=0; i<numberTransitions; ++i){
        transitions[i]=std::vector<Transition>();
    }
}

void StateMachine::addTransition(Transition &transition) {
    
    transitions[transition.state].push_back(std::move(transition));
}

int StateMachine::processEntry(int entry) {
    std::vector<Transition> stateTransition=transitions[state];
    uint i=0;
    bool finish=false;
    while(i<stateTransition.size() && !finish){
        if(stateTransition[i].entry==entry){
            finish=true;
            state=stateTransition[i].newState;
        }
    }
    return (finish)? state:-1;
}

StateMachine::~StateMachine() {

}
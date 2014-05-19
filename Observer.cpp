/* 
 * File:   Observer.cpp
 * Author: johadunf
 * 
 * Created on May 19, 2014, 8:32 AM
 */

#include "Observer.h"
#include <iostream>

void Observer::eventStateChanged(){
    std::cout << "Observer notified that state changed" << std::endl;
}


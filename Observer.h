/* 
 * File:   Observer.h
 * Author: johadunf
 *
 * Created on May 19, 2014, 8:32 AM
 */

#ifndef OBSERVER_H
#define	OBSERVER_H
#include "libs/lineedit/EditorMachineObserver.h"

class Observer : public EditorMachineObserver{
public:
    void eventStateChanged(void);
private:

};

#endif	/* OBSERVER_H */


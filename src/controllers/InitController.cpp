#include "ControllerManager.h"
#include "TestCtrl.h"


void initController(ControllerManager* manager){
    manager->addController(new TestCtrl());
}
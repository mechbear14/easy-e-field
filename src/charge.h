#ifndef CHARGE_H
#define CHARGE_H

#include "ofMain.h"

class Charge
{

public:
    Charge();
    Charge(ofVec2f location, int charge);

    ofVec2f getLocation();
    int getCharge();
    void render(float size);

private:
    ofVec2f location;
    int charge;

};

#endif // CHARGE_H

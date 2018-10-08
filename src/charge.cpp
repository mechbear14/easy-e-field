#include "charge.h"
#include "string"

Charge::Charge(){

}

Charge::Charge(ofVec2f location, int charge){
    this->location = location;
    this->charge = charge;
}

int Charge::getCharge(){
    return this->charge;
}

ofVec2f Charge::getLocation(){
    return this->location;
}

void Charge::render(float size){
    ofColor colour = (this->charge) > 0 ? (ofColor::red) : (ofColor::darkGreen);
    string sign = (this->charge) > 0 ? "+" : "";
    string num = std::to_string(this->charge);
    string out = sign.append(num);

    ofFill();
    ofSetColor(colour);
    ofDrawCircle(this->location, size);
    ofNoFill();
    ofSetColor(ofColor::white);
    ofSetLineWidth(2);
    ofDrawCircle(this->location, size);
    ofDrawBitmapString(out, this->location - ofVec2f(10, 0));
}

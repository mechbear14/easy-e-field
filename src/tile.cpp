#include "tile.h"
#include "ofMain.h"

Tile::Tile(){

}

Tile::Tile(float x, float y){
    this->position = ofVec2f(x, y);
    this->field = ofVec2f(0, 0);
}

void Tile::setPos(float x, float y){
    this->position.set(x, y);
}

void Tile::setPos(ofVec2f pos){
    this->position.set(pos);
}

ofVec2f Tile::getPos(){
    return this->position;
}

void Tile::setVec(float x, float y){
    this->field.set(x, y);
}

void Tile::setVec(ofVec2f vec){
    this->field.set(vec);
}

ofVec2f Tile::getVec(){
    return this->field;
}

void Tile::addVec(float x, float y){
    this->field += ofVec2f(x, y);
}

void Tile::addVec(ofVec2f vec){
    this->field += vec;
}

float Tile::map(float val, float min, float max){
    float map = (min == max) ? 0.0f : (val - min) / (max - min);
    return map;
}

void Tile::update(){
    this->arrow = this->field.getNormalized();
}

void Tile::render(float min, float max, float len){
    float colourStop = this->map(this->field.length(), min, max);
    ofColor colour = (ofColor::blue).getLerped(ofColor::red, colourStop);

    ofVec2f start = this->position - (this->arrow) * len / 2;
    ofVec2f end = start + this->arrow * len;

    ofSetColor(colour);
    ofSetLineWidth(2);
    ofDrawLine(start, end);
    ofFill();
    ofDrawCircle(end, 2);
}



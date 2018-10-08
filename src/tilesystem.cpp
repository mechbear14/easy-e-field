#include "tilesystem.h"
#include "tile.h"
#include "cmath"

TileSystem::TileSystem(){

}

TileSystem::TileSystem(ofVec2f screenSize, ofVec2f tileSize){
    int x = ceil(screenSize.x / tileSize.x);
    int y = ceil(screenSize.y / tileSize.y);
    this->size = ofVec2f(x, y);

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            float xPos = (j + 0.5) * tileSize.x;
            float yPos = (i + 0.5) * tileSize.y;
            this->tiles.push_back(Tile(xPos, yPos));
        }
    }
}

void TileSystem::setArrowLength(int len){
    this->arrowLength = len;
}

void TileSystem::addCharge(Charge q){
    int charge = q.getCharge();
    ofVec2f loc = q.getLocation();

    ofVec2f size = this->size;
    for(int i = 0; i < size.y; i++){
        for(int j = 0; j < size.x; j++){
            int index = i * size.x + j;
            Tile current = this->tiles.at(index);
            ofVec2f dist = loc - current.getPos();
            ofVec2f field = this->getField(dist, charge);
            current.addVec(field);
            this->tiles.at(index) = current;
        }
    }

    this->maxMin();
}

void TileSystem::update(){
    for(int i = 0; i < size.y; i++){
        for(int j = 0; j < size.x; j++){
            int index = i * size.x + j;
            this->tiles.at(index).update();
        }
    }
}

void TileSystem::render(){
    for(int i = 0; i < size.y; i++){
        for(int j = 0; j < size.x; j++){
            int index = i * size.x + j;
            this->tiles.at(index).render(this->minField, this->maxField, this->arrowLength);
        }
    }
}

ofVec2f TileSystem::getField(ofVec2f dist, int charge){
    float d3 = pow(dist.length() / 10, 3);
    float e = (round(d3) == 0) ? 0 : (-20 * charge / d3);
    return e * dist;
}

void TileSystem::maxMin(){
    float max = 0;
    float min = 100;
    for(int i = 0; i < size.y; i++){
        for(int j = 0; j < size.x; j++){
            int index = i * size.x + j;
            float e = this->tiles.at(index).getVec().length();
            if(abs(e) > max) max = e;
            if(abs(e) < min) min = e;
        }
    }

    this->maxField = round(max);
    this->minField = round(min);
}



#ifndef TILE_H
#define TILE_H

#include "ofMain.h"

class Tile
{

public:
    Tile();
    Tile(float x, float y);

    ofVec2f getPos();
    void setPos(float x, float y);
    void setPos(ofVec2f pos);
    ofVec2f getVec();
    void setVec(float x, float y);
    void setVec(ofVec2f vec);
    void addVec(float x, float y);
    void addVec(ofVec2f vec);
    float map(float val, float min, float max);
    void update();
    void render(float min, float max, float len);

private:
    ofVec2f position;
    ofVec2f field;
    ofVec2f arrow;

};

#endif // TILE_H

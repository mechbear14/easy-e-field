#ifndef TILESYSTEM_H
#define TILESYSTEM_H

#include "ofMain.h"
#include "tile.h"
#include "charge.h"
#include "vector"

class TileSystem
{

public:
    TileSystem();
    TileSystem(ofVec2f screenSize, ofVec2f tileSize);

    void addCharge(Charge q);
    void setArrowLength(int len);
    void update();
    void render();

private:
    ofVec2f size;
    vector<Tile> tiles;
    int arrowLength;
    float maxField = 0.0f;
    float minField = 0.0f;

    ofVec2f getField(ofVec2f dist, int charge);
    void maxMin();

};

#endif // TILESYSTEM_H

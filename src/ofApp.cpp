#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofVec2f screenSize(ofGetWidth(), ofGetHeight());
    ofVec2f tileSize(20, 20);
    grid = TileSystem(screenSize, tileSize);
    grid.setArrowLength(10);
    ofSetBackgroundColor(ofColor(240));
}

//--------------------------------------------------------------
void ofApp::update(){
    grid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    grid.render();
    for(Charge c : charges){
        c.render(10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofVec2f location(x, y);
    Charge charge;
    if(button == OF_MOUSE_BUTTON_LEFT) charge = Charge(location, 1);
    else if(button == OF_MOUSE_BUTTON_RIGHT) charge = Charge(location, -1);
    charges.push_back(charge);
    grid.addCharge(charge);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

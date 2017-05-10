#include "ofApp.h"

void ofApp::setup(){
    mySound.load("/home/steve/song.mp3");
    mySound.setLoop(true);

    ofBuffer buff = ofBufferFromFile("/home/steve/score.txt");
    game.highScore = stoi(buff.getText());

}

void ofApp::update(){
        game.update();

}

void ofApp::draw(){
        game.draw();

}

void ofApp::mousePressed(int x, int y, int button){
    if (game.screen == game.START) {
        //TODO check if on start button
        game.screen = game.GAME;
        mySound.play();
    }
    else if (game.screen == game.GAME) {
        mySound.stop();
        game.screen = game.END;
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

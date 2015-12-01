#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(20, 20, 20);

    // Load sound
    beat.loadSound("intro.mp3");

    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }

    bands = 64;

    beat.setLoop(true);
    beat.setVolume(0.2);

    // Smooth out shape
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();

    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // Random circles in background
    for (int i = 0; i < bands; i++){

        float randomX = ofRandom (0, ofGetWidth());
        float randomY = ofRandom (0, ofGetHeight());
        ofSetColor(230, 241, 245);

            ofCircle(randomX, randomY, -(fftSmooth[i]*50));
            ofCircle(randomX, randomY, -(fftSmooth[i]*100));
            ofCircle(randomX, randomY, -(fftSmooth[i]*150));
    }

    // Lines
    for (int i = 0; i < bands; i++){

        ofSetColor(230, 241, 245);
        ofSetLineWidth(1.5);

        // From right top corner
        ofLine(ofGetWidth(), 0, 0, ofGetHeight()+fftSmooth[i]*2000);
        ofLine(ofGetWidth(), 0, 0, ofGetHeight()+fftSmooth[i]*-2000);

        // From left bottom corner
        ofLine(0, ofGetHeight(), ofGetWidth()+fftSmooth[i]*2000, 0);
        ofLine(0, ofGetHeight(), ofGetWidth()+fftSmooth[i]*-2000, 0);

        // From left top corner
        ofLine(0, 0, ofGetWidth()+fftSmooth[i]*1000, ofGetHeight());
        ofLine(0, 0, ofGetWidth()+fftSmooth[i]*-1000, ofGetHeight());

        // From right bottom corner
        ofLine(ofGetWidth(), ofGetHeight(), 0+fftSmooth[i]*1000, 0);
        ofLine(ofGetWidth(), ofGetHeight(), 0+fftSmooth[i]*-1000, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // If any key is pressed, start the song
    //beat.play();

    // If 1 is pressed, stop the song
    switch (key) {
        case '1':
            beat.play();
        break;
        case '2':
            beat.stop();
        break;
    }
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

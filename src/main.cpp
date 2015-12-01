#include "ofMain.h"
#include "ofApp.h"

int main(){
    // Open small window - used for testing
	//ofSetupOpenGL(1024,768,OF_WINDOW);

    // Open in fullscreen
    ofSetupOpenGL(1024,768,OF_FULLSCREEN);

	ofRunApp(new ofApp());

}

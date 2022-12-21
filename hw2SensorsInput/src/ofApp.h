#pragma once

#include "ofMain.h"
#include "ofxSimpleSerial.h"
#include <vector>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void onNewMessage(string & message);
    
        ofxSimpleSerial serial;
        string message;

    string xVS;
    string yVS;
    string aS;
        
    int xVal;
    int yVal;
    int angle;
    
    ofVec2f vPoint;
    ofVec2f vUnit;
    ofVec2f vDiff;

    string str0;

    int cX=0;
    int cY=0;
    
    ofEasyCam cam;
     
    float rotate;
    
//    ofxPanel gui;
    ofParameter <int> uiAmount;
    ofParameter <ofVec3f> uiPower;
//    ofParameter <float> uiRadius;
    ofParameter <ofVec2f> uiPosition;
    
};

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    cam.setDistance(200);
    
    ofBackground(0, 0, 0);
    ofSetWindowTitle("chanu HW 0927");
    ofSetLineWidth (2 );
    ofSetCircleResolution (128) ;
    ofEnableSmoothing();
    
    ofBackground(2,11,35);
    vUnit.set(534,476);
    
    int baud = 115200;
    serial.setup("/dev/cu.usbmodem212401", baud);
    
    serial.startContinuousRead();
    ofAddListener(serial.NEW_MESSAGE,this,&ofApp::onNewMessage);
    
    message = "";
}

void ofApp::onNewMessage(string & message)
{
    cout << "onNewMessage, message: " << message << "\n";
    
    vector<string> input = ofSplitString(message, ",");
    
    
    if(input.size() >= 3)
    {
        xVS = input.at(0);
        yVS = input.at(1);
        aS = input.at(2);
        

        xVal= ofToInt(xVS);
        yVal= ofToInt(yVS);
        angle= ofToInt(aS);
//        vPoint.set(xVal, yVal);


    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    cout << xVS << endl; //test
//    cout << yVS << endl; //test
//    cout << aS << endl; //test
//    vDiff = vPoint-vUnit;
    
//    str0 = "d:" + ofToString(vDiff.x) +","+ ofToString(vDiff.y);
//    cout << str0 << endl; // output the sensorValue

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofColor myC;
    myC.setHsb(223-angle, 255-xVal/12, 255-yVal/12);
    ofSetColor(myC);
    ofNoFill();
    ofRotateXDeg(xVal/5-104);
    ofRotateYDeg(yVal/5-100);
    ofDrawSphere(angle);
    ofRotateDeg(xVal);

    ofDrawCircle(0, 0, angle+10);
    
//    ofSetPolyMode(OF_POLY_WINDING_NONZERO); //fill curve
//
//    ofSetColor(204,233,233);
//    ofNoFill();
//    ofBeginShape();
//        ofCurveVertex(360+180, 495);
//        ofCurveVertex(360+180, 495);
//        ofCurveVertex(360, 607.5+77.5);
//        ofCurveVertex(360+180, 720);
//        ofCurveVertex(360+360, 607);
//        ofCurveVertex(360+181, 495);
//        ofCurveVertex(360+180, 495);
//    ofEndShape();
    cam.end();
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	v = new Vehicle(ofGetWindowWidth()/2,ofGetWindowHeight()/4);
	ofSetBackgroundColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
	v->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if(v->debug){
		ofSetCircleResolution(60);
		ofSetColor(0);
		ofNoFill();
		ofCircle(v->circleLocation,v->circleRadius);
	}
	v->boundaries();
	v->display();
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
	v->debug = !v->debug;
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

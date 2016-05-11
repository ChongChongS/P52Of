#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(640,360);
	ofSetBackgroundColor(255);
	//background(255);
	wind  = ofVec2f(0.01,0);
	gravity =ofVec2f(0,0.01);
	m = new Mover();   
}

//--------------------------------------------------------------
void ofApp::update(){
	m->applyForce(wind);
	m->applyForce(gravity);
	m->update();
	m->checkEdges();
}

//--------------------------------------------------------------
void ofApp::draw(){
	m->display();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(640,360);
	ofSetBackgroundColor(255);
	m1 = new Mover(ofGetWindowWidth()/2,100);
	m2 = new Mover(ofGetWindowWidth()/2,50);
	m3 = new Mover(ofGetWindowWidth()/2,150);
	s1 = new Spring(m1,m2,100);
	s2 = new Spring(m1,m3,100);
	s3 = new Spring(m3,m2,100);
}

//--------------------------------------------------------------
void ofApp::update(){
	s1->update();
	s2->update();
	s3->update();

	m1->update();
	m2->update();
	m3->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	s1->display();
	s2->display();
	s3->display();
	
	m1->display();
	m2->display();
	m3->display();
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
	m1->drag(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	m1->clicked(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	m1->stopDragging();
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

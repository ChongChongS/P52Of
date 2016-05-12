#include "ofApp2.h"

//--------------------------------------------------------------
void ofApp2::setup(){
	ofSetWindowShape(640,360);
	ofSetBackgroundColor(0);
	img.loadImage("texture.png");
	ps = new imgParticleSystem(0,ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight() - 75),img);
	ofSetFrameRate(30);
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp2::update(){
	float dx = ofMap(ofGetMouseX(),0,ofGetWindowWidth(),-0.2,0.2);
	ofVec2f wind = ofVec2f(dx,0);
	ps->applyForce(wind);
	ps->update();
	for(int i = 0; i < 2; i++)
		ps->addParticle();
}

//--------------------------------------------------------------
void ofApp2::draw(){
	ps->display();
}

//--------------------------------------------------------------
void ofApp2::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp2::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp2::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp2::dragEvent(ofDragInfo dragInfo){ 

}

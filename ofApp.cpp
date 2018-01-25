#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	
	ofEnableLighting();
	this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update() { }

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	this->light.setPosition(this->cam.getPosition());

	int size = 30;
	for (int x = -ofGetWidth(); x <= ofGetWidth(); x += size) {

		for (int y = -ofGetHeight(); y <= ofGetHeight(); y += size) {

			float z = ofNoise(ofVec2f(x, y).length() * 0.005 - ofGetFrameNum() * 0.005) * 300;
			ofDrawBox(ofPoint(x, y, z), size * 0.95, size * 0.95, size * 0.95);
		}
	}

	this->cam.end();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
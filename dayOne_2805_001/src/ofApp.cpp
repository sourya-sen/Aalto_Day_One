#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 5.0;
    save = true;
    fileName = "perlinShapeShifter";
    
    width = scale * ofGetWidth();
    height = scale * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * scale)/2, (ofGetHeight() * scale)/2);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(700 * scale); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofClear(0, 0, 0, 0);
    //draw code goes here.
    
    
    for(int i = 0; i<500; i++){
        
        float r = 255 * sin(ofDegToRad(i + ofGetFrameNum()));
        float g = 255 * sin(ofDegToRad(i + 20 * sin(ofDegToRad(ofGetFrameNum()))));
        float b = 255 * sin(ofDegToRad(i + 10 * cos(ofDegToRad(ofGetFrameNum()))));
        
        ofSetColor(r, g, b);
        
        float x = centre.x + (i/1.0) * cos(ofDegToRad(i)) * ofNoise(ofGetFrameNum()/100.0) * scale;
        float y = centre.y + (i/1.0) * sin(ofDegToRad(i)) * ofNoise(ofGetFrameNum()/1000.0) * scale;
        
        ofDrawCircle(x, y, 100 * cos(ofDegToRad(i + ofGetFrameNum()/10.0)) * scale);
        
    }
    
    
    fbo.end();
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    if(save){
        ofPixels pix;
        fbo.readToPixels(pix);
        ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
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

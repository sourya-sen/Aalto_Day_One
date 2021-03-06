#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 2.0;
    save = true;
    fileName = "shapeB_Appear_Static_";
    
    width = scale * ofGetWidth();
    height = scale * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * scale)/2.0, (ofGetHeight() * scale)/2.0);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(100 * scale); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(1);
    
    controlPoints.resize(3 + 1);
    
    for(int i = 0; i<controlPoints.size(); ++i){
        controlPoints[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
    }
    
    points = evalBezier(controlPoints, 1120);
    
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameNum()));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofClear(0, 0);
    //draw code goes here.
    
    //    ofSetColor(0);
    //    ofDrawRectangle(0, 0, width, height);
    
    for(int i = 0; i<counter; i++){
        
        int sFrame = 429;
        
        float r = 255 * sin(ofDegToRad(i + 429));
        float g = 255 * sin(ofDegToRad(i + 100 * sin(ofDegToRad(429))));
        float b = 255 * sin(ofDegToRad(i + 45 * sin(ofDegToRad(429))));
        
        ofSetColor(r, g, b);
        
        float x = centre.x + (i/1.0) * cos(ofDegToRad(i)) * ofNoise((sFrame)/100.0) * scale;
        float y = centre.y + (i/1.0) * sin(ofDegToRad(i)) * ofNoise((sFrame)/1000.0) * scale;
        
        ofDrawCircle(points[i], 100 * scale + 50 * cos(ofDegToRad((i + sFrame)/1.0)) * scale); //50 * cos
        
    }
    
    fbo.end();
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    if(save){
        ofPixels pix;
        fbo.readToPixels(pix);
        ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
    }
    
    if(counter >= points.size()) ofExit();
    
    if (counter < points.size()) counter ++;
    
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

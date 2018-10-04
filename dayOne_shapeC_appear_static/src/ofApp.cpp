#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 2.0;
    save = true;
    fileName = "shapeC_appS_";
    
    width = scale * ofGetWidth();
    height = scale * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * 2.0)/2.0, (ofGetHeight() * 2.0)/2.0);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(150 * 2.0); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(2111);
    
    int it = 2;
    
    controlPoints.resize(3 * it + 1);
    
    for(int i = 0; i<controlPoints.size(); ++i){
        controlPoints[i] = glm::vec3(ofRandom(200 * 2.0, width - 200 * 2.0), ofRandom(200 * 2.0, height - 200 * 2.0), 0.0);
    }
    
    points = evalCR(controlPoints, 200);
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
    
    int selectedFrame = 79;
    
    
    for(int i = 0; i<counter; i++){
        
        float r = 127 + 127 * sin(ofDegToRad(i/2.0 + selectedFrame));
        float g = 127 + 127 * sin(ofDegToRad(i/2.0 + 10 * sin(ofDegToRad(selectedFrame))));
        float b = 192 + 64 * sin(ofDegToRad(i/3.0 + 45 * sin(ofDegToRad(selectedFrame))));
        
        ofSetColor(r, g, b);
     
        ofDrawCircle(points[i], (120  + (60 * sin(ofDegToRad(i + selectedFrame + 0.0)))) * ofNoise(selectedFrame + 0.0/1000.0) * scale);
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

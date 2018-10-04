#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 1.0;
    save = false;
    fileName = "swirlyTwister";
    
    width = scale * ofGetWidth();
    height = scale * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * scale)/2.0, (ofGetHeight() * scale)/2.0);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(150 * scale); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(18);
    
    int it = 2;
    
    controlPoints.resize(3 * it + 1);
    
    for(int i = 0; i<controlPoints.size(); ++i){
        controlPoints[i] = glm::vec3(ofRandom(300 * scale, width - 300 * scale), ofRandom(300 * scale, height - 300 * scale), 0.0);
    }
    
    points = evalCR(controlPoints, 200);

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
    
    for(int i = 0; i<points.size(); i++){
        
        float r = 127 + 127 * sin(ofDegToRad(i + ofGetFrameNum()));
        float g = 127 + 127 * sin(ofDegToRad(i + 10 * sin(ofDegToRad(ofGetFrameNum()))));
        float b = 192 + 64 * sin(ofDegToRad(i + 145 * sin(ofDegToRad(ofGetFrameNum()))));
        
        ofSetColor(r, g, b);
        
        float x = points[i].x + (i/12.0) * cos(ofDegToRad(i + ofGetFrameNum())) * scale;
        float y = points[i].y + (i/8.0) * sin(ofDegToRad(i + ofGetFrameNum()/10.0)) * scale;
        
        
        ofDrawCircle(x, y, 45 * scale + 30 * cos(ofDegToRad(i + ofGetFrameNum()/2.0)) * scale);
//        ofDrawBitmapStringHighlight("WHAT?", x, y);
        
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

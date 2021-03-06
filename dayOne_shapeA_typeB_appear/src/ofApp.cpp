#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 2.0;
    save = true;
    fileName = "shapeA_typeD_App_Static_";
    
    width = 2.0 * ofGetWidth();
    height = 2.0 * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * 2.0)/2.0, (ofGetHeight() * 2.0)/2.0);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(100 * 2.0); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(8872);
    
    controlPoints.resize(3 * 2 + 1);
    
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
    
    int selectedFrame = 467;
    
    for(int i = 0; i<counter; i++){
        
        float r = 127 + 127 * sin(ofDegToRad(i + selectedFrame));
        float g = 127 + 127 * sin(ofDegToRad(i + 100 * sin(ofDegToRad(selectedFrame))));
        float b = 127 + 127 * sin(ofDegToRad(i + 45 * sin(ofDegToRad(selectedFrame))));
        
        ofSetColor(r, g, b);
        
        float x = centre.x + (i/1.0) * cos(ofDegToRad(i)) * ofNoise((selectedFrame)/100.0) * scale;
        float y = centre.y + (i/1.0) * sin(ofDegToRad(i)) * ofNoise((selectedFrame)/1000.0) * scale;
        
        ofDrawCircle(points[i], 80 * scale + 50 * cos(ofDegToRad((i + selectedFrame)/1.0)) * scale);
        
    }
    
    fbo.end();
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    if(save && (counter < points.size())){
        ofPixels pix;
        fbo.readToPixels(pix);
        ofSaveImage(pix, fileName + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
    }
    
    if(counter >= points.size()) ofExit();
    
    if (counter < points.size()) counter ++;
    
    //scale += .01;
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

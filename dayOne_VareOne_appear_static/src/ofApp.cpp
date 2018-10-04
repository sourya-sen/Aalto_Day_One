#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scale = 2.0;
    save = true;
    fileName = "vare_main_";
    
    width = scale * ofGetWidth();
    height = scale * ofGetHeight();
    centre = glm::vec2((ofGetWidth() * scale)/2.0, (ofGetHeight() * scale)/2.0);
    
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(150 * scale); //check
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(122); //122 for version 1. //1232147 for version 2.
    
    int it = 1;
    
    controlPoints.resize(3 * it + 1);
    newControls.resize(3 * it + 1);
    
    for(int i = 0; i<controlPoints.size(); ++i){
        controlPoints[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
    }
    
    ofSeedRandom(78); //78 for version 1. //5352 for version 2.

    for(int i = 0; i<newControls.size(); ++i){
        newControls[i] = glm::vec3(ofRandom(200 * scale, width - 200 * scale), ofRandom(200 * scale, height - 200 * scale), 0.0);
    }
    
    otherPoints = evalCR(newControls, 500);
    points = evalCR(controlPoints, 500);
    
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
    
    int sFrame = 121;
    
    for(int i = 0; i<counter; i++){
        
        float r = 127 + 127 * sin(ofDegToRad(i/2.0 + sFrame));
        float g = 127 + 127 * sin(ofDegToRad(i/2.0 + 10 * sin(ofDegToRad(sFrame))));
        float b = 192 + 64 * sin(ofDegToRad(i/3.0 + 45 * sin(ofDegToRad(sFrame))));
        
        float bForGrey = 191 + 64 * sin(ofDegToRad(i + ofGetFrameNum()));
        
        float hue = 245;
       
        float saturation = 127 * sin(ofDegToRad(i));
        
        float brightness = 255;
        
//        ofPushMatrix();
        ofSetColor(ofColor::fromHsb(hue, 0, bForGrey)); //Use for b&w
//        ofSetColor(ofColor::fromHsb(hue, saturation, brightness)); //Use for p&w
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        auto l = (60  + (60 * sin(ofDegToRad(i + sFrame)))) * scale;
        auto l2 = (90  + (45 * sin(ofDegToRad(i + sFrame)))) * scale;

        
        auto x = width/2 + i/4.0 * cos(ofDegToRad(i));
        auto y = height/2 + i/4.0 * sin(ofDegToRad(i));
        
        ofDrawCircle(otherPoints[i], l);
        
        ofSetColor(ofColor::fromHsb(hue, 0, bForGrey)); //Use for b&w
//        ofSetColor(ofColor::fromHsb(hue, saturation, brightness)); //Use for p&w

        ofDrawCircle(points[i], l2);

//        ofTranslate(points[i]);
//        ofRotate(i/float(10));
//        ofDrawRectangle(0, 0, l, l);
//        ofSetColor(255 - r, 255);
       
//        for(int j = 45; j<360 + 45; j+=15){
//            auto len = (60  + (45 * sin(ofDegToRad(i + ofGetFrameNum())))) * scale;
//            ofDrawCircle(l * cos(ofDegToRad(j)), l * sin(ofDegToRad(j)), len);
//        }
//        ofPopMatrix();
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

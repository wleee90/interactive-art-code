#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofTexture image1;
    ofTexture image2;
    ofTexture image3;
    
    ofLoadImage(image1,"1.png");
    ofLoadImage(image2,"2.png");
    ofLoadImage(image3,"3.png");
    
    grabber.setup(640, 480);
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(),OF_PIXELS_GRAY);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    
    if (grabber.isFrameNew())
        {
        //get the camera pixels!
        grabberPix = grabber.getPixels();
        grabberPix.mirror(false, true);
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
        //ofRectMode(OF_RECTMODE_CENTER);
    
    ofBackground(0);
    
    //now we can iterate through out pixels
    for (int x =0; x < grabberPix.getWidth(); x+= 20)
    {
        for (int y = 0; y < grabberPix.getHeight(); y += 20)
        {
            ofColor pixelColor = grabberPix.getColor(x,y);
            float brightnessValue = pixelColor.getBrightness();
            
            
            brightnessValue = ofMap(brightnessValue, 0, 255, 0, 25);
            
            ofSetColor(pixelColor);
            ofFill();
            ofDrawCircle (x, y, brightnessValue);
            
            float
            
            ofPushMatrix();

            ofTranslate(x,y);
            ofRotateZDeg(degrees);
            
            ofSetColor(ofColor::royalBlue);
            ofFill();
            ofDrawRectangle(0-brightnessValue/4, 0-brightnessValue/4, brightnessValue/2, brightnessValue/2);
           
            ofPopMatrix();
            
            degrees = degrees + 0.006;
                if (degrees>360) {
                    degrees = 0;
                }
            
            
//            if (brightnessValue > )
           
        }
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

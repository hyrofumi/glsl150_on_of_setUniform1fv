#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    // ランダムに周波数の配列を生成
    for (int i = 0; i < NUM; i++) {
        freq[i] = ofRandom(4.0, 10.0);
    }
    for (int i = 0; i < NUM; i++) {
        cout << ofToString( freq[i] ) << endl;
    }
    shader.load("shader.vert","shader.frag");
    
    cout << ofToString(sizeof(float)) << endl;
    cout << ofToString( glGetUniformLocation(shader.getProgram(), "freq") ) << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    //freqの配列をShaderに渡す
//    shader.setUniform1fv("freq", &freq[0], NUM); //渡せない
    glUniform1fv(glGetUniformLocation(shader.getProgram(), "freq"), NUM, &freq[0]); //渡せる

    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    shader.end();
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

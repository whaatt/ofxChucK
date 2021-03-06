#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel( OF_LOG_VERBOSE );
    ofEnableDepthTest();
    ofSetVerticalSync( false );
    
    showOverlay = false;
    
    // CHUCK STUFF -------------------------------------------------------------
    
    // get singleton
    chuck = TheChucK::instance();
    // arguments
    const char * argv[] = { "the", "-v0" };
    
    // initialize (SHOULD HAPPEN BEFORE AUDIO STREAM STARTS)
    chuck->initialize( MY_SRATE, MY_BUFFERSIZE, MY_CHANNELS, 2, argv );
    
    // compile and run a file
    chuck->compileFile( "ck/dot-circle.ck" );
    
    // setup the sound stream...
    soundStream.setup( this,
                      MY_CHANNELS,     // output
                      0,               // input
                      MY_SRATE,        // sample rate
                      MY_BUFFERSIZE,   // buffer size
                      MY_NUMBUFFERS ); // num buffer
    
    // set location
    w = 250;
    h = 200;
    
    // OCULUS STUFF ------------------------------------------------------------
    
    oculusRift.baseCamera = &cam;
    oculusRift.setup();
    oculusRift.fullscreenOnRift();
    
    if (ofIsGLProgrammableRenderer())
        bshader.load("Shaders_GL3/simple.vert", "Shaders_GL3/simple.frag");
    
    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();
    
    //enable mouse;
    cam.setAutoDistance(false);
    cam.begin();
    cam.end();
    
    // set camera y to user eye height
    cam.setGlobalPosition(0, oculusRift.getUserEyeHeight(), 3);
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS );
    chuck->onInput( input, bufferSize );
    
}


//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS );
    // chuck
    chuck->onOutput( output, bufferSize );
}


//--------------------------------------------------------------
void ofApp::update()
{
    // set background
    ofBackground( 1, 1, 1 );
    
    // entity pointer
    VREntity * e = NULL;

    // db
    OFCKDB * db = OFCKDB::instance();
    
    // draw list
    map<string,VREntity *>::iterator i;
    for( i = db->string2entity.begin(); i != db->string2entity.end(); i++ )
    {
        // get entity
        e = i->second;
        // draw it
        e->updateAll(1/60.0f);
    }
    
    // trigger displaySync to chuck
    chuck->displaySync();
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if(oculusRift.isSetup()){
        if(showOverlay){
            
            oculusRift.beginOverlay(-230, 320,240);
            ofRectangle overlayRect = oculusRift.getOverlayRectangle();
            
            ofPushStyle();
            ofEnableAlphaBlending();
            ofFill();
            ofSetColor(255, 40, 10, 200);
            
            ofRect(overlayRect);
            
            ofSetColor(255,255);
            ofFill();
            
            ofSetColor(0, 255, 0);
            ofNoFill();
            ofCircle(overlayRect.getCenter(), 20);
            
            ofPopStyle();
            oculusRift.endOverlay();
        }
        
        oculusRift.beginLeftEye();
        drawScene();
        oculusRift.endLeftEye();
        
        oculusRift.beginRightEye();
        drawScene();
        oculusRift.endRightEye();
        
        oculusRift.draw();
    }
    else{
        cam.begin();
        drawScene();
        cam.end();
    }
}


//--------------------------------------------------------------
void ofApp::drawScene()
{
    
    ofPushMatrix();
    ofRotate(90, 0, 0, -1);
    ofSetColor(30);
    ofDrawGridPlane(12.0f, 8.0f, false );
    ofPopMatrix();
    
    //--------------------------------------------------------------------------
    // Draw ChucK-controlled elements
    //--------------------------------------------------------------------------
    // entity pointer
    VREntity * e = NULL;
    // db
    OFCKDB * db = OFCKDB::instance();
    // draw list
    map<string,VREntity *>::iterator i;
    for( i = db->string2entity.begin(); i != db->string2entity.end(); i++ )
    {
        // get entity
        e = i->second;
        // draw it
        e->renderAll();
    }
    
    
    //--------------------------------------------------------------------------
    //billboard and draw the mouse
    //--------------------------------------------------------------------------
    if(oculusRift.isSetup()){
        
        ofPushMatrix();
        oculusRift.multBillboardMatrix();
        ofSetColor(255, 0, 0);
        ofCircle(0,0,.5);
        ofPopMatrix();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // dismiss safety warning on any key
    oculusRift.dismissSafetyWarning();
    
    if( key == 'f' )
    {
        //gotta toggle full screen for it to be right
        ofToggleFullscreen();
    }
    
    
    if(key == 'a'){
        cout << "FPS " << ofGetFrameRate() << " TARGET " << ofGetTargetFrameRate() << endl;
    }
    
    
    if(key == 's'){
        oculusRift.reloadShader();
    }
    if(key == 'v'){
        oculusRift.setVignette( !oculusRift.getVignette() );
    }
    
    if(key == 'l'){
        oculusRift.lockView = !oculusRift.lockView;
    }
    
    if(key == 'o'){
        showOverlay = !showOverlay;
    }
    if(key == 'r'){
        oculusRift.reset();
    }
    if(key == 'c'){
        oculusRift.recenterPose();
    }
    if(key == 'h'){
        ofHideCursor();
    }
    if(key == 'H'){
        ofShowCursor();
    }
    
    if(key == 'd'){
        oculusRift.setPixelDensity( oculusRift.getPixelDensity()-0.1 );
    }
    if(key == 'D'){
        oculusRift.setPixelDensity( oculusRift.getPixelDensity()+0.1 );
    }
    
    if(key == 'p'){
        oculusRift.setPositionTracking( !oculusRift.getPositionTracking() );
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    chuck->db()->setFloat( "mouse-x", x );
    chuck->db()->setFloat( "mouse-y", y );
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
    // log
    cerr << "window resized w: " << w << " h: " << h << endl;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

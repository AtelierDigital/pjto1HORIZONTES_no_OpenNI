//
//  Boid.hpp
//  oSitioHORIZONTES
//
//  Created by Tiago Brizolara on 10/3/17.
//
//

#ifndef Boid_hpp
#define Boid_hpp

#include <stdio.h>

#include "ofVec2f.h"
#include "ofMath.h"

///  Baseado em
///
/// Flocking
/// Daniel Shiffman <http://www.shiffman.net>
/// The Nature of Code, Spring 2009
/// Boid class
/// Methods for Separation, Cohesion, Alignment added
///
///  Adicionado comportamento "quero-quero"
class Boid
{
    
protected:
    
    float r;
    
    ofVec2f separate, align, cohere, seek;
    
    float swt = 100;//25.0;     //sep.mult(25.0f);
    float awt = 4.0;      //ali.mult(4.0f);
    float cwt = 5.0;      //coh.mult(5.0f);
    float maxspeed = 10;    //  era 1...
    float maxforce = 0.025;
    
    //  [ADi]
    float rEnterFlee_sq, rExitFlee_sq;
    static const int stateChase = 0;
    static const int stateFlee  = 1;
    int state;
    ofVec2f target;
    float yThreshold;
    
    //  Alem do flock(), temos um comportamento quero_quero()
    
    float chaseWt = 10;//100.0;  //  chases a target
    //float avoidFloorWt = 30.f;  //  avoids floor
    ofVec2f rightStop, leftStop;
    

    void applyForce(ofVec2f& force);
    
    // We accumulate a new acceleration each time based on three rules
    void flock(vector<Boid>& boids);
    
    //
    //  [ADi]
    void quero_quero();
    
    // Method to update position
    void update();
    // A method that calculates and applies a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    void calcSeek(ofVec2f& target, ofVec2f& out_steer);
    
    void render();
    
    // Separation
    // Method checks for nearby boids and steers away
    void calcSeparate (vector<Boid>& boids);
    
    // Alignment
    // For every nearby boid in the system, calculate the average velocity
    void calcAlign (vector<Boid>& boids);
    
    // Cohesion
    // For the average position (i.e. center) of all nearby boids, calculate steering vector towards that position
    void calcCohesion (vector<Boid>& boids);
    
public:
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    Boid(float x, float y, ofVec2f& p_leftStop, ofVec2f& p_rightStop, float p_yThreshold);
    void run(vector<Boid>& boids);
    
    
};

#endif /* Boid_hpp */

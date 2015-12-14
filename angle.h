#ifndef _ANGLE_H_
#define _ANGLE_H_
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

#include <SFML/System.hpp>
#define M_2PI (2*M_PI)

double outputRound(double);

class Angle 
{
public:
    Angle(double init = 0);
        
    void operator=(Angle a2) ;
    void operator=(double val) ;
    
    Angle& operator+=(const Angle& a2) ;
    Angle& operator+=(double val) ;
    
    Angle& operator-=(const Angle& a2) ;
    Angle& operator-=(double val) ;
    
    double toRadians() const  ;  
    double toDegrees() const ;
    double forSprite() const ;
    
    double softSign(double limit) ;
    
    double xComp() const ;
    double yComp() const ;
    
    sf::Vector2f makeVector(float length) const ;
    
    static Angle angleTo(sf::Vector2f src, sf::Vector2f dest ) ;
    
    static constexpr double toDegreeFactor = 180.0/M_PI ;
    static constexpr double toRadianFactor = M_PI/180 ;
    
private:
    double angle;
    void setInRange(double val) ;
    static inline double withinRange(double val); 
    static inline double rawAngleTo(sf::Vector2f src, sf::Vector2f dest ); 
};

inline Angle operator+(Angle a1, const Angle& a2) { return a1+= a2; }
inline Angle operator-(Angle a1, const Angle& a2) { return a1-= a2; }

#endif
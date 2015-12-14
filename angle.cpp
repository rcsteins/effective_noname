#include "angle.h"

Angle::Angle(double init) : angle(init) { setInRange(angle);  }
    
void Angle::operator=(Angle a2) { setInRange(a2.angle );  }
void Angle::operator=(double val) { setInRange( val ); }

Angle& Angle::operator+=(const Angle& a2) { setInRange(angle + a2.angle); return *this; }
Angle& Angle::operator+=(double val) { setInRange(angle + val ); return *this; }

Angle& Angle::operator-=(const Angle& a2) { setInRange(angle - a2.angle); return *this;  }
Angle& Angle::operator-=(double val) { setInRange(angle - val ); return *this; }

double Angle::toRadians() const  {return angle * toRadianFactor;}  
double Angle::toDegrees() const {return angle;}
double Angle::forSprite() const {return angle + 90;}

double Angle::softSign(double limit) {
    return std::fabs(angle) < limit ? ( angle/limit ) : std::copysign(1, angle);
}

double Angle::xComp() const { return cos( toRadians()  ); }
double Angle::yComp() const { return sin( toRadians() ); }

sf::Vector2f Angle::makeVector(float length) const {
    return sf::Vector2f( xComp(), yComp() ) * length;
}

Angle Angle::angleTo(sf::Vector2f src, sf::Vector2f dest ) {
    return Angle( rawAngleTo(src, dest) * toDegreeFactor );
}

void Angle::setInRange(double val) {
    angle = Angle::withinRange( val );
}

double Angle::withinRange(double val) {
    while (val > 180 ) val -= 360;
    while (val < -180 ) val += 360;
    return val;
}  

double Angle::rawAngleTo(sf::Vector2f src, sf::Vector2f dest ){
    return std::atan2( (dest.y - src.y ) , ( dest.x - src.x) ) ;
}
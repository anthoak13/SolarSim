///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                            Copyright (C) 2016                             //
//                    Adam Anthoony : All rights reserved                    //
//                                                                           //
//     This source code is licensed under the GNU GPL v3.0.You have the      //
//     right to modify and/or redistribute this source code under the terms  //
//     specified in the license, which may be found online at                //
//     http://www.gnu.org/licenses.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

//Particle implementation
//Adam Anthony 6/30/16

#include "TMath.h"
#include "Particle.h"

ClassImp(Particle);

Particle::Particle()
{
    position = TVector3();
    velocity = TVector3();
    mass = 0;
}
Particle::Particle(const TVector3 pos, const TVector3 vel, const Double_t massIn)
{
    position = TVector3(pos);
    velocity = TVector3(vel);
    mass = massIn;
}

//accel in N, time in seconds
void Particle::update(const TVector3 F, const UInt_t time)
{
    position += velocity*time + 0.5*F * time * time;
    velocity += F*time;
}

void Particle::print() const
{
    std::cout << "Velocity: ( " << velocity.X() << "," << velocity.Y() << ")" << std::endl;
    std::cout << "Position: ( " << position.X() << "," << position.Y() << ")" << std::endl;
}

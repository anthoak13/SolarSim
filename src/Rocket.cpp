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
#include "Rocket.h"

ClassImp(Rocket);

Rocket::Rocket()
{
    position = TVector3();
    velocity = TVector3();
    mass = 0;
    dm = 0;
    Vex = 0;
}
Rocket::Rocket(const TVector3 pos, const TVector3 vel, const Double_t massIn,
		   const Double_t dmIn, const Double_t VexIn)
{
    position = pos;
    velocity = TVector3(vel);
    mass = massIn;
    dm = dmIn;
    Vex = VexIn;

}

//accel in N, time in seconds
void Rocket::update(const TVector3 a, const UInt_t time, const bool thrust)
{
    if (thrust)
    {
	position += time * (velocity + 0.5 * a * time + Vex*dm/(2*mass)*velocity.Unit());
	velocity += a * time + Vex*dm/mass*velocity.Unit();
    }
    else
    {
	position += time * (velocity + 0.5 * a * time);
	velocity += a * time;
    }
}



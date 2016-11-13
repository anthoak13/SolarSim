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

//Particle
//Adam Anthony
//6/30/16
#ifndef ROCKET_H
#define ROCKET_H

#ifndef __CINT__
#include "TObject.h"
#include "TVector3.h"
#include "Particle.h"
#include <iostream>
#endif

//Class def
class Rocket : public Particle
{
private:
    Double_t  dm;
    Double_t Vex;
    

public:
    Rocket();
    Rocket(const TVector3 pos, const TVector3 vel, const Double_t mass,
	     const Double_t dm, const Double_t Vex);
    
    void update(const TVector3 accel, const UInt_t time, const bool thrust = false);

    ClassDef(Rocket, 1)
};

#endif

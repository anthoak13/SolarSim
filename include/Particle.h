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
#ifndef PARTICLE_H
#define PARTICLE_H

#ifndef __CINT__
#include "TObject.h"
#include "TVector3.h"
#include <iostream>
#endif

//Class def
class Particle : public TObject
{
private:
    Double_t mass;
    TVector3 position;
    TVector3 velocity;
    const double  mE = 5.974e24;

public:
    Particle();
    Particle(const TVector3 pos, const TVector3 vel, const Double_t mass);
    
    void update(const TVector3 force, const UInt_t time);
    void print() const;

    TVector3 getPos() const {return position; }
    TVector3 getVel() const {return velocity; }
    Double_t getM() const {return mass;}

    ClassDef(Particle, 1)
};

#endif

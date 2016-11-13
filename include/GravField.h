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
#ifndef GRAVFIELD_H
#define GRAVFIELD_H

#ifndef __CINT__
#include "TObject.h"
#include "TVector3.h"
#include "TMath.h"
#include <iostream>
#include <vector>
#include "Particle.h"
#endif

using vParticle = std::vector<Particle>;
//Class def
class GravField : public TObject
{
public:
    GravField();
    
    TVector3 getForce( vParticle& objects, const Particle& pos) const;
    TVector3 getForce(const vParticle& objects, const UInt_t  objNum) const;
    TVector3 getA(const vParticle& objects, const UInt_t  objNum) const;
    
    ClassDef(GravField, 1)
};

#endif

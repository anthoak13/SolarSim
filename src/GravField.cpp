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

#include "GravField.h"

ClassImp(GravField);


GravField::GravField()
{

}
TVector3 GravField::getForce(vParticle& objects, const Particle& pos) const
{
    objects.emplace_back(pos);

    TVector3 F = getForce(objects, objects.size()-1);

    objects.pop_back();

    return F;
}
TVector3 GravField::getForce(const vParticle& objects, const UInt_t  objNum) const
{
    TVector3 F;
    Particle target = objects[objNum];

    for(int i =0; i < objects.size() && i != objNum; i++)
    {
	Particle planet = objects[i];
	auto r = target.getPos() - planet.getPos();
	auto modr = r.Mag();

	F += -(TMath::G()*target.getM()*planet.getM())/(modr*modr*modr)*r;
    }

    return F;
}

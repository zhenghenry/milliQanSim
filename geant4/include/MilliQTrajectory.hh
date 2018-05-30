//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: MilliQTrajectory.hh 72349 2013-07-16 12:13:16Z gcosmo $
//
/// \file optical/MilliQ/include/MilliQTrajectory.hh
/// \brief Definition of the MilliQTrajectory class
//
#ifndef MilliQTrajectory_h
#define MilliQTrajectory_h 1

#include "G4Trajectory.hh"
#include "G4Allocator.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4TrajectoryPoint.hh"
#include "G4Track.hh"
#include "G4Step.hh"

class G4Polyline;                   // Forward declaration.

class MilliQTrajectory : public G4Trajectory
{
  public:

    MilliQTrajectory();
    MilliQTrajectory(const G4Track* aTrack);
    MilliQTrajectory(MilliQTrajectory &);
    virtual ~MilliQTrajectory();
 
    virtual void DrawTrajectory() const;
 
    inline void* operator new(size_t);
    inline void  operator delete(void*);

    void SetDrawTrajectory(G4bool b){fDrawit=b;}
    void SetForceDrawTrajectory(G4bool b){fForceDraw=b;}
    void SetForceNoDrawTrajectory(G4bool b){fForceNoDraw=b;}

  private:

    G4bool fDrawit;
    G4bool fForceNoDraw;
    G4bool fForceDraw;
    G4ParticleDefinition* fParticleDefinition;
};

extern G4ThreadLocal G4Allocator<MilliQTrajectory>* MilliQTrajectoryAllocator;

inline void* MilliQTrajectory::operator new(size_t)
{
  if(!MilliQTrajectoryAllocator)
      MilliQTrajectoryAllocator = new G4Allocator<MilliQTrajectory>;
  return (void*)MilliQTrajectoryAllocator->MallocSingle();
}

inline void MilliQTrajectory::operator delete(void* aTrajectory)
{
  MilliQTrajectoryAllocator->FreeSingle((MilliQTrajectory*)aTrajectory);
}

#endif
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
// $Id: SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file SteppingAction.cc
/// \brief Implementation of the SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "Run.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
/*ParticleName=step->GetTrack()->GetDefinition()->GetParticleName();
if(ParticleName=="triton")
{
i=step->GetTrack()->GetCurrentStepNumber();
if(i==1)
{
Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
VolumeName=step->GetTrack()->GetVolume()->GetName();
if(VolumeName=="He3")
run->AddCounter();
//G4double Energy=step->GetPreStepPoint()->GetKineticEnergy();
//G4cout<<"triton:  "<<Energy<<G4endl;
}
}
*/
/*else if(ParticleName=="proton")
{
i=step->GetTrack()->GetCurrentStepNumber();
VolumeName=step->GetTrack()->GetVolume()->GetName();
if(i==1&&VolumeName=="He3")
{
G4double Energy=step->GetPreStepPoint()->GetKineticEnergy();
G4cout<<"proton:  "<<Energy<<G4endl;
}
}*/

VolumeName=step->GetTrack()->GetVolume()->GetName();
if(VolumeName=="He3")
{
EnergyDespoit=step->GetTotalEnergyDeposit();
fEventAction->AddEnergyDespoit(EnergyDespoit);
}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


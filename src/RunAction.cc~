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
// $Id: RunAction.cc 75216 2013-10-29 16:08:11Z gcosmo $
//
/// \file RunAction.cc
/// \brief Implementation of the RunAction class

#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "Run.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include<fstream>  
#include<string>  
#include "G4Timer.hh"
G4Timer myTimer;
std::fstream dataFile("ResponseFunctions",std::ios::out);
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4int runID;
RunAction::RunAction()
: G4UserRunAction()
{ 
  // add new units for dose
  // 
 /* const G4double milligray = 1.e-3*gray;
  const G4double microgray = 1.e-6*gray;
  const G4double nanogray  = 1.e-9*gray;  
  const G4double picogray  = 1.e-12*gray;
   
  new G4UnitDefinition("milligray", "milliGy" , "Dose", milligray);
  new G4UnitDefinition("microgray", "microGy" , "Dose", microgray);
  new G4UnitDefinition("nanogray" , "nanoGy"  , "Dose", nanogray);
  new G4UnitDefinition("picogray" , "picoGy"  , "Dose", picogray);  */      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Run* RunAction::GenerateRun()
{
  return new Run; 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* run)
{ 
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  runID=run->GetRunID();
  if (IsMaster()&&runID==0)
     myTimer.Start(); 
   CounterAll200=0;
   CounterAll300=0;
   CounterAll400=0;
   CounterAll500=0;
   CounterAll600=0;
   CounterAll700=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* run)
{ 
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;
  
  const Run* aRun = static_cast<const Run*>(run);
  if (IsMaster()) 
  {

 // G4String FileNumber=runID+48;

//  std::fstream dataFile(FileNumber,std::ios::out);
 // std::fstream dataFile("EnergyDespoitSpectrum",std::ios::out);
   for(G4int i=0;i<800;i++)
  {
   G4int counter=aRun->GetCounterSpectrum(i);
  //   dataFile<<counter<<G4endl;
   if(i>192-1)
     CounterAll200+=counter;
 /*  if(i>300-1)
     CounterAll300+=counter;
   if(i>400-1)
     CounterAll400+=counter;
   if(i>500-1)
     CounterAll500+=counter;
   if(i>600-1)
     CounterAll600+=counter;
   if(i>700-1)
     CounterAll700+=counter;*/
  }
 G4cout<<CounterAll200<<G4endl;
 dataFile<<CounterAll200<<G4endl;
 // G4cout<<CounterAll200<<"    "<<CounterAll300<<"    "<<CounterAll400<<"    "<<CounterAll500<<"    "<<CounterAll600<<"    "<<CounterAll700<<"    "<<G4endl;

  //if(runID==44)
 // {
 //myTimer.Stop();
 // G4cout<<myTimer<<G4endl;
 // G4cout<<G4endl<<G4endl;
 // }
  }
/*  else 
  {
 G4cout<<aRun->GetCounter()<<G4endl;
  }
  
  G4cout
     << "\n The run consists of " << nofEvents << " "<< runCondition
     << "\n Dose in scoring volume : " 
     << G4BestUnit(dose,"Dose") << " +- " << G4BestUnit(rmsDose,"Dose")
     << "\n------------------------------------------------------------\n"
     << G4endl;*/
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

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
/// \file hadronic/Hadr03/Hadr03.cc
/// \brief Main program of the hadronic/Hadr03 example
//
//
// $Id: TestEm1.cc,v 1.16 2010-04-06 11:11:24 maire Exp $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "Randomize.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"
#include "G4VUserPhysicsList.hh"
#include "G4PhysListFactory.hh"
#include "G4VModularPhysicsList.hh"
#include "G4MTRunManager.hh"
#include "G4GenericPhysicsList.hh"
#ifdef G4VIS_USE
 #include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
int main(int argc,char** argv) {
 
  //choose the Random engine
 G4Random::setTheEngine(new CLHEP::RanecuEngine);
//  CLHEP::HepRandom::setTheSeed(9876);
    
  // Construct the default run manager
  G4MTRunManager* runManager = new G4MTRunManager;
  runManager->SetNumberOfThreads(24);
//  G4RunManager * runManager = new G4RunManager;

  // set mandatory initialization classes
  DetectorConstruction* det=new DetectorConstruction();
  runManager->SetUserInitialization(det);

 /* std::vector<G4String>* MyConstr = new std::vector<G4String>;

      MyConstr->push_back("G4EmStandardPhysics");
      MyConstr->push_back("G4EmExtraPhysics");
      MyConstr->push_back("G4DecayPhysics");
      MyConstr->push_back("G4HadronElasticPhysics");
      MyConstr->push_back("G4HadronPhysicsQGSP_BERT_HP");
     // MyConstr->push_back("G4HadronPhysicsQGSP_BERT");
      MyConstr->push_back("G4StoppingPhysics");
      MyConstr->push_back("G4IonPhysics");
      MyConstr->push_back("G4NeutronTrackingCut");

     G4VModularPhysicsList*  phys = new G4GenericPhysicsList(MyConstr);

  runManager->SetUserInitialization(phys);*/

  // Physics list
     PhysicsList* phys = new PhysicsList;
  runManager->SetUserInitialization(phys);
/* G4PhysListFactory factory;
  G4String physName = "QGSP_BIC";
  G4VModularPhysicsList* phys = factory.GetReferencePhysList(physName);
  runManager->SetUserInitialization(phys);*/

 // G4PhysListFactory factory;
 // G4VModularPhysicsList* phys=factory.GetReferencePhysList("QGSP_BERT_HP");
  //G4VModularPhysicsList* phys=factory.GetReferencePhysList("QGSP_BIC_HP");
 // runManager->SetUserInitialization(phys);

  // User action initialization
 runManager->SetUserInitialization(new ActionInitialization());     
 runManager->Initialize();
  
#ifdef G4VIS_USE
  // Initialize visualization
 G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
 visManager->Initialize();
#endif

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (argc!=1) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else {
    // interactive mode : define UI session
#ifdef G4UI_USE
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
    UImanager->ApplyCommand("/control/execute energy1.mac"); 
#else
   // UImanager->ApplyCommand("/control/execute init.mac"); 
#endif
   // UImanager->ApplyCommand("/control/execute energy1.mac"); 
    ui->SessionStart();
    delete ui;
#endif
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !
  
#ifdef G4VIS_USE
  delete visManager;
#endif
  delete runManager;

  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 

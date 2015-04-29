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
/// \file hadronic/Hadr03/src/DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 70759 2013-06-05 12:26:43Z gcosmo $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4RunManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4double OrbDiameter[13]={3,3.5,4,4.5,5,6,7,8,9,9.5,10,12,15};
DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
 solidWorld(0),  logicWorld(0),  physiWorld(0),
 solidBonnerSphere(0),logicBonnerSphere(0),physiBonnerSphere(0),
 solidHe3sphere(0),solidHandle(0),solidHe3Detector(0),logicHe3Detector(0),physiHe3Detector(0),
 solidHe3(0),logicHe3(0),physiHe3(0),
 solidRareGas(0),logicRareGas(0),physiRareGas(0),i(4),
 stepLimit(0)
{
DefineMaterials();
DetectorMessenger* fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
 return ConstructVolumes();
}

void DetectorConstruction::DefineMaterials()
{
  G4double a;  
  G4double z; 
  G4double density,fractionmass;
  G4int nel,natoms,i,ncomponents;

 // G4Element* H = new G4Element( "H_of_Polyethylene" , "H_POLYETHYLENE" , 1.0 , 1.0079*g/mole );
 /* G4Isotope* H1=new G4Isotope("H1",1,1);
  G4Element* H  = new G4Element("TS_H_of_Polyethylene" ,"H" , ncomponents=1);
  H->AddIsotope(H1,100.*perCent);*/
  G4Element* H  = new G4Element("TS_H_of_Polyethylene" ,"H" , 1., 1.0079*g/mole);  
  

  G4Isotope* C12 = new G4Isotope("C12",6,12);
  G4Element* elC=new G4Element("Carbon","C",nel=1);
  elC->AddIsotope(C12,100.*perCent);

  G4Isotope* N14 = new G4Isotope("N14",7,14,a=14.01*g/mole);
  G4Element* TS_N=new G4Element("Nitrogen","N",nel=1);
  TS_N->AddIsotope(N14,100.*perCent);

  G4Isotope* O16 = new G4Isotope("O16",z=8,16,a=16.01*g/mole);
  G4Element* TS_O=new G4Element("Oxygen","O",nel=1);
  TS_O->AddIsotope(O16,100.*perCent);

  G4Element* N=new G4Element("Nitrogen","N",7,14.01*g/mole);
  G4Element* O=new G4Element("Oxygen","O",7,14.01*g/mole);
  G4Element* C=new G4Element("Carbon","C",6,12.01*g/mole);

  G4NistManager* man=G4NistManager::Instance();
  Ar=man->FindOrBuildMaterial("G4_Ar");
 // matCH2_TS=man->FindOrBuildMaterial("G4_POLYETHYLENE");

  G4Isotope* Fe56 = new G4Isotope("Fe56",z=26,56,a=56*g/mole);
  G4Element* TS_Fe=new G4Element("Iron","Fe",nel=1);
  TS_Fe->AddIsotope(Fe56,100.*perCent);

  Air = new G4Material("Air", density= 1.29*mg/cm3, nel=2);
  Air->AddElement(TS_N, 70*perCent);
  Air->AddElement(TS_O, 30*perCent);
  
  Fe=new G4Material("Fe",density=7.8*g/cm3,nel=1);
  Fe->AddElement(TS_Fe,100.*perCent);

  G4Isotope* He3=new G4Isotope("He3",2,3,a=3.016029*g/mole);
  G4Element* He=new G4Element("Helium","He",nel=1);
  He->AddIsotope(He3,100.*perCent);
  HeGas_TS=new G4Material("HeGas_TS",density=152.0/76.0*0.166322*mg/cm3,nel=1,kStateGas,300*kelvin,152.0/76.0*atmosphere);
  HeGas_TS->AddElement(He,100.*perCent);

  matCH2_TS = new G4Material( "polyethylene" , density = 0.946*g/cm3 , ncomponents=2,kStateSolid,293.15*kelvin,1*atmosphere);
  matCH2_TS -> AddElement(H,0.143711);
  matCH2_TS -> AddElement(elC,0.856289);
  }

G4VPhysicalVolume* DetectorConstruction::ConstructVolumes()
  {
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();

  G4ThreeVector WorldPosition=G4ThreeVector(0.0,0.0,0.0);
  solidWorld=new G4Box("World",400.0*mm,400.0*mm,400.0*mm); 
  logicWorld=new G4LogicalVolume(solidWorld,Air,"World",0,0,0);
  physiWorld=new G4PVPlacement(0,WorldPosition,logicWorld,"World",0,false,0);                                    //World

  if(i==-1)
  {
  solidBonnerSphere=new G4Orb("BonnerSphere",0.5*4*25.4*mm);
  logicBonnerSphere=new G4LogicalVolume(solidBonnerSphere,Air,"BonnerSphere",0,0,0);
  physiBonnerSphere=new G4PVPlacement(0,WorldPosition,logicBonnerSphere,"World",logicWorld,false,0);      //Air Bare He3 detector
  }
  else
  {
  solidBonnerSphere=new G4Orb("BonnerSphere",0.5*OrbDiameter[i]*25.4*mm);
  logicBonnerSphere=new G4LogicalVolume(solidBonnerSphere,matCH2_TS,"BonnerSphere",0,0,0);
  physiBonnerSphere=new G4PVPlacement(0,WorldPosition,logicBonnerSphere,"World",logicWorld,false,0);      //聚乙烯球，放在40cm处
  }
 

  G4ThreeVector RelativePosition=G4ThreeVector(0,0,40.5*mm);
  solidHe3sphere=new G4Orb("He3sphere",0.5*33*mm);
  solidHandle=new G4Tubs("Handle",0*mm,0.5*12.62*mm,0.5*134*mm,0*deg,360*deg);
  solidHe3Detector=new G4UnionSolid("He3Detector",solidHe3sphere,solidHandle,0,RelativePosition);
  logicHe3Detector=new G4LogicalVolume(solidHe3Detector,Fe,"He3Detector",0,0,0);
  physiHe3Detector=new G4PVPlacement(0,WorldPosition,logicHe3Detector,"He3Detector",logicBonnerSphere,false,0);  //He3探测器

  solidHe3=new G4Orb("He3",0.5*32*mm);
  logicHe3=new G4LogicalVolume(solidHe3,HeGas_TS,"He3",0,0,0);
  physiHe3=new G4PVPlacement(0,WorldPosition,logicHe3,"He3",logicHe3Detector,false,0);                           

  G4ThreeVector RareGasPosition=G4ThreeVector(0,0,(107.5-42.5)*mm);
  solidRareGas=new G4Tubs("RareGas",0*mm,0.5*0.5*12.62*mm,0.5*85*mm,0*deg,360*deg);
  logicRareGas=new G4LogicalVolume(solidRareGas,Air,"RareGas",0,0,0);
  physiRareGas=new G4PVPlacement(0,RareGasPosition,logicRareGas,"RareGas",logicHe3Detector,false,0);

  G4VisAttributes* BoxVisAtt= new G4VisAttributes(G4Colour(1,1,1,0.4)); 
  BoxVisAtt->SetForceSolid(true);
  BoxVisAtt->SetVisibility(true);
  logicBonnerSphere->SetVisAttributes(BoxVisAtt);

  G4VisAttributes* BoxVisAtt1= new G4VisAttributes(G4Colour(0,0,1,0.2)); 
  BoxVisAtt1->SetForceSolid(true);
  BoxVisAtt1->SetVisibility(true);
  logicHe3Detector->SetVisAttributes(BoxVisAtt1);

  G4VisAttributes* BoxVisAtt2= new G4VisAttributes(G4Colour(1.0,0.0,0.0)); 
  BoxVisAtt2->SetVisibility(true);
  BoxVisAtt1->SetForceSolid(true);
  logicHe3->SetVisAttributes(BoxVisAtt2);

  G4VisAttributes* BoxVisAtt3= new G4VisAttributes(G4Colour(0.0,1.0,0.0)); 
  BoxVisAtt3->SetVisibility(true);
  logicRareGas->SetVisAttributes(BoxVisAtt3);

  G4VisAttributes* BoxVisAtt4= new G4VisAttributes(G4Colour(1.0,0.0,0.0)); 
  BoxVisAtt4->SetVisibility(false);
  logicWorld->SetVisAttributes(BoxVisAtt4);

  return physiWorld;
}
  
void DetectorConstruction::SetBonnerSphereNumber(G4int BonnerSphereNumber)
{
this->i=BonnerSphereNumber;
G4RunManager::GetRunManager()->ReinitializeGeometry();
}


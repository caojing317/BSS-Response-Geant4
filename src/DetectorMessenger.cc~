#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcommand.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithADouble.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* det)
 : Detector(det)
{
 DetectorDir = new G4UIdirectory("/LXe/detector/");
 DetectorDir->SetGuidance("Detector geometry control");
 
 BonnerSphereNumberCmd = new G4UIcmdWithAnInteger("/LXe/detector/BonnerSphereNumber",this);
 BonnerSphereNumberCmd->SetGuidance("Set the BonnerSphereNumber of the multisphere spectrometer.");
 BonnerSphereNumberCmd->SetParameterName("BonnerSphereNumber",false);
}

DetectorMessenger::~DetectorMessenger()
{
delete BonnerSphereNumberCmd;
delete DetectorDir;
}

void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
if( command == BonnerSphereNumberCmd ){
    Detector->SetBonnerSphereNumber(BonnerSphereNumberCmd->GetNewIntValue(newValue));
  }
}

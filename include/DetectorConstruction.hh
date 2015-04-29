
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4Tubs;
#include "G4UnionSolid.hh"
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
#include "G4UserLimits.hh"
class G4Orb;
class G4Sphere;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();

  public:
  
    virtual G4VPhysicalVolume* Construct();
    void SetBonnerSphereNumber(G4int); 
     
  private:
     G4Box*             solidWorld;    // pointer to the solid envelope 
     G4LogicalVolume*   logicWorld;    // pointer to the logical envelope
     G4VPhysicalVolume* physiWorld;    // pointer to the physical envelope

     G4Material* HeGas_TS;
     G4Material* matCH2_TS;
     G4Material* Wood;
     G4Material* Air;
     G4Material* Fe;
     G4Material* Ar;
     G4int       i;
    
     G4Orb*             solidBonnerSphere;       
     G4LogicalVolume*   logicBonnerSphere;                                    
     G4VPhysicalVolume* physiBonnerSphere;
     
     G4Box*             solidFloor;       
     G4LogicalVolume*   logicFloor;                                    
     G4VPhysicalVolume* physiFloor; 

     G4Orb*             solidHe3;       
     G4LogicalVolume*   logicHe3;                                    
     G4VPhysicalVolume* physiHe3; 

     G4Tubs*            solidRareGas;       
     G4LogicalVolume*   logicRareGas;                                    
     G4VPhysicalVolume* physiRareGas; 

     G4Orb*             solidHe3sphere;
     G4Tubs*            solidHandle;
     G4UnionSolid*      solidHe3Detector;
     G4LogicalVolume*   logicHe3Detector;                                    
     G4VPhysicalVolume* physiHe3Detector;

     G4Orb*             solidHe3sphereIn;
     G4Tubs*            solidHandleIn;
     G4UnionSolid*      solidHe3DetectorIn;
     G4LogicalVolume*   logicHe3DetectorIn;                                    
     G4VPhysicalVolume* physiHe3DetectorIn;
     
     G4UserLimits* stepLimit; 
            
     void               DefineMaterials();
     G4VPhysicalVolume* ConstructVolumes();  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif


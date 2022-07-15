#ifndef CMVDRecoAlg_h
#define CMVDRecoAlg_h 1

#include "micalDetectorParameterDef.hh"
#include "ParameterMessenger.hh"
#include "MultiSimAnalysisDigi.hh"
#include "GeneralRecoInfo.hh"
#include "vect_manager.h"

#include "InoVertex.h"
#include "globals.hh"
#include "TCanvas.h"
#include "TStyle.h"
#include "TMatrixD.h"
#include "TMath.h"
#include "TMatrixDEigen.h"
#include "CmvHit.h"
#include "CmvLayExtra.h"
#include "CmvCluster.h"
using namespace std;

/**
* @file
* @author Raj  <rajbhupen20@gmail.com >
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* Reconstruction including CMVD
*/

/**
* @brief This class is used for CMVD Reco Algorithm
* @author Raj Bhupen Shah
*
*/


class CMVDRecoAlg {
public:
  CMVDRecoAlg(int isInOut);
  ~CMVDRecoAlg();

  //cmvd
   void ReadCMVDdata(int ixt);
  void CMVD_Extrapolation();
  void CreateCmvHit();
  void FormCmvCluster();
private:



  void SaveCMVHitData(unsigned int hits,CmvHit* pCmvHit );
  void SaveCMVClusterData(unsigned int clusthits,CmvCluster* pCmvCluster );
  void SaveCMVExtrapData(unsigned int extrap , CmvLayExtra* pCmvLayExtra);

  micalDetectorParameterDef* paradef;
  MultiSimAnalysisDigi* pAnalysis;
  ParameterMessenger *MessengerFile;
  GeneralRecoInfo* grecoi;


  //cmvd

 bool LinePlaneInt(double* Line, double* Plane, double* Point);



	double partopscint[3];     //halflength of scintillators of thickness 1cm
	float AirGapScintTop;
double PhyVolGlPos[7][4][3];
  //	double PhyVolGlPos[4][4][3];
  int NoScntStrpTop;
  int NoScntStrpSide;

  int NoScintStrip;

  int NoScntStrpSideSmallay;
  double SideSmallPlaneHalfLength;
  double ScntLayShifSide;
  double SidePlaneHalfLength;
  double TopPlaneHalfLength;
  double magfield;

  CmvHit_Manager* CmvHit_pointer;
  SipmHit_Manager* SipmHit_pointer;

  CmvStrip_Manager* CmvStrip_pointer;
  CmvLayExtra_Manager* CmvLayExtra_pointer;

   CmvCluster_Manager* CmvCluster_pointer;
  int isData;

};
#endif

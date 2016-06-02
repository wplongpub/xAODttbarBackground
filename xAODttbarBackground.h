#ifndef ttbarBackground_xAODttbarBackground_H
#define ttbarBackground_xAODttbarBackground_H

#include <EventLoop/Algorithm.h>
#include <TTree.h>
#include <TH1.h>
#include "xAODBTaggingEfficiency/BTaggingSelectionTool.h"
#include "JetMomentTools/JetVertexTaggerTool.h"

class xAODttbarBackground : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;



  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  //  Tree *myTree; //!
  // TH1 *myHist; //!
  TTree *tree;//!


  // b-quark truth level
  /********************************************************************************/

  TH1 *bPT; //!
  TH1 *bEta; //!
  TH1 *deltaPhi; //!
  TH1 *bPTW;//!
  TH1 *bPTAll; //!
  TH1 *nParent; //!
  TH1 *parentPdgId; //!
  TH1 *dquarknParent;//!
  TH1 *dquarkParentPdgId; //!

  TH1 *bPTFromTquark;//!
  TH1 *bPTFromUquark;//!
  TH1 *bPTFromBquark;//!
  TH1 *bPTFromGluon;//!

  double dpPdgId1;//!
  double dpPdgId2;//!

  double temp1; //!
  double temp2; //!
  double temp3; //!
  double temp4; //!

  std::string outputName;

  double b1PT; //!
  double b2PT; //!

  double b1Eta; //!
  double b2Eta; //!

  double b1Phi; //!
  double b2Phi; //!

  double b1M; //!
  double b2M; //!

  double b1Px; //!
  double b1Py; //!
  double b1Pz; //!

  double b2Px; //!
  double b2Py; //!
  double b2Pz; //!

  double b1b2DeltaPhi; //!

  double temp; //!


  // b-jet level histogram or tree
  /***********************************************************************************/
  // BTaggingSelectionTool initialization
  BTaggingSelectionTool *btagtool; //!

  // JetVertexTaggerTool initialization
  JetVertexTaggerTool* pjvtag = 0; //!
  ToolHandle<IJetUpdateJvt> hjvtagup; //!


  TH1 *bJetPt;//!
  TH1 *bJetTaggedPt;//!
  TH1 *bJetTaggedUpdatedPt; //!

  int nOfJets;//!
  int nOfJetsTagged; //!

  //  double bJetPt;
  // double bJetTaggedPt;
 



  // member function 
  /*******************************************/

  // this is a standard constructor
  xAODttbarBackground ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(xAODttbarBackground, 1);
};

#endif

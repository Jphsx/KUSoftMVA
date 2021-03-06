//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr 15 16:07:35 2020 by ROOT version 6.14/09
// from TTree Events/Events
// found on file: ../../OutputFiles/DYJetsToLL2018_MINI_numEvent50000.root
//////////////////////////////////////////////////////////

#ifndef DY18_minitree_h
#define DY18_minitree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DY18_minitree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   UInt_t          nGenPart;
   Float_t         GenPart_eta[89];   //[nGenPart]
   Float_t         GenPart_mass[89];   //[nGenPart]
   Float_t         GenPart_phi[89];   //[nGenPart]
   Float_t         GenPart_pt[89];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[89];   //[nGenPart]
   Int_t           GenPart_pdgId[89];   //[nGenPart]
   Int_t           GenPart_status[89];   //[nGenPart]
   Int_t           GenPart_statusFlags[89];   //[nGenPart]
   UInt_t          nMuon;
   Float_t         Muon_dxy[17];   //[nMuon]
   Float_t         Muon_dxyErr[17];   //[nMuon]
   Float_t         Muon_dz[17];   //[nMuon]
   Float_t         Muon_dzErr[17];   //[nMuon]
   Float_t         Muon_eta[17];   //[nMuon]
   Float_t         Muon_ip3d[17];   //[nMuon]
   Float_t         Muon_jetPtRelv2[17];   //[nMuon]
   Float_t         Muon_jetRelIso[17];   //[nMuon]
   Float_t         Muon_mass[17];   //[nMuon]
   Float_t         Muon_miniPFRelIso_all[17];   //[nMuon]
   Float_t         Muon_miniPFRelIso_chg[17];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[17];   //[nMuon]
   Float_t         Muon_pfRelIso03_chg[17];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[17];   //[nMuon]
   Float_t         Muon_phi[17];   //[nMuon]
   Float_t         Muon_pt[17];   //[nMuon]
   Float_t         Muon_ptErr[17];   //[nMuon]
   Float_t         Muon_segmentComp[17];   //[nMuon]
   Float_t         Muon_sip3d[17];   //[nMuon]
   Float_t         Muon_softMva[17];   //[nMuon]
   Float_t         Muon_tkRelIso[17];   //[nMuon]
   Float_t         Muon_tunepRelPt[17];   //[nMuon]
   Int_t           Muon_charge[17];   //[nMuon]
   Int_t           Muon_jetIdx[17];   //[nMuon]
   Int_t           Muon_nStations[17];   //[nMuon]
   Int_t           Muon_nTrackerLayers[17];   //[nMuon]
   Int_t           Muon_pdgId[17];   //[nMuon]
   Int_t           Muon_tightCharge[17];   //[nMuon]
   UChar_t         Muon_highPtId[17];   //[nMuon]
   Bool_t          Muon_inTimeMuon[17];   //[nMuon]
   Bool_t          Muon_isGlobal[17];   //[nMuon]
   Bool_t          Muon_isPFcand[17];   //[nMuon]
   Bool_t          Muon_isTracker[17];   //[nMuon]
   Bool_t          Muon_looseId[17];   //[nMuon]
   Bool_t          Muon_mediumId[17];   //[nMuon]
   Bool_t          Muon_mediumPromptId[17];   //[nMuon]
   UChar_t         Muon_miniIsoId[17];   //[nMuon]
   UChar_t         Muon_multiIsoId[17];   //[nMuon]
   UChar_t         Muon_mvaId[17];   //[nMuon]
   UChar_t         Muon_pfIsoId[17];   //[nMuon]
   UChar_t         Muon_puppiIsoId[17];   //[nMuon]
   Bool_t          Muon_softId[17];   //[nMuon]
   Bool_t          Muon_softMvaId[17];   //[nMuon]
   Bool_t          Muon_tightId[17];   //[nMuon]
   UChar_t         Muon_tkIsoId[17];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[17];   //[nMuon]
   UInt_t          nQP;
   Float_t         QP_dxy[5];   //[nQP]
   Float_t         QP_dxyError[5];   //[nQP]
   Float_t         QP_dz[5];   //[nQP]
   Float_t         QP_dzError[5];   //[nQP]
   Float_t         QP_eta[5];   //[nQP]
   Float_t         QP_mass[5];   //[nQP]
   Float_t         QP_phi[5];   //[nQP]
   Float_t         QP_pt[5];   //[nQP]
   Float_t         QP_ptErr[5];   //[nQP]
   Int_t           QP_charge[5];   //[nQP]
   Int_t           QP_pdgId[5];   //[nQP]
   Int_t           Muon_genPartIdx[17];   //[nMuon]
   UChar_t         Muon_genPartFlav[17];   //[nMuon]
   Int_t           QP_genPartIdx[5];   //[nQP]
   UChar_t         QP_genPartFlav[5];   //[nQP]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_jetPtRelv2;   //!
   TBranch        *b_Muon_jetRelIso;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_miniPFRelIso_all;   //!
   TBranch        *b_Muon_miniPFRelIso_chg;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_softMva;   //!
   TBranch        *b_Muon_tkRelIso;   //!
   TBranch        *b_Muon_tunepRelPt;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_nTrackerLayers;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_inTimeMuon;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_looseId;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_mediumPromptId;   //!
   TBranch        *b_Muon_miniIsoId;   //!
   TBranch        *b_Muon_multiIsoId;   //!
   TBranch        *b_Muon_mvaId;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_puppiIsoId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_softMvaId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_tkIsoId;   //!
   TBranch        *b_Muon_triggerIdLoose;   //!
   TBranch        *b_nQP;   //!
   TBranch        *b_QP_dxy;   //!
   TBranch        *b_QP_dxyError;   //!
   TBranch        *b_QP_dz;   //!
   TBranch        *b_QP_dzError;   //!
   TBranch        *b_QP_eta;   //!
   TBranch        *b_QP_mass;   //!
   TBranch        *b_QP_phi;   //!
   TBranch        *b_QP_pt;   //!
   TBranch        *b_QP_ptErr;   //!
   TBranch        *b_QP_charge;   //!
   TBranch        *b_QP_pdgId;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_QP_genPartIdx;   //!
   TBranch        *b_QP_genPartFlav;   //!

   DY18_minitree(TTree *tree=0);
   virtual ~DY18_minitree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   

};

#endif

#ifdef DY18_minitree_cxx
DY18_minitree::DY18_minitree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../OutputFiles/DYJetsToLL2018_MINI_numEvent50000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../OutputFiles/DYJetsToLL2018_MINI_numEvent50000.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

DY18_minitree::~DY18_minitree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DY18_minitree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DY18_minitree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DY18_minitree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_jetPtRelv2", Muon_jetPtRelv2, &b_Muon_jetPtRelv2);
   fChain->SetBranchAddress("Muon_jetRelIso", Muon_jetRelIso, &b_Muon_jetRelIso);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_miniPFRelIso_all", Muon_miniPFRelIso_all, &b_Muon_miniPFRelIso_all);
   fChain->SetBranchAddress("Muon_miniPFRelIso_chg", Muon_miniPFRelIso_chg, &b_Muon_miniPFRelIso_chg);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   fChain->SetBranchAddress("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_softMva", Muon_softMva, &b_Muon_softMva);
   fChain->SetBranchAddress("Muon_tkRelIso", Muon_tkRelIso, &b_Muon_tkRelIso);
   fChain->SetBranchAddress("Muon_tunepRelPt", Muon_tunepRelPt, &b_Muon_tunepRelPt);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   fChain->SetBranchAddress("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   fChain->SetBranchAddress("Muon_nTrackerLayers", Muon_nTrackerLayers, &b_Muon_nTrackerLayers);
   fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   fChain->SetBranchAddress("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   fChain->SetBranchAddress("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   fChain->SetBranchAddress("Muon_inTimeMuon", Muon_inTimeMuon, &b_Muon_inTimeMuon);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   fChain->SetBranchAddress("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
   fChain->SetBranchAddress("Muon_looseId", Muon_looseId, &b_Muon_looseId);
   fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   fChain->SetBranchAddress("Muon_mediumPromptId", Muon_mediumPromptId, &b_Muon_mediumPromptId);
   fChain->SetBranchAddress("Muon_miniIsoId", Muon_miniIsoId, &b_Muon_miniIsoId);
   fChain->SetBranchAddress("Muon_multiIsoId", Muon_multiIsoId, &b_Muon_multiIsoId);
   fChain->SetBranchAddress("Muon_mvaId", Muon_mvaId, &b_Muon_mvaId);
   fChain->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
   fChain->SetBranchAddress("Muon_puppiIsoId", Muon_puppiIsoId, &b_Muon_puppiIsoId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_softMvaId", Muon_softMvaId, &b_Muon_softMvaId);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("Muon_tkIsoId", Muon_tkIsoId, &b_Muon_tkIsoId);
   fChain->SetBranchAddress("Muon_triggerIdLoose", Muon_triggerIdLoose, &b_Muon_triggerIdLoose);
   fChain->SetBranchAddress("nQP", &nQP, &b_nQP);
   fChain->SetBranchAddress("QP_dxy", QP_dxy, &b_QP_dxy);
   fChain->SetBranchAddress("QP_dxyError", QP_dxyError, &b_QP_dxyError);
   fChain->SetBranchAddress("QP_dz", QP_dz, &b_QP_dz);
   fChain->SetBranchAddress("QP_dzError", QP_dzError, &b_QP_dzError);
   fChain->SetBranchAddress("QP_eta", QP_eta, &b_QP_eta);
   fChain->SetBranchAddress("QP_mass", QP_mass, &b_QP_mass);
   fChain->SetBranchAddress("QP_phi", QP_phi, &b_QP_phi);
   fChain->SetBranchAddress("QP_pt", QP_pt, &b_QP_pt);
   fChain->SetBranchAddress("QP_ptErr", QP_ptErr, &b_QP_ptErr);
   fChain->SetBranchAddress("QP_charge", QP_charge, &b_QP_charge);
   fChain->SetBranchAddress("QP_pdgId", QP_pdgId, &b_QP_pdgId);
   fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   fChain->SetBranchAddress("QP_genPartIdx", QP_genPartIdx, &b_QP_genPartIdx);
   fChain->SetBranchAddress("QP_genPartFlav", QP_genPartFlav, &b_QP_genPartFlav);
   Notify();
}

Bool_t DY18_minitree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DY18_minitree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DY18_minitree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DY18_minitree_cxx

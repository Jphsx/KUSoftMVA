#define dy_match_cxx
// The class definition in dy_match.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("dy_match.C")
// root> T->Process("dy_match.C","some options")
// root> T->Process("dy_match.C+")
//


#include "dy_match.h"
#include <TH2.h>
#include <TStyle.h>

void dy_match::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void dy_match::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t dy_match::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

    for(int i=0; i< *nMuon ; i++){
    	matchpt.Fill(Muon_pt[i], Muon_genPartIdx[i]);
	mupt.Fill(Muon_pt[i]);
	//specifically unmatched
	if(Muon_genPartIdx[i] == -1){
		unmatchPt.Fill(Muon_pt[i]);
		
		
	}
	//specifically matched
	if(Muon_genPartIdx[i] != -1){
		matchpdg.Fill( abs(GenPart_pdgId[Muon_genPartIdx[i]] ));
	
		int pdg = abs( GenPart_pdgId[Muon_genPartIdx[i]] );

		if( pdg == 11 ) nonmuongenflav.Fill(0., (float)Muon_genPartFlav[i] );
		if( pdg == 211 ) nonmuongenflav.Fill(1., (float)Muon_genPartFlav[i]);
		if( pdg == 321 ) nonmuongenflav.Fill(2., (float)Muon_genPartFlav[i]);
		
		if( globalctr_1 < 20 && (pdg == 11|| pdg==211 ||pdg==321) ){
			int idx = Muon_genPartIdx[i];
				std::cout<<"Evt num: "<<*event<<std::endl;
				std::cout<<"This particle (pt,eta,phi):"<< Muon_pt[i] <<" "<<Muon_eta[i]<<" "<<Muon_phi[i]<<" "<<std::endl;
				std::cout<<"Gen match     (pt,eta,phi):"<< GenPart_pt[idx]<<" "<<GenPart_eta[idx]<<" "<<GenPart_phi[idx]<<std::endl;
				std::cout<<"match quality (dR,dptrel):"<<dR(Muon_eta[i],Muon_phi[i], GenPart_eta[idx], GenPart_phi[idx])<<" "<< (GenPart_pt[idx] -Muon_pt[i])/(GenPart_pt[idx])<<std::endl;
				getrelatives( Muon_genPartIdx[i] );
				globalctr_1++;

		}


		

	}
	
	// require muon pt >1.5
    	if(Muon_pt[i] > 1.5){
		//for(int j=0; j< *nGenPart; j++){
			
		//}
	
	}

    }


//do some basic event printout (impose simple pt cut)
   if(Muon_pt[0] > 3){
		if(globalctr_0 < 20){
			//get muon 0
			if(Muon_genPartIdx[0] != -1){
				int idx = Muon_genPartIdx[0];
				std::cout<<"Evt num: "<<*event<<std::endl;
				std::cout<<"This particle (pt,eta,phi):"<< Muon_pt[0] <<" "<<Muon_eta[0]<<" "<<Muon_phi[0]<<" "<<std::endl;
				std::cout<<"Gen match     (pt,eta,phi):"<< GenPart_pt[idx]<<" "<<GenPart_eta[idx]<<" "<<GenPart_phi[idx]<<std::endl;
				std::cout<<"match quality (dR,dptrel):"<<dR(Muon_eta[0],Muon_phi[0], GenPart_eta[idx], GenPart_phi[idx])<<" "<< (GenPart_pt[idx] - Muon_pt[0])/GenPart_pt[idx]<<std::endl;
				getrelatives( Muon_genPartIdx[0] );
				globalctr_0++;
			}
		}

   }


   return kTRUE;
}

void dy_match::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void dy_match::Terminate()
{

   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  TFile* f = new TFile("dytest.root", "RECREATE");
  f->WriteObject(&matchpt,matchpt.GetName());
  f->WriteObject(&unmatchPt, unmatchPt.GetName());
  f->WriteObject(&mupt,mupt.GetName());
  f->WriteObject(&matchpdg, matchpdg.GetName());
  f->WriteObject(&nonmuongenflav, nonmuongenflav.GetName());
  f->Write();
  f->Close();

}
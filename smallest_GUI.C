{   TString OurTString;
// main frame
   TGMainFrame *OurFrame = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   OurFrame->SetLayoutBroken(kTRUE);
//    embedded canvas
   TRootEmbeddedCanvas *OurCanvas = new TRootEmbeddedCanvas(0,OurFrame,624,425,kSunkenFrame);
   Int_t Cnum = OurCanvas->GetCanvasWindowId();
   TCanvas *Canv = new TCanvas("Canv", 10, 10, Cnum);
   OurCanvas->AdoptCanvas(Canv);
      OurFrame->AddFrame(OurCanvas);
//   Text Label defined
   TGLabel *OurLabel = new TGLabel(OurFrame,"OurLabel");      
   OurLabel->SetTextJustify(kTextLeft);
   OurLabel->SetText("Enter Text Below");
      OurFrame->AddFrame(OurLabel);
//  Text entry defined   
   TGTextBuffer *Buf=new TGTextBuffer(228);
   TGTextEntry *OurText=new TGTextEntry(OurFrame,Buf,-1);
   OurText->SetAlignment(kTextLeft);
   OurText->SetText("Here ...");
      OurFrame->AddFrame(OurText);                                   
//        Buttons  defined  and placed 
   ReadButton = new TGTextButton(OurFrame, "Read Text", "Do_Get_Text()");
       OurFrame->AddFrame(ReadButton);
   ExitButton = new TGTextButton(OurFrame, "EXIT", "Do_Exit()");
       OurFrame->AddFrame(ExitButton);
//   Housekeeping
   OurFrame->MapSubwindows();
                                    OurLabel->MoveResize  ( 24,453,260, 28);      
                                    OurText->MoveResize   ( 24,483,480, 28);
                                    OurCanvas->MoveResize ( 24, 16,704,425);
                                    ReadButton->MoveResize(544,446,184, 32);  
                                    ExitButton->MoveResize(544,483,184, 32);
   OurFrame->MapWindow();           OurFrame->Resize      (776,531);
//              Canvas - THIS IS AN EXAMPLE ONLY    
   Canv->cd();
   TH1F * hist=new TH1F("a","Empty histogram",100,0,4);
   hist->Draw();
}  
void Do_Get_Text(){                //  For the Read Button
    OurTString=  OurText->GetText();
    cout << "\n\n\t\t\t " << OurTString << "\n\t\t\t TString OurTString set as title of the histogram \n";
    hist->SetTitle(OurTString);   Canv->Update();  Canv->Modified();
    
}
void Do_Exit(){                   //  For the Exit Button
    gROOT->ProcessLine(".q");
}

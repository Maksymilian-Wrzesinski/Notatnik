//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString nazwapliku="";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Otwrz2Click(TObject *Sender)
{
 if (OpenDialog1->Execute())
 {
  try {

  tresc->Lines->LoadFromFile(OpenDialog1->FileName);
  nazwapliku = OpenDialog1->FileName;

  }
   catch(...)
   {
   ShowMessage("B³¹d otwarcia pliku. U¿yj poprawnej nazwy.");
   }

 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
   if (SaveDialog1->Execute())
 {
  try {

  tresc->Lines->SaveToFile(SaveDialog1->FileName);
  nazwapliku = SaveDialog1->FileName;

  }
   catch(...)
   {
   ShowMessage("B³¹d. Nie uda³o siê zapisa pliku.");
   }

 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(nazwapliku!="")
        {
        tresc->Lines->SaveToFile(nazwapliku);
        }
        else
        {
         Form1->Zapiszjako1Click(MainMenu1);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if(Application->MessageBoxA("Czy chcesz utworzyc nowy plik?",
        "PotwierdŸ",MB_YESNOCANCEL | MB_ICONQUESTION)==IDYES)
        {
         tresc->Lines->Clear();
         nazwapliku="";
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::trescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Shift.Contains(ssCtrl))
        {
                if((Key == 's' || Key == 'S'))
                {
                         Form1->Zapisz1Click(MainMenu1);
                }
                if((Key=='n' || Key=='N'))
                {
                         Form1->Nowy1Click(MainMenu1);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
        //Form1->Close();
        if(Application->MessageBoxA("Czy chcesz zapisac plik?",
        "PotwierdŸ",MB_YESNOCANCEL | MB_ICONQUESTION)==IDYES)
        {
         tresc->Lines->Clear();
         nazwapliku="";
        }

        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBoxA("Czy chcesz zakonczyc program?",
        "PotwierdŸ",MB_YESNOCANCEL | MB_ICONQUESTION)==IDNO)
        {
                Action=caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wytnij1Click(TObject *Sender)
{
        tresc->CutToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KopiujCTTRLC1Click(TObject *Sender)
{
        tresc->CopyToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WklejCTRLV1Click(TObject *Sender)
{
        tresc->PasteFromClipboard();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if(Zawijaniewierszy1->Checked==true)
        {
          Zawijaniewierszy1->Checked=false;
          tresc->WordWrap=false;
          tresc->ScrollBars=ssBoth;
        }
        else
        {
        Zawijaniewierszy1->Checked=true;
        tresc->WordWrap=true;
        tresc->ScrollBars=ssVertical;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
        if(FontDialog1->Execute())
        {
        //krój
        tresc->Font->Name = FontDialog1->Font->Name;
        //kolor
        tresc->Font->Color = FontDialog1->Font->Color;
        //rozmiar
        tresc->Font->Size =  FontDialog1->Font->Size;
        //pogrubienie/styl
         tresc->Font->Style =  FontDialog1->Font->Style;

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::O1Click(TObject *Sender)
{
        Form2->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Linkdobloga1Click(TObject *Sender)
{
        ShellExecute(NULL,"open","https://www.youtube.com/watch?v=dQw4w9WgXcQ",NULL,NULL, SW_SHOWNORMAL);        
}
//---------------------------------------------------------------------------


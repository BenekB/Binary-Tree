/*  author: Benedykt Bela
 *  author: Justyna Jeliñska
 *  Code Blocks 17.12
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct branch {
    int wartosc;
    branch *prawy;
    branch *lewy;
};


void pisz_menu();
void dodaj_wartosc (branch *&korzen);
void dodaj_wartosc_2(branch *&korzen, int cyferka);
void usun_wartosc (branch *&korzen);
void usun_wartosc_2 (branch *&korzen, int usuwana);
void rysuj_drzewo (branch *korzen, int ile, int maksimum);
void oblicz_warstwy(branch *korzen, int licznik, int &maksimum);
void usun_wartosc_3 (branch *&korzen, int usuwana);
int przypiecie_wezla (branch *&korzen);



int main()
{
    branch *korzen = NULL;

    int check;
    bool sprawdz = true;

    do
    {
      pisz_menu();
      cin>>check;
      int maksimum=0;

      switch (check)
      {
          case 1: dodaj_wartosc(korzen); break;
          case 2: usun_wartosc(korzen); break;
          case 3: oblicz_warstwy(korzen, 0, maksimum);
                  rysuj_drzewo(korzen, 1, maksimum);break;
          case 4: sprawdz = false; break;
          default: cout<<"NIEPOPRAWNA WARTOSC"<<endl;
      }

    }
    while (sprawdz);

}



void dodaj_wartosc (branch *&korzen)
{
    int cyferka;

    cout<<"PODAJ WARTOSC > ";
    cin>>cyferka;

    dodaj_wartosc_2(korzen, cyferka);

}



void dodaj_wartosc_2 (branch *&korzen, int cyferka)
{
    if (korzen == NULL)
    {
        branch *nowy = new branch;
        nowy->wartosc = cyferka;
        nowy->prawy = NULL;
        nowy->lewy = NULL;
        korzen = nowy;
    }
    else if (cyferka > korzen->wartosc)
        dodaj_wartosc_2 (korzen->prawy, cyferka);
    else
        dodaj_wartosc_2 (korzen->lewy, cyferka);
}



void usun_wartosc (branch *&korzen)
{
    int usuwana;
    cout<<"CO CHCESZ USUNAC? > ";
    cin>>usuwana;

    usun_wartosc_2 (korzen, usuwana);
}



void usun_wartosc_2 (branch *&korzen, int usuwana)
{

    if (korzen == NULL)
        cout<<"NIE MA TAKIEJ WARTOSCI"<<endl;
    else if (korzen->wartosc==usuwana)
        usun_wartosc_3 (korzen, usuwana);
    else if (usuwana > korzen->wartosc)
        usun_wartosc_2(korzen->prawy, usuwana);
    else
        usun_wartosc_2 (korzen->lewy, usuwana);

}



void usun_wartosc_3 (branch *&korzen, int usuwana)
{
    int zamiana;

    if (korzen->lewy == NULL && korzen->prawy == NULL)
        korzen = NULL;
    else if (korzen->lewy == NULL)
        korzen = korzen->prawy;
    else if (korzen->prawy == NULL)
        korzen = korzen->lewy;
    else
    {
        zamiana = przypiecie_wezla(korzen->prawy);
        korzen->wartosc = zamiana;
    }
}


int przypiecie_wezla (branch *&korzen)
{
    int x;

    if (korzen->lewy == NULL)
    {
        x = korzen->wartosc;
        korzen = korzen->prawy;
        return x;
    }
    else
        return przypiecie_wezla(korzen->lewy);
}


void rysuj_drzewo (branch *korzen,int ile, int maksimum)
{
   if(korzen!=NULL)
   {
       rysuj_drzewo(korzen->prawy, ++ile, maksimum);
       cout<<setw(ile*8)<<korzen->wartosc<<endl;
       rysuj_drzewo(korzen->lewy, ile, maksimum);
   }
   else
   {
        for (int i = maksimum-ile+1; i>0; i--)
            cout<<endl;
   }

}



void oblicz_warstwy(branch *korzen, int licznik, int &maksimum)
{
    if(korzen!=NULL)
    {
        oblicz_warstwy(korzen->prawy, ++licznik, maksimum);
        licznik--;
        oblicz_warstwy(korzen->lewy, ++licznik, maksimum);
    }
    else
    {
        if(licznik > maksimum)
            maksimum = licznik;

        licznik--;
    }
}



void pisz_menu()
{
    cout<<"DODAJ WARTOSC > 1"<<endl
        <<"USUN WARTOSC > 2"<<endl
        <<"RYSUJ DRZEWO > 3"<<endl
        <<"ZAKONCZ PROGRAM > 4"<<endl;
}



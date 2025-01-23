/**       
* @file main.cpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "IkiliAramaAgaci.hpp"
#include "Dugum.hpp"
#include "Liste.hpp"
#include "ListeDugum.hpp"
int main()
{
    system("Color 70");
    Liste liste;
    IkiliAramaAgaci* agac = new IkiliAramaAgaci();
    agac->dosyadanAgaclariOlustur("agaclar.txt", liste);
    agac = liste.ilkagaciGetir();

    int mevcutindex = 0;
    int uzunluk = liste.uzunluk();

    int* dizi = agac->agacdandiziolustur();

    //ilk ekran
    liste.ListeyiCiz(liste, mevcutindex, dizi);
    string tus;
    cout << endl << "secim...:";
    cin >> tus;
    while (true) {
        if ((tus == "a" || tus == "A") && mevcutindex > 0) {
            mevcutindex--;
            if (mevcutindex % 10 == 9) {
                liste.setsayfasayisi(-1);
            }
            dizi = liste.getDugum(mevcutindex)->agac->agacdandiziolustur();
            liste.ListeyiCiz(liste, mevcutindex, dizi);
            cout << endl << "secim...:";
            cin >> tus;
        }
        else if ((tus == "d" || tus == "D") && mevcutindex < uzunluk - 1) {
            mevcutindex++;
            if (mevcutindex % 10 == 0) {
                liste.setsayfasayisi(1);
            }
            dizi = liste.getDugum(mevcutindex)->agac->agacdandiziolustur();
            liste.ListeyiCiz(liste, mevcutindex, dizi);
            cout << endl << "secim...:";
            cin >> tus;
        }
        else if (tus == "s" || tus == "S") {
            ListeDugum* silinecekDugum = liste.getDugum(mevcutindex);
            liste.silDugum(silinecekDugum);

            uzunluk--;
            if (uzunluk % 10 == 0 && mevcutindex % 10 == 0 && uzunluk / 10 == liste.getsayfasayisi() && uzunluk != 0) {
                liste.setsayfasayisi(-1);
            }
            if (mevcutindex < uzunluk)
            {
                dizi = liste.getDugum(mevcutindex)->agac->agacdandiziolustur();
                liste.ListeyiCiz(liste, mevcutindex, dizi);
                cout << endl << "secim...:";
                cin >> tus;
            }
            else
            {
                mevcutindex--;
                if (liste.getDugum(mevcutindex) != NULL)
                    dizi = liste.getDugum(mevcutindex)->agac->agacdandiziolustur();
                liste.ListeyiCiz(liste, mevcutindex, dizi);
                cout << endl << "secim...:";
                cin >> tus;
            }
        }
        else if (tus == "w" || tus == "W") {

            if (liste.getDugum(mevcutindex) != NULL)
            {
                liste.aynala(liste.getDugum(mevcutindex)->agac->getagackokdugum());
                dizi = liste.getDugum(mevcutindex)->agac->agacdandiziolustur();
            }

            liste.ListeyiCiz(liste, mevcutindex, dizi);
            cout << endl << "secim...:";
            cin >> tus;
        }
        else
        {
            liste.ListeyiCiz(liste, mevcutindex, dizi);
            cout << endl << "secim...:";
            cin >> tus;
        }
    }

    return 0;
}
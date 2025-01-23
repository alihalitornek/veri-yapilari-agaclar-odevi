/**       
* @file Liste.cpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "Liste.hpp"

Liste::Liste()
{
    ilk = 0;
}

void Liste::ekle(IkiliAramaAgaci* agac)
{
    ListeDugum* yeni = new ListeDugum(agac);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        ListeDugum* gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        yeni->onceki = gec;
    }
}

IkiliAramaAgaci* Liste::ilkagaciGetir()
{
    if (ilk != 0)
        return ilk->agac;
}

ListeDugum* Liste::getDugum(int index) {
    ListeDugum* gec = ilk;
    int i = 0;
    while (gec != nullptr) {
        if (i == index) return gec;
        gec = gec->sonraki;
        i++;
    }
    return nullptr; //yoksa
}

int Liste::uzunluk() {
    int say = 0;
    ListeDugum* gec = ilk;
    while (gec) {
        say++;
        gec = gec->sonraki;
    }
    return say;
}
void Liste::setsayfasayisi(int degisim)
{
    sayfa += degisim;
}
int Liste::getsayfasayisi()
{
    return sayfa;
}
void Liste::basilacakdugumfiltreleyaz(ListeDugum* dugumadres)
{
    uintptr_t addr = reinterpret_cast<uintptr_t>(dugumadres);

    stringstream ss;
    ss << hex << addr;
    string adres = ss.str();

    if (adres.size() >= 11)
        adres.substr(adres.size() - 11);
    else
    {
        string onek = "";
        for (int i = 0;i < 11 - adres.size();i++) onek += "0";
        adres = onek + adres;
    }

    cout << adres;
}
void Liste::aynala(Dugum* kok) {
    if (!kok) return;

    //sol ve sağı değiştir
    Dugum* gecici = kok->sol;
    kok->sol = kok->sag;
    kok->sag = gecici;

    aynala(kok->sol);
    aynala(kok->sag);
}
void Liste::ListeyiCiz(Liste& liste, int mevcutindex, int* dizi) {
    system("CLS");
    int uzunluk = liste.uzunluk();


    ListeDugum* seciliDugum = liste.getDugum(0);

    int sonsayfa = uzunluk / 10;
    int nekadarbasacak;
    if (sayfa == sonsayfa)
    {
        nekadarbasacak = uzunluk;
    }
    else
    {
        nekadarbasacak = sayfa * 10 + 10;
    }

    seciliDugum = liste.getDugum(sayfa * 10);

    cout << "|";
    for (int i = sayfa * 10; i < nekadarbasacak; i++) {
        basilacakdugumfiltreleyaz(seciliDugum);
        cout << "|";
        seciliDugum = seciliDugum->sonraki;
    }
    seciliDugum = liste.getDugum(0);
    cout << endl;

    cout << "|";
    for (int i = sayfa * 10; i < nekadarbasacak; i++) {
        seciliDugum->agac->preOrderhesap(liste, i);

        if (seciliDugum)
        {
            if (seciliDugum->agac->getagacdeger() < 1000)
                cout << " ";
            if (seciliDugum->agac->getagacdeger() < 100)
                cout << " ";
            if (seciliDugum->agac->getagacdeger() < 10)
                cout << " ";
        }
        cout << "       " << seciliDugum->agac->getagacdeger() << "|";
        seciliDugum->agac->agacdegersifirla();
        seciliDugum = seciliDugum->sonraki;
    }
    cout << endl;

    seciliDugum = liste.getDugum(sayfa * 10);

    cout << "|";
    for (int i = sayfa * 10; i < nekadarbasacak; i++) {

        seciliDugum = seciliDugum->sonraki;
        
        basilacakdugumfiltreleyaz(seciliDugum);
        cout << "|";
    }
    cout << endl;

    for (int i = sayfa * 10; i < nekadarbasacak; i++) {
        if (i == mevcutindex)
        {
            cout << " ^^^^^^^^^^^";
        }

        else
            cout << "            ";
    }
    cout << endl;
    for (int i = sayfa * 10; i < nekadarbasacak; i++) {
        if (i == mevcutindex)
        {
            cout << " |||||||||||";
        }

        else
            cout << "            ";
    }

    seciliDugum = liste.getDugum(mevcutindex);
    cout << endl << endl;

    if (seciliDugum && seciliDugum->agac) {
        seciliDugum->agac->ciz(dizi, mevcutindex);

    }

}
void Liste::silDugum(ListeDugum* silinecek) {
    if (!silinecek) return;

    if (silinecek == ilk) {
        ilk = silinecek->sonraki;
        if (ilk) {
            ilk->onceki = nullptr;
        }
    }
    else {
        ListeDugum* onceki = silinecek->onceki;
        ListeDugum* sonraki = silinecek->sonraki;

        if (onceki)
            onceki->sonraki = sonraki;
        if (sonraki)
            sonraki->onceki = onceki;
    }

    if (silinecek->agac) {
        silinecek->agac->agacTamamenSil();
        delete silinecek->agac;
    }

    delete silinecek;
}

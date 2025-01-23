/**       
* @file IkiliAramaAgaci.cpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "IkiliAramaAgaci.hpp"

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = 0;
}
IkiliAramaAgaci::~IkiliAramaAgaci() {
    agacYokEt(kok);
    kok = nullptr;
}
void IkiliAramaAgaci::ekle(char eklenecek)
{
    if (kok == 0)
        kok = new Dugum(eklenecek);
    else
        ekle(eklenecek, kok);
}
int IkiliAramaAgaci::yukseklik()
{
    return yukseklik(kok);
}
void IkiliAramaAgaci::dosyadanAgaclariOlustur(const string& dosyaAdi, Liste& liste) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "dosya yok" << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir))
    {
        if (!satir.empty())
        {
            IkiliAramaAgaci* agac = new IkiliAramaAgaci();
            for (char c : satir)
            {
                agac->ekle(c);
            }

            liste.ekle(agac);
        }
    }

    dosya.close();
}

void IkiliAramaAgaci::ciz(int* dizi, int mevcutindex)
{
    agaciCiz(dizi, mevcutindex);
    sayac = 0;
}

void IkiliAramaAgaci::agacTamamenSil() {
    agacSil(kok);
    kok = nullptr;
}
int IkiliAramaAgaci::getagacdeger()
{
    return agacdeger;
}
void IkiliAramaAgaci::agacdegersifirla()
{
    agacdeger = 0;
}
void IkiliAramaAgaci::preOrderhesap(Dugum* aktif)
{
    if (aktif)
    {
        agacdeger += aktif->veri;
        if (aktif->sol)
            agacdeger += aktif->sol->veri;
        preOrderhesap(aktif->sol);
        preOrderhesap(aktif->sag);
    }
}
void IkiliAramaAgaci::preOrderhesap(Liste liste, int index)
{
    Dugum* aktif = liste.getDugum(index)->agac->getagackokdugum();
    agacdeger = 0;
    if (aktif)
    {
        agacdeger += aktif->veri;
        if (aktif->sol)
            agacdeger += aktif->sol->veri;
        preOrderhesap(aktif->sol);
        preOrderhesap(aktif->sag);
    }

}
Dugum* IkiliAramaAgaci::getagackokdugum()
{
    return kok;
}
int* IkiliAramaAgaci::agacdandiziolustur()
{
    int h = yukseklik(kok);
    int maxdugumsayisi = pow(2, h + 1) - 1;

    int* dizi = new int[maxdugumsayisi];
    for (int i = 0; i < maxdugumsayisi; i++) {
        dizi[i] = 0;
    }

    Dugum** dugumdizi = new Dugum * [maxdugumsayisi];
    int* indexdizi = new int[maxdugumsayisi];

    int index1 = 0;
    int index2 = 0;

    dugumdizi[index2] = kok;
    indexdizi[index2] = 0;
    index2++;

    while (index1 < index2) {
        Dugum* dugum = dugumdizi[index1];
        int index = indexdizi[index1];
        index1++;

        if (dugum && index < maxdugumsayisi) {
            dizi[index] = 1;

            if (dugum->sol) {
                dugumdizi[index2] = dugum->sol;
                indexdizi[index2] = index * 2 + 1;
                index2++;
            }
            if (dugum->sag) {
                dugumdizi[index2] = dugum->sag;
                indexdizi[index2] = index * 2 + 2;
                index2++;
            }
        }
    }


    delete[] dugumdizi;
    delete[] indexdizi;

    return dizi;

}
void IkiliAramaAgaci::agacYokEt(Dugum* aktif) {
    if (!aktif) return;
    agacYokEt(aktif->sol);
    agacYokEt(aktif->sag);
    delete aktif;
}

string IkiliAramaAgaci::levelOrdersirala(Dugum* aktif, int level, string siraliveri)
{
    if (aktif)
    {

        if (level == 0)
        {
            siraliveri += aktif->veri;
        }
        else
        {
            if (aktif->sol)
            {
                siraliveri = levelOrdersirala(aktif->sol, level - 1, siraliveri);
            }

            if (aktif->sag)
            {
                siraliveri = levelOrdersirala(aktif->sag, level - 1, siraliveri);
            }
        }
    }
    return siraliveri;
}
void IkiliAramaAgaci::agaciCiz(int* dizi, int mevcutindex)
{
    int agacyukseklik = yukseklik(kok);

    string satir = "";
    for (int level = 0; level <= agacyukseklik; level++) {
        satir = levelOrdersirala(kok, level, satir);
    }
    sayac = 0;


    int maxdugumsayisi = (int)pow(2, agacyukseklik + 1) - 1;

    noktavebosluk(agacyukseklik, dizi, 0, true);
    for (int i = 0, j = 0, anasira = 0, sira = 0;i < maxdugumsayisi;i++)
    {
        noktavebosluk(agacyukseklik, dizi, anasira,false);
        if (dizi[i] == 1)
        {
            cout << satir[sira];
            sira++;
            anasira++;
        }
        else
        {
            cout << " ";
            anasira++;
        }
        if (i == j)
        {
            j += pow(2, (j + 1));
        }
    }

}
void IkiliAramaAgaci::noktavebosluk(int agacyukseklik, int* dizi, int s, bool reset = false)
{


    static int arabosluk = pow(2, agacyukseklik);
    static int birakilacabosluk = pow(2, agacyukseklik + 1);
    if ((sayac == 0) || (sayac == 1) || (sayac == 3) || (sayac == 7) || (sayac == 15) || (sayac == 31) || (sayac == 63) || (sayac == 127) || (sayac == 255) || (sayac == 511) || (sayac == 1023))
    {

        if (sayac != 0)
        {
            birakilacabosluk -= arabosluk;
            arabosluk /= 2;
        }
        if (reset)
        {
            arabosluk = pow(2, agacyukseklik);
            birakilacabosluk = pow(2, agacyukseklik + 1);
        }
        else
        {
            cout << endl;
            cout << setw(birakilacabosluk) << " ";
            sayac++;
        }

    }
    else
    {
        if (dizi[s - 1] == 1 && s != 0 && (s - 1) % 2 == 1)
        {
            for (int i = 0;i < 2 * arabosluk;i++) cout << ".";
        }
        else
        {
            cout << setw(2 * arabosluk - 1) << " ";
            if (dizi[s] == 1 && s % 2 == 0)
                cout << ".";
            else
                cout << " ";
        }
        if (dizi[s] == 1 && s % 2 == 0)
        {
            for (int i = 0;i < 2 * arabosluk - 1;i++) cout << ".";
        }
        else
        {
            cout << setw(2 * arabosluk - 1) << " ";
        }
        sayac++;
    }

}
int IkiliAramaAgaci::yukseklik(Dugum* aktifDugum)
{
    if (aktifDugum)
    {
        aktifDugum->yukseklik = 1 + max(yukseklik(aktifDugum->sol),
            yukseklik(aktifDugum->sag));
        return aktifDugum->yukseklik;
    }
    return -1;
}
void IkiliAramaAgaci::ekle(char veri, Dugum* aktifDugum)
{
    if (aktifDugum->veri > veri)
    {
        if (aktifDugum->sol)
            ekle(veri, aktifDugum->sol);
        else
            aktifDugum->sol = new Dugum(veri);
    }
    else if (aktifDugum->veri < veri)
    {
        if (aktifDugum->sag)
            ekle(veri, aktifDugum->sag);
        else
            aktifDugum->sag = new Dugum(veri);
    }
    else
        return;
}
void IkiliAramaAgaci::agacSil(Dugum* aktif) {
    if (!aktif) return;
    agacSil(aktif->sol);
    agacSil(aktif->sag);
    delete aktif;
}
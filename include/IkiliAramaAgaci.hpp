/**       
* @file IkiliAramaAgaci.hpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include "Dugum.hpp"
#include "Liste.hpp"
#include "ListeDugum.hpp"

class IkiliAramaAgaci
{
public:
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void ekle(char eklenecek);
    int yukseklik();
    void dosyadanAgaclariOlustur(const string& dosyaAdi, Liste& liste);
    void ciz(int* dizi, int mevcutindex);
    void agacTamamenSil();
    int getagacdeger();
    void agacdegersifirla();
    void preOrderhesap(Dugum* aktif);
    void preOrderhesap(Liste liste, int index);
    Dugum* getagackokdugum();
    int* agacdandiziolustur();
private:
    void agacYokEt(Dugum* aktif);
    string levelOrdersirala(Dugum* aktif, int level, string siraliveri);
    void agaciCiz(int* dizi, int mevcutindex);
    void noktavebosluk(int agacyukseklik, int* dizi, int s, bool reset);
    int yukseklik(Dugum* aktifDugum);
    void ekle(char veri, Dugum* aktifDugum);
    void agacSil(Dugum* aktif);
    Dugum* kok;
    int sayac = 0;
    int agacdeger = 0;
};
#endif
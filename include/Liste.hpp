/**       
* @file Liste.hpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef LISTE_HPP
#define LISTE_HPP

#include "ListeDugum.hpp"
#include "Dugum.hpp"
#include "IkiliAramaAgaci.hpp"

class Liste
{
public:
    Liste();
    void ekle(IkiliAramaAgaci* agac);
    IkiliAramaAgaci* ilkagaciGetir();
    ListeDugum* getDugum(int index);
    int uzunluk();
    void setsayfasayisi(int degisim);
    int getsayfasayisi();
    void basilacakdugumfiltreleyaz(ListeDugum* dugumadres);
    void aynala(Dugum* kok);
    void ListeyiCiz(Liste& liste, int currentIndex, int* dizi);
    void silDugum(ListeDugum* silinecek);

private:
    ListeDugum* ilk;
    int sayfa = 0;
};
#endif
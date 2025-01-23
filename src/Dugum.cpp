/**       
* @file Dugum.cpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(char veri)
{
    this->veri = veri;
    sag = sol = 0;
}
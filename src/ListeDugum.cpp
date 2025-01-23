/**       
* @file ListeDugum.cpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "ListeDugum.hpp"

ListeDugum::ListeDugum(IkiliAramaAgaci* agac)
{
    this->agac = agac;
    sonraki = onceki = 0;
}
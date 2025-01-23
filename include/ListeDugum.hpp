/**       
* @file ListeDugum.hpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef LISTEDUGUM_HPP
#define LISTEDUGUM_HPP

#include "IkiliAramaAgaci.hpp"
#include "Dugum.hpp"
#include "Liste.hpp"
#include "ListeDugum.hpp"

class ListeDugum
{
public:
    ListeDugum(IkiliAramaAgaci* agac);
    IkiliAramaAgaci* agac;
    ListeDugum* sonraki;
    ListeDugum* onceki;
};
#endif
/**       
* @file Dugum.hpp
* @description dosyanın her satırdan bir ikili arama ağacı oluşturur ve bu ağaçları bir liste yapısı içerisinde saklar
* @course  1. öğretim A gurubu
* @assignment  2. ödev
* @date  08.12.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <queue>
#include <cmath>
#include <windows.h>

using namespace std;

class IkiliAramaAgaci;
class ListeDugum;
class Liste;

class Dugum
{
public:
    Dugum(char veri);
    char veri;
    Dugum* sag;
    Dugum* sol;
    int yukseklik;
};
#endif
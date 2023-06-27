

#include <bits/stdc++.h>
#include <string.h>
#include "Phong.h"
using namespace std;
Phong::Phong()
{

}
Phong::~Phong()
{

}
Phong::Phong(string maPhong, double dienTich, bool tinhTrang, bool coGac, double giaThue) {
    this->maPhong = maPhong;
    this->dienTich = dienTich;
    this->tinhTrang = tinhTrang;
    this->coGac = coGac;
    this->giaThue = giaThue;
}
Phong::Phong(const Phong &p)
{
    this->maPhong = p.maPhong;
    this->dienTich = p.dienTich;
    this->tinhTrang = p.tinhTrang;
    this->coGac = p.coGac;
    this->giaThue = p.giaThue;

}
void Phong::setMaPhong(string maPhong) 
{
    this->maPhong = maPhong;
}
string Phong::getMaPhong() 
{
    return maPhong;
}
void Phong::setDienTich(double dienTich) 
{
    this->dienTich = dienTich;
}
double Phong::getDienTich() 
{
    return dienTich;
}
void Phong::setTinhTrang(bool tinhTrang) 
{
    this->tinhTrang = tinhTrang;
}
bool Phong::getTinhTrang() 
{
    return tinhTrang;
}

void Phong::setCoGac(bool coGac) 
{
    this->coGac = coGac;
}
bool Phong::getCoGac() 
{
    return coGac;
}

void Phong::setGiaThue(double giaThue) 
{
    this->giaThue = giaThue;
}
double Phong::getGiaThue() 
{
    return giaThue;
}


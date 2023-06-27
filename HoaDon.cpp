#include <iostream>
#include <string> 
#include <iomanip>
#include "NguoiThue.h"
#include "Phong.h"
#include "HoaDon.h"
using namespace std;
HoaDon::HoaDon()
{

}
HoaDon::~HoaDon()
{

}
HoaDon::HoaDon(string maHoaDon, NguoiThue nguoiThue, Phong phong, string ngayThue, int thang, int soDien, int soNuoc, double tongTien)
{
    this->nguoiThue = nguoiThue;
    this->maHoaDon = maHoaDon;
    this->phong = phong;
    this->thang = thang;
    this->soDien = soDien;
    this->soNuoc = soNuoc;
    this->tongTien = tongTien;
}
HoaDon::HoaDon (const HoaDon &p)
{
    this->maHoaDon = p.maHoaDon;
    this->nguoiThue = p.nguoiThue;
    this->phong = p.phong;
    this->thang = p.thang;
    this->soDien = p.soDien;
    this->soNuoc = p.soNuoc;
    this->tongTien = p.tongTien;
}
void HoaDon::setMaHoaDon(string maHoaDon)
{
    this->maHoaDon = maHoaDon;
}
string HoaDon::getMaHoaDon() 
{
    return maHoaDon;
}
void HoaDon::setNguoiThue(NguoiThue nguoiThue)
{
    this->nguoiThue = nguoiThue;
}
NguoiThue HoaDon::getNguoiThue()
{
    return getNguoiThue();
}
void HoaDon::setPhong(Phong phong)
{
    this->phong = phong;
}
Phong HoaDon::getPhong()
{
    return getPhong();
}
void HoaDon::setThang(int thang)
{
    this->thang = thang;
}
int HoaDon::getThang() 
{
    return thang;
}
void HoaDon::setSoDien(int soDien)
{
    this->soDien = soDien;
}
int HoaDon::getSoDien() 
{
    return soDien;
}

void HoaDon::setSoNuoc(int soNuoc)
{
    this->soNuoc = soNuoc;
}
int HoaDon::getSoNuoc() 
{
    return soNuoc;
}

void HoaDon::setTongTien()
{
    this->tongTien = phong.getGiaThue() + this->soDien*3 + this->soNuoc*6;
}
int HoaDon::getTongTien() 
{
    return tongTien;
}

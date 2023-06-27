#include <iostream>
#include <string> 
#include <iomanip>
#include "NguoiThue.h"
#include "Phong.h"
#include "HopDong.h"
HopDong::HopDong()
{

}

HopDong::~HopDong()
{

}
HopDong::HopDong(string maHopDong, string sdtNguoiThue, string maPhong,  string ngayBatDauThue, string ngayKetThucThue)
{
    this->maHopDong = maHopDong;
    this->sdtNguoiThue = sdtNguoiThue;
    this->maPhong = maPhong;
    this->ngayBatDauThue = ngayBatDauThue;
    this->ngayKetThucThue = ngayKetThucThue;
}
HopDong::HopDong (const HopDong &p)
{
    this->maHopDong = p.maHopDong;
    this->sdtNguoiThue = p.sdtNguoiThue;
    this->maPhong = p.maPhong;
    this->ngayBatDauThue = p.ngayBatDauThue;
    this->ngayKetThucThue = p.ngayKetThucThue;
}
void HopDong::setMaHopDong(string maHopDong)
{
    this->maHopDong = maHopDong;
}
string HopDong::getMaHopDong() 
{
    return maHopDong;
}


void HopDong::setSDTNguoiThue(string sdtNguoiThue)
{
    this->sdtNguoiThue = sdtNguoiThue;
}
string HopDong::getSDTNguoiThue()
{
    return sdtNguoiThue;
}

void HopDong::setMaPhong(string  maPhong)
{
    this->maPhong = maPhong;
}
string HopDong::getMaPhong() 
{
    return maPhong;
}

void HopDong::setNgayBatDauThue(string ngayBatDauThue)
{
    this->ngayBatDauThue = ngayBatDauThue;
}
string HopDong::getNgayBatDauThue() 
{
    return ngayBatDauThue;
}

void HopDong::setNgayKetThucThue(string ngayKetThucThue)
{
    this->ngayKetThucThue = ngayKetThucThue;
}
string HopDong::getNgayKetThucThue() 
{
    return ngayKetThucThue;
}
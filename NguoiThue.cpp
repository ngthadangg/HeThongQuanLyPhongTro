#include <bits/stdc++.h>
#include <string.h>
#include "NguoiThue.h"
using namespace std;
NguoiThue::NguoiThue()
{
    
}
NguoiThue::~NguoiThue()
{
    
}

NguoiThue::NguoiThue(string ten,string CCCD, string diaChi, string soDienThoai, string ngaySinh, bool gioiTinh) 
{
    this->ten = ten;
    this->CCCD = CCCD;
    this->diaChi = diaChi;
    this->soDienThoai = soDienThoai;
    this->ngaySinh = ngaySinh;
    this->gioiTinh = gioiTinh;
}
NguoiThue::NguoiThue (const NguoiThue &p)
{
    this->ten = p.ten;
    this->CCCD = p.CCCD;
    this->diaChi = p.diaChi;
    this->soDienThoai = p.soDienThoai;
    this->ngaySinh = p.ngaySinh;
    this->gioiTinh = p.gioiTinh;
}
void NguoiThue::setTen(string ten) 
{
    this->ten = ten;
}
string NguoiThue::getTen() 
{
    return ten;
}
void NguoiThue::setCCCD(string CCCD) 
{
    this->CCCD = CCCD;
}
string NguoiThue::getCCCD() 
{
    return CCCD;
}
void NguoiThue::setDiaChi(string diaChi) 
{
    this->diaChi = diaChi;
}
string NguoiThue::getDiaChi() 
{
    return diaChi;
}
void NguoiThue::setSoDienThoai(string soDienThoai) 
{
    this->soDienThoai = soDienThoai;
}
string NguoiThue::getSoDienThoai() 
{
    return soDienThoai;
}
void NguoiThue::setNgaySinh(string ngaySinh) 
{
    this->ngaySinh = ngaySinh;
}
string NguoiThue::getNgaySinh() 
{
    return ngaySinh;
}
void NguoiThue::setGioiTinh(bool gioiTinh) 
{
    this->gioiTinh = gioiTinh;
}
bool  NguoiThue::getGioiTinh() 
{
    return gioiTinh;
}

// friend ostream& operator << ( ostream &out , const NguoiThue &nguoiThue)
// {
//     out<< "Thong tin Nguoi Thue: \n";
//     out<< setw(20) << left <<"Ten: "<<nguoiThue.getTen()<<"\n";
//     out<< setw(20) << left <<"CCCD: "<<nguoiThue.getCCCD()<<"\n";
//     out<< setw(20) << left <<"Dia Chi: "<<nguoiThue.getDiaChi()<<"\n";
//     out<< setw(20) << left <<"So Dien Thoai : "<<nguoiThue.getSoDienThoai()<<"\n";
//     out<< setw(20) << left <<"Ngay Sinh: "<<nguoiThue.getNgaySinh()<<"\n";
//     out<< setw(20) << left <<"Gioi Tinh: "<<nguoiThue.getGioiTinh()<<"\n";
//     out<< setw(20) << left <<"Ma Phong: "<<nguoiThue.getMaPhong()<<"\n";
// }

// friend istream& operator >> ( istream &in , NguoiThue &nguoiThue)
// {
//     cout<<"Nhap thong tin Nguoi Thue: \n";
//     cout<< "Ten: "; in>>nguoiThue.ten;
//     cout<< "CCCD: "; in>>nguoiThue.CCCD;
//     cout<< "Dia Chi: "; in>>nguoiThue.diaChi;
//     cout<< "So Dien Thoai " ; in>>nguoiThue.soDienThoai;
//     cout<< "Ngay Sinh: "; in>>nguoiThue.ngaySinh;
//     cout<< "Gioi Tinh: ";in>>nguoiThue.gioiTinh;
//     cout<< "Ma Phong: ";in>>nguoiThue.maPhong;
// }
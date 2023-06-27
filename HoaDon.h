#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <string> 
#include <iomanip>
#include "NguoiThue.h"
#include "Phong.h"
using namespace std;
class HoaDon : public NguoiThue, public Phong{
    private:
        string maHoaDon;
        NguoiThue nguoiThue;
        Phong phong;
        int thang;
        int soDien;
        int soNuoc;
        double tongTien ;
    public:
        HoaDon();
        
        HoaDon(string maHoaDon, NguoiThue nguoiThue, Phong phong, string ngayThue, int thang, int soDien, int soNuoc, double tongTien);
        
        HoaDon (const HoaDon &p);
        
        ~HoaDon();
        
        void setMaHoaDon(string maHoaDon);
        
        string getMaHoaDon(); 
        
        void setNguoiThue(NguoiThue nguoiThue);
        
        NguoiThue getNguoiThue();
        
        void setPhong(Phong phong);

        Phong getPhong();

        void setThang(int thang);
        
        int getThang() ;   

        void setSoDien(int soDien);
       
        int getSoDien();

        void setSoNuoc(int soNuoc);

        int getSoNuoc() ;
        
        void setTongTien();
       
        int getTongTien();
        
        friend ostream& operator << ( ostream &out , const HoaDon &hoaDon)
        {
            out << "\nThong tin Hoa Don: \n";
            out << setw(20) << left << "Ma Hoa Don: "<< hoaDon.maHoaDon << "\n";
            out << hoaDon.nguoiThue;
            out << hoaDon.phong;
            out << setw(20) << left << "Thang: "<< hoaDon.thang << "\n";
            out << setw(20) << left << "So Dien: "<< hoaDon.soDien << "\n";
            out << setw(20) << left << "So Nuoc: "<< hoaDon.soNuoc << "\n";
            out << setw(20) << left << "Tong tien: "<< hoaDon.tongTien << "\n";
            return out;

        }

        friend istream& operator >> ( istream &in , HoaDon &hoaDon)
        {
            cout << "Nhap thong tin Hoa Donn: \n";
            cout << "Ma Hoa Don: "; in>>hoaDon.maHoaDon;
            in>>hoaDon.nguoiThue;
            in>>hoaDon.phong;
            cout << "Thang: "; in>>hoaDon.thang;
            cout << "So Dien: "; in>>hoaDon.soDien;
            cout << "So Nuoc: " ; in>>hoaDon.soNuoc;
            return in;

        }
        
};

#endif
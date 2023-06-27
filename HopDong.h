#ifndef HOPDONG_H
#define HOPDONG_H

#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;
class HopDong{
    private:
        string maHopDong;
        string sdtNguoiThue;
        string maPhong;
        string ngayBatDauThue;
        string ngayKetThucThue;
    public:
        HopDong();
        
        HopDong(string maHopDong, string sdtNguoiThue, string maPhong, string ngayBatDauThue, string ngayKetThucThue);
        
        HopDong (const HopDong &p);

        ~HopDong();
        
        void setMaHopDong(string maHopDong);
        
        string getMaHopDong() ;

        void setSDTNguoiThue(string sdtNguoiThue);
        
        string getSDTNguoiThue();
        
        void setMaPhong(string maPhong);
        
        string getMaPhong() ;
        
        void setNgayBatDauThue(string ngayBatDauThue);
       
        string getNgayBatDauThue() ;

        void setNgayKetThucThue(string ngayKetThucThue);
       
        string getNgayKetThucThue() ;

        friend ostream& operator << ( ostream &out , const HopDong &hopDong)
        {
            out << "Thong tin Hop Dong: \n";
            out << setw(20) << left <<"Ma Hop Dong: " << hopDong.maHopDong<<"\n";
            out << setw(20) << left <<"So Dien Thoai  Nguoi Thue: " << hopDong.sdtNguoiThue << endl;
            out << setw(20) << left <<"Ma Phong: " <<hopDong.maPhong << endl;
            out << setw(20) << left <<"Ngay Bat Dau Thue Thue : " << hopDong.ngayBatDauThue<<"\n";
            out << setw(20) << left <<"Ngay Ket Thuc Thue : " << hopDong.ngayKetThucThue<<"\n";
            return out;
        }
        friend istream& operator >> ( istream &in , HopDong &hopDong)
        {
            cout << "Nhap thong tin Hop Dong: \n";
//            cout << "Ma Hop Dong: "; in >> hopDong.maHopDong;
            cout << "So Dien Thoai Nguoi Thue: " ; in>>hopDong.sdtNguoiThue;
            cout << "Ma Phong: " ;in>>hopDong.maPhong;
            cout << "Ngay bat dau Thue: "; in>>hopDong.ngayBatDauThue;
            cout << "Ngay ket thuc Thue: "; in>>hopDong.ngayKetThucThue;
            hopDong.maHopDong = hopDong.sdtNguoiThue + hopDong.maPhong;
            
            return in;
        }
       
};
#endif
#ifndef NGUOITHUE_H
#define NGUOITHUE_H

#include <iostream>
#include <string> 
#include <iomanip>
#include <limits>

using namespace std;
class NguoiThue {
    private:
        string ten;
        string CCCD;
        string diaChi;
        string soDienThoai;
        string ngaySinh;
        bool gioiTinh;
    public:
        NguoiThue();
        
        NguoiThue(string ten,string CCCD, string diaChi, string soDienThoai, string ngaySinh, bool gioiTinh) ;
        
        ~NguoiThue();
        
        NguoiThue (const NguoiThue &p);
        
        void setTen(string ten) ;
        
        string getTen() ;

        void setCCCD(string CCCD); 
        
        string getCCCD() ;
        
        void setDiaChi(string diaChi) ;
        
        string getDiaChi() ;

        void setSoDienThoai(string soDienThoai) ;
        
        string getSoDienThoai() ;

        void setNgaySinh(string ngaySinh) ;
        
        string getNgaySinh() ;
    
        void setGioiTinh(bool gioiTinh) ;
        
        bool getGioiTinh() ;
        
        
        
        friend ostream& operator << ( ostream &out , const NguoiThue &nguoiThue)
        {
            out<< "\nThong tin Nguoi Thue: \n";
            out<< setw(20) << left << "Ten: "<< nguoiThue.ten << "\n";
            out<< setw(20) << left << "CCCD: "<< nguoiThue.CCCD << "\n";
            out<< setw(20) << left << "Dia Chi: "<< nguoiThue.diaChi << "\n";
            out<< setw(20) << left << "So Dien Thoai: "<< nguoiThue.soDienThoai << "\n";
            out<< setw(20) << left << "Ngay Sinh: "<< nguoiThue.ngaySinh << "\n";
            out<< setw(20) << left << "Gioi Tinh: "; (nguoiThue.gioiTinh) ? out << "Nam\n" : out << "Nu\n";

            return out;
        }

        friend istream& operator >> ( istream &in , NguoiThue &nguoiThue)
        {
            cout<<"\nNhap thong tin Nguoi Thue: \n";
            // cout<< "Ten: "; getline(in, nguoiThue.ten);
            cout << "Ten: ";
            in.ignore(numeric_limits<streamsize>::max(), '\n'); //getline khong xóa ký tự  newline cuối cùng nên hàm getline trả về khoảng trắng
            getline(in, nguoiThue.ten);

            // cout<< "CCCD: "; in >> nguoiThue.CCCD;
            cout<< "Dia Chi: ";  getline(in, nguoiThue.diaChi);
            cout<< "CCCD: "; in >> nguoiThue.CCCD;
            cout<< "So Dien Thoai: " ; in >> nguoiThue.soDienThoai;
            cout<< "Ngay Sinh (dd//mm/yyyy):"; in >> nguoiThue.ngaySinh;
            cout<< "Gioi Tinh (0: Nu or 1: Nam): "; in >> nguoiThue.gioiTinh;

            return in;
        }
        
};

#endif
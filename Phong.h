#ifndef PHONG_H
#define PHONG_H

#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

class Phong {
    private:
        string maPhong;
        double dienTich;
        bool tinhTrang;
        bool coGac;
        double giaThue;
    public:
        Phong();
        
        Phong(string maPhong, double dienTich, bool tinhTrang, bool coGac, double giaThue); 
        
        Phong(const Phong &p);
        
        ~Phong();
        
        void setMaPhong(string maPhong) ;
        
        string getMaPhong() ;
        
        void setDienTich(double dienTich) ;
        
        double getDienTich() ;
        
        void setTinhTrang(bool tinhTrang) ;
        
        bool getTinhTrang();

        void setCoGac(bool coGac) ;

        bool getCoGac();
        
        void setGiaThue(double giaThue) ;
        
        double getGiaThue() ;
        
        friend ostream& operator << ( ostream &out , const Phong &phong)
        {
            out << "\nThong tin phong: \n";
            out << setw(20) << left <<"Ma Phong: "<<phong.maPhong << "\n";
            out << setw(20) << left <<"Dien Tich: "<<phong.dienTich << "\n";
            out << setw(20) << left <<"Tinh Trang: "; (phong.tinhTrang)? out << "Phong da duoc cho thue\n" : out << "Phong trong\n";
            out << setw(20) << left <<"Co Gac: "; (phong.coGac)? out<<"Co gac\n" : out<< "Khong co gac\n";
            // out<< setw(20) << left <<"GiaThue: "<<phong.giaThue << "\n";
            out << setw(20) << left <<"GiaThue: "<< fixed << setprecision(0) << phong.giaThue << "\n";
            return out;
    
        }
        friend istream& operator >> ( istream &in , Phong &phong)
        {
            cout <<"\nNhap thong tin phong: \n";
            cout << "Ma Phong: "; in>>phong.maPhong;
            cout << "Dien Tich: "; in>>phong.dienTich;
            cout << "Tinh Trang (0: Phong trong or 1: Phong da duoc cho thue): "; in>>phong.tinhTrang;
            cout << "Co Gac(0: khong co gac or 1: co gac): " ; in>>phong.coGac;
            cout << "GiaThue: "; in>>phong.giaThue;
            return in;
   
        }
        

};

#endif
#include <iostream>
#include <string> 
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include "NguoiThue.h"
#include "Phong.h"
#include "HoaDon.h"
#include "HopDong.h"
#include "LinkedList.cpp"
using namespace std;
string getCurrentTime();
string xoaKhoangTrangCuoi(string str);
LinkedList<NguoiThue> docTepNguoiThue();
LinkedList<Phong> docTepPhong();
LinkedList<HopDong> docTepHopDong();
void QuanLyHopDongThueTro(LinkedList<HopDong> dsHopDong, LinkedList<NguoiThue> dsNT, LinkedList<Phong> dsP);
void QuanLyDanhSachNguoiThueTro(LinkedList<NguoiThue> dsNT);
void QuanLyDanhSachPhong(LinkedList<Phong> dsP);
//void QuanLyHoaDonThueTro(LinkedList<HoaDon> dsHoaDon );
void mainMenu();
void MenuQLHopDong();
int main()
{
   
   LinkedList<NguoiThue> dsNguoiThue = docTepNguoiThue();
   LinkedList<Phong> dsPhong = docTepPhong();
   LinkedList<HopDong> dsHopDong = docTepHopDong();
   LinkedList<HoaDon> dsHoaDon; 

   bool isRun = true;
   while (isRun)
   {
      mainMenu();
      int choice;
      cin >> choice;
      switch (choice)
      {
      case 1:
         QuanLyHopDongThueTro(dsHopDong, dsNguoiThue, dsPhong);
         break;
      case 2:
         QuanLyDanhSachPhong(dsPhong);   
         break;
      case 3:
         QuanLyDanhSachNguoiThueTro(dsNguoiThue);
         break;
      case 4:

         system("cls");
         cout << "Quan ly Hoa Don Thue tro" << endl;

         system("pause");
         break;
      default:
         isRun = false;
         exit(0);
         break;
      }      
   }
   
}

LinkedList<NguoiThue> docTepNguoiThue()
{
   fstream f;
   string line;
   LinkedList<NguoiThue> ds;
   try
   {
      try
      {
         f.open("D:\\Semester 5\\PBL\\NguoiThue.txt");
       
      }
      catch(const exception& e1)
      {
          cerr << e1.what() << '\n';
      }


      while (getline(f, line))
      {
         //cout<<"\n"<<line.length()<<": "<<line<< endl;
         cout<<endl;
         string ten = line.substr(0, 30);
         ten = xoaKhoangTrangCuoi(ten);

         string CCCD = line.substr(30, 11);
         CCCD = xoaKhoangTrangCuoi(CCCD);

         string diaChi = line.substr(50, 100);
         diaChi = xoaKhoangTrangCuoi(diaChi);

         string soDienThoai = line.substr(150, 10);

         string ngaySinh = line.substr(170, 10);

         bool gioiTinh = (line[181] == '1');

         NguoiThue nt(ten, CCCD, diaChi, soDienThoai, ngaySinh, gioiTinh);
         ds.themCuoi(nt);

      }
//      ds.inDanhSach();
      f.close();
      return ds;
    
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
   return ds;
}
LinkedList<Phong> docTepPhong()
{
   fstream f;
   string line;
   LinkedList<Phong> ds;
   try
   {
      try
      {
         f.open("D:\\Semester 5\\PBL\\Phong.txt");
       
      }
      catch(const exception& e1)
      {
          cerr << e1.what() << '\n';
      }


      while (getline(f, line))
      {
         // cout<<"\n"<<line.length()<<": "<<line<< endl;
         istringstream iss(line);

         string maPhong;
         double dienTich;
         bool tinhTrang;
         bool coGac;
         double giaThue;

         iss >> maPhong >> dienTich >> tinhTrang >> coGac >> giaThue;
        
         Phong p(maPhong, dienTich, tinhTrang, coGac, giaThue);
         ds.themCuoi(p);

      }
//      ds.inDanhSach();
      f.close();
      return ds;
    
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
   return ds;
}
LinkedList<HopDong> docTepHopDong()
{
   fstream f;
   string line;
   LinkedList<HopDong> ds;
   try
   {
      try
      {
         f.open("D:\\Semester 5\\PBL\\HopDong.txt");
       
      }
      catch(const exception& e1)
      {
          cerr << e1.what() << '\n';
      }


      while (getline(f, line))
      {
         // cout<<"\n"<<line.length()<<": "<<line<< endl;
         stringstream ss(line);

         string maHopDong;
         string sdtNguoiThue;
         string maPhong;
         string ngayBatDauThue;
         string ngayKetThucThue;

         ss >> maHopDong >> sdtNguoiThue >> maPhong >> ngayBatDauThue >> ngayKetThucThue;
            
         HopDong hd(maHopDong, sdtNguoiThue, maPhong, ngayBatDauThue, ngayKetThucThue);
         ds.themCuoi(hd);

      }
//      ds.inDanhSach();
      f.close();
      return ds;
    
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
   return ds;
}
string getCurrentTime()
{
   time_t now = time(0);
   tm *ltm = localtime(&now);
   stringstream ss;
//   ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
   ss << ltm->tm_mday <<"/"<< 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
   return ss.str();
}
string xoaKhoangTrangCuoi(string str) {
    std::size_t pos = str.find_last_not_of(' ');
    if (pos != std::string::npos) {
        str.erase(pos + 1);
    } else {
        str.clear();
    }
    return str;
}
void QuanLyHopDongThueTro(LinkedList<HopDong> dsHopDong, LinkedList<NguoiThue> dsNguoiThue, LinkedList<Phong> dsPhong)
{
   try
   {
      bool isRunning = true;
      while (isRunning) 
      {
         MenuQLHopDong();
         int choice;
         cin >> choice;
         if ( choice == 1)
         {
            NguoiThue nt;
            string maPhong;
            string maHopDong, ngayThue;
            cin >> nt;
            dsNguoiThue.themCuoi(nt);      
            cout << endl;

            bool kiemTraPhongTrong = true;
            while (kiemTraPhongTrong) 
            {
               bool  check;
               dsPhong.inDanhSachPhongTrong(check);
               if (check == false) break;
               cout << endl;

               cout << "Nhap ma phong: "; cin >> maPhong;
               Node<Phong> *p = dsPhong.timKiemPhong(maPhong);
               if (p == nullptr) 
               {
                  cout << "Phong khong ton tai, vui long chon mot phong khac." << endl;
                  system("pause");
               } 
               else if (p->data.getTinhTrang()) 
               {
                  cout << "Phong da duoc cho thue, vui long chon mot phong khac." << endl;
                  system("pause");
               } 
               else if (p != nullptr && p->data.getTinhTrang() == 0)
               {
                  kiemTraPhongTrong = false;
                  p->data.setTinhTrang(1);
                  cout << "Nhap ngay thue: "; cin >> ngayThue;
                  maHopDong = nt.getSoDienThoai() + maPhong;

                  HopDong hd(maHopDong, nt.getSoDienThoai(), maPhong, ngayThue, " ");
                  dsHopDong.themCuoi(hd);

                  cout << "Them moi hop dong thanh cong!! ";
                  system ("pause");
               }
            }         
         }
         else if (choice == 2)
         {
            cout << "Danh sach cac hop dong cho thue tro: ";
            dsHopDong.inDanhSach();
            cout<< endl;
            system ("pause");
         }
         else if (choice == 3)
         {
            cout << "Nhap ma phong can tra: ";
            string traPhong;
            cin >> traPhong;
            Node<Phong> *p = dsPhong.timKiemPhong(traPhong);
            if ( p == nullptr )
            {
               cout << "Phong khong ton tai "<< endl;
            }
            else
            {
               p->data.setTinhTrang(0);
               Node<HopDong> *hd = dsHopDong.timKiemHopDongTheoMaPhong(traPhong);
               if (hd == nullptr )
               {
                  cout << "Hop Dong khong ton tai " << endl;
               }
               else
               {
                  hd->data.setNgayKetThucThue(getCurrentTime());            
                  cout << hd->data;
                  system("pause");
               }
            }            
         }
         else if ( choice == 4)
         {
            cout << "Nhap ma hop dong can xoa: ";
            string maHopDong;
            cin >> maHopDong;
            Node<HopDong> *hd = dsHopDong.timKiemHopDongTheoMaHopDong(maHopDong);
            if ( hd == nullptr )
            {
               cout << "Hop Dong khong ton tai "<< endl;
               system("pause");

            }
            else if (hd->data.getNgayKetThucThue() == "" )
            {
               cout << "Hop Dong chua het han, vui long ket thuc hop dong truoc khi xoa!  " << endl;
               system("pause");

            }
            else
            {
               dsHopDong.xoaHopDong(maHopDong);
               cout << "Xoa Hop Dong thanh cong" ;
               system("pause");

            }
               
            
         }
         else 
         {
            isRunning = false;
         }      
      }  
      cout<< endl;
      system("pause");  
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }   
}
void QuanLyDanhSachPhong(LinkedList<Phong> dsP)
{
   try
   {
      bool isRunning = true;
      while (isRunning) 
      {
         system("cls");
         cout  << "========================================" << endl
                  << "||     QUAN LY DANH SACH PHONG TRO    ||" << endl
               << "========================================" << endl << endl
               << "Cac chuc nang: " << endl
               << "1. Xem danh sach cac phong tro" << endl
               << "2. Them moi phong tro "<< endl
               << "3. Cap nhat gia phong tro " << endl
               << "0. Quay lai" << endl
               << "Nhap cong viec can lua chon: ";
         int choice;
         cin >> choice;
         if ( choice == 1)
         {
            cout << "Danh sach cac phong tro: " << endl;
            dsP.inDanhSach();
            cout << endl;
            system("pause");            
         }
         else if (choice == 2)
         {
            Phong ph;
            cin >>ph;

            Node<Phong> *p = dsP.timKiemPhong(ph.getMaPhong());
            if (p != nullptr) 
            {
               cout << "Ma Phong da ton tai. Vui long nhap mot ma phong khac" << endl;
               system("pause");
            } 
            else
            {
               dsP.themCuoi(ph);

               cout << "Them phong thanh cong" << endl;

            }
            
            system("pause");
            
         }
         else if (choice == 3)
         {
            cout << "Nhap ma phong can cap nhap gia: ";
            string maPhong;
            cin >> maPhong;
            Node<Phong> *p = dsP.timKiemPhong(maPhong);
            if (p == nullptr) 
            {
               cout << "Phong khong ton tai." << endl;
               system("pause");
            } 
            else 
            {
               cout << "Gia cu: "<< p->data.getGiaThue() << endl;
               cout << "Nhap gia moi ban muon cap nhat: ";
               double giaMoi;
               cin >> giaMoi;
               p->data.setGiaThue(giaMoi);

               cout << "Cap nhat gia thanh cong  "<< endl;

               system("pause");
            }
                       
         }
         else 
         {
            isRunning = false;
         }      
      }  
      cout<< endl;
      system("pause");  
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }   

}
void QuanLyDanhSachNguoiThueTro(LinkedList<NguoiThue> dsNguoiThue)
{
   try
   {
      bool isRunning = true;
      while (isRunning) 
      {
         system("cls");
         cout  << "========================================" << endl
               << "||  QUAN LY DANH SACH NGUOI THUE TRO  ||" << endl
               << "========================================" << endl << endl
               << "Cac chuc nang: " << endl
               << "1. Xem danh sach nguoi thue tro" << endl
               << "2. Xoa nguoi thue tro "<< endl
               << "3. Cap nhat thong tin nguoi thue tro " << endl
               << "0. Quay lai" << endl
               << "Nhap cong viec can lua chon: ";
         int choice;
         cin >> choice;
         if ( choice == 1)
         {
            cout << "Danh sach nguoi thue tro : " << endl;
            dsNguoiThue.inDanhSach();
            cout << endl;
            system("pause");            
         }
         else if (choice == 2)
         {
            cout << "Nhap ten nguoi thue tro can xoa : ";
            string ten;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, ten);

            Node<NguoiThue> *nt = dsNguoiThue.timKiemNguoiThue(ten);

            if (nt != nullptr) 
            {
               cout << "Nguoi Thue nay khong co trong he thong" << endl;
               system("pause");
            } 
            else
            {
               dsNguoiThue.xoaNguoiThue(ten);
               cout << "Xoa Nguoi thue thanh cong" << endl;

            }
            
            system("pause");
            
         }
         else if (choice == 3)
         {
            cout << "Cap nhat gi day ???" << endl;
            system("pause");

         }
         else 
         {
            isRunning = false;
         }      
      }  
      cout<< endl;
      system("pause");  
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }   


}
void mainMenu()
{
      system("cls");
      cout  << "========================================" << endl
            << "||     HE THONG QUAN LY PHONG TRO     ||" << endl
            << "========================================" << endl << endl
            << "Welcome Admin" << endl <<endl
            << "         MAIN MENU                      " << endl
            << "1. Quan ly Hop Dong Thue Tro" << endl
            << "2. Quan ly danh sach phong  tro" << endl
            << "3. Quan ly danh sach Nguoi Thue" <<endl
            << "4. Quan ly Hoa Don Thue tro " << endl
            << "0. Thoat khoi he thong " << endl
            << "Vui long nhap lua chon cua ban: ";
}
void MenuQLHopDong()
{
         system("cls");
         cout  << "========================================" << endl
               << "||     QUAN LY HOP DONG THUE TRO      ||" << endl
               << "========================================" << endl << endl
               << "Cac chuc nang: " << endl
               << "1. Them moi Hop Dong cho thue tro" << endl
               << "2. Xem tat ca cac Hop Dong "<< endl
               << "3. Xac nhan tra phong, ket thuc hop dong " << endl
               << "4. Xoa Hop Dong " << endl
               << "0. Quay lai" << endl
               << "Nhap cong viec can lua chon: ";
}





// {
//    LinkedList<NguoiThue> dsNguoiThue;

//    NguoiThue nt1("Nguyen Van A", "001", "Ha Noi", "0123456789", "01/01/1990", true, "P001");
//    NguoiThue nt2("Tran Thi B", "002", "Hai Phong", "0987654321", "02/02/1995", false, "P002");

//    dsNguoiThue.themDau(nt1);
//    dsNguoiThue.themCuoi(nt2);

//    dsNguoiThue.inDanhSach();

//    LinkedList<Phong> dsPhong;

//    Phong p1("P001", 20.0, true, false, 1000000);
//    Phong p2("P002", 25.0, false, true, 1500000);

//    dsPhong.themDau(p1);
//    dsPhong.themCuoi(p2);

//    dsPhong.inDanhSach();

//    return 0;


// }


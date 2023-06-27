#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void inputPhong()
{
    fstream f;
    string line;

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
            cout<<line<<endl;

        }

        f.close();
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
}
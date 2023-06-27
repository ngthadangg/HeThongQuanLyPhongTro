#include <iostream>
using namespace std;

// Định nghĩa một node trong danh sách liên kết đôi
template <typename T>
struct Node {
    T data;
    Node *prev;
    Node *next;
};

// Định nghĩa lớp template DanhSach
template <typename T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    // Thêm một phần tử vào đầu danh sách
    void themDau(T data) {
        Node<T> *newNode = new Node<T>{data, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Thêm một phần tử vào cuối danh sách
    void themCuoi(T data) {
        Node<T> *newNode = new Node<T>{data, tail, nullptr};
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
    }

    // In ra danh sách
    void inDanhSach() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void inDanhSachPhongTrong(bool &check) 
    {
        cout << "Danh sach cac phong chua duoc cho thue:" << endl;
        Node<T> *temp = head;
        int count = 0; 
        
        while (temp != nullptr) {
            if (!temp->data.getTinhTrang()) {
                cout << temp->data;
                count++;
            }
            temp = temp->next;
        }
        if (count == 0) 
        {
        cout << "Het phong trong." << endl;
        check = false;
        }
    }
    Node<T>* timKiemPhong(string maPhong) {
        Node<T> *temp = head;
        while (temp != nullptr) {
            if (temp->data.getMaPhong() == maPhong) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    Node<T>* timKiemHopDongTheoMaPhong(string maPhong) {
        Node<T> *temp = head;
        while (temp != nullptr) {
            if (temp->data.getMaPhong() == maPhong) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    Node<T>* timKiemHopDongTheoMaHopDong(string maHopDong) {
        Node<T> *temp = head;
        while (temp != nullptr) {
            if (temp->data.getMaHopDong() == maHopDong) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    Node<T>* timKiemNguoiThue(string ten) {
        Node<T> *temp = head;
        while (temp != nullptr) {
            if (temp->data.getTen() == ten) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    void xoaHopDong(string maHopDong) 
    {
        Node<T> *temp = head;
        while (temp != nullptr) 
        {
            if (temp->data.getMaHopDong() == maHopDong) 
            {
                if (temp->prev != nullptr) 
                {
                    temp->prev->next = temp->next;
                } 
                else 
                {
                    head = temp->next;
                }

                if (temp->next != nullptr) 
                {
                    temp->next->prev = temp->prev;
                } 
                else 
                {
                    tail = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }
    void xoaNguoiThue(string ten) 
    {
        Node<T> *temp = head;
        while (temp != nullptr) 
        {
            if (temp->data.getTen() == ten) 
            {
                if (temp->prev != nullptr) 
                {
                    temp->prev->next = temp->next;
                } 
                else 
                {
                    head = temp->next;
                }

                if (temp->next != nullptr) 
                {
                    temp->next->prev = temp->prev;
                } 
                else 
                {
                    tail = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    
};
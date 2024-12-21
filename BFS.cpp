#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

const int MaxDinh = 1 + 1e5;

int soDinh;
bool daTham[MaxDinh]; 
vector<int> danhSachKe[MaxDinh]; 

void TimKiemTheoChieuRong() {
    queue<int> hangDoi; 
    hangDoi.push(1); 
    while (!hangDoi.empty()) {
        int dinhHienTai = hangDoi.front(); 
        hangDoi.pop(); 
        daTham[dinhHienTai] = true;
        cout << dinhHienTai << " "; 

        for (int dinhKe : danhSachKe[dinhHienTai]) {
            if (!daTham[dinhKe]) {
                hangDoi.push(dinhKe); 
                daTham[dinhKe] = true; 
            }
        }
    }
}

int main() {
    cout << "Nhap so dinh: ";
    cin >> soDinh;

    cout << "Nhap cac canh (moi canh la 2 dinh u v):" << endl;
    for (int i = 0; i < soDinh - 1; ++i) {
        int dinh1, dinh2;
        cin >> dinh1 >> dinh2; 
        danhSachKe[dinh1].push_back(dinh2); 
        danhSachKe[dinh2].push_back(dinh1); 
    }

    cout << "Ket qua duyet BFS: ";
    TimKiemTheoChieuRong(); 

    return 0;
}

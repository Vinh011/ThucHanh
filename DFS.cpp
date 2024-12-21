#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void Tim_Kiem_Chieu_Sau(vector<vector<int>> do_thi, int bat_dau, int ket_thuc) {
    stack<int> Open;
    Open.push(bat_dau);
    vector<bool> da_tham(do_thi.size(), false);

    while (!Open.empty()) { 
        int u = Open.top(); 
        Open.pop(); 

        if (da_tham[u]) continue; 
        da_tham[u] = true;

        cout << "Dang xet trang thai: " << u << endl; 

        if (u == ket_thuc) {
            cout << "Tim thay trang thai ket thuc!" << endl;
            return;
        }

        for (int v : do_thi[u]) {
            if (!da_tham[v]) Open.push(v); 
        }
    }

    cout << "Khong tim thay trang thai ket thuc!" << endl; 
}

int main() {
    int so_dinh, so_canh;
    cout << "Nhap so dinh: ";
    cin >> so_dinh;
    cout << "Nhap so canh: ";
    cin >> so_canh;

    vector<vector<int>> do_thi(so_dinh + 1); 
    cout << "Nhap cac canh (dinh1 dinh2): " << endl;
    for (int i = 0; i < so_canh; i++) {
        int dinh1, dinh2;
        cin >> dinh1 >> dinh2;
        do_thi[dinh1].push_back(dinh2);
        
    }

    int bat_dau, ket_thuc;
    cout << "Nhap trang thai bat dau: ";
    cin >> bat_dau;
    cout << "Nhap trang thai ket thuc: ";
    cin >> ket_thuc;

    Tim_Kiem_Chieu_Sau(do_thi, bat_dau, ket_thuc);

    return 0;
}

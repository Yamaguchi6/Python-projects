C++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struktur untuk merepresentasikan data sebuah buku
struct Buku {
    string judul;
    string pengarang;
    string status;
};

// Fungsi untuk mengubah string ke lowercase agar pencarian tidak case-sensitive
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(const vector<Buku>& bukuList) {
    cout << "\n--- DAFTAR BUKU PERPUSTAKAAN ---\n";
    if (bukuList.empty()) {
        cout << "Buku tidak ditemukan.\n";
        return;
    }

    for (size_t i = 0; i < bukuList.size(); ++i) {
        cout << i + 1 << ". Judul    : " << bukuList[i].judul << "\n";
        cout << "   Pengarang: " << bukuList[i].pengarang << "\n";
        cout << "   Status   : " << bukuList[i].status << "\n";
        cout << "--------------------------------\n";
    }
}

// Fungsi untuk mencari buku berdasarkan judul atau pengarang
void cariBuku(const vector<Buku>& daftarBuku) {
    string keyword;
    cout << "Masukkan judul atau pengarang yang dicari: ";
    cin.ignore(); // Membersihkan buffer newline
    getline(cin, keyword);

    string keywordLower = toLower(keyword);
    vector<Buku> hasilPencarian;

    for (const auto& b : daftarBuku) {
        if (toLower(b.judul).find(keywordLower) != string::npos || 
            toLower(b.pengarang).find(keywordLower) != string::npos) {
            hasilPencarian.push_back(b);
        }
    }

    cout << "\n--- HASIL PENCARIAN: \"" << keyword << "\" ---\n";
    tampilkanBuku(hasilPencarian);
}

int main() {
    // Inisialisasi data awal perpustakaan SMP
    vector<Buku> daftarBuku = {
        {"Matematika Kelas 7", "Kemendikbud", "Tersedia"},
        {"IPA Terpadu Kelas 8", "Tim Abdi Guru", "Tersedia"},
        {"Bahasa Indonesia Kelas 9", "Eko Suroso", "Dipinjam"},
        {"Laskar Pelangi", "Andrea Hirata", "Tersedia"},
        {"Sejarah Nusantara", "Bambang Soekarno", "Dipinjam"}
    };

    int pilihan;

    // Menu Utama
    do {
        cout << "\n=== SISTEM PERPUSTAKAAN SMP ===\n";
        cout << "1. Lihat Semua Buku\n";
        cout << "2. Cari Buku\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu (1/2/3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanBuku(daftarBuku);
                break;
            case 2:
                cariBuku(daftarBuku);
                break;
            case 3:
                cout << "Terima kasih telah berkunjung ke Perpustakaan SMP!\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}
# Data buku perpustakaan SMP (List berisi dictionary)
daftar_buku = [
    {"judul": "Matematika Kelas 7", "pengarang": "Kemendikbud", "status": "Tersedia"},
    {"judul": "IPA Terpadu Kelas 8", "pengarang": "Tim Abdi Guru", "status": "Tersedia"},
    {"judul": "Bahasa Indonesia Kelas 9", "pengarang": "Eko Suroso", "status": "Dipinjam"},
    {"judul": "Laskar Pelangi", "pengarang": "Andrea Hirata", "status": "Tersedia"},
    {"judul": "Sejarah Nusantara", "pengarang": "Bambang Soekarno", "status": "Dipinjam"}
]

def tampilkan_buku(buku_list):
    print("\n--- DAFTAR BUKU PERPUSTAKAAN ---")
    if not buku_list:
        print("Buku tidak ditemukan.")
        return
    
    for i, buku in enumerate(buku_list, 1):
        print(f"{i}. Judul    : {buku['judul']}")
        print(f"   Pengarang: {buku['pengarang']}")
        print(f"   Status   : {buku['status']}")
        print("-" * 30)

def cari_buku():
    keyword = input("Masukkan judul atau pengarang yang dicari: ").lower()
    
    # Filter buku berdasarkan kata kunci
    hasil = [
        buku for buku in daftar_buku 
        if keyword in buku['judul'].lower() or keyword in buku['pengarang'].lower()
    ]
    
    tampilkan_buku(hasil)

# Program utama (Menu Sederhana)
while True:
    print("\n=== SISTEM PERPUSTAKAAN SMP ===")
    print("1. Lihat Semua Buku")
    print("2. Cari Buku")
    print("3. Keluar")
    
    pilihan = input("Pilih menu (1/2/3): ")
    
    if pilihan == '1':
        tampilkan_buku(daftar_buku)
    elif pilihan == '2':
        cari_buku()
    elif pilihan == '3':
        print("Terima kasih telah berkunjung ke Perpustakaan SMP!")
        break
    else:
        print("Pilihan tidak valid, silakan coba lagi.")
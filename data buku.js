// Data buku perpustakaan SMP (Array of Objects)
let daftarBuku = [
    { judul: "Matematika Kelas 7", pengarang: "Kemendikbud", status: "Tersedia" },
    { judul: "IPA Terpadu Kelas 8", pengarang: "Tim Abdi Guru", status: "Tersedia" },
    { judul: "Bahasa Indonesia Kelas 9", pengarang: "Eko Suroso", status: "Dipinjam" },
    { judul: "Laskar Pelangi", pengarang: "Andrea Hirata", status: "Tersedia" },
    { judul: "Sejarah Nusantara", pengarang: "Bambang Soekarno", status: "Dipinjam" }
];

// Fungsi untuk menampilkan semua daftar buku
function tampilkanBuku(bukuArray = daftarBuku) {
    console.log("\n--- DAFTAR BUKU PERPUSTAKAAN ---");
    if (bukuArray.length === 0) {
        console.log("Buku tidak ditemukan.");
        return;
    }
    bukuArray.forEach((buku, index) => {
        console.log(`${index + 1}. Judul    : ${buku.judul}`);
        console.log(`   Pengarang: ${buku.pengarang}`);
        console.log(`   Status   : ${buku.status}`);
        console.log("--------------------------------");
    });
}

// Fungsi untuk mencari buku berdasarkan judul atau pengarang
function cariBuku(keyword) {
    const query = keyword.toLowerCase();
    const hasil = daftarBuku.filter(buku => 
        buku.judul.toLowerCase().includes(query) || 
        buku.pengarang.toLowerCase().includes(query)
    );
    
    console.log(`\n--- HASIL PENCARIAN: "${keyword}" ---`);
    tampilkanBuku(hasil);
}

// --- Contoh Penggunaan (Uji Coba) ---

// 1. Menampilkan seluruh daftar buku
tampilkanBuku();

// 2. Mencari buku dengan kata kunci "matematika"
cariBuku("matematika");

// 3. Mencari buku berdasarkan pengarang "andrea"
cariBuku("andrea");
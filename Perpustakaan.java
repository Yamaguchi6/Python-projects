import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Kelas untuk merepresentasikan data sebuah buku
class Buku {
    String judul;
    String pengarang;
    String status;

    public Buku(String judul, String pengarang, String status) {
        this.judul = judul;
        this.pengarang = pengarang;
        this.status = status;
    }
}

public class Perpustakaan {
    private static List<Buku> daftarBuku = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        // Mengisi data awal perpustakaan SMP
        daftarBuku.add(new Buku("Matematika Kelas 7", "Kemendikbud", "Tersedia"));
        daftarBuku.add(new Buku("IPA Terpadu Kelas 8", "Tim Abdi Guru", "Tersedia"));
        daftarBuku.add(new Buku("Bahasa Indonesia Kelas 9", "Eko Suroso", "Dipinjam"));
        daftarBuku.add(new Buku("Laskar Pelangi", "Andrea Hirata", "Tersedia"));
        daftarBuku.add(new Buku("Sejarah Nusantara", "Bambang Soekarno", "Dipinjam"));

        // Menu Utama
        while (true) {
            System.out.println("\n=== SISTEM PERPUSTAKAAN SMP ===");
            System.out.println("1. Lihat Semua Buku");
            System.out.println("2. Cari Buku");
            System.out.println("3. Keluar");
            System.out.print("Pilih menu (1/2/3): ");
            
            String pilihan = scanner.nextLine();

            if (pilihan.equals("1")) {
                tampilkanBuku(daftarBuku);
            } else if (pilihan.equals("2")) {
                cariBuku();
            } else if (pilihan.equals("3")) {
                System.out.println("Terima kasih telah berkunjung ke Perpustakaan SMP!");
                break;
            } else {
                System.out.println("Pilihan tidak valid, silakan coba lagi.");
            }
        }
    }

    // Fungsi untuk menampilkan daftar buku
    public static void tampilkanBuku(List<Buku> bukuList) {
        System.out.println("\n--- DAFTAR BUKU PERPUSTAKAAN ---");
        if (bukuList.isEmpty()) {
            System.out.println("Buku tidak ditemukan.");
            return;
        }

        for (int i = 0; i < bukuList.size(); i++) {
            Buku b = bukuList.get(i);
            System.out.println((i + 1) + ". Judul    : " + b.judul);
            System.out.println("   Pengarang: " + b.pengarang);
            System.out.println("   Status   : " + b.status);
            System.out.println("--------------------------------");
        }
    }

    // Fungsi untuk mencari buku berdasarkan judul atau pengarang
    public static void cariBuku() {
        System.out.print("Masukkan judul atau pengarang yang dicari: ");
        String keyword = scanner.nextLine().toLowerCase();

        List<Buku> hasilPencarian = new ArrayList<>();
        for (Buku b : daftarBuku) {
            if (b.judul.toLowerCase().contains(keyword) || b.pengarang.toLowerCase().contains(keyword)) {
                hasilPencarian.add(b);
            }
        }

        tampilkanBuku(hasilPencarian);
    }
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Struct untuk merepresentasikan data sebuah buku
type Buku struct {
	Judul     string
	Pengarang string
	Status    string
}

func main() {
	// Inisialisasi data awal perpustakaan SMP
	daftarBuku := []Buku{
		{"Matematika Kelas 7", "Kemendikbud", "Tersedia"},
		{"IPA Terpadu Kelas 8", "Tim Abdi Guru", "Tersedia"},
		{"Bahasa Indonesia Kelas 9", "Eko Suroso", "Dipinjam"},
		{"Laskar Pelangi", "Andrea Hirata", "Tersedia"},
		{"Sejarah Nusantara", "Bambang Soekarno", "Dipinjam"},
	}

	reader := bufio.NewReader(os.Stdin)

	// Menu Utama
	for {
		fmt.Println("\n=== SISTEM PERPUSTAKAAN SMP ===")
		fmt.Println("1. Lihat Semua Buku")
		fmt.Println("2. Cari Buku")
		fmt.Println("3. Keluar")
		fmt.Print("Pilih menu (1/2/3): ")

		inputPilihan, _ := reader.ReadString('\n')
		pilihan := strings.TrimSpace(inputPilihan)

		if pilihan == "1" {
			tampilkanBuku(daftarBuku)
		} else if pilihan == "2" {
			fmt.Print("Masukkan judul atau pengarang yang dicari: ")
			inputKeyword, _ := reader.ReadString('\n')
			keyword := strings.TrimSpace(inputKeyword)
			
			cariBuku(daftarBuku, keyword)
		} else if pilihan == "3" {
			fmt.Println("Terima kasih telah berkunjung ke Perpustakaan SMP!")
			break
		} else {
			fmt.Println("Pilihan tidak valid, silakan coba lagi.")
		}
	}
}

// Fungsi untuk menampilkan daftar buku
func tampilkanBuku(bukuList []Buku) {
	fmt.Println("\n--- DAFTAR BUKU PERPUSTAKAAN ---")
	if len(bukuList) == 0 {
		fmt.Println("Buku tidak ditemukan.")
		return
	}

	for i, b := range bukuList {
		fmt.Printf("%d. Judul    : %s\n", i+1, b.Judul)
		fmt.Printf("   Pengarang: %s\n", b.Pengarang)
		fmt.Printf("   Status   : %s\n", b.Status)
		fmt.Println("--------------------------------")
	}
}

// Fungsi untuk mencari buku berdasarkan judul atau pengarang
func cariBuku(bukuList []Buku, keyword string) {
	keywordLower := strings.ToLower(keyword)
	var hasilPencarian []Buku

	for _, b := range bukuList {
		if strings.Contains(strings.ToLower(b.Judul), keywordLower) || 
		   strings.Contains(strings.ToLower(b.Pengarang), keywordLower) {
			hasilPencarian = append(hasilPencarian, b)
		}
	}

	fmt.Printf("\n--- HASIL PENCARIAN: \"%s\" ---\n", keyword)
	tampilkanBuku(hasilPencarian)
}
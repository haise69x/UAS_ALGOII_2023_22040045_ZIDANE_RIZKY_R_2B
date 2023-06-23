/*
Nama	: Zidane Rizky Ramadhani
Nim		: 22040045
Kelas	: 2B
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#define clear_command "cls"
#else
#define clear_command "clear"
#endif
using namespace std;

struct barang {
	int kode;
	string nama_barang;
	int harga_satuan;
	int jumlah_barang;
	int diskon;
	int harga_diskon;
	
	struct penjualan {
		int total;
		int jumlah;
		int diskon;
	} penjualan_barang[10];
	
} data_barang[10];


void hijauTeks() {
    cout << "\033[32m";
}

void merahTeks() {
    cout << "\033[31m";
}


void kuningTeks() {
    cout << "\033[33m";
}


void resetTeks() {
    cout << "\033[0m";
}

void gotoxy(int x, int y){
	
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menampilkan_dataBarang(int tabel_barang) {
			gotoxy(3, 0);
			kuningTeks();
			cout << "======================[ Data Barang Belum Disorting ]======================" << endl;
			resetTeks();
			gotoxy(3, 1);
			hijauTeks();
			cout << "===========================================================================" << endl;
			gotoxy(3, 2);
			cout << "|    |                         |                 |           |            |" << endl;
			gotoxy(3,3);
			cout << "===========================================================================" << endl;
			for (int i = 0; i < 8; i++) {
			gotoxy(3,4+i);
			cout << "|    |                         |                 |           |            |" << endl;
			}
			gotoxy(3, 12);
			cout << "===========================================================================" << endl;
			resetTeks();
			
			gotoxy(5, 2);
			cout << "NO" << endl;
			gotoxy(16, 2);
			cout << "NAMA BARANG" << endl;
			gotoxy(38, 2);
			cout << "KODE BARANG" << endl;
			gotoxy(56, 2);
			cout << "HARGA" << endl;
			gotoxy(68, 2);
			cout << "DISKON" << endl;
			
				for(int i = 0; i < tabel_barang; ++i) {
					gotoxy(5, 4 + i);
					cout << i + 1 << endl;
					gotoxy(13, 4 + i);
					cout << data_barang[i].nama_barang << endl;
					gotoxy(40, 4 + i);
					cout << data_barang[i].kode << endl;
  				  	gotoxy(56, 4 + i);
					cout << data_barang[i].harga_satuan << endl;
  					gotoxy(68, 4 + i);
					cout << data_barang[i].diskon << endl;
				}
}
void bubble_sorting (barang sort[], int dt) {
	for (int i = 0; i < dt; i++) {
		for (int j = 0; j < dt - i - 1; j++) {
			if (sort[j].kode < sort[j + 1].kode) {
				barang letak = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = letak;
			}
		}
	}
	for(int i = 0; i < dt; i++) {
			gotoxy(3, 14);
			kuningTeks();
			cout << "======================[ Data Barang Sudah Disorting ]======================" << endl;
			resetTeks();
			gotoxy(3, 15);
			hijauTeks();
			cout << "===========================================================================" << endl;
			gotoxy(3, 16);
			cout << "|    |                         |                 |           |            |" << endl;
			gotoxy(3, 17);
			cout << "===========================================================================" << endl;
			for(int i = 0; i < 8; i++) {
			gotoxy(3, 18 + i);
			cout << "|    |                         |                 |           |            |" << endl;
			}
			gotoxy(3, 26);
			cout << "===========================================================================" << endl;
			resetTeks();
			
			gotoxy(5, 16);
			cout << "NO" << endl;
			gotoxy(16, 16);
			cout << "NAMA BARANG" << endl;
			gotoxy(38, 16);
			cout << "KODE BARANG" << endl;
			gotoxy(56, 16);
			cout << "HARGA" << endl;
			gotoxy(68, 16);
			cout << "DISKON" << endl;
			
			
				for (int i = 0; i < dt; ++i) {
					gotoxy(5, 18 + i);
					cout << i + 1 << endl;
					gotoxy(10, 18 + i);
					cout << data_barang[i].nama_barang << endl;
					gotoxy(40, 18 + i);
					cout << data_barang[i].kode << endl;
  				  	gotoxy(56, 18 + i);
					cout << data_barang[i].harga_satuan << endl;
  					gotoxy(68, 18 + i);
					cout << data_barang[i].diskon << endl;
					}
	    }
	
}

void pressEnterToContinue() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}


int main() {
 	string nama, nim, kelas;
	int jumlah_databarang, indeks, pilih_menu, total = 0, kode_barang, diskon, uang, pembayaran = 0, total_diskon = 0, kembalian, kurang_uang = 0;
	bool selesai = false;
	char tanya_lagi, lanjut;
	
	hijauTeks();
    cout << "+==============+[ Login Program Kasir Swalayan ]+==============+" << endl;
	cout << "|                                                              |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|                                                              |" << endl;
    cout << "+==============================================================+" << endl;
    resetTeks();
    
    gotoxy(2, 1);
    cout << "Masukkan NIM\t\t:\t\t\t\t" << endl;
    gotoxy(2, 2);
	cout << "Masukkan Nama\t\t:\t\t\t\t" << endl;
	gotoxy(2, 3);
	cout << "Masukkan Kelas\t:\t\t\t\t" << endl;
	       
    gotoxy(26, 1);
    getline(cin, nim);
    gotoxy(26, 2);
    getline(cin, nama);
    gotoxy(26, 3);
    getline(cin, kelas);
    
	cout << endl << endl;
	hijauTeks();
	pressEnterToContinue();
	resetTeks();
	system(clear_command);
    
do{
	hijauTeks();
    cout << "=======================[ PROGRAM KASIR SWALAYAN ]======================\n";
    cout << "|                    |                            |                   |\n";
    cout << "=======================================================================\n";
    cout << "|                    |                            |                   |\n";
    cout << "=======================================================================\n\n";
    resetTeks();
	gotoxy(10, 1);
	cout << "NIM" << endl;
	gotoxy(34, 1);
	cout << "NAMA" << endl;
	gotoxy(59, 1);
	cout << "KELAS" << endl;
	
	gotoxy(7, 3);
	cout << nim << endl;
	gotoxy(25, 3);
	cout << nama << endl;
	gotoxy(60, 3);
	cout << kelas << endl;
	
    kuningTeks();
    	gotoxy(0, 6);
        cout << "==========[ Menu Utama ]==========" << endl;
        gotoxy(0, 7);
        cout << "| 1. Tambahkan barang		 |" << endl;
        gotoxy(0, 8);
        cout << "| 2. Tampilkan data barang  	 |" << endl;
        gotoxy(0, 9);
        cout << "| 3. Gunakan Program		 |" << endl;
        gotoxy(0, 10);
        cout << "| 4. Cetak nota barang           |" << endl;
        gotoxy(0, 11);
        cout << "==================================" << endl;
        gotoxy(0, 12);
        cout << "Pilih menu\t: ";
        cin >> pilih_menu;
        system(clear_command);
        resetTeks();

	switch (pilih_menu) {
		
		case 1: {
			kuningTeks();
			cout << "======================[ Tambahkan Data Barang ]======================";
			resetTeks();
			cout << endl;
			cout << "Mau Menambah barang berapa Kak? ";
			cin >> jumlah_databarang;
			for (int i = 0 ; i < jumlah_databarang ; ++i) {
				hijauTeks();
				cout << "==================[ Barang Ke " << i + 1 << " ]==================" << endl;
				resetTeks();
				cout << "Kode barang\t: ";
				cin >> data_barang[i].kode;
				cin.ignore();
				cout << "Nama Barang\t: ";
				getline(cin, data_barang[i].nama_barang);
				cout << "Harga Barang\t: Rp. ";
				cin >> data_barang[i].harga_satuan;
				cout << "Diskon\t\t: ";
				cin >> data_barang[i].diskon;
				hijauTeks();
				cout << "===================================================" << endl;
				resetTeks();
			}
			hijauTeks();
			pressEnterToContinue(); 
			resetTeks();
			system(clear_command);
			break;
		}
		case 2: {
			menampilkan_dataBarang(jumlah_databarang);
			bubble_sorting(data_barang, jumlah_databarang);	
			gotoxy(3, 28);
			hijauTeks();
			pressEnterToContinue();
			resetTeks();
			system(clear_command);
			break;
		}
		
		case 3: {
			kuningTeks();
			cout << "======================[ Gunakan Program ]======================";
			resetTeks();
			do{
			cout << endl;
			cout << "Masukkan Kode Barang\t\t\t : ";
			cin >> kode_barang;
			for (indeks = 0; indeks < jumlah_databarang; indeks++) {
				if (kode_barang == data_barang[indeks].kode) {
					cout << "Nama Barang\t\t\t\t : " << data_barang[indeks].nama_barang << endl;
					cout << "Harga Barang\t\t\t\t : Rp. " << data_barang[indeks].harga_satuan <<endl;
					cout << "Diskon\t\t\t\t\t : " << data_barang[indeks].diskon << endl;
					data_barang[indeks].harga_diskon = data_barang[indeks].harga_satuan - data_barang[indeks].diskon;
					cout<< "Berapa Banyak jumlah barang\t\t : ";
					cin >> data_barang[indeks].jumlah_barang;
					data_barang[indeks].penjualan_barang[indeks].jumlah = data_barang[indeks].harga_diskon * data_barang[indeks].jumlah_barang;
					hijauTeks();
					cout << "Total\t\t\t\t\t : Rp. " << data_barang[indeks].penjualan_barang[indeks].jumlah << endl;
					resetTeks();
					total += data_barang[indeks].penjualan_barang[indeks].jumlah;
					total_diskon = data_barang[indeks].diskon * data_barang[indeks].jumlah_barang;
					diskon += total_diskon;
				}
			}
			
			cin.ignore();
			cout << "Apakah ingin belanja lagi? [Y/n]\t : ";
			cin >> lanjut;
			if (lanjut == 'N' || lanjut == 'n'){
			tanya_lagi == true;
			}
			
		} while (lanjut == 'Y' || lanjut == 'y');
			hijauTeks();
			cout << "Totalnya adalah\t\t\t\t : Rp. " << total << endl;
			resetTeks();
			cout << "Anda Hemat Sebesar\t\t\t : " << diskon << endl;
			cin.ignore();
			cout<<"Masukkan uang untuk membayar barang\t : Rp. ";
			cin >> uang;
			while(uang < total) {
				kurang_uang = uang - total;
				merahTeks();
				cout << "\n[ Maaf, uang anda kurang. Mohon Masukkan uang kembali! ]" << endl;
				resetTeks();
				cout << "Masukkan uang kembali\t\t\t : Rp. ";
				cin >> uang;
			}
			hijauTeks();
			kembalian = uang - total;
			cout << "Kembaliannya adalah\t\t\t : Rp. " << kembalian << endl;
			resetTeks();
			hijauTeks();
			cout << endl;
			pressEnterToContinue();
			resetTeks();
			system(clear_command);
			break;
		}
		case 4: {
			system(clear_command);
			kembalian = uang - uang;
			gotoxy(2, 2);
			hijauTeks();
			cout << "==========================================================================" << endl;
			gotoxy(2, 3);
			cout << "|    |                             |                  |                  |" << endl;
			gotoxy(2,4);
			cout << "==========================================================================" << endl;
			for (indeks = 0; indeks < 8; indeks++) {
			gotoxy(2, 5 + indeks);
			cout << "|    |                             |                  |                  |" << endl;
			}
			gotoxy(2, 13);
			cout << "==========================================================================" << endl;
			gotoxy(2, 14);
			cout << "|                                                     |                  |" << endl;
			gotoxy(2, 15);
			cout << "|                                                     |                  |" << endl;
			gotoxy(2, 16);
			cout << "|                                                     |                  |" << endl;
			gotoxy(2, 17);
			cout << "|                                                     |                  |" << endl;
			gotoxy(2, 18);
			cout << "==========================================================================" << endl;
			resetTeks();
			
			gotoxy(4, 3);
			cout << "NO" << endl;
			gotoxy(15, 3);
			cout << "NAMA BARANG" << endl;
			gotoxy(41, 3);
			cout << "TOTAL BARANG" <<  endl;
			gotoxy(64, 3);
			cout << "HARGA" << endl;
			
			
			gotoxy(44, 14);
			cout << "TOTAL HARGA" << endl;
			gotoxy(46, 15);
			cout << "KEMBALIAN" << endl;
			gotoxy(45, 16);
			cout << "UANG TUNAI" << endl;
			gotoxy(49, 17);
			cout << "DISKON" << endl;	
		
			gotoxy(61, 14);
			cout << "Rp. " << total << endl;
			gotoxy(61, 15);
			kembalian = uang - total;
			cout << "Rp. " << kembalian << endl;
			gotoxy(61, 16);
			cout << "Rp. " << uang;
			gotoxy(65, 17);
			diskon += total_diskon;
			cout << diskon << endl;	
			
				for (indeks = 0 ; indeks < jumlah_databarang; ++indeks) {
					if (data_barang[indeks].jumlah_barang != 0) {
					gotoxy(15, 5 + indeks);
					cout << data_barang[indeks].nama_barang << endl;
					gotoxy(45, 5 + indeks);
					cout << data_barang[indeks].jumlah_barang << endl;
  				  	gotoxy(64, 5 + indeks);
					cout << data_barang[indeks].harga_satuan << endl;
					}
			
				}
			gotoxy(2, 19);
			hijauTeks();
			pressEnterToContinue();
			resetTeks();
			tanya_lagi = true;
			break;
		}
		default:
		tanya_lagi = true;
	}

} while (tanya_lagi == false);
system(clear_command);
cout << "Terima Kasih, Telah Belanja Di Tempat Kami" << endl << endl;
hijauTeks();
    cout << "=======================[ PROGRAM KASIR SWALAYAN ]======================\n";
    cout << "|                    |                            |                   |\n";
    cout << "=======================================================================\n";
    cout << "|                    |                            |                   |\n";
    cout << "=======================================================================\n\n";
    resetTeks();
	gotoxy(10, 3);
	cout << "NIM" << endl;
	gotoxy(34, 3);
	cout << "NAMA" << endl;
	gotoxy(59, 3);
	cout << "KELAS" << endl;
	
	gotoxy(7, 5);
	cout << nim << endl;
	gotoxy(25, 5);
	cout << nama << endl;
	gotoxy(60, 5);
	cout << kelas << endl << endl;
	
	return 0;
}


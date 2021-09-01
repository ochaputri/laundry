/*Nama kelompok:
1. Faiza Rachma
2. Farah Zhafirah
3. Ocha Putri*/

//library
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//menggunakan percabangan, perulangan, struct, function, dan prosedur.

//atur waktu
time_t now = time(0);
char * dt = ctime(&now);

//menggunakan struck data
struct data { //kumpulan beberapa variable dengan beberapa tipe data.
    char nama[30],alamat[60],noHP[15],kdKategori, data, ulang;
    int biaya, diskon, biayafix , jumlahBayar , uangKembalian, totalbiaya;
    float berat;
};
data batas[100]; //untuk membatasi data
int a,b,c,d,i; //variable global

//menulis kategori cucian tanpa adanya nilai return
void kategoricucian() {
	cout<<"\t    KATEGORI CUCIAN         "<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "1. REGULER CUCI 3 HARI" << endl;
    cout << "2. EKSPRESS CUCI 2 HARI" << endl;
    cout << "3. KILAT CUCI 1 HARI" << endl << endl;
}

//menulis inputan data sekaligus membayar
void inputdata() {
    char kategori;
    cout << "Jumlah Data yang akan diinput : "; cin>>b;
    d=0;

    for (c=0;c<b;c++) {
        d=d+1;
        cout<<"\nData ke-"<<d<<endl;

        cout << "Nama Pelanggan     : "; cin >> batas[a].nama;
        cout << "Alamat             : "; cin >> batas[a].alamat;
        cout << "No Handphone       : "; cin >> batas[a].noHP;
        cout << "------------------------------------------------" << endl;
        kategori:
        kategoricucian();
        cout << "Input No Kategori [1-3]    : "; cin >> batas[a].kdKategori;
        switch (batas[a].kdKategori) {
        case '1':
            batas[a].biaya=5000;
            break;
        case '2':
            batas[a].biaya=7000;
            break;
        case '3':
            batas[a].biaya=10000;
            break;
        default:
            cout << "Anda salah memasukkan nomor, silahkan coba lagi!" << endl;
            goto kategori;
        }
        cout << "Berat Cucian (Kg)          : "; cin >> batas[a].berat;
        batas[a].totalbiaya = batas[a].biaya*batas[a].berat;
        if (batas[a].berat>=10) {
            cout << "Special diskon 5% setiap cuci lebih dari 10kg!" << endl;
            batas[a].diskon=batas[a].totalbiaya*5/100;
            batas[a].biayafix=batas[a].totalbiaya-batas[a].diskon;
        } else {
            cout << "Maaf. Anda tidak mendapatkan diskon 5%!" << endl;
            batas[a].biayafix=batas[a].totalbiaya;
            batas[a].diskon=0;
        }
        cout << "------------------------------------------------" << endl;
        cout << "\tResi Pesanan Laundry" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Nama Pelanggan             : " << batas[a].nama << endl;
        cout << "Alamat                     : " << batas[a].alamat << endl;
        cout << "No Handphone               : " << batas[a].noHP << endl;
        cout << "Kategori ke-" << batas[a].kdKategori << "              : Rp" << batas[a].biaya << endl;
        cout << "Total Biaya                : " << batas[a].totalbiaya << endl;
        cout << "Diskon special             : " << batas[a].diskon << endl;
        cout << "Total Biaya setelah diskon : " << batas[a].biayafix << endl;
        cout << "Total Bayar                : "; cin >> batas[a].jumlahBayar;
        cout << endl;
        cout << "================================================" << endl;
        batas[a].uangKembalian=batas[a].jumlahBayar-batas[a].biayafix;
        cout << "Kembalian                  : " << batas[a].uangKembalian << endl;
        cout << "================================================" << endl;
        a++;
    }
}

//untuk menampilkan data yang sudah dimasukkan di menu pertama
void lihatdata() {
    int j,totalpenjualan;
    cout<<"Time :"<<dt ;
    cout<<"\n=========================================================================MENAMPILKAN DATA=========================================================================\n\n";
    cout<<"==================================================================================================================================================================\n";
    cout <<"||\tNO\t||\tNama\t||\tAlamat\t\t||\tNo.HP\t||\tKg\t||\tDiskon\t\t||\tKembalian\t||\tTotal Harga\t||" << endl;

	totalpenjualan=0;
    j=0;
    for (i=0;i<a;i++) {
        j += 1;
        cout<<"==================================================================================================================================================================\n";
        cout <<"||\t"<<j<<"\t||";
        cout <<batas[i].nama<<"\t||";
        cout <<batas[i].alamat<<"\t\t||";
        cout <<batas[i].noHP<<"\t||";
        cout <<batas[i].berat<<"\t\t||";
        cout <<"Rp." << batas[i].diskon<<"\t\t||";
        cout <<"Rp." << batas[i].uangKembalian<<"\t\t||";
        cout <<"Rp." << batas[i].biayafix<<"\t\t||";
        totalpenjualan += batas[i].biayafix;
    }
    cout << endl;
    cout<<"==================================================================================================================================================================\n";
    cout<<"\t\t\t\t\t\t\t\t           TOTAL             \t\t\t\t      \t\t ||       " << "Rp."<<totalpenjualan << "\t||\n";
    cout<<"==================================================================================================================================================================\n";
}

//untuk menghapus data pesanan
void hapusdata() {
    int input,data;
    cout<<"Hapus data ke-";cin>>input;
    data=input-1;
    a--;

    for (int i=data;i<a;i++) {
        batas[i]=batas[i+1];
    }
    system("cls");
}

//untuk mengedit data pesanan
void editdata() {
    int angka,l;
    char kategori;
    cout << "Masukkan Data yang akan diedit: "; cin>>angka;
    l=angka-1;
    cout << "Nama Pelanggan     : "; cin >> batas[l].nama;
    cout << "Alamat             : "; cin >> batas[l].alamat;
    cout << "No Handphone       : "; cin >> batas[l].noHP;
    kategori:
    	kategoricucian();
        cout << "Input No Kategori [1-3]    : "; cin >> batas[l].kdKategori;
        switch (batas[l].kdKategori) {
        case '1':
            batas[l].biaya=5000;
            break;
        case '2':
            batas[l].biaya=7000;
            break;
        case '3':
            batas[l].biaya=10000;
            break;
        default:
            cout << "Anda salah memasukkan nomor, silahkan coba lagi!" << endl;
            goto kategori;
        }
        cout << "Berat Cucian (Kg)          : "; cin >> batas[l].berat;
        batas[l].totalbiaya = batas[l].biaya*batas[l].berat;
        if (batas[l].berat>=10) {
            cout << "Special diskon 5% setiap cuci lebih dari 10kg!" << endl;
            batas[l].diskon=batas[l].totalbiaya*5/100;
            batas[l].biayafix=batas[l].totalbiaya-batas[l].diskon;
        } else {
            cout << "Maaf. Anda tidak mendapatkan diskon 5%!" << endl;
            batas[l].biayafix=batas[l].totalbiaya;
            batas[l].diskon=0;
        }
        cout << "------------------------------------------------" << endl;
        cout << "\tResi Pesanan Laundry" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Nama Pelanggan             : " << batas[l].nama << endl;
        cout << "Alamat                     : " << batas[l].alamat << endl;
        cout << "No Handphone               : " << batas[l].noHP << endl;
        cout << "Kategori ke-" << batas[l].kdKategori << "              : Rp" << batas[l].biaya << endl;
        cout << "Total Biaya                : " << batas[l].totalbiaya << endl;
        cout << "Diskon special             : " << batas[l].diskon << endl;
        cout << "Total Biaya setelah diskon : " << batas[l].biayafix << endl;
        cout << "Total Bayar                : "; cin >> batas[l].jumlahBayar;
        cout << endl;
        cout << "================================================" << endl;
        batas[l].uangKembalian=batas[l].jumlahBayar-batas[l].biayafix;
        cout << "Kembalian                  : " << batas[l].uangKembalian << endl;
        cout << "================================================" << endl;
    lihatdata();
}


//function untuk memanggil beberapa prosedur
int main() {
    int pilih;
    char w,awal, user, pass, akhir,menu;
	string pass_input, user_input;
	//menu login
	awal:
	cout << "==========================================\n";
   	cout << "          \tLOGIN\t\n";
   	cout << "==========================================\n";
   	cout << "Silahkan login!\n";
   	string username ="admin";
   	string password = "admin";
   	string login = "block"; //pengisian variable
   	i = 1;
	//perulangan login
   	do {
       	cout << "Username : "; cin>>user_input;
       	cout << "Password : "; cin>>pass_input;
       	if (user_input == username && pass_input == password) {
       	system("cls");
       	menu:
        cout<<"\n\n\t\t    BIG LAUNDRY         "<<endl;
        cout<<"jln.DI.Panjaitan No.03 Purwokerto Hub.08981288289"<<endl;
        cout<<"==================================================="<<endl;
        cout<<"Time :"<<dt << endl;

        cout<<"\t\t   PILIHAN MENU         "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout << "1. Masukkan Data Pesanan" << endl;
        cout << "2. Lihat Data Pesanan" << endl;
        cout << "3. Edit Data Pesanan" << endl;
        cout << "4. Hapus Data Pesanan" << endl;
        cout << "5. Keluar" << endl << endl;
        cout << "Pilih Menu         : "; cin >> pilih;
        system("cls");

        if(pilih == 1) {
            system("cls");
            inputdata();
            goto menu;
        } if (pilih == 2) {
            system("cls");
            lihatdata();
            goto menu;
        } if (pilih == 3) {
            system("cls");
            editdata();
            goto menu;
        } if (pilih == 4) {
            system("cls");
            hapusdata();
            goto menu;
        } if (pilih == 5) {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                     APAKAH ANDA YAKIN KELUAR DARI PROGRAM??\n\n";
            cout<<"                         [Y]                         [N]                  \n"<<endl;
            cout<<"                                         ";cin>>w;

            if (w == 'y' || w == 'Y') {
                cout<<"\n\n\n\n\n******************************* PROGRAM SELESAI *******************************";
                goto akhir;
            } else {
            	system("cls");
                goto awal;
            }
        }

		} else {
           cout << "\n===========================\n";
           cout << "Username / Password Salah! ("<<i<<"x)\n";
		   cout << "=============================\n\n";
           i = i +1;
       		}
    	} while (i <= 3); //kalau sudah 3x maka berhenti

    	if(login != "berhasil"){
       		cout<<"Anda telah 3x salah login.\n";
       		cout<<"Silahkan coba lagi. Terima Kasih..\n\n";
		}
    	system("cls");

    	akhir:
    	return 0;
}

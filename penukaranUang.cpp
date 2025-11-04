/*
input : uang
ouput : jumlah lembar uang 100000, 50000, 20000, 10000, 5000, 2000, 1000, 500


fitur fiturnya :
- print semua itemnya
- minta no item
    - print nama dan harga item
    - konfirmasi pembelian (y/n)
        - if y: call function bayar
        - if n: batal
- bayar
    - if uang < item.harga
        - minta masukin uang lagi
    - else if uang == item.harga
        - transaksi sukses dengan uang pas
    - else if uang > item.harga
        - transaksi sukses
        - call function kembalianUang
- kembalianUang
    - print semua jumlah lembaran uang kembalian
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// struct untuk no, nama, dan harga item
struct Item
{
    int no;
    string nama;
    int harga;
};

// function prototype agar bisa dipanggil di manapun
void DisplayItems(const vector<Item> &vendingItems); // fungsi untuk menampilkan item vending machine
void kembalianUang(int kembalian);                   // print jumlah lembaran uang kembalian
void bayar(int hargaItem);                           // fugnsi untuk masukkan uang pembayaran dan panggil fungsi kembalianUang kalau ada kembalian
void konfirmasiPembelian(int hargaItem);             // fugnsi untuk konfirmasi pembelian dan panggil fungsi bayar kalau iya

int main(){

    vector<Item> vendingItems = {
        {1, "Le Minerale", 6000},
        {2, "Teh pucuk", 6000},
        {3, "Coca-Cola", 7000},
        {4, "Pocari Sweat", 8000},
        {5, "Kopi Nescafe", 9000},
        {6, "Susu cokelat", 7000},
        {7, "Chitato BBQ", 10000},
        {8, "SilverQueen", 12000},
        {9, "Biskuit Oreo", 8000},
        {10, "Wafer Tango", 5000}};

    //tunjukkan item itemnya
    cout << endl;
    DisplayItems(vendingItems);
    
    //loo minta no item terus menerus kalau nomor item yang dimasukkan user valid
    while(1){
        //minta no item
        int noItem;
        cout << endl << "Pilih no item bentuk bilangan bulat tanpa tanda baca, ex: 6000:"
            << endl << "no item : ";
        cin >> noItem;

        //iterasi untuk cari item berdasarkan no item yang dimasukkan user
        bool itemFound = false;
        for (const auto &item : vendingItems)
        {
            if (item.no == noItem)
            {
                //print nama item dan harga
                itemFound = true;
                cout << endl
                    << "item : " << item.nama << " Rp" << item.harga
                    << endl;
                konfirmasiPembelian(item.harga);
                break;
            }
        }

        //kalau tidak found, print item tidak tersedia dan minta input ulang
        if (!itemFound){
            cout << "Item tidak tersedia. Silakan pilih nomor item yang valid." << endl;
        }
    }
}

void DisplayItems(const vector<Item> &vendingItems)
{
    cout << "Daftar Item Vending Machine:" << endl;
    for (const auto &item : vendingItems)
    {
        cout << item.no << "-" << item.nama << "\t: Rp" << item.harga << endl;
    }
}

void konfirmasiPembelian(int hargaItem){
    char konfirmasi;
    cout << "Apakah Anda ingin melanjutkan pembelian? (y/n): ";
    cin >> konfirmasi;
    konfirmasi = tolower(konfirmasi);

    if (konfirmasi == 'y')
    {
        bayar(hargaItem);
    }
    else if (konfirmasi == 'n')
    {
        cout << "Pembelian dibatalkan." << endl;
    }
    else
    {
        cout << "Input tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
        konfirmasiPembelian(hargaItem);
    }
}

void bayar(int hargaItem)
{
    int uangDimasukkan = 0;

    while (1)
    {
        cout << "Masukkan uang (bilangan bulat tanpa rupiah, ex 6000): ";
        cin >> uangDimasukkan;
        int kembalian = uangDimasukkan - hargaItem;

        if (kembalian < 0){
            cout << "Uang yang dimasukkan kurang. Silakan masukkan lagi." << endl;
        }    
        else{
            cout << endl;
            cout << "Uang dimasukkan: Rp" << uangDimasukkan << endl;
            cout << "Harga item: Rp" << hargaItem << endl;
            cout << "Kembalian: Rp" << kembalian << endl;
            cout << endl;
            
            if (kembalian > 0) kembalianUang(kembalian);
            cout << "Transaksi sukses. Terima kasih!" << endl<<endl;
            break;
        }
    }
}

void kembalianUang(int kembalian)
{
    vector<int> recehan = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500};
    cout << "Kembalian dalam lembaran uang:" << endl;
    for (int receh : recehan)
    {
        int count = kembalian / receh;
        if (count > 0)
        {
            cout << "Rp" << receh << " : " << count << " lembar" << endl;
            kembalian %= receh;
        }
    }
}

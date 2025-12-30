#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

    infotype x;
    address P;

    // INPUT 4 DATA KENDARAAN
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek duplikasi
        if (findElm(L, x.nopol) != NULL) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    // ============================
    // CARI ELEMEN BERDASARKAN NOPOL
    // ============================
    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    P = findElm(L, cari);
    if (P != NULL) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    // =============================
    // HAPUS DATA BERDASARKAN NOPOL
    // =============================
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    P = findElm(L, cari);
    if (P == NULL) {
        cout << "Data tidak ditemukan." << endl;
    } else {
        address Q;
        
        if (P == L.First) {
            deleteFirst(L, Q);
        } else if (P == L.Last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(P->prev, Q);
        }

        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus.\n";
        dealokasi(Q);
    }

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    return 0;
}

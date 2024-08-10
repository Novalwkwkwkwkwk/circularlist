#include <iostream>
#include <string>
using namespace std;

struct Tagihan {
    string nama, nomor;
    double jumlah;
    Tagihan* next;
    Tagihan* prev; 
};

Tagihan* kepala,* ekor,* newNode,* cur, *dataBaru,* del;

void buatCircularDoublelist(string dataBaru[3]) {
    Tagihan* newNode = new Tagihan();
    newNode->nama = dataBaru[0];
    newNode->nomor = dataBaru[1];
    newNode->jumlah = stod(dataBaru[2]);
    newNode->next = newNode;
    newNode->prev = newNode; 
    kepala = newNode;
    ekor = newNode;
}

void tambahAwal(string dataBaru[3]) {
    if (kepala == NULL) {
        buatCircularDoublelist(dataBaru);
        return;
    }
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);
    nodeBaru->next = kepala;
    nodeBaru->prev = ekor; 
    ekor->next = nodeBaru;
    kepala->prev = nodeBaru; 
    kepala = nodeBaru;
}

void tambahTengah(string dataBaru[3]) {
    if (kepala == NULL) {
        buatCircularDoublelist(dataBaru);
        return;
    }
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);

  
    Tagihan* cur = kepala;
    for (int i = 0; i < 2; ++i) {
        cur = cur->next;
    }

    nodeBaru->next = cur->next;
    nodeBaru->prev = cur;
    cur->next->prev = nodeBaru;
    cur->next = nodeBaru;
}

void tambahAkhir(string dataBaru[3]) {
    if (kepala == NULL) {
        buatCircularDoublelist(dataBaru);
        return;
    }
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);
    nodeBaru->next = kepala;
    nodeBaru->prev = ekor; 
    ekor->next = nodeBaru;
    ekor = nodeBaru;
    kepala->prev = ekor; 
}

void hapusAwal() {
    if (kepala == NULL) return;

    if (kepala == ekor) {
        delete kepala;
        kepala = NULL;
        ekor = NULL;
    } else {
        Tagihan* del = kepala;
        kepala = kepala->next;
        ekor->next = kepala;
        kepala->prev = ekor; 
        delete del;
    }
}

void cetakCircularDouble() {
    cout << "Data Tagihan" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << "| Nama\t\t\t| Nomor\t\t| Tagihan\t|" << endl;
    cout << " -------------------------------------------------------" << endl;
    if (kepala == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Tagihan* cur = kepala;
    do {
        cout << "| " << cur->nama << "\t\t| " << cur->nomor << "\t\t| " << cur->jumlah << "\t\t|" << endl;
        cur = cur->next;
    } while (cur != kepala);
}

int main() {
    string dataBaru1[3] = {"Rahwana", "01", "2000"};
    buatCircularDoublelist(dataBaru1);

    string dataBaru2[3] = {"Buto Cakil", "02", "2500"};
    tambahAwal(dataBaru2);

    string dataBaru3[3] = {"Ontoseno", "03", "3000"};
    tambahAkhir(dataBaru3);

    string dataBaru4[3] = {"Gatotkaca", "04", "3500"}; 
    tambahTengah(dataBaru4);

    cout << "\nSetelah tambah data tengah dengan nama Gatotkaca:" << endl;
    cetakCircularDouble();
    return 0;
}

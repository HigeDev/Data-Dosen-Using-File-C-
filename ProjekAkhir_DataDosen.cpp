#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

typedef struct{
	int nik[100], n;
	float menit;
	string namadosen, mka, hari;
}datadosen;

typedef struct{
	datadosen data[100];
	}dataarray;

	ifstream fi;
    ofstream fo;
    dataarray array;
    char carinim[10], namafile[50], namafile2[50], filemarging[50], filemergingurut[50];
    int x;
    int search, carinik, transaksi;
    int sort, temp;
    string yn;
        
void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void seqsearch();
void binsearch();
void sorting();
void bubblesort();
void selectsort();
void insertsort();
void shellsort();
void margesort();
void quicksort();
void merging();
void mergingurut();

int main(){
	do{
		menu();
		cout<<"Pilihan Menu : ";cin>>x;
		if(x==1){
			menu1();
			cout<<"\n\nKembali ke Menu Utama?(y/n) : ";cin>>yn;
			system("cls");
		}
		if(x==2){
			menu2();
			cout<<"\n\nKembali ke Menu Utama?(y/n) : ";cin>>yn;
			system("cls");
		}
		if(x==3){
			menu3();
			cout<<"\n\nKembali ke Menu Utama?(y/n) : ";cin>>yn;
			system("cls");
		}
		if(x==4){
			menu4();
			cout<<"\n\nKembali ke Menu Utama?(y/n) : ";cin>>yn;
			system("cls");
		}
		if(x==5){
			break;
		}
	}while(yn=="y"||yn=="Y");
}

void menu(){
	cout<<endl;
	cout<<setfill('=')<<setw(50)<<'='<<endl;
	cout<<"=======================MENU======================="<<endl;
	cout<<setfill('=')<<setw(50)<<'='<<endl;
	cout<<endl;
	
	cout<<"\t 1. Input Data\n";
	cout<<"\t 2. Show Data\n";
	cout<<"\t 3. Searching\n";
	cout<<"\t 4. Transaksi\n";
	cout<<"\t 5. Exit\n";
}

void menu1(){
	cout<<endl;
	cout<<"   INPUT DATA\n\n";
	cout<<"Masukkan nama file baru : ";cin>>namafile;
	fo.open(namafile, ios::binary | ios::app);
	cout<<"Masukkan banyak data : ";
	cin>>array.data[0].n;cin.ignore();
	for (int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: ";cin>>array.data[i].nik[i]; cin.ignore();
		cout<<"Nama Dosen \t\t: ";getline(cin, array.data[i].namadosen);
		cout<<"Mata Kuliah Ampuan \t: ";getline(cin, array.data[i].mka);
		cout<<"Hari \t\t\t: ";getline(cin, array.data[i].hari);
		cout<<"Lama Mengajar (menit) \t: ";cin>>array.data[i].menit;
		cout<<endl;
		fo.write((char *) &array, sizeof(array));
	}
	fo.close();
}

void menu2(){
	cout<<setfill('=')<<setw(50)<<'='<<endl;
	cout<<"===================TAMPILAN DATA=================="<<endl;
	cout<<setfill('=')<<setw(50)<<'='<<endl;	
	cout<<endl;
	
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int j=0;

	while(fi.read((char*) &array, sizeof(array))){
		cout<<"Data ke-"<<j+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[j].nik[j]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[j].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[j].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[j].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[j].menit<<endl;
		j++;
	}
	fi.close();
}

void menu3(){
	cout<<setfill('=')<<setw(50)<<'='<<endl;	
	cout<<"====================MENU SEARCHING================"<<endl;
	cout<<setfill('=')<<setw(50)<<'='<<endl;	
	cout<<endl;
	cout<<"  1. Seq Search\n";
	cout<<"  2. Binary Search\n";
	cout<<"  3. Kembali ke Menu Utama\n";
	cout<<" Menu yang dipilih = "; cin>>search;
	if(search==1){
		seqsearch();
	}
	if(search==2){
		sorting();
	}
	if(search==3){
		main();
	}
}

void seqsearch(){
	bool found=false;
	int k=0;
	cout<<"Masukkan nama file : ";cin>>namafile;
	cout<<"Cari NIK : ";cin>>carinik;
	fi.open(namafile, ios::binary);
	cout<<"\nPENCARIAN SEQUENTIAL\n";
	while(fi.read((char*) &array, sizeof(array))){
		if(array.data[k].nik[k]==carinik){
			found=true;
			cout<<"Data ke-"<<k+1<<endl;
			cout<<"NIK \t\t\t: "<<array.data[k].nik[k]<<endl;
			cout<<"Nama Dosen \t\t: "<<array.data[k].namadosen<<endl;
			cout<<"Mata Kuliah Ampuan \t: "<<array.data[k].mka<<endl;
			cout<<"Hari \t\t\t: "<<array.data[k].hari<<endl;
			cout<<"Lama Mengajar (menit) \t: "<<array.data[k].menit<<endl;
			cout<<endl;
		}
		else if(!found){}
		k++;
	}
	if (!found){
		cout<<"NIK : "<<carinik<<" tidak ditemukan"<<endl;
	}
	fi.close();
}

void sorting(){
	cout<<"  Sorting : \n";
	cout<<"  1. Bubble Sort\n";
	cout<<"  2. Selection Sort\n";
	cout<<"  3. Insertion sort\n";
	cout<<"  4. Shell sort\n";
	cout<<"  5. Marge sort\n";
	cout<<"  6. Quick sort\n";
	cout<<" Pilih metode sorting = "; cin>>sort;
	if(sort==1){
		bubblesort();
	}
	if(sort==2){
		selectsort();
	}
	if(sort==3){
		insertsort();
	}
	if(sort==4){
		shellsort();
	}
	if(sort==5){
		margesort();
	}
	if(sort==6){
		quicksort();
	}
}

void bubblesort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	for(int m=0; m<array.data[0].n-1; m++){
		for(int n=0; n<array.data[0].n-1; n++){
			if(array.data[n].nik[n]>array.data[n+1].nik[n+1]){
			temp=array.data[n].nik[n];
			array.data[n].nik[n]=array.data[n+1].nik[n+1];
			array.data[n+1].nik[n+1]=temp;
			}
		}
	}
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	bool found=false; 
	int i=0, k, j=array.data[0].n-1;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+j)/2;
		if(carinik==array.data[k].nik[k])
			found=true;
		else{
			if(carinik<array.data[k].nik[k])
				j=k-1;
			else
				i=k+1;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[k].nik[k]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[k].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[k].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[k].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[k].menit<<endl;
	}
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void selectsort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	for(int m=0; m<array.data[0].n; m++){
		for(int n=m+1; n<array.data[0].n; n++){
			if(array.data[m].nik[m]>array.data[n].nik[n]){
			temp=array.data[m].nik[m];
			array.data[m].nik[m]=array.data[n].nik[n];
			array.data[n].nik[n]=temp;
			}
		}
	}
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}	
	
	bool found=false;
	int i=0, k;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+array.data[0].n)/2;
		if(carinik==array.data[i].nik[i])
			found=true;
		else{
			if(carinik<array.data[i].nik[i])
				array.data[0].n=k-1;
			else
				i=k++;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void insertsort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	int n;
	
	for(int m=0; m<array.data[0].n; m++){
		temp=array.data[m].nik[m];
		n = m - 1;
		while((temp<array.data[n].nik[n])&(n >= 0))
		{
			array.data[n+1].nik[n+1]=array.data[n].nik[n];
			n = n - 1;
			array.data[n+1].nik[n+1] = temp;
		}
	}
	
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}	
	
	bool found=false;
	int i=0, k;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+array.data[0].n)/2;
		if(carinik==array.data[i].nik[i])
			found=true;
		else{
			if(carinik<array.data[i].nik[i])
				array.data[0].n=k-1;
			else
				i=k++;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void shellsort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	for(int m=array.data[0].n;m>0;m=m/2)
	{
		for(int n=m; n<array.data[0].n; n++)
		{
			for(int o=n-m; o>=0; o-=m)
			{
				if(array.data[m+o].nik < array.data[m].nik)
				{
				temp=array.data[m+o].nik[m+o];
				array.data[m+o].nik[m+o]=array.data[o].nik[o];
				array.data[o].nik[o]=temp;
				}
		
			}
		}
	}
	
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}	
	
	bool found=false;
	int i=0, k;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+array.data[0].n)/2;
		if(carinik==array.data[i].nik[i])
			found=true;
		else{
			if(carinik<array.data[i].nik[i])
				array.data[0].n=k-1;
			else
				i=k++;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void margesort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	bool found=false;
	int i=0, k;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+array.data[0].n)/2;
		if(carinik==array.data[i].nik[i])
			found=true;
		else{
			if(carinik<array.data[i].nik[i])
				array.data[0].n=k-1;
			else
				i=k++;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void quicksort(){
	cout<<"Masukkan nama file : ";cin>>namafile;
	fi.open(namafile, ios::binary);
	int l=0;
	while(fi.read((char*) &array, sizeof(array))){
		l++;
	}
	
		
	cout<<"\nNIK urut : \n";
	for(int i=0; i<array.data[0].n; i++){
		cout<<"Data ke-"<<i+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}	
	
	bool found=false;
	int i=0, k;
	cout<<"\nPENCARIAN BINARY\n\n";
	cout<<"Cari NIK : ";cin>>carinik;cout<<endl;
	while((!found)&(i<array.data[0].n)){
		k=(i+array.data[0].n)/2;
		if(carinik==array.data[i].nik[i])
			found=true;
		else{
			if(carinik<array.data[i].nik[i])
				array.data[0].n=k-1;
			else
				i=k++;
		}
	}
	if(found){
		cout<<"Ditemukan pada data ke-"<<k<<endl;
		cout<<"NIK \t\t\t: "<<array.data[i].nik[i]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[i].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[i].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[i].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[i].menit<<endl;
	}
	
	cout<<"\n\nSimpan data sorting?(y/n) ";cin>>yn;
	if(yn=="y"){
		cout<<"Simpan dengan nama file : ";cin>>namafile;
		fo.open(namafile, ios::binary | ios::app);
		for(int i=0; i<array.data[0].n; i++){
			cout<<array.data[i].nik[i]<<endl;
			cout<<array.data[i].namadosen<<endl;
			cout<<array.data[i].mka<<endl;
			cout<<array.data[i].hari<<endl;
			cout<<array.data[i].menit<<endl;
			fo.write((char *) &array, sizeof(array));
		}
		fo.close();
		cout<<"File telah tersimpan!"<<endl;
	}
	fi.close();
}

void menu4(){
	cout<<setfill('=')<<setw(50)<<'='<<endl;	
	cout<<"=================MENU TRANSAKSI==================="<<endl;
	cout<<setfill('=')<<setw(50)<<'='<<endl;
	cout<<endl;
	
	cout<<"  1. Merging Sambung\n";
	cout<<"  2. Merging Urut\n";
	cout<<"  3. Kembali ke Menu Utama\n";
	cout<<" Menu yang dipilih = "; cin>>transaksi;
	if(transaksi==1){
		merging();
	}
	if(transaksi==2){
		mergingurut();
	}
	if(transaksi==3){
		main();
	}
}

void merging(){
	cout<<"\nNama file yang akan di merging sambung : \n";
	cout<<"File 1 : ";cin>>namafile;
	cout<<"File 2 : ";cin>>namafile2;
	cout<<"Simpan dengan nama file : ";cin>>filemarging;
	fo.open(filemarging, ios::binary | ios::app);
	fi.open(namafile, ios::binary);
	int f=0, jum;
	while(fi.read((char*) &array, sizeof(array))){
		cout<<"Data ke-"<<f+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[f].nik[f]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[f].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[f].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[f].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[f].menit<<endl;
		f++;
		fo.write((char *) &array, sizeof(array));
	}
	fi.close();
	fi.open(namafile2, ios::binary);
	jum=array.data[0].n;
	int g=0;
	while(fi.read((char*) &array, sizeof(array))){
		cout<<"Data ke-"<<g+1+jum<<endl;
		array.data[g+jum].nik[g+jum]=array.data[g].nik[g];
		cout<<"NIK \t\t\t: "<<array.data[g+jum].nik[g+jum]<<endl;
		array.data[g+jum].namadosen=array.data[g].namadosen;
		cout<<"Nama Dosen \t\t: "<<array.data[g+jum].namadosen<<endl;
		array.data[g+jum].mka=array.data[g].mka;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[g+jum].mka<<endl;
		array.data[g+jum].hari=array.data[g].hari;
		cout<<"Hari \t\t\t: "<<array.data[g+jum].hari<<endl;
		array.data[g+jum].menit=array.data[g].menit;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[g+jum].menit<<endl;
		g++;
		fo.write((char *) &array, sizeof(array));
	}
	fi.close();
	fo.close();
	cout<<"\n\nFile telah tersimpan!\n\n";
}

void mergingurut(){
	cout<<"\nNama file yang akan di merging urut : \n";
	cout<<"File 1 : ";cin>>namafile;
	cout<<"File 2 : ";cin>>namafile2;
	cout<<"Simpan dengan nama file : ";cin>>filemergingurut;
	fo.open(filemergingurut, ios::binary | ios::app);
	fi.open(namafile, ios::binary);
	int jum;
	for(int f=0; f<array.data[f].nik[f]; f++){
		for(int g=0;g<array.data[g+jum].nik[g+jum]; g++){
	while(fi.read((char*) &array, sizeof(array))){
		cout<<"Data ke-"<<f+1<<endl;
		cout<<"NIK \t\t\t: "<<array.data[f].nik[f]<<endl;
		cout<<"Nama Dosen \t\t: "<<array.data[f].namadosen<<endl;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[f].mka<<endl;
		cout<<"Hari \t\t\t: "<<array.data[f].hari<<endl;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[f].menit<<endl;
		f++;
		fo.write((char *) &array, sizeof(array));
	}
	fi.close();
	fi.open(namafile2, ios::binary);
	jum=array.data[0].n;
	while(fi.read((char*) &array, sizeof(array))){
		cout<<"Data ke-"<<g+1+jum<<endl;
		array.data[g+jum].nik[g+jum]=array.data[g].nik[g];
		cout<<"NIK \t\t\t: "<<array.data[g+jum].nik[g+jum]<<endl;
		array.data[g+jum].namadosen=array.data[g].namadosen;
		cout<<"Nama Dosen \t\t: "<<array.data[g+jum].namadosen<<endl;
		array.data[g+jum].mka=array.data[g].mka;
		cout<<"Mata Kuliah Ampuan \t: "<<array.data[g+jum].mka<<endl;
		array.data[g+jum].hari=array.data[g].hari;
		cout<<"Hari \t\t\t: "<<array.data[g+jum].hari<<endl;
		array.data[g+jum].menit=array.data[g].menit;
		cout<<"Lama Mengajar (menit) \t: "<<array.data[g+jum].menit<<endl;
		g++;
		fo.write((char *) &array, sizeof(array));
		
	}}}
	fi.close();
	fo.close();
	cout<<"\n\nFile telah tersimpan!\n\n";	
}

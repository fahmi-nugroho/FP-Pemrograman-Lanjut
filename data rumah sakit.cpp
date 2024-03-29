#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void border(){
	gotoXY(15,3);printf("*************************************************************************\n");
	gotoXY(15,4);printf("*************************************************************************\n");
	gotoXY(15,5);printf("**********                                                     **********\n");
	gotoXY(15,6);printf("**********                                                     **********\n");
	gotoXY(15,7);printf("**********                                                     **********\n");
	gotoXY(15,8);printf("****  ****                                                     ****  ****\n");
	gotoXY(15,9);printf("****  ****                                                     ****  ****\n");
	gotoXY(15,10);printf("****  ****                                                     ****  ****\n");
	gotoXY(15,11);printf("****  ****                                                     ****  ****\n");
	gotoXY(15,12);printf("**********                                                     **********\n");
	gotoXY(15,13);printf("**********                                                     **********\n");
	gotoXY(15,14);printf("**********                                                     **********\n");
	gotoXY(15,15);printf("*************************************************************************\n");
	gotoXY(15,16);printf("*************************************************************************\n");
}

void list(int n){
	int i,m;
	m=n*9;
	printf("**************************************************************\n");
	for(i=0;i<m;i++){
		printf("***                                                        ***\n");
	}
	printf("**************************************************************\n");
}

struct ttl{
	int tanggal;
	int bulan;
};
struct data{
	int id;
	char nama[10];
	char penyakit[15];
	char kamar[5];
	int nomorkamar;
	struct ttl tl;
};
typedef struct data data;

int jump(int arr[], int jumlah, int cari){
	int m = sqrt(jumlah);
	int indexatas = m;
	int indexbawah = 0;
	int ketemu = 0;
	int index = -1;
	
	for (int i=0; i<(jumlah/m); i++){
		if (cari==arr[indexbawah]){
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (cari==arr[indexatas]){
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (cari>arr[indexbawah]&&cari<arr[indexatas]){
			for (int j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
				}
			}
			break;
		}
		else if (cari>arr[indexbawah]&&i==((jumlah/m)-1)){
			for (int j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
					break;
				}
			}
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		system("cls");
		border();
		gotoXY(35,9);printf("Data Tidak Ditemukan !!!");
		getch();
	}
	return index;
}

int strjump(char arr[][100], int jumlah, char data[][100]){
	char cari[100][100];
	strcpy(cari[0], data[0]);
	int m = sqrt(jumlah);
	int indexatas = m;
	int indexbawah = 0;
	int ketemu = 0;
	int index = -1;
	
	for (int i=0; i<=(jumlah/m); i++){
		if (strcmp(cari[0], arr[indexbawah])==0){
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (strcmp(cari[0], arr[indexatas])==0){
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (strcmp(cari[0], arr[indexbawah])>0&&strcmp(cari[0], arr[indexatas])<0){
			for (int j=indexbawah; j<indexatas; j++){
				if (strcmp(cari[0], arr[j])==0){
					index = j;
				}
			}
			ketemu = 1;
			break;
		}
		else if (strcmp(cari[0], arr[indexbawah])>0&&i==((jumlah/m)-1)){
			for (int j=indexbawah; j<indexatas; j++){
				if (strcmp(cari[0], arr[j])==0){
					index = j;
					ketemu = 1;
				}
			}
			break;
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		system("cls");
		border();
		gotoXY(35,9);printf("Data Tidak Ditemukan !!!");
		getch();
	}
	return index;
}

int partition(int arr[], int awal, int akhir){
	int pivot = arr[akhir];
	int index = awal;
	int temp;
	
	for (int i=awal; i<=(akhir-1); i++){
		if (arr[i]<=pivot){
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	temp = arr[index];
	arr[index] = arr[akhir];
	arr[akhir] = temp;
	return index;
}

void quick(int arr[], int awal, int akhir){
	if (awal < akhir){
		int index = partition(arr, awal, akhir);
		quick(arr, awal, (index-1));
		quick(arr, (index+1), akhir);
	}
}

int strpartition(char arr[][100], int awal, int akhir){
	char pivot[100][100];
	strcpy(pivot[0],arr[akhir]);
	int index = awal;
	char temp[100][100];
	
	for (int i=awal; i<=(akhir-1); i++){
		if (strcmp(arr[i],pivot[0])<0){
			strcpy(temp[0], arr[i]);
			strcpy(arr[i], arr[index]);
			strcpy(arr[index], temp[0]);
			index++;
		}
	}
	strcpy(temp[0], arr[index]); 
	strcpy(arr[index], arr[akhir]);
	strcpy(arr[akhir], temp[0]);
	return index;
}

void strquick(char arr[][100], int awal, int akhir){
	if (awal < akhir){
		int index = strpartition(arr, awal, akhir);
		strquick(arr, awal, (index-1));
		strquick(arr, (index+1), akhir);
	}
}

int main(){
	srand(time(0));
	data dt[100];
	int a,b,i,j,loop=1,menu,menu1,orang=0,n=0,dat=0,sort,ganti,cekid=0,ceknama=0,ceknkamar=0;
	char cganti[10],ccari[10];
	while(loop==1){
		border();
		gotoXY(35,6);printf("Draft Menu : \n");
		gotoXY(35,7);printf("1. Input data\n");
		gotoXY(35,8);printf("2. Tampilkan data\n");
		gotoXY(35,9);printf("3. Cari data\n");
		gotoXY(35,10);printf("4. Ganti data\n");
		gotoXY(35,11);printf("5. Pengurutan data\n");
		gotoXY(35,12);puts("0. X-it\n");
		gotoXY(35,13);printf("Pilihan : ");
		scanf("%d",&menu);
		switch(menu){
			case 1:{//input
				a=10;b=2;dat=1;
				dt[n].id = rand() &1001 + 11;
				fflush(stdin);
				system("cls");
				list(1);
				gotoXY(a,b);printf("Nama Pasien\t\t: ");b++;
				gets(dt[n].nama);
				gotoXY(a,b);printf("Jenis Penyakit\t: ");b++;
				gets(dt[n].penyakit);
				gotoXY(a,b);printf("Jenis Kamar\t\t: ");b++;
				gets(dt[n].kamar);
				fflush(stdin);
				gotoXY(a,b);printf("Nomor Kamar\t\t: ");b++;
				scanf("%d",& dt[n].nomorkamar);
				gotoXY(a,b);printf("Tanggal masuk\t\t: ");b++;
				scanf("%d",&dt[n].tl.tanggal);
				gotoXY(a,b);printf("Bulan masuk\t\t: ");b++;
				scanf("%d",&dt[n].tl.bulan);
				system("cls");
				n++;
				cekid=0;
				ceknama=0;
				ceknkamar=0;
				system("cls");
				break;
			}
			case 2:{//history
				if(dat==0){
					system("cls");
					printf("Data belum di inputkan\n");
					getch();
					system("cls");
				}
				else{
					system("cls");
					list(n);
					a=4,b=1;
					for(j=0;j<n;j++){
						gotoXY(a,b);printf("Data ke - %d",j+1);printf("\n");b++;
						gotoXY(a,b);printf("ID Pasien\t\t: %d\n",dt[j].id);b++;
						gotoXY(a,b);printf("Nama Pasien\t\t: %s\n",dt[j].nama);b++;
						gotoXY(a,b);printf("Jenis Penyakit\t: %s\n",dt[j].penyakit);b++;
						gotoXY(a,b);printf("Jenis Kamar\t\t: %s\n",dt[j].kamar);b++;
						gotoXY(a,b);printf("Nomor Kamar\t\t: %d\n",dt[j].nomorkamar);b++;
						gotoXY(a,b);printf("Tanggal Masuk\t: %d\n",dt[j].tl.tanggal);b++;
						gotoXY(a,b);printf("Bulan Masuk\t\t: %d\n",dt[j].tl.bulan);b++;
						b++;
					}
					getch();
					system("cls");
				}
				break;
			}
			case 3:{//search
				int cari, cari2, index;
				char coba[100][100];
				char caristr[100][100];
				int tempid[n];
				char tempnama[10];
				char temppenyakit[15];
				char tempkamar[5];
				int tempnomorkamar[n];
				int temptanggal[n];
				int tempbulan[n];
				system("cls");
				border();
				gotoXY(38,7);printf("List : \n");
				gotoXY(38,8);printf("1. ID\n");
				gotoXY(38,9);printf("2. Nama\n");
				gotoXY(38,10);printf("3. Nomor Kamar\n");
				gotoXY(38,11);printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch (menu1){
					case 1://id
						if (cekid==1){
							for (int i=0; i<=n; i++){
								tempid[i] = dt[i].id;
							}
							gotoXY(26,12);printf("Masukkan ID Pasien Yang Ingin Dicari = ");scanf("%d",& cari);fflush(stdin);
							index = jump(tempid, n, cari);	
							system("cls");
							ceknama=0;
							ceknkamar=0;
						}
						else{
							system("cls");
							border();
							gotoXY(30,9);
							printf("Harap Melakukan Sorting ID Terlebih Dahulu !!!");
							getch();
							index=-1;
						}
							break;
					case 2://nama
						if (ceknama==1){
							for (int i=0; i<=n; i++){
								strcpy(coba[i], dt[i].nama);
							}
							fflush(stdin);
							gotoXY(26,12);printf("Masukkan Nama Pasien Yang Ingin Dicari = ");gets(caristr[0]);
							index = strjump(coba, n, caristr);
							system("cls");
							cekid=0;
							ceknkamar=0;
						}
						else{
							system("cls");
							border();
							gotoXY(30,9);
							printf("Harap Melakukan Sorting Nama Terlebih Dahulu !!!");
							getch();
							index=-1;
						}
						break;
					case 3://nomer kamar
						if (ceknkamar==1){
							for (int i=0; i<n; i++){
								tempnomorkamar[i] = dt[i].nomorkamar;
							}
							gotoXY(26,12);printf("Masukkan No Kamar Yang Ingin Dicari = ");scanf("%d",& cari2);fflush(stdin);
							index = jump(tempnomorkamar, n, cari2);	
							system("cls");
							cekid=0;
							ceknama=0;
						}
						else{
							system("cls");
							border();
							gotoXY(30,9);
							printf("Harap Melakukan Sorting No Kamar Terlebih Dahulu !!!");
							getch();
							index=-1;
						}
						break;
				}
				if (index!=-1){
					list(1);
					a=4;b=1;
					gotoXY(a,b);printf("Data ke - %d",index+1);printf("\n");b++;
					gotoXY(a,b);printf("ID Pasien\t\t: %d\n",dt[index].id);b++;
					gotoXY(a,b);printf("Nama Pasien\t\t: %s\n",dt[index].nama);b++;
					gotoXY(a,b);printf("Jenis Penyakit\t: %s\n",dt[index].penyakit);b++;
					gotoXY(a,b);printf("Jenis Kamar\t\t: %s\n",dt[index].kamar);b++;
					gotoXY(a,b);printf("Nomor Kamar\t\t: %d\n",dt[index].nomorkamar);b++;
					gotoXY(a,b);printf("Tanggal Masuk\t: %d\n",dt[index].tl.tanggal);b++;
					gotoXY(a,b);printf("Bulan Masuk\t\t: %d\n",dt[index].tl.bulan);b++;
					getch();
				}
				system("cls");
				break;
			}
			case 4:{//ubah
				if (cekid=1){
					int tempid[n], ganti, index;
					char tempnama[10];
					char temppenyakit[15];
					char tempkamar[5];
					int tempnomorkamar[n];
					int temptanggal[n];
					int tempbulan[n];
					for (int i=0; i<n; i++){
						tempid[i] = dt[i].id;
					}
					system("cls");
					fflush(stdin);
					list(1);
					a=4;b=1;
					gotoXY(a,b);printf("Masukkan NomorID yang ingin anda ubah : ");scanf("%d",& ganti);fflush(stdin);b++;
					index = jump(tempid, n, ganti);
					if(index!=-1){
						gotoXY(a,b);printf("Masukkan data baru\n");b++;
						gotoXY(a,b);printf("Nama Pasien\t\t: ");b++;
						gets(dt[index].nama);
						gotoXY(a,b);printf("Jenis Penyakit\t: ");b++;
						gets(dt[index].penyakit);
						gotoXY(a,b);printf("Jenis Kamar\t\t: ");b++;
						gets(dt[index].kamar);
						gotoXY(a,b);printf("Nomor Kamar\t\t: ");b++;
						scanf("%d",& dt[index].nomorkamar);
						fflush(stdin);
						gotoXY(a,b);printf("Tanggal masuk\t: ");b++;
						scanf("%d",&dt[index].tl.tanggal);
						gotoXY(a,b);printf("Bulan masuk\t\t: ");b++;
						scanf("%d",&dt[index].tl.bulan);
						system("cls");
						printf("Data Berhasil Diupdate !!!");
						getch();
					}
					system("cls");
					ceknama=0;
					ceknkamar=0;
				}
				else{
					system("cls");
					border();
					gotoXY(30,9);
					printf("Harap Melakukan Sorting ID Terlebih Dahulu !!!");
					getch();
				}
				break;
			}
			case 5:{//sorting
				system("cls");
				char temp[100][100];
				int tempi[n];
				int tempid[n];
				char tempnama[10];
				char temppenyakit[15];
				char tempkamar[5];
				int tempnomorkamar[n];
				int temptanggal[n];
				int tempbulan[n];
				border();
				gotoXY(35,5);printf("List : \n");
				gotoXY(35,6);printf("1. ID\n");
				gotoXY(35,7);printf("2. Nama\n");
				gotoXY(35,8);printf("3. Penyakit\n");
				gotoXY(35,9);printf("4. Kamar\n");
				gotoXY(35,10);printf("5. No. Kamar\n");
				gotoXY(35,11);printf("6. Tanggal\n");
				gotoXY(35,12);printf("7. Bulan\n");
				gotoXY(35,13);printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch(menu1){
					case 1:
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].id;
						}
						quick(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].id){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						cekid=1;
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 2: //nama
						fflush(stdin);
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].nama);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].nama)==0){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						ceknama=1;
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 3:  //penyakit
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].penyakit);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].penyakit)==0){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 4: //kamar
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].kamar);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].kamar)==0){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 5://No.Kamar
						for (int i=0; i<=n; i++){
							tempnomorkamar[i] = dt[i].nomorkamar;
						}
						quick(tempnomorkamar, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempnomorkamar[i]==dt[j].nomorkamar){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						ceknkamar=1;
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
					case 6://tanggal
						for (int i=0; i<=n; i++){
							temptanggal[i] = dt[i].tl.tanggal;
						}
						quick(temptanggal, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (temptanggal[i]==dt[j].tl.tanggal){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
					case 7://bulan
						for (int i=0; i<=n; i++){
							tempbulan[i] = dt[i].tl.bulan;
						}
						quick(tempbulan, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempbulan[i]==dt[j].tl.bulan){
									tempid[i] = dt[i].id;
									strcpy(tempnama, dt[i].nama);
									strcpy(temppenyakit, dt[i].penyakit);
									strcpy(tempkamar, dt[i].kamar);
									tempnomorkamar[i] = dt[i].nomorkamar;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].nomorkamar = dt[j].nomorkamar;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].nomorkamar = tempnomorkamar[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();						
						system("cls");
						border();
						gotoXY(35,9);printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
				}	
				break;
			}
			case 0:
				loop=0;
				gotoXY(0,20);exit(0);
				break;
		}
	}	
}

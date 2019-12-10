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
	gotoXY(15,3);printf("**************************************************************\n");
	gotoXY(15,4);printf("**************************************************************\n");
	gotoXY(15,5);printf("**********                                          **********\n");
	gotoXY(15,6);printf("**********                                          **********\n");
	gotoXY(15,7);printf("**********                                          **********\n");
	gotoXY(15,8);printf("****  ****                                          ****  ****\n");
	gotoXY(15,9);printf("****  ****                                          ****  ****\n");
	gotoXY(15,10);printf("****  ****                                          ****  ****\n");
	gotoXY(15,11);printf("****  ****                                          ****  ****\n");
	gotoXY(15,12);printf("**********                                          **********\n");
	gotoXY(15,13);printf("**********                                          **********\n");
	gotoXY(15,14);printf("**********                                          **********\n");
	gotoXY(15,15);printf("**************************************************************\n");
	gotoXY(15,16);printf("**************************************************************\n");
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
//	printf("m=%d", m);
	
	for (int i=0; i<(jumlah/m); i++){
		if (cari==arr[indexbawah]){
//			printf("\nData Ditemukan Di Index ke-%d", indexbawah);
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (cari==arr[indexatas]){
//			printf("\nData Ditemukan Di Index ke-%d", indexatas);
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (cari>arr[indexbawah]&&cari<arr[indexatas]){
			for (int j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
//					printf("\nData Ditemukan Di Index ke-%d", j);
					index = j;
				}
			}
			ketemu = 1;
			break;
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		printf("\nData Tidak Ditemukan !!!");
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
//	printf("m=%d", m);
	
	for (int i=0; i<(jumlah/m); i++){
		if (strcmp(cari[0], arr[indexbawah])==0){
//			printf("\nData Ditemukan Di Index ke-%d", indexbawah);
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (strcmp(cari[0], arr[indexatas])==0){
//			printf("\nData Ditemukan Di Index ke-%d", indexatas);
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (strcmp(cari[0], arr[indexbawah])>0&&strcmp(cari[0], arr[indexatas])<0){
			for (int j=indexbawah; j<indexatas; j++){
				if (strcmp(cari[0], arr[j])==0){
//					printf("\nData Ditemukan Di Index ke-%d", j);
					index = j;
				}
			}
			ketemu = 1;
			break;
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		gotoXY(35,13);printf("Data Tidak Ditemukan !!!");
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
		printf("\nProses Partisi\n");
		for	(int i=0;i<=akhir;i++){
			printf("%d ", arr[i]);
		}
	}
	temp = arr[index];
	arr[index] = arr[akhir];
	arr[akhir] = temp;
	printf("\nHasil Partisi\n");
	for	(int i=0;i<=akhir;i++){
		printf("%d ", arr[i]);
	}
	return index;
}

void quick(int arr[], int awal, int akhir){
	if (awal < akhir){
		int index = partition(arr, awal, akhir);
		printf("\nProses Quick Kiri\n");
		for	(int i=0;i<=akhir;i++){
			printf("%d ", arr[i]);
		}
		quick(arr, awal, (index-1));
		printf("\nProses Quick Kanan\n");
		for	(int i=0;i<=akhir;i++){
			printf("%d ", arr[i]);
		}
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
		printf("\nProses Partisi\n");
		for	(int i=0;i<=akhir;i++){
			printf("%s ", arr[i]);
		}
	}
	strcpy(temp[0], arr[index]); 
	strcpy(arr[index], arr[akhir]);
	strcpy(arr[akhir], temp[0]);
	printf("\nHasil Partisi\n");
	for	(int i=0;i<=akhir;i++){
		printf("%s ", arr[i]);
	}
	return index;
}

void strquick(char arr[][100], int awal, int akhir){
	if (awal < akhir){
		int index = strpartition(arr, awal, akhir);
		printf("\nProses Quick Kiri\n");
		for	(int i=0;i<=akhir;i++){
			printf("%s ", arr[i]);
		}
		strquick(arr, awal, (index-1));
		printf("\nProses Quick Kanan\n");
		for	(int i=0;i<=akhir;i++){
			printf("%s ", arr[i]);
		}
		strquick(arr, (index+1), akhir);
	}
}

void urutdata(int n, data dt[], int temp[], int data[]){
	int tempid[n];
	char tempnama[10];
	char temppenyakit[15];
	char tempkamar[5];
	int tempnomorkamar[n];
	int temptanggal[n];
	int tempbulan[n];
	for (int i=0; i<(n-1); i++){
		for (int j=0; j<n; j++){
			if (temp[i]==data[j]){
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
}

void strurutdata(int n, data dt[], char temp[][100], char data[][100]){
	int tempid[n];
	char tempnama[10];
	char temppenyakit[15];
	char tempkamar[5];
	int tempnomorkamar[n];
	int temptanggal[n];
	int tempbulan[n];
	for (int i=0; i<(n-1); i++){
		for (int j=0; j<n; j++){
			if (strcmp(temp[i], data[j])==0){
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
}

int main(){
	srand(time(0));
	data dt[100];
	int a,b,i,j,loop=1,menu,menu1,orang=0,n=0,dat=0,sort,ganti;
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
				dat=1;
				dt[n].id = rand() &1001 + 11;
				fflush(stdin);
				system("cls");
				printf("Nama Pasien\t\t: ");
				gets(dt[n].nama);
				printf("Jenis Penyakit\t\t: ");
				gets(dt[n].penyakit);
				printf("Jenis Kamar\t\t: ");
				gets(dt[n].kamar);
				fflush(stdin);
				printf("Nomor Kamar\t\t: ");
				scanf("%d",& dt[n].nomorkamar);
				printf("Tanggal masuk\t\t: ");
				scanf("%d",&dt[n].tl.tanggal);
				printf("Bulan masuk\t\t: ");
				scanf("%d",&dt[n].tl.bulan);
				system("cls");
				n++;
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
				int tempid[n], tempid2[n],tempnomorkamar[n], tempnomorkamar2[n], cari, index;
				char coba[100][100], coba2[100][100];
				char caristr[100][100];
				system("cls");
				border();
				gotoXY(38,7);printf("List : \n");
				gotoXY(38,8);printf("1. ID\n");
				gotoXY(38,9);printf("2. Nama\n");
				gotoXY(38,10);printf("3. Nomor Kamar\n");
				gotoXY(38,11);printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch (menu1){
					case 1://id
						for (int i=0; i<=n; i++){
							tempid[i] = dt[i].id;
						}
						for (int i=0; i<=n; i++){
							tempid2[i] = dt[i].id;
						}
						gotoXY(26,12);printf("Masukkan ID Pasien Yang Ingin Dicari = ");scanf("%d",& cari);fflush(stdin);
						quick(tempid, 0, (n-1));
						urutdata(n, dt, tempid, tempid2);
						index = jump(tempid, n, cari);	
						system("cls");
//						if (index!=-1){
//							list(n);
//							a=4;b=1;
//							gotoXY(a,b);printf("Data ke - %d",index+1);printf("\n");b++;
//							gotoXY(a,b);printf("ID Pasien\t: %d\n",dt[index].id);b++;
//							gotoXY(a,b);printf("Nama Pasien\t: %s\n",dt[index].nama);b++;
//							gotoXY(a,b);printf("Jenis Penyakit\t: %s\n",dt[index].penyakit);b++;
//							gotoXY(a,b);printf("Jenis Kamar\t: %s\n",dt[index].kamar);b++;
//							gotoXY(a,b);printf("Nomor Kamar\t: %d\n",dt[index].nomorkamar);b++;
//							gotoXY(a,b);printf("Tanggal Masuk\t: %d\n",dt[index].tl.tanggal);b++;
//							gotoXY(a,b);printf("Bulan Masuk\t: %d\n",dt[index].tl.bulan);b++;
//							getch();
//						}
						system("cls");
						break;
					case 2://nama
						for (int i=0; i<=n; i++){
							strcpy(coba[i], dt[i].nama);
						}
						for (int i=0; i<=n; i++){
							strcpy(coba2[i], dt[i].nama);
						}
						fflush(stdin);
						gotoXY(26,12);printf("Masukkan Nama Pasien Yang Ingin Dicari = ");gets(caristr[0]);
						strquick(coba, 0, (n-1));
						strurutdata(n, dt, coba, coba2);
						index = strjump(coba, n, caristr);
						system("cls");
//						if (index!=-1){
//							printf("Data ke - %d",index+1);
//							printf("\n");
//							printf("ID Pasien\t: %d\n",dt[index].id);
//							printf("Nama Pasien\t: %s\n",dt[index].nama);
//							printf("Jenis Penyakit\t: %s\n",dt[index].penyakit);
//							printf("Jenis Kamar\t: %s\n",dt[index].kamar);
//							printf("Nomor Kamar\t: %d\n",dt[index].nomorkamar);
//							printf("Tanggal Masuk\t: %d\n",dt[index].tl.tanggal);
//							printf("Bulan Masuk\t: %d\n",dt[index].tl.bulan);
//							getch();
//						}
						system("cls");
						break;
					case 3://nomer kamar
						for (int i=0; i<n; i++){
							tempnomorkamar[i] = dt[i].nomorkamar;
						}
						for (int i=0; i<=n; i++){
							tempnomorkamar2[i] = dt[i].nomorkamar;
						}
						gotoXY(26,12);printf("Masukkan No Kamar Yang Ingin Dicari = ");scanf("%d",& cari);fflush(stdin);
						quick(tempnomorkamar, 0, (n-1));
						urutdata(n, dt, tempnomorkamar, tempnomorkamar2);
						index = jump(tempnomorkamar, n, cari);	
						system("cls");
//						if (index!=-1){
//							printf("Data ke - %d",index+1);
//							printf("\n");
//							printf("ID Pasien\t: %d\n",dt[index].id);
//							printf("Nama Pasien\t: %s\n",dt[index].nama);
//							printf("Jenis Penyakit\t: %s\n",dt[index].penyakit);
//							printf("Jenis Kamar\t: %s\n",dt[index].kamar);
//							printf("Nomor Kamar\t: %d\n",dt[index].nomorkamar);
//							printf("Tanggal Masuk\t: %d\n",dt[index].tl.tanggal);
//							printf("Bulan Masuk\t: %d\n",dt[index].tl.bulan);
//							getch();
//						}
						system("cls");
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
				int tempid[n], ganti, index;
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
				break;
			}
			case 5:{//sorting
				system("cls");
				char temp[100][100], temp2[100][100];
				int tempi[n], tempi2[n];
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
						for (int i=0; i<=n; i++){
							tempi2[i] = dt[i].id;
						}
						for	(int i=0;i<n;i++){
							printf("%d ", tempi[i]);
						}
						printf("\n%d", n);
						getch();
						quick(tempi, 0, (n-1));
						for	(int i=0;i<n;i++){
							printf("%d ", tempi[i]);
						}
						urutdata(n, dt, tempi, tempi2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 2: //nama
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].nama);
						}
						for (int i=0; i<=n; i++){
							strcpy(temp2[i], dt[i].nama);
						}
						strquick(temp, 0, (n-1));
						strurutdata(n, dt, temp, temp2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 3:  //penyakit
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].penyakit);
						}
						for (int i=0; i<=n; i++){
							strcpy(temp2[i], dt[i].penyakit);
						}
						strquick(temp, 0, (n-1));
						strurutdata(n, dt, temp, temp2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 4: //kamar
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].kamar);
						}
						for (int i=0; i<=n; i++){
							strcpy(temp2[i], dt[i].kamar);
						}
						strquick(temp, 0, (n-1));
						strurutdata(n, dt, temp, temp2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 5://No.Kamar
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].nomorkamar;
						}
						for (int i=0; i<=n; i++){
							tempi2[i] = dt[i].nomorkamar;
						}
						quick(tempi, 0, (n-1));
						urutdata(n, dt, tempi, tempi2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
					case 6://tanggal
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].tl.tanggal;
						}
						for (int i=0; i<=n; i++){
							tempi2[i] = dt[i].nomorkamar;
						}
						quick(tempi, 0, (n-1));
						urutdata(n, dt, tempi, tempi2);
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
					case 7://bulan
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].tl.bulan;
						}
						for (int i=0; i<=n; i++){
							tempi2[i] = dt[i].tl.bulan;
						}
						quick(tempi, 0, (n-1));
						urutdata(n, dt, tempi, tempi2);
						getch();						
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
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

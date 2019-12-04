#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
//		printf("\nProses Partisi\n");
//		for	(int i=0;i<8;i++){
//			printf("%d ", arr[i]);
//		}
	}
	temp = arr[index];
	arr[index] = arr[akhir];
	arr[akhir] = temp;
//	printf("\nHasil Partisi\n");
//	for	(int i=0;i<8;i++){
//		printf("%d ", arr[i]);
//	}
	return index;
}

void quick(int arr[], int awal, int akhir){
	if (awal < akhir){
		int index = partition(arr, awal, akhir);
//		printf("\nProses Quick Kiri\n");
//		for	(int i=0;i<8;i++){
//			printf("%d ", arr[i]);
//		}
		quick(arr, awal, (index-1));
//		printf("\nProses Quick Kanan\n");
//		for	(int i=0;i<8;i++){
//			printf("%d ", arr[i]);
//		}
		quick(arr, (index+1), akhir);
	}
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


int main(){
	srand(time(0));
	data dt[100];
	int i,j,loop=1,menu,orang=0,n=0,dat=0,sort,ganti;
	while(loop==1){
		printf("Draft Menu : \n");
		printf("1. Input data\n");
		printf("2. Tampilkan data\n");
		printf("3. Cari data\n");
		printf("4. Ganti data\n");
		printf("5. Pengurutan data\n");
		puts("0. X-it\n");
		printf("Pilihan : ");
		scanf("%d",&menu);
		switch(menu){
			case 1://input
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
			case 2://history
				if(dat==0){
					system("cls");
					printf("Data belum di inputkan\n");
					getch();
					system("cls");
				}
				else{
					system("cls");
					for(j=0;j<n;j++){
						printf("Data ke - %d",j+1);
						printf("\n");
						printf("ID Pasien\t: %d\n",dt[j].id);
						printf("Nama Pasien\t: %s\n",dt[j].nama);
						printf("Jenis Penyakit\t: %s\n",dt[j].penyakit);
						printf("Jenis Kamar\t: %s\n",dt[j].kamar);
						printf("Nomor Kamar\t: %d\n",dt[j].nomorkamar);
						printf("Tanggal Masuk\t: %d\n",dt[j].tl.tanggal);
						printf("Bulan Masuk\t: %d\n",dt[j].tl.bulan);
						printf("\n\n");
					}
					getch();
					system("cls");
				}
				break;
			case 3:{//search
				int temp[n], cari, index;
				system("cls");
				for (int i=0; i<=n; i++){
					temp[i] = dt[i].id;
				}
				
				printf("Masukkan ID Pasien Yang Ingin Dicari = ");scanf("%d",& cari);fflush(stdin);
				index = jump(temp, (n+1), cari);
				system("cls");
				if (index!=-1){
					printf("Data ke - %d",index+1);
					printf("\n");
					printf("ID Pasien\t: %d\n",dt[index].id);
					printf("Nama Pasien\t: %s\n",dt[index].nama);
					printf("Jenis Penyakit\t: %s\n",dt[index].penyakit);
					printf("Jenis Kamar\t: %s\n",dt[index].kamar);
					printf("Nomor Kamar\t: %d\n",dt[index].nomorkamar);
					printf("Tanggal Masuk\t: %d\n",dt[index].tl.tanggal);
					printf("Bulan Masuk\t: %d\n",dt[index].tl.bulan);
					getch();
				}
				system("cls");
				break;
			}
			case 4:{
				int ketemu=0;
				system("cls");
				fflush(stdin);
				printf("\nMasukkan NomorID yang ingin anda ubah : ");
				scanf("%d",&ganti);
				fflush(stdin);
				for(i=0;i<n;i++){
					if(dt[i].id==ganti){
						system("cls");
						printf("Masukkan data baru\n");
						printf("Nama Pasien\t\t: ");
						gets(dt[n].nama);
						printf("Jenis Penyakit\t\t: ");
						gets(dt[n].penyakit);
						printf("Jenis Kamar\t\t: ");
						gets(dt[n].kamar);
						printf("Nomor Kamar\t\t: ");
						scanf("%d",& dt[n].nomorkamar);
						fflush(stdin);
						printf("Tanggal masuk\t\t: ");
						scanf("%d",&dt[n].tl.tanggal);
						printf("Bulan masuk\t\t: ");
						scanf("%d",&dt[n].tl.bulan);
						ketemu = 1;
					}
				}
				if (ketemu==0){
					system("cls");
					printf("ID Yang Dimasukkan Tidak Ditemukan !!!");
					getch();
					system("cls");
				}
			}
				break;
			case 5:{//sorting
				int temp[n];
				char tempnama[10];
				char temppenyakit[15];
				char tempkamar[5];
				int tempnomorkamar;
				int temptanggal;
				int tempbulan;
				for (int i=0; i<=n; i++){
					temp[i] = dt[i].id;
				}
				quick(temp, 0, n);
				for (int i=0; i<(n-1); i++){
					for (int j=0; j<n; j++){
						if (temp[i]==dt[j].id){
							strcpy(tempnama, dt[i].nama);
							strcpy(temppenyakit, dt[i].penyakit);
							strcpy(tempkamar, dt[i].kamar);
							tempnomorkamar = dt[i].nomorkamar;
							temptanggal = dt[i].tl.tanggal;
							tempbulan = dt[i].tl.bulan;
							
							strcpy(dt[i].nama, dt[j].nama);
							strcpy(dt[i].penyakit, dt[j].penyakit);
							strcpy(dt[i].kamar, dt[j].kamar);
							dt[i].nomorkamar = dt[j].nomorkamar;
							dt[i].tl.tanggal = dt[j].tl.tanggal;
							dt[i].tl.bulan = dt[j].tl.bulan;
						
							strcpy(dt[j].nama, tempnama);
							strcpy(dt[j].penyakit, temppenyakit);
							strcpy(dt[j].kamar, tempkamar);
							dt[j].nomorkamar = tempnomorkamar;
							dt[j].tl.tanggal = temptanggal;
							dt[j].tl.bulan = tempbulan;
						}
					}
				}
				for (int i=0; i<n; i++){
					dt[i].id = temp[i];
				}
				system("cls");
				printf("Data Berhasil Diurutkan !!!");
				getch();
				system("cls");

				break;
			}
			case 0:
				loop=0;
				break;
		}
	}
	
}

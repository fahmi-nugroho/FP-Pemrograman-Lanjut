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
	int i,j,loop=1,menu,menu1,orang=0,n=0,dat=0,sort,ganti;
	char cganti[10],ccari[10];
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
				int tempid[n], cari, index;
				char tempnama[10];
				printf("\nMasukkan ID Pasien Yang Ingin Dicari = ");scanf("%d",& cari);fflush(stdin);
				index = jump(tempid, (n+1), cari);	
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
				printf("List : \n");
				printf("1. ID\n");
				printf("2. Nama\n");
				printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch(menu1){
					case 1:
						printf("\nMasukkan NomorID yang ingin anda ubah : ");
						scanf("%d",&ganti);
						fflush(stdin);
						for(i=0;i<n;i++){
							if(dt[i].id==ganti){
								ketemu = 1;
								j=i;
							}
						}
						break;
					case 2:
						printf("\nMasukkan Nama yang ingin anda ubah : ");
						gets(cganti);
						fflush(stdin);
						for(i=0;i<n;i++){
							if(strcmp(dt[i].nama, cganti)==0){
								ketemu = 1;
								j=i;
							}
						}
						break;
				}
				if(ketemu==1){
//					system("cls");
					printf("Masukkan data baru\n");
					printf("Nama Pasien\t\t: ");
					gets(dt[j].nama);
					printf("Jenis Penyakit\t\t: ");
					gets(dt[j].penyakit);
					printf("Jenis Kamar\t\t: ");
					gets(dt[j].kamar);
					printf("Nomor Kamar\t\t: ");
					scanf("%d",& dt[j].nomorkamar);
					fflush(stdin);
					printf("Tanggal masuk\t\t: ");
					scanf("%d",&dt[j].tl.tanggal);
					printf("Bulan masuk\t\t: ");
					scanf("%d",&dt[j].tl.bulan);
				}
				else if (ketemu==0){
					system("cls");
					printf("ID Yang Dimasukkan Tidak Ditemukan !!!");
					getch();
					system("cls");
				}
				system("cls");
				printf("Data Berhasil Diupdate !!!");
				getch();
				system("cls");
			}
				break;
			case 5:{//sorting
				char temp[100][100];
				int tempid[n];
				char tempnama[10];
				char temppenyakit[15];
				char tempkamar[5];
				int tempnomorkamar[n];
				int temptanggal[n];
				int tempbulan[n];
				printf("List : \n");
				printf("1. ID\n");
				printf("2. Nama\n");
				printf("3. Penyakit\n");
				printf("4. Kamar\n");
				printf("5. No. Kamar\n");
				printf("6. Tanggal\n");
				printf("7. Bulan\n");
				printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch(menu1){
					case 1:
						for (int i=0; i<=n; i++){
							tempid[i] = dt[i].id;
						}
						for	(int i=0;i<n;i++){
							printf("%d ", tempid[i]);
						}
						printf("\n%d", n);
						getch();
						quick(tempid, 0, (n-1));
						for	(int i=0;i<n;i++){
							printf("%d ", tempid[i]);
						}
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempid[i]==dt[j].id){
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
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					case 2: //nama
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
						printf("Data Berhasil Diurutkan !!!");
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
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
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
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									tempnomorkamar[i] = dt[i].nomorkamar;
									
									
									dt[i].id = dt[j].id;
									strcpy(dt[i].nama, dt[j].nama);
									strcpy(dt[i].penyakit, dt[j].penyakit);
									strcpy(dt[i].kamar, dt[j].kamar);
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
									dt[i].nomorkamar = dt[j].nomorkamar;
								
									dt[j].id = tempid[i];
									strcpy(dt[j].nama, tempnama);
									strcpy(dt[j].penyakit, temppenyakit);
									strcpy(dt[j].kamar, tempkamar);
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
									dt[j].nomorkamar = tempnomorkamar[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
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
									dt[i].tl.tanggal = dt[j].tl.bulan;
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
						printf("Data Berhasil Diurutkan !!!");
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
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");

						break;
				}	
				break;
			}
			case 0:
				loop=0;
				break;
		}
	}	
}

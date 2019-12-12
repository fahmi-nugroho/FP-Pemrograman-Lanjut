#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int jumpsearch(){
	
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
	struct ttl tl;
};
typedef struct data data;

//bool compareTwoStudents(data a, data b) 
//{ 
//    // If total marks are not same then 
//    // returns true for higher total 
//    if (a.total != b.total ) 
//        return a.total > b.total; 
//  
//    // If marks in Maths are not same then 
//    // returns true for higher marks 
//    if (a.math != b.math) 
//            return a.math > b.math; 
//  
//    return (a.phy > b.phy); 
//} 
//void computeRanks(data a[], int n) 
//{ 
//    // To calculate total marks for all Students 
//    for (int i=0; i<n; i++) 
//        a[i].total = a[i].math + a[i].phy + a[i].che; 
//  
//    // Sort structure array using user defined 
//    // function compareTwoStudents() 
//    sort(a, a+5, compareTwoStudents); 
//  
//    // Assigning ranks after sorting 
//    for (int i=0; i<n; i++) 
//        a[i].rank = i+1; 
//} 
void quickSort (data dt[], int lo, int hi){ 
//  lo adalah index bawah, hi adalah index atas 
//  dari bagian array yang akan di urutkan 
	int i=lo, j=hi, h; 
 
//  pembagian 
    do{ 
        while (dt[i].id<dt[lo].id) i++; 
        while (dt[j].id>dt[lo].id) j--; 
        if (i<=j) 
        { 
            h=dt[i]; dt[i]=dt[j]; dt[j].id=h;//tukar 
            i++; j--; 
        } 
    } while (i<=j); 
 
//  pengurutan 
    if (lo<j) quickSort(dt, lo, j); 
    if (i<hi) quickSort(dt, i, hi); 
} 
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
				printf("Nama Pasien\t\t: ");
				gets(dt[n].nama);
				printf("Jenis Penyakit\t\t: ");
				gets(dt[n].penyakit);
				printf("Jenis Kamar\t\t: ");
				gets(dt[n].kamar);
				printf("Tanggal masuk\t\t: ");
				scanf("%d",&dt[n].tl.tanggal);
				printf("Bulan masuk\t\t: ");
				scanf("%d",&dt[n].tl.bulan);
				system("cls");
				n++;
				break;
			case 2://history
				if(dat==0){
					printf("Data belum di inputkan\n");
//					getch();
//					system("cls");
				}
				else{
					for(j=0;j<n;j++){
						printf("Data ke - %d",j+1);
						printf("\n");
						printf("ID Pasien\t: %d\n",dt[j].id);
						printf("Nama Pasien\t: %s\n",dt[j].nama);
						printf("Jenis Penyakit\t: %s\n",dt[j].penyakit);
						printf("Jenis Kamar\t: %s\n",dt[j].kamar);
						printf("Tanggal Masuk\t: %d\n",dt[j].tl.tanggal);
						printf("Bulan Masuk\t: %d\n",dt[j].tl.bulan);
						printf("\n\n");
					}
				}
				break;
			case 3://search
				jumpsearch();
				break;
			case 4:
				fflush(stdin);
//				printf("%d",n);
				printf("Data siapa yang ingin anda ganti : ");
				scanf("%d",&ganti);
				for(i=0;i<n;i++){
					if(dt[n].id==ganti){
						printf("Masukkan nama baru\n");
						printf("Nama Pasien\t\t: ");
						gets(dt[n].nama);
						printf("Jenis Penyakit\t\t: ");
						gets(dt[n].penyakit);
						printf("Jenis Kamar\t\t: ");
						gets(dt[n].kamar);
						printf("Tanggal masuk\t\t: ");
						scanf("%d",&dt[n].tl.tanggal);
						printf("Bulan masuk\t\t: ");
						scanf("%d",&dt[n].tl.bulan);
					}
				}
				break;
			case 5://sorting
				for(i=0;i<n;i++){ 
	        		printf("%d ",dt[i].id); 
	   			} 
	    		printf("\n"); 
	    		quickSort(dt,0,n-1); 
	 
	    		for(i=0;i<n;i++){ 
	        		printf("%d ",dt[i].id); 
	        		printf("%d ",dt[i].id); 
	        		printf("%d ",dt[i].id); 
	        		printf("%d ",dt[i].id); 
	        		printf("%d ",dt[i].id); 
	        		printf("%d ",dt[i].id); 
	    		} 
				break;
			case 0:
				loop=0;
				break;
		}
	}
	
}

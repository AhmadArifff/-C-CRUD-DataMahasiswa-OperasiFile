// #include <iostream>
// #include <fstream>
// #include <string>
// #include <algorithm>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct dataMahasiswa {
  int npm;
  char nama[50];
  char matkul[50];
  int nilai;
}mahasiswa;
struct DataMahasiswa
{
	int npm;
  char nama[50];
  char matkul[50];
  int nilai;
}Data[200];
void readMhs(
  char * fileName,
  mahasiswa * listMhs,
  int * listSize
) {
  FILE * file = fopen(fileName, "r");
  int counter = 0;
  while (
    fscanf(
      file,
      "%d %s %s %d",
      & listMhs[counter].npm,
      listMhs[counter].nama,
      listMhs[counter].matkul,
      & listMhs[counter].nilai
    ) == 4
  ) {
    counter++;
  }
  * listSize = counter;
  fclose(file);
}

void outputMhs(mahasiswa * listMhs, int listSize) {
	int i;
  for (i = 0; i < listSize; i++) {
    printf(
        "%d %s %s %d\n",
        listMhs[i].npm,
        listMhs[i].nama,
        listMhs[i].matkul,
        listMhs[i].nilai
      );
  }
}

int compareNilai(const void* a, const void* b) {
  const mahasiswa* mhsA = (const mahasiswa*)a;
  const mahasiswa* mhsB = (const mahasiswa*)b;
  return mhsA->nilai - mhsB->nilai;
}

void display_all() {
  int npm;
  char nama[50];
  char matkul[50];
  int nilai;

  int no = 1;
  FILE * file = fopen("Mahasiswa.txt", "r");
  printf(
      "%-5s %-7s %-15s %-20s %-5s\n",
      "No",
      "NPM",
      "Nama",
      "Mata Kuliah",
      "Nilai"
    );
  if (file != NULL) {
    while (
      fscanf(
        file,
        "%d %s %s %d",
        & npm,
        nama,
        matkul,
        & nilai
      ) == 4
    ) {
      printf(
        "%-5d %-7d %-15s %-20s %-5d\n",
         no,
         npm,
         nama,
         matkul,
         nilai
      );
      no++;
    }
  }
  fclose(file);
}

void insert_student() {
  int npm;
  char nama[50];
  char matkul[50];
  int nilai;

  FILE * file = fopen("Mahasiswa.txt", "a");
  printf(" \n NPM : ");
  scanf("%d", & npm);
  printf(" \n Nama : ");
  scanf("%s", nama);
  printf(" \n Matkul : ");
  scanf("%s", matkul);
  printf(" \n Nilai : ");
  scanf("%d", & nilai);
  fprintf(
    file,
    "%d %s %s %d\n",
    npm,
    nama,
    matkul,
    nilai
  );
  printf("Done !");
  fclose(file);
}

void delete_student() {
  int npm;
  char nama[50];
  char matkul[50];
  int nilai;
  int a;

  FILE * file = fopen("Mahasiswa.txt", "r");
  FILE * temp_file = fopen("temp.txt", "w");
  printf(" \n\t Masukkan NPM : ");
  scanf("%d", & a);
  if (file != NULL) {
    while (
      fscanf(
        file,
        "%d %s %s %d",
        & npm,
        nama,
        matkul,
        & nilai
      ) == 4
    ) {
      if (npm == a) {
        continue;
      } else {
        fprintf(
          temp_file,
          "%d %s %s %d\n",
          npm,
          nama,
          matkul,
          nilai
        );
      }
    }
  }
  fclose(file);
  fclose(temp_file);

  file = fopen("Mahasiswa.txt", "w");
  temp_file = fopen("temp.txt", "r");
  if (temp_file != NULL) {
    while (
      fscanf(
        temp_file,
        "%d %s %s %d",
        & npm,
        nama,
        matkul,
        & nilai
      ) == 4
    ) {
      if (a == npm) {
        fprintf(
          file,
          "%d %s %s %d\n",
          npm,
          nama,
          matkul,
          nilai
        );
      } else {
        fprintf(
          file,
          "%d %s %s %d\n",
          npm,
          nama,
          matkul,
          nilai
        );
      }
    }
  }
  fclose(file);
  fclose(temp_file);
  remove("temp.txt");
  printf("\n done");
}

void update_student() {
  FILE * filestream;
  FILE * filetemp;
  filestream = fopen("Mahasiswa.txt", "r");
  filetemp = fopen("temp.txt", "w");

  int npm;
  char nama[50];
  char matkul[50];
  int nilai;
  int a;

  printf("Masukkan npm : ");
  scanf("%d", & a);
  if (filestream != NULL) {
    while (fscanf(filestream, "%d %s %s %d", & npm, nama, matkul, & nilai) != EOF) {
      if (npm == a) {
        printf(" \n\t masukkan nilai baru \n ");
        printf(" \n nilai : ");
        scanf("%d", & nilai);
        fprintf(filetemp, "%d %s %s %d\n", npm, nama, matkul, nilai);
      } else {
        fprintf(filetemp, "%d %s %s %d\n", npm, nama, matkul, nilai);
      }
    }
  }
  fclose(filestream);
  fclose(filetemp);

  filestream = fopen("Mahasiswa.txt", "w");
  filetemp = fopen("temp.txt", "r");

  if (filetemp != NULL) {
    while (fscanf(filetemp, "%d %s %s %d", & npm, nama, matkul, & nilai) != EOF) {
      if (a == npm) {
        fprintf(filestream, "%d %s %s %d\n", npm, nama, matkul, nilai);
      } else {
        fprintf(filestream, "%d %s %s %d\n", npm, nama, matkul, nilai);
      }
    }
  }
  fclose(filetemp);
  fclose(filestream);
  remove("temp.txt");
}

void search_student() {
  FILE * filestream;
  int npm;
  char nama[50];
  char matkul[50];
  int nilai;
  int a;
  printf(" \n masukkan npm : ");
  scanf("%d", & a);
  int x = 0;
  filestream = fopen("Mahasiswa.txt", "r");
  if (filestream != NULL) {
    while (fscanf(filestream, "%d %s %s %d", & npm, nama, matkul, & nilai) == 4) {
      if (npm == a) {
        printf("%-5s %-15s %-20s %-5s\n", "NPM", "Nama", "Mata Kuliah", "Nilai");
        printf("%-5d %-15s %-20s %-5d\n", npm, nama, matkul, nilai);
        x = 1;
        break;
      }
    }
    fclose(filestream);
  }
  if (x == 0) {
    printf(" \n not found !!!!\n");
  }
}

void sort(mahasiswa* listMhs, int listSize, bool (*compare)(const mahasiswa*, const mahasiswa*)) {
  int i;
  int j;
  for (i = 0; i < listSize - 1; i++) {
    for (j = i + 1; j < listSize; j++) {
      if (compare(&listMhs[i], &listMhs[j])) {
        mahasiswa temp = listMhs[i];
        listMhs[i] = listMhs[j];
        listMhs[j] = temp;
      }
    }
  }
}
void sortinglulus(){
	struct DataMahasiswa temp;
	FILE *fp;
	int i=0,size,j;
	char ch; 
 			printf(
      "%-5s %-7s %-15s %-20s %-5s\n",
      "No",
      "NPM",
      "Nama",
      "Mata Kuliah",
      "Nilai"
    );
	fp=fopen("Mahasiswa.txt","r");
	if(fp==NULL){ 
		printf("\n Cannot open the file \n");
		exit(0);
	}
	while(ch!=EOF){
		fscanf(fp,"%d %s %s %d",&Data[i].npm,Data[i].nama,Data[i].matkul,&Data[i].nilai);  
		ch=fgetc(fp); 
		i++;  
	} 
	size=i-1;
	for(i=0;i<size;++i){
		for(j=i+1;j<size;j++){
			if(Data[i].nilai<Data[j].nilai){
			temp=Data[i];
			Data[i]=Data[j];
			Data[j]=temp;
			}
		}
	}
	fp=fopen("DataMahasiswaLulus.txt","w");
	for(i=0;i<size;i++){
		if(Data[i].nilai>=55){
				printf("%-5d %-7d %-15s %-20s %-5d\n",i+1,Data[i].npm, Data[i].nama,Data[i].matkul,Data[i].nilai);
		}
		fprintf(fp,"%d %s %s %d\n",Data[i].npm,Data[i].nama,Data[i].matkul,Data[i].nilai);
	}
	printf("Record size : %d \n",size);
}

int main(void) {
  char fileName[] = "Mahasiswa.txt";
  mahasiswa listMhs[30];
  int listSize = 0;
  bool flag = true;

  while (flag) {
    int menu;
    system("cls");
    printf("Aplikasi Data Rekap Nilai Mahasiswa Menggunakan Operasi File\n1. Tampilkan Mahasiswa Lulus \n");
    printf("2. Update Nilai Mahasiswa \n");
    printf("3. Search Nilai Mahasiswa\n");
    printf("4. Insert Nilai Mahasiswa\n");
    printf("5. Display all Nilai Mahasiswa\n");
    printf("6. Delete Nilai Mahasiswa\n");
    printf("7. Exit \n");
    printf("Input menu: ");
    scanf("%d", & menu);

    switch (menu) {
    case 1:
//      readMhs(fileName, listMhs, & listSize);
//      qsort(listMhs, listSize, sizeof(mahasiswa), compareNilai);
//      outputMhs(listMhs, listSize);
		sortinglulus();
      break;
    case 2:
      update_student();
      printf("DONE");
      break;
    case 3:
      search_student();
      break;
    case 4:
      insert_student();
      break;
    case 5:
      display_all();
      break;
    case 6:
      delete_student();
      break;
    case 7:
      printf("Exit \n");
      return 1;
    default:
      printf("Input salah");
      break;
    }

    printf("\nIngin Melakukan Aksi lain? Tekan 'y' \n");
    char f;
    scanf(" %c", & f);
    if (f != 'y') {
      flag = false;
    }
  }

  return 0;
}

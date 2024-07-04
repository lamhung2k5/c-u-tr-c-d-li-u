#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//khai bao cau truc mot sinh vien
struct sinhvien{
	char hoTen[50];
	char maLop[7];
	int maSV;
	float diem;
};

typedef struct sinhvien sinhvien;

//danh sah lien ket
struct node{
	sinhvien data;
	struct node *next;
};

typedef struct node node;

struct list{
	node *head;
	node *tail;
};

typedef struct list list;

void KhoiTao(list &l){
	l.head = NULL;
	l.tail = NULL;
}

node *KhoiTaoNode(sinhvien x){
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("\loi cap phat bo nho.");
		return NULL;
	}
	p -> data = x;
	p -> next = NULL;
	return p;
}

void ThemVaoCuoi(list &l, node *p){
	if(l.head == NULL){
		l.head = l.tail = p;
	}else{
		l.tail -> next = p;
		l.tail = p;
	}
}

//xuat thong tin sv
void xuat(list l){
	int i = 1;
	for(node *k = l.head; k != NULL; k = k -> next){
		printf("|%3d|%30s|%10s|%10d|%5.2f|\n",i,k -> data.hoTen, k -> data.maLop,k -> data.maSV,k-> data.diem);
		printf("----------------------------------------------------------------\n");
		i++;
	}
}

//nhap thong tin
void nhap(sinhvien &x){
	fflush(stdin);
	printf("nhap ho ten: ");
	gets(x.hoTen);
	fflush(stdin);
	printf("nhap ma lop: ");
	gets(x.maLop);
	fflush(stdin);
	printf("nhap ma sinh vien: ");
	scanf("%d",&x.maSV);
	fflush(stdin);
	printf("nhap diem: ");
	scanf("%f",&x.diem);
}

//doc va ghi file
void docFile(list &l, char *tenFile) {
  FILE *f = fopen(tenFile, "r");
  if (f == NULL) {
    printf("Khong the mo file!\n");
    return;
  }

  sinhvien x;
  while (fscanf(f, "%[^,],%[^,],%d,%f\n", x.hoTen, x.maLop, &x.maSV, &x.diem) != EOF) {
    node *p = KhoiTaoNode(x);
    ThemVaoCuoi(l, p);
  }

  fclose(f);
}

void ghiFile(list l, char *tenFile){
	//tao file
	FILE *f;
	f = fopen(tenFile,"w");
	if(f == NULL){
		printf("\nkhong the mo tep.");
		exit(1);
	}
	
	for(node *k = l.head; k != NULL; k = k -> next){
		fprintf(f,"%s,%s,%d,%.2f\n",k -> data.hoTen,k -> data.maLop,k -> data.maSV,k -> data.diem);
	}
	
	//dong file
	fclose(f);
}

//ham menu
void menu(list &l){
	while(true){
		
		fflush(stdin);
		system("cls");
		
		printf("1. nhap thong tin sinh vien.\n");
		printf("2. xuat thong tin sinh vien.\n");
		printf("3. luu danh sach.\n");
		printf("4. mo danh sach.\n");
		printf("0. thoat.\n");
		
		printf("\n\n\t\tAN PHIM CHON: ");
		int chon;
		scanf("%d",&chon);
		
		switch(chon){
			case 1:
			{
				fflush(stdin);
				system("cls");
				
				sinhvien x;
				nhap(x);
				node *p = KhoiTaoNode(x);
				ThemVaoCuoi(l,p);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				if(l.head == NULL){
					printf("chua co du lieu.");
				}else{
					printf("\t\tDANH SACH SV\n\n");
					printf("----------------------------------------------------------------\n");
					printf("|%3s|%30s|%10s|%10s|%5s|\n","stt","ho va ten","ma lop","ma sv","diem");
					printf("----------------------------------------------------------------\n");
					xuat(l);
				}
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 3:
			{
				fflush(stdin);
				system("cls");
				
				char tenFile[30];
				printf("nhap ten file can luu: ");
				gets(tenFile);
				ghiFile(l,tenFile);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 4:
			{
				fflush(stdin);
				system("cls");
				
				char tenFile1[30];
				printf("nhap ten file can mo: ");
				gets(tenFile1);
				docFile(l,tenFile1);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 0:
				exit(1);
			default:
			{
				fflush(stdin);
				system("cls");
				
				printf("\nkhong co chuc nang nay. an phim bat ki de tiep tuc.");
				getch();
				break;
			}
		}
	}	
}

int main(){
	list l;
	KhoiTao(l);
	menu(l);
	return 0;
}

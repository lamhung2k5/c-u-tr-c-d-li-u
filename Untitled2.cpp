#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//khai bao danh sach sinh vien
struct sinhVien{
	char hoTen[50];
	char maLop[7];
	int maSV;
	float diem;
};

typedef struct sinhVien sinhVien;

//danh sach lien ket
struct node{
	sinhVien data;
	struct node *next;
};

typedef struct node node;

struct list{
	node *head;
	node *tail;
};

typedef struct list list;

void khoiTao(list &l){
	l.head = NULL;
	l.tail = NULL;
}

node *khoiTaoNode(sinhVien x){
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("\nkhong the khoi tao node.");
		return NULL;
	}
	p -> data = x;
	p -> next  = NULL;
	return p;
}

void themVaoCuoi(list &l, node *p){
	if(l.head ==  NULL){
		l.head = l.tail = p;
	}else{
		l.tail -> next = p;
		l.tail = p;
	}
}

//ham nhap thong tin sinh vien
void nhap(sinhVien &sv){
	fflush(stdin);
	printf("\nnhap ho ten: ");
	gets(sv.hoTen);
	
	fflush(stdin);
	printf("\nnhap ma lop: ");
	gets(sv.maLop);
	
	fflush(stdin);
	printf("\nnhap ma sinh vien: ");
	scanf("%d",&sv.maSV);
		
	fflush(stdin);
	printf("\nnhap diem: ");
	scanf("%f",&sv.diem);
}

//ham xuat thong tin sinh vien
void xuat(list l){
	int i = 1;
	for(node *k = l.head; k != NULL; k = k -> next){
		printf("|%3d|%30s|%10s|%10d|%10.2f|\n",i,k -> data.hoTen,k -> data.maLop,k -> data.maSV,k -> data.diem);
		i++;
	}
}

//ham ghi file
void ghiFile(list l, char *tenFile){
	//tao file
	FILE *f;
	f = fopen(tenFile,"w");
	if(f == NULL){
		printf("file khong mo duoc.");
		return;
	}
	//ghi file
	for(node *k = l.head; k != NULL; k = k -> next){
		fprintf(f,"%s,%s,%d,%.2f\n",k -> data.hoTen,k -> data.maLop,k -> data.maSV,k -> data.diem);
	}
	printf("\nluu file thanh cong!\n");
	//dong file
	fclose(f);
}

//ham doc file
void docFile(list &l, char *tenFile){
	//tao file
	FILE *f;
	f = fopen(tenFile,"r");
	if(f == NULL){
		printf("file khong co trong may.");
		return;
	}
	//doc file
	sinhVien x;
	while(fscanf(f,"%[^,],%[^,],%d,%f\n",x.hoTen,x.maLop,&x.maSV,&x.diem) != EOF){
		node *p = khoiTaoNode(x);
		themVaoCuoi(l,p);
	}
	printf("\nmo file thanh cong!\n");
	//dong file
	fclose(f);
}

void menu(list &l){
	while(true){
		
		fflush(stdin);
		system("cls");
		
		printf("1. nhap danh sach sinh vien.\n");
		printf("2. xuat danh sach sinh vien.\n");
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
				
				//thao tac nhap
				sinhVien x;
				nhap(x);
				node *p = khoiTaoNode(x);
				themVaoCuoi(l,p);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				if(l.head != NULL){
					printf("\t\tDANH SACH SINH VIEN\n\n");
					printf("|%3s|%30s|%10s|%10s|%10s|\n","stt","ho va ten","ma lop","ma sv","diem");
					xuat(l);
				}else{
					printf("chua co du lieu.");
				}
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 3:
			{
				fflush(stdin);
				system("cls");
				
				printf("nhap ten file can luu: ");
				char tenFile[50];
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
				
				printf("nhap ten file can doc: ");
				char tenFile[50];
				gets(tenFile);
				docFile(l,tenFile);
				
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
	khoiTao(l);
	menu(l);
	return 0;
}

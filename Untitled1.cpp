#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//dinh nghia tam giac
struct TamGiac{
	float canh1;
	float canh2;
	float canh3;
	float ChuVi;
	float DienTich;
};

typedef struct TamGiac TamGiac;

//cau truc danh sach lien ket
struct node{
	TamGiac data;
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

node *KhoiTaoNode(TamGiac x){
	node *p = (node*)malloc(sizeof(node));
	if(p ==NULL){
		printf("\nloi khoi tao");
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

//ham de nhap thong tin cac tam giac
void nhap(TamGiac &x){
	fflush(stdin);
	printf("\nnhap canh thu 1: ");
	scanf("%f",&x.canh1);
	fflush(stdin);
	printf("\nnhap canh thu 2: ");
	scanf("%f",&x.canh2);
	fflush(stdin);
	printf("\nnhap canh thu 3: ");
	scanf("%f",&x.canh3);
	
	float p = (x.canh1 + x.canh2 + x.canh3)/2;
	x.ChuVi = 2*p;
	x.DienTich = sqrt(p*(p-x.canh1)*(p-x.canh2)*(p-x.canh3));
}

void xuat(list l){
	int i = 1; 
	for(node *k = l.head; k != NULL; k = k -> next){
		printf("\n|%3d|%8.2f|%8.2f|%8.2f|%8.2f|%11.2f|",i, k -> data.canh1, k -> data.canh2, k -> data.canh3, k -> data.ChuVi, k -> data.DienTich);
		i++;
	}
}

//ham xoa danh sach lien ket
void FreeAll(list &l){
	while(l.head != NULL){
		node *temp = l.head;
		l.head = l.head -> next;
		free(temp);
	}
}

//ham ghi file 
void ghifile(list l){
	//tao file
	FILE *file;
	file = fopen("tamgiac.txt","w");
	if(file == NULL){
		printf("\nkhong the mo file");
		exit(1);
	}
	//ghi file
	for(node *k = l.head; k != NULL; k = k -> next){
		fprintf(file,"%f,%f,%f,%f,%f\n",k -> data.canh1, k -> data.canh2, k -> data.canh3, k -> data.ChuVi, k -> data.DienTich);
	}	
	//dong file
	fclose(file);
}

//ham ghi file 
void docfile(list &l){
	//tao file
	FILE *file;
	file = fopen("tamgiac.txt","r");
	if(file == NULL){
		printf("\nkhong the mo file");
		exit(1);
	}
	//doc file
	
	while(!feof(file)){
		TamGiac x;
		fscanf(file,"%f,%f,%f,%f,%f\n",&x.canh1,&x.canh2,&x.canh3,&x.ChuVi,&x.DienTich);
		node *p = KhoiTaoNode(x);
		ThemVaoCuoi(l,p);

	}
		
	//dong file
	fclose(file);
}

void menu(list &l){
	while(true){
		fflush(stdin);
		system("cls");
		printf("1. nhap va kiem tra.\n");
		printf("2. xuat thong tin tam giac.\n");
		printf("3. xoa toan bo danh sach.\n");
		printf("4. luu danh sach.\n");
		printf("5. mo danh sach.\n");
		printf("0. thoat.\n");
		printf("\n\n\t\tAN PHIM CHON: ");
		int chon;
		scanf("%d",&chon);
		
		switch(chon){
			case 1:
			{
				fflush(stdin);
				system("cls");
				
				TamGiac x;
				
				nhap(x);
				
				if((x.canh1 >= 0 && x.canh2 >= 0 && x.canh3 >= 0)&&(x.canh1 + x.canh2 > x.canh3) && (x.canh2 + x.canh3 > x.canh1) && (x.canh1 + x.canh3 > x.canh2)){
					printf("\nco the tao thanh tam giac");
					node *p = KhoiTaoNode(x);
					ThemVaoCuoi(l,p);
				}else{
					printf("\nkhong the tao thanh tam giac!");
				}
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				if(l.head == NULL){
					printf("chua co dư lieu.\n");
				}else{
					printf("\t\t\tTHONG SO TAM GIAC\n\n\n");
					printf("|stt| canh 1 | canh 2 | canh 3 | chu vi | dien tich |");
					xuat(l);
				}
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 3:
			{
				fflush(stdin);
				system("cls");
				
				FreeAll(l);
				printf("danh sach da duoc luu");
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 4:
			{
				fflush(stdin);
				system("cls");
				
				ghifile(l);
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 5:
			{
				fflush(stdin);
				system("cls");
				
				docfile(l);	
				
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 0:
				exit(1);
			default:
				fflush(stdin);
				system("cls");
				
				printf("\nkhong co chuc nang nay. an phim bat ki de tiep tuc!");
				getch();
				break;
		}
	}
}

int main(){
	list l;
	KhoiTao(l);
	menu(l);
	return 0;
}


//fix loi hien thi lai sau khi doc danh sach

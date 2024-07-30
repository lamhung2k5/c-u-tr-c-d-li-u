#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct khachHang{
	int maSo;
	char hoTen[50];
	char phai[5];
	int namSinh;
	int tien;
};

typedef struct khachHang khachHang;

struct node{
	khachHang data;
	struct node *next;
};

typedef struct node node;

struct list{
	node *head;
	node *tail;
};

typedef struct list list;

void khoiTao(list &l) {
	l.head = NULL;
	l.tail = NULL;
}

node *khoiTaoNode(khachHang &x) {
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("khong the khoi tao.");
		return NULL;
	}
	p -> data = x;
	p -> next = NULL;
	return p;
}

void themVaoCuoi(list &l, node *p) {
	if(l.head == NULL) {
		l.head = l.tail = p;
	}else{
		l.tail -> next = p;
		l.tail = p;
	}
}

void nhap(khachHang &x) {
	fflush(stdin);
	printf("\nnhap ma so: ");
	scanf("%d",&x.maSo);
	fflush(stdin);
	printf("\nnhap ho ten: ");
	gets(x.hoTen);
	fflush(stdin);
	printf("\nnhap phai: ");
	gets(x.phai);
	fflush(stdin);
	printf("\nnhap nam sinh: ");
	scanf("%d",&x.namSinh);
	fflush(stdin);
	printf("\nnhap tien: ");
	scanf("%d",&x.tien);
}

void in(list l){
	int i = 1;
	for(node *k = l.head; k != NULL; k = k -> next) {
		if(strcmp(k -> data.phai,"nu") == 0 && k -> data.namSinh < 1990){
			printf("khach hang %d:", i++);
			printf("\nma so: %d",k -> data.maSo);
			printf("\nho ten: %s",k -> data.hoTen);
			printf("\nphai: %s",k -> data.phai);
			printf("\nnam sinh: %d",k -> data.namSinh);
			printf("\nso tien: %d\n\n",k -> data.tien);
		}
	}
}

void dem(list l){
	int i = 0;
	for(node *k = l.head; k != NULL; k = k -> next){
		if(k -> data.tien != 0){
			i++;
		}
	}
	printf("co %d khach hang.", i);
}

void menu(list &l){
	while(true){
		fflush(stdin);
		system("cls");
		
		printf("1.nhap thong tin.\n");
		printf("2.xuat khach hang nu va nam sinh nho hon 1990.\n");
		printf("3.dem so luong khach hang co so tien khac.\n");
		printf("0.thoat.\n");
		
		int chon;
		printf("\n\n\t\tAN PHIM CHON: ");
		scanf("%d",&chon);
		switch(chon) {
			case 1:
			{
				fflush(stdin);
				system("cls");

				khachHang x;
				nhap(x);
				node *p = khoiTaoNode(x);
				themVaoCuoi(l,p);
					
				printf("\nan phim bat ki.");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				in(l);
					
				printf("\nan phim bat ki.");
				getch();
				break;
			}
			case 3:
			{
				fflush(stdin);
				system("cls");
				
				dem(l);
					
				printf("\nan phim bat ki.");
				getch();
				break;
			}
			case 0:
				exit(1);
			default:
			{
				fflush(stdin);
				system("cls");
				
				
				
				printf("\nkhong co chuc nang nay. an phim bat ki.");
				getch();
				break;
			}
		}
	}
}

int main() {
	list l;
	khoiTao(l);
	menu(l);
	return 0;
}
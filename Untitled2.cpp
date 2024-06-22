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

//cau truc stack
struct node{
	TamGiac data;
	struct node *next;
};

typedef struct node node;

struct stack{
	node *top; //quan ly stack
};

typedef struct stack stack;


void KhoiTao(stack &s){
	s.top = NULL;
}

//ham khoi tao mot node
node *KhoiTaoNode(TamGiac x){
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		return NULL;
	}
	p -> data = x;
	p -> next = NULL;
	return p;
}

//kiem tra stack co ron hay khong
bool IsEmpty(stack s){
	if(s.top == NULL){
		return true; //danh sach rong
	}
	return false; //danh sach co phan tu
}

//them phan tu vao stack theo LIFO
bool push(stack &s, node *p){
	if(!IsEmpty(s)){
		s.top = p;
	}else{
		p -> next = s.top;
		s.top = p;
	}
	return true;
}

bool pop(stack &s, TamGiac x){
	if(!IsEmpty(s)){
		return false;
	}else{
		node *p = s.top;
		x = p -> data;
		s.top = s.top -> next;
		free(p);
	}
	return true;
}

//xem thong tin cua stack
bool top(stack &s, TamGiac &x){
	if(!IsEmpty(s)){
		return false;
	}
	x = s.top -> data;
	return true;
}

//ham xuat stack
void xuat(stack s){
	int i = 0;
	while(!IsEmpty(s)){
		TamGiac x;
		pop(s,x);
		printf("\n|%3d|%8.2f|%8.2f|%8.2f|%8.2f|%11.2f|",i++, s.top -> data.canh1, s.top -> data.canh2, s.top -> data.canh3, s.top -> data.ChuVi, s.top -> data.DienTich);
	}
	if(IsEmpty(s) == true){
		printf("\ndanh sach dang rong");
	}else{
		printf("\ndanh sach ton tai phan tu");
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


void menu(stack &s){
	while(true){
		fflush(stdin);
		system("cls");
		printf("1. nhap va kiem tra.\n");
		printf("2. xuat thong tin tam giac.\n");
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
				
				if((x.canh1 + x.canh2 > x.canh3) && (x.canh2 + x.canh3 > x.canh1) && (x.canh1 + x.canh3 > x.canh2)){
					printf("\nco the tao thanh tam giac");
					node *p = KhoiTaoNode(x);
					push(s,p);
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
				
				printf("\t\t\tTHONG SO TAM GIAC\n\n\n");
				printf("|stt| canh 1 | canh 2 | canh 3 | chu vi | dien tich |");
				xuat(s);
				
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
	stack s;
	KhoiTao(s);
	menu(s);
	return 0;
}
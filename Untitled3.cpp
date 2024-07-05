#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
typedef struct node
{       long maso;
	char hoten[40];
	char diachi[100];
}node;
typedef struct stack
{
	int top;
	node list[N];#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node node;
typedef node* tree;

void khoiTao(tree &t){
	t = NULL;
}

void themNodeVaoCay(tree &t, int x){
	if(t == NULL){
		node *p = (node*)malloc(sizeof(node));
		p -> data = x;
		p -> left = NULL;
		p -> right = NULL;
		t = p;
	}
	else{
		if(x < t -> data){
			themNodeVaoCay(t -> left,x);
		}else if(x > t -> data){
			themNodeVaoCay(t -> right,x);
		}
	}
}

void duyetNLR(tree t){
	if(t != NULL){
		printf("\t%d", t -> data);
		duyetNLR(t -> left);
		duyetNLR(t -> right);
	}
}

void duyetLNR(tree t){
	if(t != NULL){
		duyetLNR(t -> left);
		printf("\t%d",t -> data);
		duyetLNR(t -> right);
	}
}

void menu(tree &t){
	while(true){
		fflush(stdin);
		system("cls");
		
		printf("1. them node vao cay.\n");
		printf("2. xuat node.\n");
		printf("0. thoat.\n");
		
		printf("\n\n\t\tAN PHIM CHON: ");
		int chon;
		scanf("%d",&chon);
		
		switch(chon){
			case 1:
			{
				fflush(stdin);
				system("cls");
				
				//them node vao cay
				int x;
				printf("nhap node x: ");
				scanf("%d",&x);
				themNodeVaoCay(t,x);
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				duyetLNR(t);
				
				printf("\nan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 0:
				exit(1);
			default:
			{
				fflush(stdin);
				system("cls");

				printf("\nkhong co chuc nang nay. an phim bat ki de tiep tuc!");
				getch();
				break;
			}
		}
	}
}

int main(){
	tree t;
	khoiTao(t);
	menu(t);
	return 0;
}
}stack;
void khoitao(stack &s)
{
	s.top=-1;
}
int empty(stack s)
{
	return s.top==-1?1:0;
}
int full(stack s)
{
	return s.top==N-1?1:0;
}
void push(stack &s,node x)
{
	if(!full(s))
	s.list[++s.top]=x;
}
node pop(stack &s)
{ node x;
	if(!empty(s))
	x=s.list[s.top--];
	return x;
}
int main()
{
	int n;stack s;node x;
	int t1; char *t2 ; char *t3 ;
	printf("\n nhap vao so phan tu:");
	scanf("%d",&n);
	khoitao(s);
	for(int i=0;i<n;i++)
	{
		printf("\n nhap ma so:");
		scanf("%d",&x.maso);
		printf("\n nhap ho ten:");
		fflush(stdin);
		gets(x.hoten);
		printf("\n nhap dia chi :");
		fflush(stdin);
		gets(x.diachi);
		push(s,x);
	}
while(!empty(s))
{
	x=pop(s);
     printf("\nMa so:%d Ho ten:%s Dia chi:%s",x.maso,x.hoten,x.diachi);
     /*  printf("\n ma so:%d",x.maso);
       printf("\n ho ten:%s",x.hoten);
       printf("\n dia chi:%s",x.diachi);
      */
}
//#include"stdio.h"
//#include"conio.h"
//#define N 20
//typedef struct node
//{
//	char hoten[40];
//	int tuoi;
//}node;
//typedef struct Queu
//{
//	int front,rear;
//	node list[N];
//}Queu;
//void khoitao(Queu &q)
//{
//	q.front=q.rear=-1;
//}
//int empty(Queu q)
//{
//	if((q.front==-1)&&(q.rear==-1))
//	return 1;
//	else
//	return 0;
//}
//int full(Queu q)
//{
//	if(q.front==0&&q.rear==N-1)
//	return 1;
//	if(q.front==q.rear+1)
//	return 1;
//	else
//	return 0;
//}
//void enqueu(Queu &q,node x)
//{
//	if(!full(q))
//	{
//		if(empty(q))
//		q.front=q.rear=0;
//		else
//		if(q.rear==N-1)
//		q.rear=0;
//		else
//		q.rear=q.rear+1;
//		q.list[q.rear]=x;
//	}
//}
//node dequeu(Queu &q)
//{
//	if(!empty(q))
//	{
//		node t=q.list[q.front];
//		if(q.front==q.rear)
//		khoitao(q);
//		else
//		if(q.front==N-1)
//		q.front=0;
//		else
//		q.front=q.front+1;
//		return t;
//	 }
//}
//int main()
//{
//	int n; node x;Queu q;
//	printf("nhap so phan tu:");
//	scanf("%d",&n);
//	khoitao(q);
//	for(int i=1;i<=n;i++)
//	{
//		printf("nhap ho ten:");
//		fflush(stdin);
//		gets(x.hoten);
//		printf("nhap tuoi:");
//		scanf("%d",&x.tuoi);
//		enqueu(q,x);
//	}
//	while(!empty(q))
//	{
//		x=dequeu(q);
//		printf("\n hotenL:%s",x.hoten);
//		printf("\n tuoi:%d",x.tuoi);
//	}
//	getch();
//}



#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//khai bao cau truc mot node
struct node{
    int data;
    struct node *next;
};

typedef struct node node;

//khai bao stack
struct queue{
    node *head;
    node *tail;
};

typedef struct queue queue;

//khoi tao stack
void KhoiTao(queue &q){
    q.head = NULL;
    q.tail = NULL;
}

//ham khoi tao 1 node
node *KhoiTaoNode(int x){
    node *p = (node*)malloc(sizeof(node));
    if(p == NULL){
        return NULL;
    }
    p -> data = x;
    p -> next = NULL;
    return p;
}

//----------------------------------------------

//ham kiem tra stack co rong hay khong
int IsEmpty(queue q){
    if(q.head == NULL){
        return 1;
    }
    return 0;
}

//thao tac push
void push(queue &q, node *p){
    if(q.head ==  NULL){
        q.head = q.tail = p;
    }else{
        q.tail -> next = p;
        q.tail = p;
    }
}

//thao tac pop
int pop(queue &q){
    if(!IsEmpty(q)){
        node *p = q.head;
        q.head = q.head -> next;
        return p -> data;
        free(p);
    }
    return 0;
}

//thao tac top
int top(queue q){
    if(!IsEmpty(q)){
        return q.head -> data;
    }
    return 0;
}

//xuat stack len man hinh
void xuat(queue q){
	for(node *k = q.head; k != NULL; k = k -> next){
		printf("\t%d",k -> data);
	}
}

//ham menu
void menu(queue &q){
    while(true){
        fflush(stdin);
        system("cls");
        
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. top.\n");
        printf("4. xuat.\n");
        printf("0. thoat.\n");
        
        int chon;
        printf("\n\n\t\tAN PHIM CHON: ");
        scanf("%d",&chon);
        
        switch(chon){
            case 1:
            {
                fflush(stdin);
                system("cls");
                
                //thao tac cho push
                int x;
                printf("nhap gia tri x: ");
                scanf("%d",&x);
                node *p = KhoiTaoNode(x);
                push(q,p);
                
                printf("\nan phim bat ki de tiep tuc.");
                getch();
                break;
            }
            case 2:
            {
                fflush(stdin);
                system("cls");
                
                //thao tac pop
                if(!IsEmpty(q)){
                	printf("gia tri cua node da xoa khoi dau danh sach la %d", pop(q));
				}else{
					printf("chua co phan tu de pop.");
				}
                
                printf("\nan phim bat ki de tiep tuc.");
                getch();
                break;
            }
            case 3:
            {
                fflush(stdin);
                system("cls");
                
                //thao tac top
                if(!IsEmpty(q)){
                	printf("gia tri cua node o dau danh sach la %d", top(q));
				}else{
					printf("chua co phan tu de top.");
				}
                
                printf("\nan phim bat ki de tiep tuc.");
                getch();
                break;
            }
            case 4:
            {
                fflush(stdin);
                system("cls");
                
                xuat(q);
                
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
    queue q;
    KhoiTao(q);
    menu(q);
    return 0;
}

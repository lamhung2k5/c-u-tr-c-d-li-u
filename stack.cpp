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
struct stack{
    node *head;
};

typedef struct stack stack;

//khoi tao stack
void KhoiTao(stack &s){
    s.head = NULL;
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
int IsEmpty(stack s){
    if(s.head == NULL){
        return 1;
    }
    return 0;
}

//thao tac push
void push(stack &s, node *p){
    if(s.head ==  NULL){
        s.head = p;
    }else{
        p -> next = s.head;
        s.head = p;
    }
}

//thao tac pop
int pop(stack &s){
    if(!IsEmpty(s)){
        node *p = s.head;
        s.head = s.head -> next;
        return p -> data;
        free(p);
    }
    return 0;
}

//thao tac top
int top(stack s){
    if(!IsEmpty(s)){
        return s.head -> data;
    }
    return 0;
}

//xuat stack len man hinh
void xuat(stack s){
	for(node *k = s.head; k != NULL; k = k -> next){
		printf("%d\n",k -> data);
	}
}

//ham menu
void menu(stack &s){
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
                push(s,p);
                
                printf("\nan phim bat ki de tiep tuc.");
                getch();
                break;
            }
            case 2:
            {
                fflush(stdin);
                system("cls");
                
                //thao tac pop
                if(!IsEmpty(s)){
                	printf("gia tri cua node da xoa khoi dau danh sach la %d", pop(s));
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
                if(!IsEmpty(s)){
                	printf("gia tri cua node o dau danh sach la %d", top(s));
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
                
                xuat(s);
                
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
    stack s;
    KhoiTao(s);
    menu(s);
    return 0;


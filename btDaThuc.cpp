#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct daThuc{
	int bacDaThuc;
	int *heSo;
};

typedef struct daThuc daThuc;

struct node{
	daThuc data;
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

node *khoiTaoNode(daThuc x){
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("loi khoi tao node");
		return NULL;
	}
	p -> data = x;
	p -> next = NULL;
	return p;
}

void themVaoCuoi(list &l, node *p){
	if(l.head == NULL){
		l.head = l.tail = p;
	}else{
		l.tail -> next = p;
		l.tail = p;
	}
}

void nhapDaThuc(daThuc &x){
	
	fflush(stdin);
	printf("nhap bac cua da thuc: ");
	scanf("%d",&x.bacDaThuc);
	
	x.heSo = (int*)malloc((x.bacDaThuc + 1)*sizeof(int));
	
	for(int i = 0; i <= x.bacDaThuc; i++){
		fflush(stdin);
		printf("nhap he so cho x^%d: ", i);
		scanf("%d",&x.heSo[i]);
	}
}

void hienMotDaThuc(daThuc x) {
    int soHangDau = 1; //kiem tra so hang dau

    for (int i = x.bacDaThuc; i >= 0; i--) {
        if (x.heSo[i] != 0) {
            if (soHangDau) {
                if (x.heSo[i] < 0) {
                    printf("%dx^%d ", x.heSo[i], i);
                } else {
                    printf("%dx^%d ", x.heSo[i], i);
                }
                soHangDau = 0;
            } else {
                if (x.heSo[i] > 0) {
                    printf("+ %dx^%d ", x.heSo[i], i);
                } else {
                    printf("%dx^%d ", x.heSo[i], i);
                }
            }
        }
    }

    if (soHangDau) {
        printf("0"); // If all coefficients are zero, print 0
    }
}


void xuatDaThuc(list l){
	int cnt = 1;
	for(node *k = l.head; k != NULL; k = k -> next){
		printf("\nda thuc thu %d: ", cnt);
		hienMotDaThuc(k -> data);
		cnt++;
	}
}

daThuc congDaThuc(daThuc a, daThuc b) {
    daThuc result;
    result.bacDaThuc = (a.bacDaThuc > b.bacDaThuc) ? a.bacDaThuc : b.bacDaThuc;
    result.heSo = (int*)malloc((result.bacDaThuc + 1) * sizeof(int));

    for (int i = 0; i <= result.bacDaThuc; i++) {
        int heSoA = (i <= a.bacDaThuc) ? a.heSo[i] : 0;
        int heSoB = (i <= b.bacDaThuc) ? b.heSo[i] : 0;
        result.heSo[i] = heSoA + heSoB;
    }

    return result;
}


void menu(list &l) {
    while (true) {
        fflush(stdin);
        system("cls");

        printf("1. nhap he so.\n");
        printf("2. xuat da thuc.\n");
        printf("3. cong hai da thuc.\n");
        printf("0. thoat.\n");

        int chon;
        printf("\n\n\t\tAN PHIM CHON: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1: {
                fflush(stdin);
                system("cls");

                daThuc x;
                nhapDaThuc(x);
                node *p = khoiTaoNode(x);
                themVaoCuoi(l, p);

                printf("\nAn phim bat ki.");
                getch();
                break;
            }
            case 2: {
                fflush(stdin);
                system("cls");

                xuatDaThuc(l);

                printf("\nAn phim bat ki.");
                getch();
                break;
            }
            case 3: {
                fflush(stdin);
                system("cls");

                if (l.head != NULL && l.head->next != NULL) {
                    daThuc result = congDaThuc(l.head->data, l.head->next->data);
                    printf("Ket qua cong hai da thuc: ");
                    hienMotDaThuc(result);
                } else {
                    printf("Can nhap it nhat hai da thuc de thuc hien phep cong.\n");
                }

                printf("\nAn phim bat ki.");
                getch();
                break;
            }
            case 0:
                exit(1);
            default: {
                fflush(stdin);
                system("cls");

                printf("\nKhong co chuc nang nay. An phim bat ki.");
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
//su dung danh sach lien ket don de cong hai da thuc
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int soMu;
	int heSo;
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

node *khoiTaoNode(int hs, int sm){
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("khoi tao that bai.");
		return NULL;
	}
	p -> soMu = sm;
	p -> heSo = hs;
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

void nhap(list &l){
	int hs,sm;
	printf("\nnhap bac da thuc: ");
	scanf("%d",&sm);
	for(int i = sm; i >= 0; i--){
		printf("\nnhap he so cua x^%d: ", i);
		scanf("%d",&hs);
		node *p = khoiTaoNode(hs,i);
		themVaoCuoi(l,p);
	}
}

void xuat(list l){
	for(node *k = l.head; k != NULL; k = k -> next) {
		printf("%d x^%d",k -> heSo, k -> soMu);
		node *p = k -> next;
		if(p != NULL){
			if(p -> heSo > 0){
				printf(" + ");
			}else if(p -> heSo < 0){
				printf(" ");
			}
		}
	}
}

void cong(list &l, list l1, list l2) {
    node *p1 = l1.head;
    node *p2 = l2.head;
    khoiTao(l); // Khởi tạo danh sách kết quả

    while (p1 != NULL && p2 != NULL) {
        if (p1->soMu > p2->soMu) {
            themVaoCuoi(l, khoiTaoNode(p1->heSo, p1->soMu)); // Thêm node của p1 vào cuối danh sách kết quả
            p1 = p1->next;
        } else if (p1->soMu < p2->soMu) {
            themVaoCuoi(l, khoiTaoNode(p2->heSo, p2->soMu)); // Thêm node của p2 vào cuối danh sách kết quả
            p2 = p2->next;
        } else {
            themVaoCuoi(l, khoiTaoNode(p1->heSo + p2->heSo, p1->soMu)); // Cộng hệ số và thêm vào cuối danh sách kết quả
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Thêm các phần tử còn lại của l1
    while (p1 != NULL) {
        themVaoCuoi(l, khoiTaoNode(p1->heSo, p1->soMu));
        p1 = p1->next;
    }

    // Thêm các phần tử còn lại của l2
    while (p2 != NULL) {
        themVaoCuoi(l, khoiTaoNode(p2->heSo, p2->soMu));
        p2 = p2->next;
    }
}


int main() {
	list l,l1,l2;
	
	khoiTao(l);
	khoiTao(l1);
	khoiTao(l2);
	
	nhap(l1);
	nhap(l2);
	
	cong(l,l1,l2);
	
	printf("\nda thuc thu 1: ");
	xuat(l1);
	printf("\nda thuc thu 2: ");
	xuat(l2);
	printf("\nda thuc 1 cong da thuc 2: ");
	xuat(l);
}
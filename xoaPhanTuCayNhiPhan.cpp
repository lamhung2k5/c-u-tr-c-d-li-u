#include <stdio.h>
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
	if(t == NULL) {
		node *p = (node*)malloc(sizeof(node));
		p -> data = x;
		p -> left = NULL;
		p -> right = NULL;
		t = p;
	}else{
		if(t -> data > x){
			themNodeVaoCay(t -> left,x);
		}else if(t -> data < x) {
			themNodeVaoCay(t -> right,x);
		}
	}
}

void duyetLNR(tree t) {
	if(t != NULL) {
		duyetLNR(t -> left);
		printf("\t%d",t -> data);
		duyetLNR(t -> right);
	}	
}


void nodeTheMang(tree &p, tree &q) {
    if (q->left != NULL) {
        nodeTheMang(p, q->left);
    } else {
        p->data = q->data;
        p = q;
        q = q->right;
    }
}

void xoaNode(tree &t, int x) {
    if (t == NULL) {
        return;
    } else {
        if (t->data > x) {
            xoaNode(t->left, x);
        } else if (t->data < x) {
            xoaNode(t->right, x);
        } else {
            node *p = t;
            if (t->left == NULL) {
                t = t->right;
            } else if (t->right == NULL) {
                t = t->left;
            } else {
                nodeTheMang(p, t -> right);
            }
            free(p);
        }
    }
}

void menu(tree &t) {
	while(true) {
		fflush(stdin);
		system("cls");
		
		printf("1. them node vao cay.\n");
		printf("2. duyet cay LNR.\n");
		printf("3. xoa mot node trong cay nhi phan.\n");
		printf("0. thoat.");
		
		printf("\n\n\t\tAN PHIM CHON: ");
		int chon;
		scanf("%d",&chon);
		
		switch(chon) {
			case 1:
			{
				fflush(stdin);
				system("cls");
				
				int x;
				printf("nhap x: ");
				scanf("%d",&x);
				themNodeVaoCay(t,x);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			case 2:
			{
				fflush(stdin);
				system("cls");
				
				duyetLNR(t);
				
				printf("\nan phim bat ki de tiep tuc.");
				getch();
				break;
			}
			
			case 3:
			{
				fflush(stdin);
				system("cls");
				
				int xoa;
				printf("nhap phan tu can xoa: ");
				scanf("%d",&xoa);
				xoaNode(t,xoa);
				
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

int main() {
	tree t;
	khoiTao(t);
	menu(t);
	return 0;
}

#include<stdio.h>
#include <string.h>

typedef struct{
	char id[20];
	char name[50];
	char author[50];
	float price;
}Book;

void bookInfo(Book books[],int *bookNum);
void printfInfo(Book books[],int bookNum);
void addBook(Book books[],int *bookNum);
void deleteBook(Book books[],int *bookNum);
void updInfo(Book books[],int bookNum);
void sortBook(Book books[],int bookNum);
void searchName(Book books[],int bookNum);

int main(){
	Book books[100] ;
	int answer,bookNum=0;
	do{
		printf("-----MENU-----\n");
		printf("1.nhap so luong va thong tin sach.\n");
		printf("2.hien thi thong tin sach.\n");
		printf("3.them sach vao vi tri.\n");
		printf("4.xoa sach theo ma sach.\n");
		printf("5.cap nhat thong tin theo ma sach.\n");
		printf("6.sap xep theo gia.\n");
		printf("7.tim kiem theo ten sach.\n");
		printf("8.thoat\n");
		printf("lua chon cua ban: ");
		scanf("%d",&answer);
		switch(answer){
			case 1:
				printf("nhap so luong sach: ");
				scanf("%d",&bookNum);
				bookInfo(books,&bookNum);
			break;
			case 2:
				printfInfo(books,bookNum);
			break;
			case 3:
				addBook(books,&bookNum);
			break;
			case 4:
				deleteBook(books,&bookNum);
			break;
			case 5:
				updInfo(books,bookNum);
			break;
			case 6:
				sortBook(books,bookNum);
			break;
			case 7:
				searchName(books,bookNum);
			break;
		}
		printf("\n----------------------------------------\n");
	}while(answer!=8);
	return 0;
}

void bookInfo(Book books[],int *bookNum){
	for(int i=0;i<*bookNum;i++){
		printf("sach thu [%d]:\n",i+1);
		printf("ma sach: ");
		getchar();
		fgets(books[i].id,20,stdin);
		books[i].id[strcspn(books[i].id, "\n")]=0;
		printf("ten sach: ");
		fgets(books[i].name,50,stdin);
        books[i].name[strcspn(books[i].name, "\n")]=0;
		printf("tac gia: ");
		fgets(books[i].author,50,stdin);
        books[i].author[strcspn(books[i].author, "\n")]=0;
		printf("gia tien: ");
		scanf("%f",&books[i].price);
	}
}

void printfInfo(Book books[],int bookNum){
	printf("\ndanh sach sach [%d]:\n",bookNum);
	printf("\n-------------------\n");
	for(int i=0;i<bookNum;i++){
		printf("sach thu [%d]\n",i+1);
		printf("ma sach: %s\n",books[i].id);
		printf("ten sach: %s\n",books[i].name);
		printf("tac gia: %s\n",books[i].author);
		printf("gia tien: %.2f\n",books[i].price);
		printf("\n-------------------\n");
	}
}

void addBook(Book books[],int *bookNum){
	int index;
	printf("vi tri ban muon them sach: ");
	scanf("%d",&index);
	if(index>=0 && index<*bookNum){
		for(int i=*bookNum;i>index;i--){
			books[i]=books[i-1];
		}
		printf("ma sach: ");
		getchar();
		fgets(books[index].id,20,stdin);
		books[index].id[strcspn(books[index].id, "\n")] = 0;
		printf("ten sach: ");
		fgets(books[index].name,50,stdin);
        books[index].name[strcspn(books[index].name, "\n")] = 0;
		printf("tac gia: ");
		fgets(books[index].author,50,stdin);
        books[index].author[strcspn(books[index].author, "\n")] = 0;
		printf("gia tien: ");
		scanf("%f",&books[index].price);
		(*bookNum)++;
	}else{
		printf("vi tri khong hop le\n");
	}
}

void deleteBook(Book books[],int *bookNum){
	char id[20];
	printf("nhap ma sach muon xoa: ");
	getchar();
	fgets(id, 20, stdin);
	id[strcspn(id, "\n")] = 0;
	for(int i=0;i<*bookNum;i++){
		if(strcmp(id, books[i].id) == 0){
			for(int j=i;j<*bookNum-1;j++){
				books[j]=books[j+1];
			}
			(*bookNum)--;
			printf("Xoa thanh cong!\n");
			return;
		}
	}
	printf("Khong tim thay ma sach!\n");
}

void updInfo(Book books[],int bookNum){
	char id[20];
	printf("nhap ma sach muon cap nhat: ");
	getchar();
	fgets(id, 20, stdin);
	id[strcspn(id, "\n")] = 0;
	for(int i=0; i<bookNum; i++){
		if(strcmp(id, books[i].id) == 0){
			printf("cap nhat thong tin cho sach ma %s:\n", id);
			printf("ten sach: ");
			fgets(books[i].name, 50, stdin);
	        books[i].name[strcspn(books[i].name, "\n")] = 0;
			printf("tac gia: ");
			fgets(books[i].author, 50, stdin);
	        books[i].author[strcspn(books[i].author, "\n")] = 0;
			printf("gia tien: ");
			scanf("%f", &books[i].price);
			printf("Cap nhat thanh cong!\n");
			return;
		}
	}
	printf("Khong tim thay ma sach!\n");
}

void sortBook(Book books[],int bookNum){
	int choose;
	Book temp;
	printf("\t1. sap xep tang dan\n");
	printf("\t2. sap xep giam dan\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choose);
	for(int i=0; i<bookNum-1; i++){
		for(int j=i+1; j<bookNum; j++){
            if((choose==1 && books[i].price > books[j].price) || (choose==2 && books[i].price < books[j].price)){
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;            
            }
		}
	}
	printf("Sap xep thanh cong!\n");
}

void searchName(Book books[],int bookNum){
	char name[50];
	printf("nhap ten sach muon tim: ");
	getchar();
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")]=0;
	int found=0;
	for(int i=0;i<bookNum;i++){
		if(strstr(books[i].name, name)!=NULL){
			printf("\nMa sach: %s\n",books[i].id);
			printf("Ten sach: %s\n",books[i].name);
			printf("Tac gia: %s\n",books[i].author);
			printf("Gia tien: %.2f\n",books[i].price);
			found=1;
		}
	}
	if(!found){
		printf("Khong tim thay ten sach\n");
	}
}


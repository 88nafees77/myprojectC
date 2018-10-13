#include<stdio.h>
#include<mysql.h>
#include"prosearch.h"
MYSQL_RES* result;
MYSQL_ROW row;
char product[100];
int main(){
	ab:
	printf("\t\tEnter product COMPANY name to be searched\n");
	scanf("%s",product);
	int f=productcheck(product);
	if(f==1){
		display(result);
	}else{
		printf("\n\tproduct not found..!\n");
		printf("\tDo you want To search Again...?\n");
		printf("\t-->1.Search Again\n\t-->2.exit\n");
		int option;
		scanf("%d",&option);
		switch(option){
			case 1:goto ab;
				break;
			case 2:printf("\tThanks for using..\n");
		}

	}
	return 0;
}

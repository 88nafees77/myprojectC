#include<stdio.h>
#include<mysql.h>
#include<string.h>
MYSQL_RES* result;
MYSQL_ROW row;
MYSQL* con;
int count=0;
char pro[100];
char price[40];
int productcheck(char *name){
	int data=0;
	con=mysql_init(NULL);
	mysql_real_connect(con,"localhost","root","admin","project",0,NULL,0);
	char old_query[100]="select productName,productPrice,Status,Rating from products where(company='%s')";
	char query[200];
	sprintf(query,old_query,name);
	mysql_query(con,query);
	result=mysql_store_result(con);
	int column=mysql_num_fields(result);
	row=mysql_fetch_row(result);
	if(row){
		 data=1;
	}
	return data;
	mysql_close(con);

}
void display(MYSQL_RES *result,int price){
	int count1=0;
	int column=mysql_num_fields(result);
	printf("\tproductName\tproductPrice\t\tStatus\t\tRating\t");
	printf("\n");
	do{
		printf("\n");
		for(int i=0;i<column;i++)
			printf("\t%s\t",row[i]);
	}while((row=mysql_fetch_row(result)));
	printf("\n");
	int option;
	main:
	printf("\t\t\t[Do you want to search again]\n");
	printf("-->0.EXIT\n-->1.AGAIN SEARCH\n-->2.Filter\n\t");
	scanf("%d",&option);
	switch(option){
		case 0:printf("bye..!!\n");
			break;
		case 1: ab:
			printf("\t\t\t[ENTER PRODUCT NAME]\n");
			scanf("%s",pro);
			con=mysql_init(NULL);
			mysql_real_connect(con,"localhost","root","admin","project",0,NULL,0);
			char old_query[100]="select productName,productPrice,Status,Rating from products where(productName='%s')";
			char query[200];
			sprintf(query,old_query,pro);
			mysql_query(con,query);
			result=mysql_store_result(con);
			while((row=mysql_fetch_row(result))){
				count++;
				for(int i=0;i<column;i++)
					printf("\t%s\t",row[i]);
			}
			printf("\n");
			if(count==0){
				printf("'Sorry product Not found...!!'\n");
			}
				break;
			printf("\n");
		case 2:
			printf("\t\t\t[ENTER THE BASE PRICE]\n");
			scanf("%d",&price);
			char old_query1[200]="select productName,productPrice,Status,Rating from products where(productPrice<%d)";
			char query1[200];
			sprintf(query1,old_query1,price);
			mysql_query(con,query1);
			result=mysql_store_result(con);
			while((row=mysql_fetch_row(result))){
				count1++;
				printf("\t");
				for(int i=0;i<column;i++)
					printf("\t%s\t",row[i]);
				printf("\n");
			}
			if(count1==0)
				printf("\tproduct not found..\n");
			printf("\n");
			break;
		}
	printf("\t\t\t[DO YOU WANT TO SEARCH AGAIN...?]\n");
	printf("\t\t[[press 'Y' for YES or press 'N' for NO or Press 'M' for main menu]]\n");
	char op;
	scanf("%s",&op);
	switch(op){
		case 'y':goto ab;
			break;
		case 'n':printf("Thanks for using....\n");
			break;
		case 'm':goto main;
			break;
	}
}

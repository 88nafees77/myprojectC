#include<stdio.h>
#include<mysql.h>
int main(){
	MYSQL* con=mysql_init(NULL);
	if(con==NULL)
		printf("connection not established\n");
	if((mysql_real_connect(con,"localhost","root","admin",NULL,0,NULL,0))==NULL)
		printf("invalid username or password\n");
	mysql_query(con,"create database project");
	mysql_close(con);
	MYSQL* conn=mysql_init(NULL);
	mysql_real_connect(con,"localhost","root","admin","project",0,NULL,0);
	mysql_query(con,"create table products(id int(10) primary key,productName varchar(20),productPrice varchar(10),productCategory varchar(20),Rating varchar(5),Discount varchar(10));");
	mysql_close(con);
	return 0;
}

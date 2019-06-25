#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int len_punkt=15; 
struct aeroflot
{
    char name[len_punkt];
    int reys;
    int tip;
};
const int size_p=sizeof(aeroflot); 

int create_file(FILE *fbin);
int sort_file(FILE *fbin);
int print_file(FILE *fbin);
int search(FILE *fbin); 

int main() 
{ 
	setlocale(0,"RUS");
	FILE *fbin;  
	char c;  
	fbin=fopen("aeroflot.txt","r+b"); 
	if (!fbin) 
	{   
		fbin=fopen("aeroflot.txt","w+b"); 
		if(!fbin)
		{    
			puts("�� ���� ������� (�������) ����\n");    
			return 1;   
		} 
	}

  while (1)       
  {  
	  system("CLS"); 
	  puts("1- ������ � ����");   
	  puts("2- ���������� �����");   
	  puts("3- ����� �����");   
	  puts("4- ����� �� ������ ����������");   
	  puts("5- �����");   
	  puts("______________________________");   
	  puts("������� ����� ������ ����:\n");   
	  c=getch();   
	  switch (c)                 
	  { 
		  case '1':create_file(fbin); break;   
		  case '2':sort_file(fbin); break;   
		  case '3':print_file(fbin); break;  
		  case '4':search(fbin); break; 
		  case '5':return 0;         
	  }  
  } 
}

int create_file(FILE *fbin)
{  
	aeroflot elem; 
	fseek(fbin,0,SEEK_END); 
	while (1) 
	{   
		puts("������� ����� ���������� (��� ������ *):");  
		scanf("%s",&elem.name);
		if (!strcmp(elem.name,"*"))   return 1;
		puts("������� ����� �����:");   
		scanf("%i",&elem.reys);
		puts("������� ��� ������� (1-��������; 2-������������):");   
		scanf("%i",&elem.tip);
		puts("_____________________________________________");  
		fwrite(&elem,size_p,1,fbin);
	} 
} 

int print_file(FILE *fbin)
{  
	aeroflot elem;  
	int n; 
	system("CLS"); 
	rewind(fbin);
	puts("����� ���������� | ����� ����� | ��� �������");  
	puts("---------------------------------------------");  
	do 
	{   
		n=fread(&elem,size_p,1,fbin);
		if (n<1) break; 
		printf("%-19s%-20i%i\n",elem.name,elem.reys,elem.tip);       
	} 
	while (1); 
	puts("_____________________________________________");  
	puts("������� ����� �������");  
	getch();  
	return 0; 
} 

int sort_file(FILE *fbin) 
{  
	long i,j;  
	aeroflot elem1,elem2; 
	puts("�������������!");  
	getch();  
	fseek(fbin,0,SEEK_END);
	long len=ftell(fbin)/size_p;
	rewind(fbin);
	for(i=len-1;i>=1;i--)     
		for (j=0;j<=i-1;j++) 
		{   
			fseek(fbin,j*size_p,SEEK_SET); 
			fread(&elem1,size_p,1,fbin);  
			fread(&elem2,size_p,1,fbin);
			if (strcmp(elem1.name,elem2.name)>=1) 
			{    
				fseek(fbin,(-2)*size_p,SEEK_CUR);      
				fwrite(&elem2,size_p,1,fbin);   
				fwrite(&elem1,size_p,1,fbin); 
			}     
		}  
	return 0; 
}

int search(FILE *fbin)
{  
	int not_found;
	char s[len_punkt];
	int n;
	aeroflot elem;
	while (1)
	{   
		puts("_____________________________________________"); 
		puts("������� ����� ���������� (��� ������ *):");   
		cin.getline(s,len_punkt);
		if (!strcmp(s,"*"))  break; 
		rewind(fbin);
		not_found=1;
		do 
		{     
			n=fread(&elem,size_p,1,fbin);  
			if (n<1) break; 
			if (strstr(elem.name,s))   
			{      
				strcpy(s,elem.name);         
				puts("����� ���������� | ����� ����� | ��� �������");       
				printf("%-19s%-20i%i\n",elem.name,elem.reys,elem.tip);                 
				not_found=0;   
			}   
		} 
		while (1);   
		if (not_found)   puts("������ ������ ���������� ��� � �����");  
	}  
	return 0; 
} 

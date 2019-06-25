#include <stdio.h> 
#include <string.h> 
#include <conio.h> 

const int len_fio=15; 
struct person 
{ 
	char fio[len_fio];
	int year;
	float salary;
};
const int size_p=sizeof(person); //������ ���������

int create_file(FILE *fbin);
int sort_file(FILE *fbin);
int print_file(FILE *fbin);
int search_persons(FILE *fbin); 

int main() 
{ 
	FILE *fbin;  
	char c;  
	fbin=fopen("person.dat","r+b"); //�������� ������������� �����        
	//��� ������ � ������ � �����  
	if (!fbin) 
	{   
		fbin=fopen("person.dat","w+b"); //�������� ������ �����         
		//��� ����������    
		if(!fbin)
		{    
			puts("�� ���� ������� (�������) ����\n");    
			return 1;   
		} 
	}

  while (1)       
  {  
	  clrscr();   
	  puts("1- ������ � ����");   
	  puts("2- ���������� �����");   
	  puts("3- ����� �����");   
	  puts("4- ����� � ����������");   
	  puts("5- �����");   
	  puts("______________________________");   
	  puts("������� ����� ������ ����\n");   
	  c=getch();   
	  switch (c)                 
	  { 
		  case '1':create_file(fbin); break;   
		  case '2':sort_file(fbin); break;   
		  case '3':print_file(fbin); break;   
		  case '4':search_persons(fbin); break;   
		  case '5':return 0;         
	  }  
  } 
}

int create_file(FILE *fbin)
{  
	person elem; 
	fseek(fbin,0,SEEK_END); 
	puts("���� ������ � �����������");  
	puts("��� ������ ������� ������ *");  
	puts("_________________________________\n");  
	while (1) 
	{   
		puts("������� �.�.�. (����������� � ����������)");   
		getline(elem.fio,len_fio);  
		if (!strcmp(elem.fio,"*"))   return 1;
		puts("������� ��� ��������");   
		scanf("%i",&elem.year);
		puts("������� ��������");   
		scanf("%f",&elem.salary);
		fwrite(&elem,size_p,1,fbin);
	} 
} 

int print_file(FILE *fbin)
{  
	person elem;  
	int n; 
	clrscr();  
	rewind(fbin);   //��������� � ������ �����
	puts("�.�.�.         ���   ��������");  
	do 
	{   
		n=fread(&elem,size_p,1,fbin);	//������ ��������� �� �����   
		if (n<1) break;    //���� n<1, �� ����� �����   
		printf("%-15s%-6i%-8.2f\n",elem.fio,elem.year,elem.salary);       
	} 
	while (1); 
	puts("_____________________________");  
	puts("������� ����� �������");  
	getch();  
	return 0; 
} 

int sort_file(FILE *fbin) 
{  
	long i,j;  
	person elem1,elem2; 
	puts("��� ���������� ������� ����� �������");  
	getch();  
	fseek(fbin,0,SEEK_END); //��������� � ����� 
	long len=ftell(fbin)/size_p; //���������� ����� �����  
	rewind(fbin);   //��������� � ������  
	//����������� ����������  
	for(i=len-1;i>=1;i--)     
		for (j=0;j<=i-1;j++) 
		{   
			fseek(fbin,j*size_p,SEEK_SET);  //��������� �� j-�� ������   
			fread(&elem1,size_p,1,fbin);  //������ ������ j � elem1   
			fread(&elem2,size_p,1,fbin);  //������ ����. ������ � elem2   
			if (strcmp(elem1.fio,elem2.fio)>=1) 
			{   //���������� �.�.�.       
				fseek(fbin,(-2)*size_p,SEEK_CUR);   //��������� �� 2 ���. �����       
				//����� ��������           
				fwrite(&elem2,size_p,1,fbin);  //������� ���������� elem2       
				fwrite(&elem1,size_p,1,fbin); // ����� ���������� elem1   
			}     
		}  
	puts("��� ������ ������� ����� �������");  
	getch();  
	return 0; 
}

int search_persons(FILE *fbin)
{  
	int not_found;   //����  ������   
	char s[len_fio];   //������ ��� ����� �������  
	int n_persons=0;   //������� �����������  
	int n;  float summa_salary=0;  //����� �������  
	person elem;  
	while (1) 
	{   
		puts("������� ������� ���  * ");   
		cin.getline(s,len_fio);  //���������� ������� � ������ s   
		if (!strcmp(s,"*"))  break;  //�����, ���� ����� *   
		rewind(fbin);   //��������� � ������ �����   
		not_found=1;   //���� � ��������� �� ������   
		do 
		{     
			n=fread(&elem,size_p,1,fbin);  //������ ������     
			if (n<1) break;    // ���� n<1, �� ����� �����     
			if (strstr(elem.fio,s))   //���� ������ s � ���� fio       
			if (elem.fio[strlen(s)]==' ') 
			{
				//���� ������ ����� ������� ?         
				strcpy(s,elem.fio);  //�������� fio � s         
				puts("_____________________________");         
				puts("�.�.�.         ���   ��������");         
				printf("%-15s%-6i%-8.2f\n",elem.fio,elem.year,elem.salary);         
				puts("_____________________________");         
				n_persons+=1;   //������� �����������         
				summa_salary+=elem.salary; //������������ ������� 
				not_found=0;    //��������� ������       
			}   
		} 
		while (1);   
		if (not_found)   puts("������ ���������� ��� � �����");  
	}  
	if (n_persons>0)	printf("������� ��������=%8.2f\n",summa_salary/n_persons);  
	puts("__________________________");  
	puts("������� ����� �������");  
	getch();  
	return 0; 
} 

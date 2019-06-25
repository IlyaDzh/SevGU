#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 

const int len=20;

struct stud  
{ 
	char fio[len]; 
	float f, i, m; 
	stud* next;
}; 

stud* dob(stud* end, const stud& z);
stud* dob_first(const stud& z); 
stud* udal(stud* beg);
stud vvod_studa(); 
int  menu();  
void print(const stud& z);   
void prosmotr(stud* beg);  
int  read_file(char* filename, stud** beg, stud** end); 
int  write_file(char* filename, stud* temp);
void ocenki(stud *beg); 
void best(stud *beg);
stud* del_index(stud* beg,int index);
stud* addsort(stud *beg, const stud& z);

int main() 
{    
	setlocale(0,"RUS"); 
	int index=0;
	stud *beg=0, *end=0;     
 	char *filename=(char *)"123.txt";     
 	read_file(filename,&beg, &end); 
 	while (1)  
	{ 
		switch (menu())	  
		{ 
		case 1: if (beg) end=dob(end,vvod_studa());   
				else
				{ 
					beg=dob_first(vvod_studa()); 
					end=beg;
				}      
				break;  
		case 2: beg=udal(beg);           
				cout<<"������� ����� �������"<<endl;      
				cin.get();      
				break;  
		case 3: prosmotr(beg); 
				break;  
		case 4: ocenki(beg);
				break; 
		case 5: best(beg);
				break; 
		case 6: cout<<"������� ����� ���������� ��������: "; cin>>index;
				del_index(beg,index);
				break; 
		case 7: addsort(beg,vvod_studa());
				break;  		
		case 8: write_file(filename,beg);  
				break;  
		case 9: return 0;  
		default:    
				cout<<"��� ������� ������ ����� �� 1 �� 9"<< endl;      
				cin.get();      
				break;  
		}       
	} 
} 

stud* dob(stud *end,const stud& z)
{         
	stud *newE=new stud;
	*newE=z;
	newE->next=0; 
	end->next=newE; 
	end=newE;
	return end; 
} 

stud* dob_first(const stud& z)  
{ 
	stud *beg=new stud;
	*beg=z;
	beg->next=0; 
	return beg;
} 

stud* udal(stud *beg)
{
  	stud *p=beg;
    while (p->next)
  	{
    	stud *temp;
       	temp = p;
        p = p->next;
    	delete temp;
  	}
  	p=p->next;
  	delete []p;
  	beg=NULL;
	return beg;
}

stud vvod_studa()  
{   
	char buf[10];  
	stud z;  
	cout<<"������� �.�.�.:"<<endl;  
	cin.getline(z.fio,len);  
	cout<<"������� ������ �� ������:"<<endl; 
	cin>>z.f;
	cout<<"������� ������ �� �������:"<<endl; 
	cin>>z.i;
	cout<<"������� ������ �� ����������:"<<endl; 
	cin>>z.m;
	
	return z; 
} 

int menu() 
{  
	char buf[10];  
	int item;  
	do    
	{
		system("CLS");      
		cout<<"1- ���������� �������� � ������"<<endl;     
		cout<<"2- �������� ���� ���������"<<endl;    
		cout<<"3- �������� ������"<<endl; 
		cout<<"4- ������������ �� ���������"<<endl; 
		cout<<"5- �������� �� ������� ������ ����� 5"<<endl; 
		cout<<"6- �������� �������� �� ������"<<endl; 
		cout<<"7- ���������� �������� � ���������������"<<endl;
		cout<<"8- ������ ������ � ����"<<endl;     
		cout<<"9- �����"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"������� ����� ������ ����"<<endl;     
		cin>>buf;  
		cin.get();     
		item=atoi(buf);  
		if (!item) 
		{                  
			cout<<"��� ������� ������� ����� �� 1 �� 9"<<endl;                     
			cin.get();                     
		}  
	} 
	while (!item); 
	return item;
} 

void print(const stud& z)  
{ 
	cout<<"�.�.�.: " <<z.fio<<endl;  
	cout<<"������ �� ������: "<<z.f<<endl; 
	cout<<"������ �� �������: "<<z.i<<endl; 
	cout<<"������ �� ����������: "<<z.m<<endl; 
} 

void prosmotr(stud *beg)  
{ 
	if (!beg) 
	{ 
		cout<<"������� ������"<<endl; 
		return;  
	}  
	stud *temp=beg;
	cout<<"=============================="<<endl;  
	while (temp) 
	{  
		print(*temp);
		cout<<"=============================="<<endl;   
		cout<<"������� ����� �������"<<endl;   
		cin.get();   
		temp=temp->next;
	} 
} 

int read_file(char* filename,stud** beg, stud** end)  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) { cout<<"��� �����"<<filename<<endl; return 1;}   
	stud z;  
	*beg = 0;  
	while (fin.getline(z.fio,len))
    {          
		fin>>z.f;   
		fin>>z.i;   
		fin>>z.m;      
		fin.get();         
		if (*beg) *end=dob(*end,z);       
		else       
		{ *beg=dob_first(z); *end=*beg; }
	}  
	return 0; 
} 

int write_file(char* filename, stud* temp)  
{ 
	ofstream fout(filename);  
	if (!fout) {cout<<"�� ���� ������� ���� ��� ������"<<endl; return 1;}  
	while (temp)  
	{  
		fout<<temp->fio<<endl; 
		fout<<temp->f<<endl;     
		fout<<temp->i<<endl;     
		fout<<temp->m<<endl;      
		temp=temp->next; 
	}  
	cout<<"������ ��������� � �����: "<<filename<<endl;  
	cout<<"=============================="<<endl;  
	cout<<"������� ����� �������"<<endl;  
	cin.get();  
	return 0; 
} 

void ocenki(stud *beg)  
{
	float sum1, sum2, sum3, c=0;
	stud *temp;
	temp=beg;
	while (temp)
	{
		sum1+=temp->f;
		sum2+=temp->i;
		sum3+=temp->m;
		c++;
		temp=temp->next;
	}
	cout<<"������� ������ �� ������:"<<sum1/c<<endl;
	cout<<"������� ������ �� �������:"<<sum2/c<<endl;
	cout<<"������� ������ �� ����������:"<<sum3/c<<endl;
	cin.get(); 
}

void best(stud *beg)  
{
	float f1, i1, m1=0;
	stud *temp;
	temp=beg;
	while (temp)
	{
		if (temp->f==5) f1++;
		if (temp->i==5) i1++;
		if (temp->m==5) m1++;
		temp=temp->next;
	}
	if (f1>i1 && f1>m1) cout<<"�� ������ ������ ����� '5'";
	if (i1>f1 && i1>m1) cout<<"�� ������� ������ ����� '5'";
	if (m1>i1 && m1>f1) cout<<"�� ���������� ������ ����� '5'";
	if (f1==i1 && f1==m1 && i1==m1) cout<<"�� ��������� ���������� ���������� '5'";
	cin.get(); 
}

stud* del_index(stud* beg,int index)
{
    stud* p=0;
    stud* temp=beg;
    int i=1;
    while(temp)
    {
        if(i==index)
        {
            if(p) p->next=temp->next;
            else beg=temp->next;
            delete temp;
            return beg;
        }
        i++;
        cout<<i;
        p=temp;
        temp=temp->next;
    }
    return beg;
}

stud* addsort(stud *beg, const stud& z) 
{ 
	stud* elem=beg; 
	while(elem->next!=NULL) 
	{ 
		if (strcmp(z.fio, elem->fio)>0) 
		{ 
			stud *newE=new stud; 
			*newE=z; 
			newE->next=elem->next; 
			elem->next=newE; 
		} 
		elem=elem->next; 
	} 
}

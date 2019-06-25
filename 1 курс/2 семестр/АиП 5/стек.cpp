#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
//----------------------------���������----------------------------------------------- 
const int d_o=20, d_n=20;
 //-----------------------��������� ��������----------------------------------------- 
struct zakaz  
{ 
	int nomer;
	char otpravlenie[d_o], naznachenie[d_n];       
	float price, time_o, time_p;
	zakaz* next;
}; 
//------------------------��������� �������----------------------------------------- 
zakaz* dob(zakaz* beg, const zakaz& z);
zakaz* add_end(zakaz *beg,const zakaz& z);
zakaz* dob_first(const zakaz& z);
zakaz* udal(zakaz* beg); 
zakaz vvod_zakaza();
int  menu();
void print(const zakaz& z);
void prosmotr(zakaz* beg);
int  read_file(char* filename, zakaz** beg, zakaz** end);
int  write_file(char* filename, zakaz* temp);
//-------------------------�������� �������------------------------------ 
int main() 
{    
	setlocale(0,"RUS"); 
	zakaz *beg=0,     //��������� ������ �������         
	*end=0;    //��������� ����� �������       
 	char *filename="123.txt";          
 	read_file(filename,&beg, &end); //������ ������ �� ����� � ������� 
 	while (1)  
	{ 
		switch (menu())		//���������� ���� � ������� �����     
		{ 
		case 1: if (beg)     //���� ������� �� ������, 
			  		beg=dob(beg,vvod_zakaza()); 	//�� ��������� ������� � �����,     
				else {  
					  beg=dob_first(vvod_zakaza());//������� ������ ������� �������.   
					  end=beg;     //��������� ������ � ����� �����   
					 }      
				break;  
		case 2: end=add_end(end,vvod_zakaza());       
				break;  
		case 3: beg=udal(beg);        
				cout<<"������� ����� �������"<<endl;      
				cin.get();      
				break;  
		case 4: prosmotr(beg);  
				break;  
		case 5: write_file(filename,beg);   
				break;  
		case 6: return 0;  
		default:    
				cout<<"��� ������� ������ ����� �� 1 �� 5"<< endl;      
				cin.get();      
				break;  
		}       
	} 
} 
//-----------------------���������� ��������----------------------------- 
zakaz* dob(zakaz *beg,const zakaz& z)
{         
	zakaz *newE=new zakaz;
	*newE=z;
	newE->next=beg;  
	beg=newE; 
	return beg; 
} 
//----------------------�������� ������� ��������------------------------ 
zakaz* dob_first(const zakaz& z)  
{ 
	zakaz *beg=new zakaz;   //��������� ������ ��� �������  
	*beg=z;     //��������� �������� ��������  
	beg->next=0;    //������ �� ��������� ��-� �������  
	return beg;     //������� ��������� �� ������� 
} 
// ---------------- ������ � �������� ��������--------------------------- 
zakaz* udal(zakaz *beg)  
{ 
	zakaz *temp;  
	if (!beg) { cout<<"������� ������"<<endl; return 0; }  
	cout<<"=============================="<<endl;  
	print(*beg);    //������ �������� ��������� ��-��  
	cout<<"=============================="<<endl;  
	temp=beg;     //��������� ��������� �� ������  
	beg=beg->next;    //������� beg �� ��������� ��-�  
	delete temp;    //�������� ��������   
	return beg;     //������� ���������� �������� beg 
} 
//-------------------���� �������� ��������------------------------------ 
zakaz vvod_zakaza()  
{   
	zakaz z;  
	cout<<"������� ������� �����������:"<<endl;  
	cin.getline(z.otpravlenie,d_o);  
	cout<<"������� ������� ����������:"<<endl;  
	cin.getline(z.naznachenie,d_n);  
	cout<<"������� ����� �����������:"<<endl;  
	cin>>z.time_o; 
	cout<<"������� ����� ��������:"<<endl;  
	cin>>z.time_p; 
	cout<<"������� ��������� ������:"<<endl;  
	cin>>z.price; 
	cout<<"������� ����� ������:"<<endl;  
	cin>>z.nomer; 
	return z; 
} 
//-----------------����������� ���� �  ���� ������ ����----------------------- 
int menu() 
{  
	char buf[10];  
	int item;  
	do    
	{
		system("CLS");       
		cout<<"1- ���������� �������� � ����"<<endl;    
		cout<<"2- ���������� �������� � �����"<<endl;  
		cout<<"3- �������� ��������"<<endl;    
		cout<<"4- �������� �����"<<endl; 
		cout<<"5- ������ ������ � ����"<<endl;     
		cout<<"6- �����"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"������� ����� ������ ����:"<<endl;     
		cin>>buf;    
		cin.get();     
		item=atoi(buf);    //������������� ��� � �����     
		if (!item) 
		{                    
			cout<<"��� ������� ������� ����� �� 1 �� 5"<<endl;                     
			cin.get();                     
		}  
	} 
	while (!item);
	return item;
} 
// -----------------------------������ ������----------------------------- 
void print(const zakaz& z)  
{ 
	cout<<"������� �����������: " <<z.otpravlenie <<endl;  
	cout<<"������� ����������: "<<z.naznachenie <<endl;  
	cout<<"����� �����������: "<<z.time_o <<endl;  
	cout<<"����� ��������: "<<z.time_p <<endl;  
	cout<<"��������� ������: "<<z.price <<endl; 
	cout<<"����� ������: " <<z.nomer <<endl; 
} 
//----------------------------�������� �������--------------------------- 
void prosmotr(zakaz *beg)  
{ 
	if (!beg) 
	{ 
		cout<<"������� ������"<<endl; 
		cout<<"������� ����� �������"<<endl;   
		cin.get(); 
		return;  
	}  
	zakaz *temp=beg;
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
// ------------------------------������ �� �����----------------------------- 
int read_file(char* filename,zakaz** beg, zakaz** end)  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) { cout<<"��� �����" <<filename<<endl; return 1;}   
	zakaz z;  
	*beg = 0;  
	while (fin.getline(z.otpravlenie,d_o))
    {    
		fin.getline(z.naznachenie,d_n);    
		fin>>z.time_o;     
		fin>>z.time_p; 
		fin>>z.price; 
		fin>>z.nomer;      
		fin.get();         
		if (*beg) *beg=dob(*beg,z);      
		else      
		{ *beg=dob_first(z); *end=*beg; }
	}  
	return 0; 
} 
// ----------------------------������ � ���� ---------------------------- 
int write_file(char* filename, zakaz* temp)  
{ 
	ofstream fout(filename); 
	if (!fout) {cout<<"�� ���� ������� ���� ��� ������"<<endl; return 1;}  
	while (temp) 
	{  
		fout<<temp->otpravlenie <<endl;    
		fout<<temp->naznachenie <<endl;    
		fout<<temp->time_o <<endl;     
		fout<<temp->time_p <<endl;
		fout<<temp->price <<endl; 
		fout<<temp->nomer <<endl;
		temp=temp->next;
	}  
	cout<<"������ ��������� � �����: "<<filename<<endl;  
	cin.get();  
	return 0; 
} 
// -------------------���������� �������� � �����------------------------
zakaz* add_end(zakaz *beg,const zakaz& z) 
{
	zakaz *temp=beg;
	zakaz *newE = new zakaz;
	newE->next = NULL;
	while (!temp->next == NULL) 
	{
		temp = temp->next;
	}
	temp->next = newE;
}

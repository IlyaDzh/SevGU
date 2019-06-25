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
const int d_n=20,    //����� �.�.�.       
		  d_m=20,    //����� �������� ������ ����������       
		  d_w=80;    //����� ������ �������� ����� 
 //-----------------------��������� ��������----------------------------------------- 
struct zakaz  
{ 
	char name[d_n],   //�.�.�.           
	model[d_m],  //�������� ������ ����������           
	work[d_w];   //�������� ������  
 	time_t time;   //����� ������ ������  
	float price;    //���������  
	zakaz* next;   //��������� �� ��������� ������� 
}; 
//------------------------��������� �������----------------------------------------- 
zakaz* dob(zakaz* end, const zakaz& z); //���������� �������� � ������� 
zakaz* dob_first(const zakaz& z);  //���������� ������� �������� 
zakaz* udal(zakaz* beg);   //�������� �������� �� ������� 
zakaz vvod_zakaza();    //���� �������� �������� 
int  menu();     //����������� ���� � ���� ��� ������ 
void print(const zakaz& z);   //����� ��������  �������� 
void prosmotr(zakaz* beg);   //�������� ������� 
int  read_file(char* filename, zakaz** beg, zakaz** end);  //������ ����� 
int  write_file(char* filename, zakaz* temp);   //������ � ���� 
//-------------------------�������� �������------------------------------ 
int main() 
{    
	setlocale(0,"RUS"); 
	zakaz *beg=0,     //��������� ������ �������         
	*end=0;    //��������� ����� �������       
 	char *filename="123.txt";  //��� �����       
 	time_t now;      // ������� �����       
 	tm t;      // ����       
 	read_file(filename,&beg, &end); //������ ������ �� ����� � ������� 
 	while (1)  
	{ 
		switch (menu())		//���������� ���� � ������� �����     
		{ 
		case 1: if (beg)     //���� ������� �� ������, 
			  		end=dob(end,vvod_zakaza()); 	//�� ��������� ������� � �����,     
				else {     //�����   
					  beg=dob_first(vvod_zakaza());//������� ������ ������� �������.   
					  end=beg;     //��������� ������ � ����� �����   
					 }      
				break;  
		case 2: beg=udal(beg);    //������ � �������� ��������     
				now = time(0);    //�������� ������� ����� � ���.      
				t = *(localtime(&now));  //�������������  � ����      
				cout<<"���� ���������� ������: " //����� ����   
					<<t.tm_mday<<'.'<<t.tm_mon+1<<'.'<<1900+t.tm_year<<endl;      
				cout<<"������� ����� �������"<<endl;      
				cin.get();      
				break;  
		case 3: prosmotr(beg);    //�������� �������      
				break;  
		case 4: write_file(filename,beg);  //������ � ����      
				break;  
		case 5: return 0;  
		default:     //���� ������� ������ ����� ������      
				cout<<"��� ������� ������ ����� �� 1 �� 5"<< endl;      
				cin.get();      
				break;  
		}       
	} 
} 
//-----------------------���������� ��������----------------------------- 
zakaz* dob(zakaz *end,const zakaz& z)    //���������� ��������� �� ���. ��-� 
{         
	zakaz *newE=new zakaz;  //��������� ������ ��� �������  
	*newE=z;     //��������� �������� ��������  
	newE->next=0;    //������ �� ��������� ��-� �������   
	end->next=newE;   //�������� ��-� � �������  
	end=newE;     //���������� ��������� end �� newE   
	return end;     //������� ���������� �������� end 
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
	char buf[10];  
	zakaz z;  
	cout<<"������� �.�.�."<<endl;  
	cin.getline(z.name,d_n);  
	cout<<"������� ������ ����������"<<endl;  
	cin.getline(z.model,d_m);  
	cout<<"������� �������� ������"<<endl;  
	cin.getline(z.work,d_w);  
	z.time=time(0);    //������������� ����� � ���� time  
	do       //�������� ����� �����   
	{  
		cout<<"������� ��������� ������"<<endl;     
		cin>>buf;  
	} 
	while (!(z.price=(float)atof(buf)));  
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
		cout<<endl;     
		cout<<"===������� ����� �������==="<<endl<<endl;     
		cout<<"1- ���������� �������� � �������"<<endl;     
		cout<<"2- ������ � �������� ��������"<<endl;    
		cout<<"3- �������� �������"<<endl; 
		cout<<"4- ������ ������ � ����"<<endl;     
		cout<<"5- �����"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"������� ����� ������ ����"<<endl;     
		cin>>buf;     //��������� ��������� ��������     
		cin.get();     
		item=atoi(buf);    //������������� ��� � �����     
		if (!item) 
		{    //������ ������ �����                      
			cout<<"��� ������� ������� ����� �� 1 �� 5"<<endl;                     
			cin.get();                     
		}  
	} 
	while (!item);   //��������� ���� �� ������ �����  
	return item;   //������� ����� ���������� ������ ���� 
} 
// -----------------------------������ ������----------------------------- 
void print(const zakaz& z)  
{ 
	tm t=*(localtime(&z.time));  
	cout<<"�.�.�.: " <<z.name<<endl;  
	cout<<"������ ����������: "<<z.model<<endl;  
	cout<<"�������� �����: "<<z.work<<endl;  
	cout<<"����  ������: "<<t.tm_mday<<'.'<<t.tm_mon+1<<'.'<<1900+t.tm_year<<endl;  
	cout<<"���������: "<<z.price<<endl; 
} 
//----------------------------�������� �������--------------------------- 
void prosmotr(zakaz *beg)  
{ 
	if (!beg) 
	{ 
		cout<<"������� ������"<<endl; 
		return;  
	}  
	zakaz *temp=beg;  //��������� temp ������������� � ������  
	cout<<"=============================="<<endl;  
	while (temp) 
	{   //������������� ���� temp!=0   
		print(*temp);  //�������� �������� �������� �� ���������   
		cout<<"=============================="<<endl;   
		cout<<"������� ����� �������"<<endl;   
		cin.get();   
		temp=temp->next; //���������� temp �� ��������� ��-�  
	} 
} 
// ------------------------------������ �� �����----------------------------- 
int read_file(char* filename,zakaz** beg, zakaz** end)  
{ 
	ifstream fin(filename,ios::in); //�������� �����  
	if (!fin) { cout<<"��� �����"    //����� ���� ��� �����   
					<<filename<<endl; return 1;}   
	zakaz z;  
	*beg = 0;  
	while (fin.getline(z.name,d_n))   //������ ��� ���� �� ����� �����  
    {    
		fin.getline(z.model,d_m);   //������ �����  ����������         
		fin.getline(z.work,d_w);   //������ �������� ������         
		fin>>z.time>>z.price;   //������ ������� � ���������         
		fin.get();         
		if (*beg)     //���� ������� �� ������,       
			*end=dob(*end,z);   //�� ��������� ������� � �����,         
		else      //�����      
		{ *beg=dob_first(z); *end=*beg; } //������� ������ �������  
	}  
	return 0; 
} 
// ----------------------------������ � ���� ---------------------------- 
int write_file(char* filename, zakaz* temp)  
{ 
	ofstream fout(filename);   //�������� �����  
	if (!fout) {cout<<"�� ���� ������� ���� ��� ������"<<endl; return 1;}  
	while (temp)     //���� temp!=0 ������� ��-�� � ����     
	{  
		fout<<temp->name<<endl; //����� ���        
		fout<<temp->model<<endl; //����� ����� ����������        
		fout<<temp->work<<endl; //����� �������� �����        
		fout<<temp->time<<' '<<temp->price<<endl; //����� � ���������        
		temp=temp->next;   //����������� ��������� �� ����. ��-�  
	}  
	cout<<"������ ��������� � �����: "<<filename<<endl;  
	cout<<"=============================="<<endl;  
	cout<<"������� ����� �������"<<endl;  
	cin.get();  
	return 0; 
} 

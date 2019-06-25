#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
//----------------------���������----------------------------------------- 
const int d_on=80;
//---------------------���������------------------------------------------- 
struct zakaz
{
	int nomer;
	char otp_naz[d_on];    
	float price, time_o, time_p;
}; 
struct node     
{ 	zakaz data; 
	node* left;  
	node* right;  
}; 
//-------------��������� �������-------------------------------------- 
node* addtree(node *top,const zakaz& newnode);
int menu();
int search(node *top, char a,int &level);
void otobr(node *top, int otstup);
void prosmotr(node *top); 
int write_file(ofstream &f, node* top);
int read_file(char* filename, node* &top);
zakaz vvod();
//-------------------------�������� �������------------------------------ 
int main() 
{      
	setlocale(0,"RUS"); 
	node *top=0;       
	char *filename="aero.txt";      
	ofstream fout;   
	read_file(filename,top);      
	while (1)        
	{   
		switch (menu())
		{
			case 1:       
				top=addtree(top,vvod());      
				break;  
			case 2:    
				otobr(top,1);      
				cout<<"������� ����� ������� "<<endl; cin.get();      
				break;  
			case 3:    
				prosmotr(top);      
				cout<<"������� ����� ������� "<<endl; cin.get();      
				break;  
			case 4:    
				{
					int level=1;     
					char a[d_on];      
					cout<<"������� �������"<<endl;      
					cin>>a[d_on];         
					cout<<"������� ��������� �� ������:"<<search(top,a,level)<<endl;      
					cout<<"������� ����� ������� "<<endl; cin.get();      
		  			break;  
	  			}
	  		case 5:    
	  			fout.open(filename);     
	  			if (!fout){cout<<"������ �������� �����"<<endl; return 1;}      
	  			write_file(fout,top);   
	  			cout<<"������ ��������� � �����: "<<filename<<endl;      
	  			cout<<"=============================="<<endl;      
	  			fout.close();      
	  			cout<<"������� ����� ������� "<<endl; cin.get();      
	  			break;  
	  		case 6:     
	  			return 0;  
	  		default:   
	  			cout<<"��� ������� ������ ����� �� 1 �� 6"<< endl; cin.get();      
	  			break;  
	  }       
	} 
} 
//-----------------------���������� ���� � ������------------------------- 
node* addtree(node *top,const zakaz& newnode)  
{ 
	if (!top)    
	{
		top=new node;
		if (!top) 
		{
			cout<<"�� ������� ������"<<endl; 
			return NULL;  
		}   
		top->data=newnode;  
		top->left=NULL;  
		top->right=NULL;  
	}  
	else 
		if (strcmp(top->data.otp_naz,newnode.otp_naz)>0) 
			top->left=addtree(top->left,newnode);  
		else top->right=addtree(top->right,newnode);
	return top; 
} 
// ----------------����������� ��������� ������--------------------------- 
void otobr(node *top, int otstup)  
{ 
	if (top)    
	{
		otstup+=3; 
		otobr(top->right,otstup); 
		cout<<setw(otstup)<<'*'<<top->data.otp_naz<<endl;   
		otobr(top->left,otstup);
	} 
} 
// ----------------�������� ������---------------------------------------- 
void prosmotr(node *top)
{ 
	if (top)    
	{
		cout<<top->data.otp_naz<<endl; 
		cout<<top->data.nomer<<endl;   
		cout<<top->data.price<<endl;
		cout<<top->data.time_o<<endl;
		cout<<top->data.time_p<<endl;
		prosmotr(top->left); 
		prosmotr(top->right);
	} 
} 
//-------------------���� ������------------------------------------------ 
zakaz vvod()  
{ 
	zakaz p;  
	cout<<"������� ����� �����������-����� ����������"<<endl;  
	cin.getline(p.otp_naz,d_on);  
	cout<<"������� ����� �����"<<endl;  
	cin>>p.nomer;
	cout<<"������� ����� �����������"<<endl;  
	cin>>p.time_o;
	cout<<"������� ����� ��������"<<endl;  
	cin>>p.time_p;
	cout<<"������� ����"<<endl;  
	cin>>p.price;
	return p; 
} 
//---------------����������� � ���� ������� ����----------------- 
int menu()  
{ 
	char buf[10];  
	int item;  
	do     
	{
		system("CLS");      
		cout<<"1- �������� ������� � ������"<<endl;     
		cout<<"2- ���������� ��������� ������"<<endl;     
		cout<<"3- �������� ������"<<endl;     
		cout<<"4- ����� ������ �� ������� ��������� �������"<<endl;     
		cout<<"5- ������ ������ � ����"<<endl;     
		cout<<"6- �����"<<endl;     
		cout<<"============================"<<endl; 
		cout<<"������� ����� ������ ����:"<<endl;     
		cin>>buf;    
		cin.get();     
		item=atoi(buf);    
		if (!item)            
		{  
			cout<<"��� ������� ������ ����� �� 1 �� 6"<<endl;            
			cin.get();        
		}  
	} 
	while (!item);  
	return item; 
}
//--------------------���������� ������� ��������------------------------- 
int search(node *top, char a, int &level)
{
	if (strcmp(a,top->data.otp_naz)>0) level=search(top->right, a, level+1);
	else if (strcmp(a,top->data.otp_naz)<0) level=search(top->left, a, level+1);
	else return level; 
} 
// -----------------------------������ �����------------------------------ 
int read_file(char* filename, node* &top )  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) {cout<<"�� ������ ����"<<filename<<endl; return 1;} 
	zakaz p; 
	top = 0;  
	while (fin.getline(p.otp_naz,d_on))
	{       
		fin>>p.nomer;   
		fin>>p.time_o;  
		fin>>p.time_p;  
		fin>>p.price;  
		top=addtree(top,p);
	}  
	return 0; 
} 
// --------------------������ ������ � ����------------------------------- 
int write_file(ofstream &f, node* top)  
{ 
	if (top)       
	{  
		f<<top->data.otp_naz<<endl;       
		f<<top->data.nomer<<endl;  
		f<<top->data.time_o<<endl;
		f<<top->data.time_p<<endl;
		f<<top->data.price<<endl;
		write_file(f,top->left);      
		write_file(f,top->right);    
	}  
	return 0; 
}

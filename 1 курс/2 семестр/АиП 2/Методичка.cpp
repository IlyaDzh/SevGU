#include <iostream> 
#include <iomanip> 
using namespace std;

// �������, ����������� �������� ����� 
void SummaStrok(int **a,int m,int n,long *v); 
// �������, ����������� ����� ������� �  
// ����� ��������� � ������� 
void Vyvod(int **a,int m,int n,long *v); 
// �������, ����������� ���������� ����� 
void Sort(int **a,int m,int n,long *v); 

main() 
{ 
setlocale(0,"RUS");
int m,n,i,j;
cout<<"������� ���������� ����� � �������� �������:"<<endl;
cin>>m>>n;    
int **a=new int *[m]; // ��������� ������     
for(i=0;i<m;i++)      // ��� �������         
	a[i]=new int[n];     
for(i=0;i<m;i++)       
	for(j=0;j<n;j++) cin>>a[i][j];     
int *v=new long[m]; // ��������������� ������  
SummaStrok(a,m,n,v); // ������������ ��������� �����  
Vyvod(a,m,n,v); // ����������� ������  
Sort(a,m,n,v); // ����������  
Vyvod(a,m,n,v); // ����� ����������� 
return 0; 
}   

//--------------------------------------- 
void SummaStrok(int **a,int m,int n,long *v) 
{ 
int i,j;   
for(i=0;i<m;i++)      
{          
v[i]=0;        
for(j=0;j<n;j++)  v[i]+=a[i][j];     
} 
}   

//--------------------------------------- 
void Vyvod(int **a,int m,int n,long *v) 
{  
int i,j;    
for(i=0;i<m;i++)    
{ 
for(j=0;i<n;j++)          cout<<setw(4)<<a[i][j]<<" ";         
cout<<endl;    
}   
for(i=0;i<m;i++)       cout<<setw(4)<<v[i]<<" ";   
cout<<endl; 
}    

//--------------------------------------- 
// ���������� ����� ������� ������� ������� ������ 
void Sort(int **a,int m,int n,long *v) 
{    
long buf_sum; 
    int min,buf_a;     
	int i,j; 
	for(i=0;i<m-1;i++)    
	{    
	 min=i;     
	 for(j=i+1;j<m;j++) // ����� ������������ ��������       
	if(v[j]<v[min]) min=j;        
	buf_sum=v[i]; // ����� �������� v        
	v[i]=v[min];        
	v[min]=buf_sum;        
	for(j=0;j<n;j++)//������������ ����� ������� a          
	{  
	buf_a=a[i][j];             
	a[i][j]=a[min][j];            
	 a[min][j]=buf_a;            
	}        
	} 
} 

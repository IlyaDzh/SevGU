#include <iostream>
using namespace std;
int main()
{
	setlocale(0,"rus");
	int n, m;
	cout<<"������� ���-�� �����: "; cin>>n;
	cout<<"������� ���-�� ��������: "; cin>>m;
	int a[n][m];
	for (int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		cout<<"������� ["<<i+1<<"]["<<j+1<<"] ������� �������: ";
		cin>>a[i][j];
	}
	cout<<"��������:"<<endl;
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	int temp;
	cout<<"���������:"<<endl;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			for (int k=j; k<n; k++)
			{
				if (a[j][i]<a[k][i])
				{
				
					temp=a[k][i];
					a[k][i]=a[j][i];
					a[j][i]=temp;
				}
			}
		}
	}
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

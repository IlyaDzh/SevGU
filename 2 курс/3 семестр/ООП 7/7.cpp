#include <iostream>
#include <fstream> 
#include <iomanip>
using namespace std;

class vector 
{
public:
	int size, v;
	float *vec;
	vector(int _size)
	{
		vec = new float [size=_size];
	}
	~vector()
	{
		delete [] vec;
	}
	void vvod_vec()
	{
		for(int i=0; i<size; i++)
		{                                              
			cout <<"������� �������� ������� ["<<i+1<<"]: ";
			try 
			{
				if(!(cin >> vec[i])) throw 1;
			}
			catch(int)
			{
				
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ������� �����: "; cin>>vec[i];
				
			}
		}
	}
	void vivod()
	{
		for(int i=0; i<size; i++)
		{                                              
			cout <<"�������� ������� ["<<i+1<<"]: "<<vec[i]<<endl;
		}
	}
};

int main()
{
	setlocale(0, "rus");

    double a, b;
    ofstream fout("1.txt"); 
    cout<<"1 �������:"<<endl;
    cout<<"������� a: "; cin>>a;
    cout<<"������� b: "; cin>>b;
    double x = (-b)/a;
	if (a==0)
	{
		if (b==0) fout<<"X - ����� �����";
		else fout<<setfill('%')<<setw(12)<<"������� ���";
	}
	else 
	{
		fout.fill ('%'); fout.width (12);
    	fout<<"x="<<setprecision(4)<<x<<endl;
	}
	cout<<"��������� � �����!"<<endl;
	fout.close(); 
	
	
	cout<<"\n2 �������:"<<endl;
	vector ob(4);
	ob.vvod_vec();
	ob.vivod();
    return 0;
}

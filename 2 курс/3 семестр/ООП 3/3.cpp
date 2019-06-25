#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

class Aqua
{
public:
	int obm;
	
	Aqua()
	{
		cout<<"������� ����� ����: ";
		cin>>obm;
	}
	
	
	void Vivod()
	{
		cout<<"������ ������ ����:"<<endl;
		cout<<"����� ����: "<<obm<<endl;
	}
};


class Substance
{	
public:
	int ves;
	char *name, *type;
	
	Substance()
	{
		name=new char [10];
		type=new char [10];
		cout<<"������� ��� ��������: ";
		cin>>ves;
		cout<<"������� ��� ��������: ";
		cin>>name;
		cout<<"������� ��� ��������: ";
		cin>>type;
	}
	
	~Substance()
	{
		delete [] name;
		delete [] type;
	}
	
	void Vivod()
	{
		cout<<"������ ������ ��������:"<<endl;
		cout<<"��� ��������: "<<ves<<endl;
		cout<<"��� ��������: "<<name<<endl;
		cout<<"��� ��������: "<<type<<endl;
	}
};


class Rastvor : public Aqua, public Substance
{
public:
	int plus, minus;
	
	void Ink()
	{
		cout<<"������� �� ������� ��������� �����: "<<endl;
		cin>>plus;
		obm+=plus;
		cout<<"������� �� ������� ��������� ���: "<<endl;
		cin>>minus;
		ves-=minus;
		cout<<"���������!"<<endl;
	}
	
	void Vivod()
	{
		cout<<"����� ����: " <<obm<<endl;
		cout<<"��� ��������: "<<ves<<endl;
		cout<<"��� ��������: "<<name<<endl;
		cout<<"��� ��������: "<<type<<endl;
		
	}
};


int main ()
{
	setlocale(0, "RUS");
	
	int key;
	
	cout<<"�������� �������� �������� ������:"<<endl;
	Rastvor ob3;
	
	while (1)
	{
		system("cls");
		cout << "1 - ����� �������� ������������ ������ ������� ������� �������(��������)" << endl;
		cout << "2 - �������� ������� ������������ ������" << endl;
		cout << "3 - ����� ����������� ������ ������������ ������" << endl;
		cout << "4 - �����" << endl;
		key=getch(); 
		switch (key)
		{
			case'1':
			{
				ob3.Aqua::Vivod();
				cout<<"-----------------------"<<endl;
				ob3.Substance::Vivod();
				system("pause");
				break;
			} 
			case '2':
			{   
				cout<<"������ ������ �������:"<<endl;
				ob3.Vivod();
				system("pause");
				break;
			}
			case '3':
			{
				ob3.Ink();
				system("pause");
				break;
			}
			case '4': return 0;
			default: cout << "������� ����� �� 1 �� 4:" << endl;
		}
	}
}

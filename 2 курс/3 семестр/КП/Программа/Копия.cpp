#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <string> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
#include <Windows.h>
using namespace std; 

//------------------------------- ���� � ���������� ���������� -------------------------------
struct job  
{ 
	char sh[9];
	char kod[4];
	char fio[16];
	int t_z;
	int t_cp;
	job* right, *left;
}; 

//------------------------------- ��������� ������� -------------------------------
job* dob_beg(job* end, job* beg, const job& z);
job* dob_end(job* end, job* beg, const job& z);
job* dob_first(const job& z);
job* dob_after(job* beg, int index, const job& z);
job* del_index(job* beg, int index);
job* del_all(job* beg);
job vvod();
int menu_main();
int menu_add();
int menu_del();
int menu_sort();
int menu_edit();
int menu_search();
int menu_save();
void sort_sh(job* beg);
void sort_kod(job* beg);
void sort_fio(job* beg);
void sort_tz(job* beg);
void sort_tcp(job* beg);
void edit(job* beg);
void search(job* beg);
void time(job* beg);
void print(const job& z);
void prosmotr(job* beg);
void Tab();
int read_file(char* filefio, job** beg, job** end);
int write_file(char* filename, job* temp);
void TextColorO(char *text);
void TextColorP(char *text);
void TextColorB(char *text);
void TextColorR(char *text);
void TextColorG(char *text);

//------------------------------- ������� ������� -------------------------------
int main() 
{    
	setlocale(0,"RUS"); 
	system ("mode con cols=100 lines=25");
	system ("title �������� ������");

    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	
	int index=0; 
	int index1=0; 
	int number1=0; 
	int number=0;
	job *beg=0, *end=0;     
 	char *filename="job.txt";   
	char filename_s[15];   
	char filename_z[15];  
	
	cout<<"�������� ������������ ����� job.txt: ";
	read_file(filename, &beg, &end);
	
 	while (1)  
	{ 
		switch (menu_main())    
		{ 
		case 1: 
				{
					switch (menu_add())
					{
						case 1:
						{
							if (beg) 
							{
								
								float iii=1;
								while(iii==1)
								{
									beg=dob_beg (end, beg, vvod());
									TextColorO("�������� ��� (1-��, 2-���)? "); 
									while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
									{
										cin.clear();
										while(cin.get()!='\n') continue;
										cout<<"   ������� ���������� ��������: ";
									};	
									cin.get();						
								}
							}
							else 
							{
								float iii=0;
								beg=dob_first(vvod()); 
								end=beg;
								TextColorO("�������� ��� (1-��, 2-���)? ");
								while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
								{
									cin.clear();
									while(cin.get()!='\n') continue;
									cout<<"   ������� ���������� ��������: ";
								};		
								cin.get();	
								while(iii==1)
								{
									beg=dob_beg (end, beg, vvod());
									TextColorO("�������� ��� (1-��, 2-���)? ");
									while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
									{
										cin.clear();
										while(cin.get()!='\n') continue;
										cout<<"   ������� ���������� ��������: ";
									};
									cin.get();		
								}
							}
							TextColorG("���������!");
							system("pause");
							break;	
						}
						case 2:
						{
							job *temp=beg;
							if (beg) 
							{
								cout<<"������� ����� ����� �������� �������� �������: ";
								while (!(cin>>index1) )
								{
									cin.clear();
									while(cin.get()!='\n') continue;
									cout<<"   ������� ���������� ��������: ";
									
								};
								do
						        {
						            ++number1;
						            temp = temp->right;
						        }
								while (temp!= NULL);
						        if(index1 > number1 || index1==0) 
								{
									number1=0;
									TextColorR("������ ������ ���!");
									while(cin.get()!='\n');
									system("pause");
									break;
								}
								if(index1==number1) 
								{
									while(cin.get()!='\n');
									end=dob_end (end, beg, vvod());  
									number1=0;
									TextColorG("���������!");
									system("pause");
									break;
								}
								while(cin.get()!='\n');
								beg=dob_after(beg, index1, vvod());
								while(cin.get()!='\n');
								number1=0;
								TextColorG("���������!");
							}
							else TextColorR("������ ������!");
							system("pause");
							break;
						}
						case 3:
						{
							if (beg) 
							{
								float iii=1;
								while(iii==1)
								{
									end=dob_end (end, beg, vvod()); 
									TextColorO("�������� ��� (1-��, 2-���)? "); 
									while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
									{
										cin.clear();
										while(cin.get()!='\n') continue;
										cout<<"   ������� ���������� ��������: ";
									};
									cin.get();							
								}
							} 
							else 
							{  
								float iii=0;
								beg=dob_first(vvod()); 
								end=beg;
								TextColorO("�������� ��� (1-��, 2-���)? "); 
								while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
								{
									cin.clear();
									while(cin.get()!='\n') continue;
									cout<<"   ������� ���������� ��������: ";
								};
								cin.get();	
								while(iii==1)
								{
									end=dob_end (end, beg, vvod()); 
									TextColorO("�������� ��� (1-��, 2-���)? ");
									while (!(cin>>iii) || iii>2 || iii<1 || (iii>1.00001 && iii<1.99999))
									{
										cin.clear();
										while(cin.get()!='\n') continue;
										cout<<"   ������� ���������� ��������: ";
									};
									cin.get();
								}
							}      
							TextColorG("���������!");
							system("pause");
							break;  
						}
						case 4: break;
					}
					break;
				}
		case 2: 
				{
					system("cls");
					if (!beg) 
					{ 
						TextColorR("������ ������!");
						system("pause");
					}  
					else prosmotr(beg);  
					break;  
				}
		case 3: 
				{
					switch (menu_del())
					{
						case 1:
						{
							if (!beg) TextColorR("������ ������!");
							else  {
								beg=del_all(beg);   
								TextColorG("������ ���� ������!");
							}
							system("pause");            
							break;  
						}
						case 2:
						{
							if (beg)
							{
								job *temp=beg;
								cout<<"������� ����� ���������� ��������: ";
								while(!(cin>>index))
								{
									cin.clear();
									while(cin.get()!='\n') continue;
									cout<<"   ������� ���������� �����: ";
								}
								do
						        {
						            ++number;
						            temp = temp->right;
						        }
								while (temp!= NULL);
						        if(index > number) 
								{
									TextColorR("������ ������ ���!");
							        system("pause");
	    							cin.get();	
								}
						        else 
								{
						        	beg=del_index(beg, index);
						        	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					    			cout<<"����� �������: "<<index<<endl;
					    			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					    			system("pause");
	    							cin.get();	
						        }
						        number=0;
							}
							else 
							{
								TextColorR("������ ������!");
								cout<<"��� ����������� ������� ����� ������� . . .";
	    						cin.get();	
							}
							
							break; 
						}
						case 3: break;
					}
					break;
				}
		case 4:
				{
					if (beg) edit(beg);
					else 
					{
						TextColorR("������ ������!");
						system("pause");
					}
					break;
				}
		case 5: 
				{
					if (beg) search(beg);
					else 
					{
						TextColorR("������ ������!");
						system("pause");
					}
					break;
				}
		case 6:
				{
					if (beg) 
					{
						switch (menu_sort())
						{
							case 1:
							{
								sort_sh(beg);
								TextColorG("�������������!");
    							system("pause");
								break;
							}
							case 2:
							{
								sort_kod(beg);
								TextColorG("�������������!");
    							system("pause");
								break;
							}
							case 3:
							{
								sort_fio(beg);
								TextColorG("�������������!");
    							system("pause");
								break;
							}
							case 4:
							{
								sort_tz(beg);
								TextColorG("�������������!");
    							system("pause");
								break;
							}
							case 5:
							{
								sort_tcp(beg);
								TextColorG("�������������!");
    							system("pause");
								break;
							}
							case 6: break;
						}
					}
					else 
					{
						TextColorR("������ ������!");
						system("pause");
					}
					break;
				}
		case 7:
		{
			if (beg) time(beg);
			else TextColorR("������ ������!");
			system("pause");
			break;
		}
		case 8: 
				{
					switch (menu_save())
					{
						case 1:
						{
							cout<<"������� �������� ����� ��� ����������:"<<endl; cin>>filename_s;
							write_file(filename_s, beg); 
							system("pause"); 
							break;
						}
						case 2:
						{
							write_file(filename, beg); 
							system("pause"); 
							break;
						}
						case 3: break;
					}
					break;  
				}
		case 9:
		{
			cout<<"������� �������� ����� ��� ��������:"<<endl;
			while(!(cin.getline(filename_z, 16)))
			{
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ������� ���������� �������� �����: ";
			}
			read_file(filename_z, &beg, &end);
			break;
		}
		case 10: 
		    	TextColorG("����� ���������!"); 
				return 0;  
		}       
	} 
} 

//------------------------------- ���������� � ������ -------------------------------
job* dob_beg(job *end, job *beg, const job& z) 
{         
	job *newE=new job;
	*newE=z;  
	newE->right=beg; 
	newE->left=0; 
	beg->left=newE; 
	beg=newE; 
	return beg; 
} 

//------------------------------- ���������� � ����� -------------------------------
job* dob_end(job *end, job *beg, const job& z)  
{         
	job *newE=new job;  
	*newE=z;     
	newE->right=0;   
	newE->left=beg;
	end->right=newE;   
	end=newE;      
	return end;    
} 

//------------------------------- ���������� ������ ��������� -------------------------------
job* dob_first(const job& z)  
{ 
	job *beg=new job;    
	*beg=z;     
	beg->right=0;   
	beg->left=0;
	return beg; 
} 

//------------------------------- ���������� ����� -------------------------------
job* dob_after(job* beg, int index1, const job& z)
{
	int number=0;
    job *temp = beg;
    job *tmp = beg;
    do 
    {
        ++number;
        tmp = tmp->right;
    }
	while(tmp != NULL);
    for(int i = 1; i < number; i++)
    {
        if(index1 == i)
        {
            job *NewE = new job;
	        *NewE = z;
            NewE->right = temp->right;
            temp->right = NewE;
        }
        else temp = temp->right;
    }
    return beg;
}

//------------------------------- ������� ��� -------------------------------
job* del_all(job *beg)
{
  	job *p=beg;
  	while (p->right)
  	{
	    job *temp;
	    temp = p;
	    p = p->right;
	    delete temp;
  	}
	p=p->right;
	delete p;
	beg=NULL;
	return beg;
}

//------------------------------- �������� �� ������� -------------------------------
job* del_index(job* beg, int index)
{
    job* p=0;
    job* temp=beg;
    int i=1;
    while(temp)
    {
        if(i==index)
        {
            if(p) p->right=temp->right;
            else beg=temp->right;
            delete temp;
            return beg;
        }
        i++;
        p=temp;
        temp=temp->right;
    }
    return beg;
}

//------------------------------- ���������� �� ����� -------------------------------
void sort_sh(job* beg) 
{    
	int b1, b2;
    job *temp=beg; 
    while(temp->right) 
    { 
    	b1=atoi(temp->sh);
    	b2=atoi(temp->right->sh);
        if(b1>b2) 
        { 
        	swap(temp->sh, temp->right->sh);
        	
        	swap(temp->kod, temp->right->kod);
        	
			swap(temp->fio, temp->right->fio);
			
            int tmp = temp->right->t_z; 
            temp->right->t_z = temp->t_z; 
            temp->t_z = tmp; 
            
            int tmp1 = temp->right->t_cp; 
            temp->right->t_cp = temp->t_cp; 
            temp->t_cp = tmp1; 
			            
            temp=temp->right;
            sort_sh(beg);
        } 
        else temp=temp->right;
    } 
}

//------------------------------- ���������� �� ���� -------------------------------
void sort_kod(job* beg) 
{    
	int b1, b2;
    job *temp=beg; 
    while(temp->right) 
    { 
    	b1=atoi(temp->kod);
    	b2=atoi(temp->right->kod);
        if(b1>b2) 
        { 
        	swap(temp->sh, temp->right->sh);
        	swap(temp->kod, temp->right->kod);
			swap(temp->fio, temp->right->fio);
            int tmp = temp->right->t_z; 
            temp->right->t_z = temp->t_z; 
            temp->t_z = tmp; 
            int tmp1 = temp->right->t_cp; 
            temp->right->t_cp = temp->t_cp; 
            temp->t_cp = tmp1; 
			            
            temp=temp->right;
            sort_kod(beg);
        } 
        else temp=temp->right;
    } 
}

//------------------------------- ���������� �� ��� -------------------------------
void sort_fio(job* beg) 
{    
    job *temp=beg; 
    while(temp->right) 
    { 
        if(strcmp(temp->fio, temp->right->fio)>0) 
        { 
        	swap(temp->sh, temp->right->sh);
        	swap(temp->kod, temp->right->kod);
			swap(temp->fio, temp->right->fio);
            int tmp = temp->right->t_z; 
            temp->right->t_z = temp->t_z; 
            temp->t_z = tmp; 
            int tmp1 = temp->right->t_cp; 
            temp->right->t_cp = temp->t_cp; 
            temp->t_cp = tmp1; 
			            
            temp=temp->right;
            sort_fio(beg);
        } 
        else temp=temp->right;
    } 
}

//------------------------------- ���������� �� ������ ������� -------------------------------
void sort_tz(job* beg) 
{    
    job *temp=beg; 
    while(temp->right) 
    { 
        if((temp->t_z)>(temp->right->t_z)) 
        { 
        	swap(temp->sh, temp->right->sh);
        	swap(temp->kod, temp->right->kod);
			swap(temp->fio, temp->right->fio);
            int tmp = temp->right->t_z; 
            temp->right->t_z = temp->t_z; 
            temp->t_z = tmp; 
            int tmp1 = temp->right->t_cp; 
            temp->right->t_cp = temp->t_cp; 
            temp->t_cp = tmp1; 
			            
            temp=temp->right;
            sort_tz(beg);
        } 
        else temp=temp->right;
    } 
}

//------------------------------- ���������� �� ������� �� -------------------------------
void sort_tcp(job* beg) 
{    
    job *temp=beg; 
    while(temp->right) 
    { 
        if((temp->t_cp)>(temp->right->t_cp)) 
        { 
        	swap(temp->sh, temp->right->sh);
        	swap(temp->kod, temp->right->kod);
			swap(temp->fio, temp->right->fio);
            int tmp = temp->right->t_z; 
            temp->right->t_z = temp->t_z; 
            temp->t_z = tmp; 
            int tmp1 = temp->right->t_cp; 
            temp->right->t_cp = temp->t_cp; 
            temp->t_cp = tmp1; 
			            
            temp=temp->right;
            sort_tcp(beg);
        } 
        else temp=temp->right;
    } 
}

//------------------------------- �������������� -------------------------------
void edit(job *beg)
{
	int index, cp, o_t;
	int number=0; int number1=0;
	char fio1[16];
	bool not_found = true;
	
	switch (menu_edit())
	{
		case 1:
		{
			system("cls");
			cout<<"������� �����: "; 
			while(!(cin>>index))
			{
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ������� ���������� �����: ";
			}
			
			job* tmp=beg;
			do
	        {
	            ++number1;
	            tmp = tmp->right;
	        }
			while (tmp!= NULL);
	        if(index > number1) 
			{
				TextColorR("������ ������ ���!");
				system("pause");
				cin.get();
				break;
			}
			Tab(); 
			job* temp = beg;
			int i=1;
			while(temp)
			{
			    if(i == index)
			    {
			    	print(*temp);
			    	cout << " |---------------------------------------------------------------------------|" <<endl;
			    	cout<<"������� ����� ���� �������: ";
					while(cin.get()!='\n');
					while(!cin.getline(temp->sh, 9))
					{
						cin.clear();
						while(cin.get()!='\n');
						cout<<"   ������� ���������� ����� ���� ������� (8 ��������): ";
					}
					cout<<"������� ����� ��� ������: ";  
					while(!cin.getline(temp->kod, 4))
					{
						cin.clear();
						while(cin.get()!='\n');
						cout<<"   ������� ���������� ����� ��� ������ (3 �������): ";
					}
					cout<<"������� ����� ��� ������������: ";  
					while(!cin.getline(temp->fio, 16))
					{
						cin.clear();
						while(cin.get()!='\n');
						cout<<"   ������� ���������� ����� ��� (15 ��������): ";
					}
					cout<<"������� ����� ����� ����� ����������� �������: ";  
					while(!(cin>>temp->t_z) || !(temp->t_z>0 && temp->t_z<99999))
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"   ������� ���������� ����� ����� ����������� ������� (5 ������): ";
					}
					cout<<"������� ����� ����� ������������ ����������:: ";  
					while(!(cin>>temp->t_cp) || (temp->t_cp>temp->t_z))
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"   ������� ���������� ����� ����� ������������ ���������� (t_�������>t_��): ";
					}
					not_found = false;
			    }
				i++;
				temp = temp->right;
			}
			if (!not_found) TextColorG("���������������!");
			system("pause");
			cin.get();
			break;	
		}
		case 2:
		{
			char bfio[16];
			char *b="*";
			int i=0;
			system("cls");
			TextColorO("��� �������� ����� ���� ������� *\n");
			cout<<"������� ���: "; 
			while(!cin.getline(fio1, 16))
			{
				cin.clear();
				while(cin.get()!='\n');
				cout<<"   ������� ���������� ��� (15 ��������): ";
			}
			
			Tab();
			job* temp = beg;
			while(temp)
			{
			    if(strncmp(temp->fio, fio1, 4)==0) 
			    {
			    	if(i>0) cout << " |---------------------------------------------------------------------------|" <<endl;
			    	print(*temp);
			    	cout << " |---------------------------------------------------------------------------|" <<endl;
					cout<<"������� ����� ��� (15 ��������): ";  
					cin.getline(bfio, 16);
					if (!strcmp(bfio, b)) 
					{
						temp = temp->right;
						not_found = false; i++;
						continue;
					}
					else 
					{
						strcpy(temp->fio, bfio);
						not_found = false; i++;
						temp = temp->right;
						continue;
					}
					
			    }
			    else temp = temp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else TextColorG("���������������!");
			system("pause");
			break;	
		}
		case 3:
		{
			int i=0;
			system("cls");
			cout<<"������� ����� �����: ";
			while(!(cin>>o_t))
			{
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ������� ���������� ����� ����� (5 ������): ";
			}
			
			Tab(); 
			job* temp = beg;
			while(temp)
			{
			    if(temp->t_z == o_t)
			    {
			    	if(i>0) cout << " |---------------------------------------------------------------------------|" <<endl;
			    	print(*temp);
			    	cout << " |---------------------------------------------------------------------------|" <<endl;
					cout<<"������� ����� ����� �����: ";  
					while(!(cin>>temp->t_z) || !(temp->t_z>0 && temp->t_z<99999))
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"   ������� ���������� ����� ����� ����� (5 ������): ";
					}
					not_found = false; i++;
					temp = temp->right;
			    }
			    else temp = temp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else TextColorG("���������������!");
			system("pause");
			cin.get();
			break;
		}
		case 4:
		{
			int i=0;
			system("cls");
			cout<<"������� ����� ������������ ����������: ";
			while(!(cin>>cp))
			{
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ������� ���������� ����� ������������ ���������� (t_�������>t_��): ";
			}
			Tab(); 
			job* temp = beg;
			while(temp)
			{
			    if(temp->t_cp == cp)
			    {
			    	if(i>0) cout << " |---------------------------------------------------------------------------|" <<endl;
			    	print(*temp);
			    	cout << " |---------------------------------------------------------------------------|" <<endl;
					cout<<"������� ����� ����� ������������ ����������: ";  
					while(!(cin>>temp->t_cp) || (temp->t_cp>temp->t_z))
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"   ������� ���������� ����� ����� ������������ ���������� (t_�������>t_��): ";
					}
					not_found = false; i++;
			    }
			    else temp = temp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else TextColorG("���������������!");
			system("pause");
			cin.get();
			break;
		}
		case 5: break;
	}
}

//------------------------------- ����� -------------------------------
void search(job *beg)
{
	int o_t, t_cp;
	char fio[16], sh[9], kod[4];
	bool not_found = true;
	job* tmp = beg;
	
	switch (menu_search())
	{
		case 1:
		{
			cout<<"������� ����: "; cin>>sh; cin.get();
			Tab();
			while(tmp)
			{
			    if(!strcmp(tmp->sh, sh)) 
				{
					print(*tmp);
					not_found = false;
				}
				tmp = tmp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else cout << " |---------------------------------------------------------------------------|" <<endl;
			system("pause");
			break;	
		}
		case 2:
		{
			cout<<"������� ���: "; cin>>kod; cin.get();
			Tab();
			while(tmp)
			{
			    if(!strcmp(tmp->kod, kod)) 
				{
					print(*tmp);
					not_found = false;
				}
				tmp = tmp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else cout << " |---------------------------------------------------------------------------|" <<endl;
			system("pause");
			break;	
		}
		case 3:
		{
			cout<<"������� �.�.�.: "; cin>>fio; 
			while(cin.get()!='\n');
			Tab();
			while(tmp)
			{
			    if(strncmp(tmp->fio, fio, 4)==0) 
				{
					print(*tmp);
					not_found = false;
				}
				tmp = tmp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else cout << " |---------------------------------------------------------------------------|" <<endl;
			system("pause");
			break;	
		}
		case 4:
		{
			cout<<"������� ����� �����: "; cin>>o_t; cin.get();
			Tab();
			while(tmp)
			{
			    if(tmp->t_z==o_t) 
				{
					print(*tmp);
					not_found = false;
				}
				tmp = tmp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else cout << " |---------------------------------------------------------------------------|" <<endl;
			system("pause");
			break;	
		}
		case 5:
		{
			cout<<"������� ����� ��: "; cin>>t_cp; cin.get();
			Tab();
			while(tmp)
			{
			    if(tmp->t_cp==t_cp)
				{
					print(*tmp);
					not_found = false;
				}
				tmp = tmp->right;
			}
			if (not_found) TextColorR("������ �� �������!");
			else cout << " |---------------------------------------------------------------------------|" <<endl;
			system("pause");
			break;	
		}
		case 6: break;
	}
}

//------------------------------- ������� ����� -------------------------------
job vvod()  
{   
	job z;  
	cout<<"������� ���� �������: ";
	while(!cin.getline(z.sh, 9))
	{
		cin.clear();
		while(cin.get()!='\n');
		cout<<"   ������� ���������� ���� ������� (8 ��������): ";
	}
	cout<<"������� ��� ������: ";  
	while(!cin.getline(z.kod, 4))
	{
		cin.clear();
		while(cin.get()!='\n');
		cout<<"   ������� ���������� ��� ������ (3 �������): ";
	}
	cout<<"������� ��� ������������: ";  
	while(!cin.getline(z.fio, 16))
	{
		cin.clear();
		while(cin.get()!='\n');
		cout<<"   ������� ���������� ��� (15 ��������): ";
	}
	cout<<"������� ����� ����� ����������� �������: ";  
	while(!(cin>>z.t_z) || !(z.t_z>0 && z.t_z<99999))
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"   ������� ���������� ����� ����������� ������� (5 ������): ";
	}
	cout<<"������� ����� ������������ ���������� (t_�������>t_��): ";  
	while(!(cin>>z.t_cp) || (z.t_cp>z.t_z))
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"   ������� ���������� ����� ������������ ���������� (t_�������>t_��): ";
	}
	return z; 
} 

//------------------------------- ������� ���� -------------------------------
int menu_main() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=10;
		}
		else if (key==80)
		{
			if (++point>10) point=0;
		}
		cout<<"============== "; TextColorP("����"); cout<<" =============="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("      ���������� ��������       ");
			cout<<"|"<<endl;
		}
		else cout<<"|      ���������� ��������"<<setw(8)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("            ��������            ");
			cout<<"|"<<endl;
		}
		else cout<<"|            ��������"<<setw(13)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("            ��������            ");
			cout<<"|"<<endl;
		}
		else cout<<"|            ��������"<<setw(13)<<"|"<<endl;
		if(point==4) 
		{
			cout<<"|";
			TextColorB("         ��������������         ");
			cout<<"|"<<endl;
		}
		else cout<<"|         ��������������"<<setw(10)<<"|"<<endl;
		if(point==5) 
		{
			cout<<"|";
			TextColorB("              �����             ");
			cout<<"|"<<endl;
		}
		else cout<<"|              �����"<<setw(14)<<"|"<<endl;
		if(point==6) 
		{
			cout<<"|";
			TextColorB("           ����������           ");
			cout<<"|"<<endl;
		}
		else cout<<"|           ����������"<<setw(12)<<"|"<<endl;
		if(point==7) 
		{
			cout<<"|";
			TextColorB("         ������ �������         ");
			cout<<"|"<<endl;
		}
		else cout<<"|         ������ �������"<<setw(10)<<"|"<<endl;
		if(point==8) 
		{
			cout<<"|";
			TextColorB("      ������ ������ � ����      ");
			cout<<"|"<<endl;
		}
		else cout<<"|      ������ ������ � ����"<<setw(7)<<"|"<<endl;
		if(point==9) 
		{
			cout<<"|";
			TextColorB("    �������� ������ �� �����    ");
			cout<<"|"<<endl;
		}
		else cout<<"|    �������� ������ �� �����"<<setw(5)<<"|"<<endl;
		if(point==10) 
		{
			cout<<"|";
			TextColorB("             �����              ");
			cout<<"|"<<endl;
		}
		else cout<<"|             �����"<<setw(15)<<"|"<<endl;  
		cout<<"=================================="<<endl;
		TextColorO(" ��� ��������� �� ���� �����������\n");
		TextColorO("      ������� ����� � ����!\n");
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 10;
} 

//------------------------------- ���� ���������� -------------------------------
int menu_add()
{
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=4;
		}
		else if (key==80)
		{
			if (++point>4) point=0;
		}
		cout<<"========= "; TextColorP("����������"); cout<<" ========="<<endl;
		cout<<"|       ���� ��������?       |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("          � ������");
			cout<<setw(11)<<"|"<<endl;
		}
		else cout<<"|          � ������"<<setw(11)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("         � ��������");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|         � ��������"<<setw(10)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("          � �����");
			cout<<setw(12)<<"|"<<endl;
		}
		else cout<<"|          � �����"<<setw(12)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==4) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 4;
}

//------------------------------- ���� �������� -------------------------------
int menu_del() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=3;
		}
		else if (key==80)
		{
			if (++point>3) point=0;
		}
		cout<<"========== "; TextColorP("��������"); cout<<" =========="<<endl;
		cout<<"|        ��� �������?        |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("        ���� ������");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|        ���� ������"<<setw(10)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("         �� ������");
			cout<<setw(11)<<"|"<<endl;
		}
		else cout<<"|         �� ������"<<setw(11)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 3;
} 

//------------------------------- ���� ���������� -------------------------------
int menu_sort() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=6;
		}
		else if (key==80)
		{
			if (++point>6) point=0;
		}
		cout<<"========= "; TextColorP("����������"); cout<<" ========="<<endl;
		cout<<"|       ����������� ��:      |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("            �����");
			cout<<setw(12)<<"|"<<endl;
		}
		else cout<<"|            �����"<<setw(12)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("             ����");
			cout<<setw(12)<<"|"<<endl;
		}
		else cout<<"|             ����"<<setw(12)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("             ���");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|             ���"<<setw(13)<<"|"<<endl;
		if(point==4) 
		{
			cout<<"|";
			TextColorB("       ������ �������");
			cout<<setw(8)<<"|"<<endl;
		}
		else cout<<"|       ������ �������"<<setw(8)<<"|"<<endl;
		if(point==5) 
		{
			cout<<"|";
			TextColorB("         ������� ��");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|         ������� ��"<<setw(10)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==6) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 6;
} 

//------------------------------- ���� �������������� -------------------------------
int menu_edit() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=5;
		}
		else if (key==80)
		{
			if (++point>5) point=0;
		}
		
		cout<<"======= "; TextColorP("��������������"); cout<<" ======="<<endl;
		cout<<"|    ��� ���������������?    |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("        ���� �������");
			cout<<setw(9)<<"|"<<endl;
		}
		else cout<<"|        ���� �������"<<setw(9)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("             ���");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|             ���"<<setw(13)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("         ����� �����");
			cout<<setw(9)<<"|"<<endl;
		}
		else cout<<"|         ����� �����"<<setw(9)<<"|"<<endl;
		if(point==4) 
		{
			cout<<"|";
			TextColorB("          ����� ��");
			cout<<setw(11)<<"|"<<endl;
		}
		else cout<<"|          ����� ��"<<setw(11)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==5) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 5;
} 

//------------------------------- ���� ������ -------------------------------
int menu_search() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=6;
		}
		else if (key==80)
		{
			if (++point>6) point=0;
		}
		cout<<"============ "; TextColorP("�����"); cout<<" ==========="<<endl;
		cout<<"|          ����� ��:         |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("            �����");
			cout<<setw(12)<<"|"<<endl;
		}
		else cout<<"|            �����"<<setw(12)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("             ����");
			cout<<setw(12)<<"|"<<endl;
		}
		else cout<<"|             ����"<<setw(12)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("             ���");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|             ���"<<setw(13)<<"|"<<endl;
		if(point==4) 
		{
			cout<<"|";
			TextColorB("       ������ �������");
			cout<<setw(8)<<"|"<<endl;
		}
		else cout<<"|       ������ �������"<<setw(8)<<"|"<<endl;
		if(point==5) 
		{
			cout<<"|";
			TextColorB("         ������� ��");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|         ������� ��"<<setw(10)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==6) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 6;
} 

//------------------------------- ���� ���������� -------------------------------
int menu_save() 
{  
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=3;
		}
		else if (key==80)
		{
			if (++point>3) point=0;
		}
		cout<<"========= "; TextColorP("����������"); cout<<" ========="<<endl;
		cout<<"|        ��������� �:        |" << endl;
		cout<<"=============================="<<endl;
		if(point==1) 
		{
			cout<<"|";
			TextColorB("         ����� ����");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|         ����� ����"<<setw(10)<<"|"<<endl;
		if(point==2) 
		{
			cout<<"|";
			TextColorB("        �����������");
			cout<<setw(10)<<"|"<<endl;
		}
		else cout<<"|        �����������"<<setw(10)<<"|"<<endl;
		cout<<"|"<<setw(29)<<"|"<<endl;
		if(point==3) 
		{
			cout<<"|";
			TextColorB("           �����");
			cout<<setw(13)<<"|"<<endl;
		}
		else cout<<"|           �����"<<setw(13)<<"|"<<endl;
		cout<<"=============================="<<endl;
		key=getch();
	} 
	while (key!=13 && key!=27);
	system ("cls");
	return key==13 ? point : 3;
} 

//------------------------------- ����� �������� -------------------------------
void print(const job& z)  
{ 
	cout << " |" <<setw(17) << z.sh << " |" << setw(11) << z.kod << " |" << setw(17) << z.fio << " |" << setw(12) << z.t_z << " |" <<setw(9) << z.t_cp << " |";
	cout<<endl;
} 

//------------------------------- �������� -------------------------------
void prosmotr(job *beg)  
{ 
	int i=1; char key = 77; int gg=0; int str=1;
	job *temp=beg; 
	TextColorO("                  ��� ������������� ������� ����������� ������� ->\n");
	TextColorO("                        ���� <- ��� ������ �� ���������\n");
	while(temp)
	{
		if (key==77)
		{
			cout << "|-----------------------------------------------------------------------------------|" <<endl;
			cout<< "| ����� |   ���� �������   | ��� ������ |      �.�.�.      | ����� ����� | ����� �� |" <<endl; 
			cout << "|-------+------------------+------------+------------------+-------------+----------|" <<endl;
			for(gg=0;gg<10;)
			{
				if(temp)
				{
					cout << "|" << setw(6) << i;
					print(*temp);   
					temp=temp->right;
					i++; gg++;
				}
				else break;
			}
			cout << "|-----------------------------------------------------------------------------------|" <<endl;
			cout << " ����� ��������: " << str++ << endl;
		}
		if (key==75) break;
		key=getch();
		system("cls");
	} 
} 

//------------------------------- ������ ������� -------------------------------
void time(job* beg)
{
	int sum1=0; int sum2=0; int sum3=0; int procent=0;
	float sr=0; 
	int ii=0;
	int i=1; char key = 77; int gg=0;
	int str=1;
	
	TextColorO("                         ��� ������������� ������� ����������� ������� ->\n");
	TextColorO("                               ���� <- ��� �������� � ����� �������\n");
	job *temp=beg; 
	while(temp)
	{
		procent=(temp->t_cp*100)/temp->t_z;
		sum1+=temp->t_cp;
		sum2+=temp->t_z;
		sum3+=procent;
		ii++;
		procent=0;
		temp=temp->right;
	}
	temp=beg; 
	while(temp)
	{
		if (key==77)
		{
			cout << "|------------------------------------------------------------------------------------------------|" <<endl;
			cout<< "| ����� |   ���� �������   | ��� ������ |      �.�.�.      | ����� ����� | ����� �� |    % ��    |" <<endl; 
			cout << "|-------+------------------+------------+------------------+-------------+----------+------------|" <<endl;
			for(gg=0;gg<10;)
			{
				if(temp)
				{
					procent=(temp->t_cp*100)/temp->t_z;
					cout << "|" << setw(6) << i;
					cout << " |" <<setw(17) << temp->sh;
					cout << " |" << setw(11) << temp->kod;
					cout << " |" << setw(17) << temp->fio;
					cout << " |" << setw(12) << temp->t_z;
					cout << " |" <<setw(9) << temp->t_cp;
					cout << " |"<<setw(11) << procent << " |"<<endl;  
					procent=0;
					temp=temp->right;
					i++; gg++;
				}
				else break;
			}
			cout << "|------------------------------------------------------------------------------------------------|" <<endl;
			cout << " ����� ��������: " << str++ << endl;
		}
		if (key==75) break;
		key=getch();
		system("cls");
	} 
	sr=(float)sum3/ii;
	cout<<"������� ������� ������� �� �� ���� ��������: "<<sr<<endl;
	cout<<"����� ������ �������: "<<sum2<<endl;
	cout<<"����� ������� ��: "<<sum1<<endl;
}

//------------------------------- ������ ����� -------------------------------
int read_file(char* filename, job** beg, job** end)  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) 
	{ 
		TextColorR("���� �� ������!");
    	cout<<"��� ����������� ������� ����� ������� . . .";
    	cin.get();
		return 1;
	}   
	else 
	{
		TextColorG("���� ������!");
		cout<<"��� ����������� ������� ����� ������� . . .";
		cin.get();
	}
	job z;  
	*beg = 0;  
	while (fin.getline(z.sh, 9))
    {    
		fin.getline(z.kod, 4); 
		fin.getline(z.fio, 16); 
		fin>>z.t_z; 
		fin>>z.t_cp;       
		fin.get();         
		if (*beg)     
			*end=dob_end(*end, *beg, z);       
		else      
		{ *beg=dob_first(z); *end=*beg; }
	}  
	return 0; 
} 

//------------------------------- ������ ����� -------------------------------
int write_file(char* filename, job* temp)  
{ 
	ofstream fout(filename);
	if (!fout) 
	{
    	TextColorR("���������� ������� ���� ��� ������!");
		return 1;
	}  
	while (temp)    
	{  
		fout<<temp->sh<<endl;
		fout<<temp->kod<<endl;
		fout<<temp->fio<<endl;
		fout<<temp->t_z<<endl;
		fout<<temp->t_cp<<endl;
		temp=temp->right;
	}  
	
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"������ ��������� � �����: "<<filename<<"!"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cin.ignore(1);
	return 0; 
} 

//------------------------------- ������� ������ ��������� ������� -------------------------------
void Tab()
{
	cout << " |---------------------------------------------------------------------------|" <<endl;
	cout<< " |   ���� �������   | ��� ������ |      �.�.�.      | ����� ����� | ����� �� |" <<endl;  
	cout << " |---------------------------------------------------------------------------|" <<endl;
}

//------------------------------- ������� ���� -------------------------------
void TextColorG(char *text)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<text<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//------------------------------- ������� ���� -------------------------------
void TextColorR(char *text)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout<<text<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//------------------------------- ����� ���� -------------------------------
void TextColorB(char *text)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout<<text;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//------------------------------- ���������� ���� -------------------------------
void TextColorP(char *text)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<text;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//------------------------------- ��������� ���� -------------------------------
void TextColorO(char *text)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<text;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

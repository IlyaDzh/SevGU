#include <stdio.h>
#include <string.h>
#define GLAS "aeiouy"  
int main()
{	
	setlocale(0,"RUS");
	FILE *f;
    f = fopen("1.txt","rt");
	if (f==NULL)
    {   
		fprintf(stderr,"�� ���� ������� ���� \n"); 
		return 1; 
    }   	
   	char s[500];
   	printf("�����, ������������ � ������� ����: \n");
   	while (fscanf(f, "%s", s) != EOF)
   	{
    	if (strchr(GLAS, s[0]) && strchr(GLAS, s[strlen(s)-1]))
        puts(s);
   	}
   	fclose(f);
   	return 0;
}

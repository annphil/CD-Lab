#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int n,m=0,p,i=0,j=0;
int flag = 0;
char prod[10][10],f[10];
void follow(char c);
void first(char c);

int main(){
	int i,z;
	char c,ch;
	//clrscr();
	printf("Enter the no of productions:\n");
	scanf("%d",&n);
	printf("Enter the productions:\n");
	for(i=0;i<n;i++)
		scanf("%s%c",prod[i],&ch);
	do{
		m=0;
		printf("Enter the element whose first & follow is to be found:");
		scanf("%c",&c);
		first(c);
		printf("First(%c) = ",c);
		for(i=0;i<m;i++)
			printf("%c",f[i]);
		printf("\n");
		
		strcpy(f," ");
		//flushall();		
		m=0;
		follow(c);
		printf("Follow(%c) = ",c);
		for(i=0;i<m;i++)
		{
			if (f[i] != 'e')
				printf("%c",f[i]);
		}
		printf("\n");
		
		printf("Continue(0/1)?");
		scanf("%d%c",&z,&ch);
	} while(z==1);
	return(0);
}
void first(char c)
{
	int k;
	if(!isupper(c))
		f[m++]=c;
		
	// n --> no of productions
	for(k=0;k<n;k++)
	{
		if(prod[k][0]==c)
		{
			if(prod[k][2]=='e' && flag == 1)
				follow(prod[k][0]);
			if(islower(prod[k][2]))
				f[m++]=prod[k][2];
			else 
				first(prod[k][2]);
		}
	}
}
void follow(char c)
{
	if(prod[0][0]==c)
		f[m++]='$';
	for(i=0;i<n;i++)
	{
		for(j=2;j<strlen(prod[i]);j++)
		{
			if(prod[i][j]==c)
			{
				if(prod[i][j+1]!='\0')
				{
					flag = 1;
					first(prod[i][j+1]);
					flag = 0;
				}
				if(prod[i][j+1]=='\0' && c!=prod[i][0])
				follow(prod[i][0]);
			}
		}
	}
}

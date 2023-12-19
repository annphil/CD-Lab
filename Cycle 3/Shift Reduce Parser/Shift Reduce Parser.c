#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,len=0;
char inp[16],ac[20],stk[15],act[10];
void check();
int main()
   {

      puts("GRAMMAR is \nE->E+E \n E->E*E \n E->(E) \n E->id");
      puts("Enter input string: ");
      scanf("%s",inp);
      len=strlen(inp);
      strcpy(act,"SHIFT->");
      puts("\nstack \t\t input \t\t\t action");
      for(i=0; j<len; i++,j++)
       { // printf("\n%d",  i);
         if(inp[j]=='i' && inp[j+1]=='d')
           {
              stk[i]=inp[j];
              stk[i+1]=inp[j+1];
              stk[i+2]='\0';
              inp[j]=' ';
              inp[j+1]=' ';
              printf("\n$%s\t\t%s$\t\t%sid",stk,inp,act);
           }
         else
           {
              stk[i]=inp[j];
              stk[i+1]='\0';
              inp[j]=' ';
              printf("\n$%s\t\t%s$\t\t%ssymbol",stk,inp,act);
           }
         //printf("\n%d %d\n", i, j);
         check();
         //printf("\n%d %d\n", i, j);
         if (j == len-1 && i == 0)
         	printf("\nString accepted\n");
       }

   }
void check()
   {
     strcpy(ac,"REDUCE TO E");
     for(z=0; z<len; z++)
       if(stk[z]=='i' && stk[z+1]=='d')
         {
           stk[z]='E';
           stk[z+1]='\0';
           printf("\n$%s\t\t%s$\t\t%s",stk,inp,ac);
           j++;
         }
     for(z=0; z<len; z++)
       if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
         {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t\t%s$\t\t%s",stk,inp,ac);
           i=i-2;
         }
     for(z=0; z<len; z++)
       if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
         {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t\t%s$\t\t%s",stk,inp,ac);
           i=i-2;
         }
     for(z=0; z<len; z++)
       if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
         {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t\t%s$\t\t%s",stk,inp,ac);
           i=i-2;
         }
   }

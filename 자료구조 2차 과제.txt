#include <stdio.h> 
#include <stdlib.h> 
#define STACK_SIZE 100 
typedef char element;
element stack[STACK_SIZE]; 
int top= -1; 
void push(element item)
{ 
   if(top >= STACK_SIZE-1) { 
      printf("\nFULL\n"); 
      return; 
   } 
   else stack[++top]=item; 
} 
element pop()      
{ 
   if(top==-1) {    
      printf("\nEMPTY\n"); 
      return 0; 
   } 
   else return stack[top--]; 
} 

void reverse_string(char in[]) 
{ 
   int i; 
   for(i=0; in[i]; i++) push(in[i]); 
   for(i=0; top > -1; i++) in[i]=pop(); 
} 
int main(void) 
{ 
	int n, m, i, x;
   scanf("%d",&n);
   char c = getchar();
   m=n+1;
   char str[n], my_string[n];
   gets(str);
   for(i=0;i<m;i++)
   my_string[i]=str[i];
   
   reverse_string(my_string); 
   printf("%s", my_string); 
     return 0; 
} 


/*


	int n, m, i, x;
   scanf("%d",&n);
   m=n+1;
   char str[m], my_string[m];
   gets(str);
   for(i=0;i<m;i++)
   my_string[i]=str[i];
   
   
   
	int n, m, i, x;
   scanf("%d",&n);
   m=n+1;
   char my_string[m];
   for(i=0;i<m;i++)
   my_string[i]=getch();


*/

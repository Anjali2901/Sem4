#include<stdio.h>
int main()
{

	FILE *fp=fopen("1.txt","w");
	char c;
	while((c=getchar())!= EOF ){
		fputc(c,fp);
	}
	fclose(fp);
	fp=fopen("1.txt","r");
	while((c=fgetc(fp)) != EOF){
		printf("%c",c);
	}
	fclose(fp);
	return 0;
}

/*
#include<stdio.h>
#include<conio.h>
struct emp
{
   char name[10];
   int age;
};

void main()
{
   struct emp e;
   FILE *p,*q;
   p = fopen("one.txt", "a");
   q = fopen("one.txt", "r");
   printf("Enter Name and Age");
   scanf("%s %d", e.name, &e.age);
   fprintf(p,"%s %d", e.name, e.age);
   fclose(p);
   do
   {
      fscanf(q,"%s %d", e.name, e.age);
      printf("%s %d", e.name, e.age);
   }
   while( !feof(q) );
   getch();
}*/

/*
#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("This is tutorialspoint.com", fp);//SEEK_SET SEEK_CUR SEEK_END	
  
   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Language", fp);
   fclose(fp);
   
   return(0);
}*/
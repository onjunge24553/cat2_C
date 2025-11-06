#include <stdio.h>

void writeInput();
void processInput();
void displayFiles();

int main()
{
 FILE *fp;
 writeInput();
 processInput();
 displayFiles();
 return 0;
}

void writeInput()
{
 FILE *fp;
 int i, num;
 fp = fopen("input.txt","w");
 if(fp == NULL)
 {
  printf("Error opening input.txt for writing\n");
  return;
 }

 printf("Enter 10 integers:\n");
 for(i=0;i<10;i++)
 {
  printf("Number %d: ",i+1);
  scanf("%d",&num);
  fprintf(fp,"%d\n",num);
 }
 fclose(fp);
 printf("Numbers saved to input.txt successfully\n\n");
}

void processInput()
{
 FILE *infile, *outfile;
 int num, sum=0, count=0;
 float average;

 infile = fopen("input.txt","r");
 if(infile == NULL)
 {
  printf("Error opening input.txt for reading\n");
  return;
 }

 while(fscanf(infile,"%d",&num)==1)
 {
  sum = sum + num;
  count++;
 }
 fclose(infile);

 if(count>0)
  average = (float)sum/count;
 else
  average = 0;

 outfile = fopen("output.txt","w");
 if(outfile == NULL)
 {
  printf("Error opening output.txt for writing\n");
  return;
 }

 fprintf(outfile,"Sum = %d\nAverage = %.2f\n",sum,average);
 fclose(outfile);
 printf("Sum and average written to output.txt\n\n");
}

void displayFiles()
{
 FILE *fp;
 char ch;

 printf("---- Contents of input.txt ----\n");
 fp = fopen("input.txt","r");
 if(fp == NULL)
 {
  printf("Error opening input.txt\n");
  return;
 }
 while((ch=fgetc(fp))!=EOF)
  putchar(ch);
 fclose(fp);

 printf("\n---- Contents of output.txt ----\n");
 fp = fopen("output.txt","r");
 if(fp == NULL)
 {
  printf("Error opening output.txt\n");
  return;
 }
 while((ch=fgetc(fp))!=EOF)
  putchar(ch);
 fclose(fp);
}

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
  char *name = argv[1];
  int eng = atoi(argv[2]);  
  int maths = atoi(argv[3]);
int total = eng + maths;
printf("Student name: %s\n",name);
printf("English marks: %d\n",eng);
printf("Maths marks: %d\n",maths);
printf("Total: %d\n",total);
}
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
char f[100]="/home/student/Desktop/lab1/100.txt";
umask(O_WRONLY|O_RDONLY);
int fo = open(f,O_CREAT|O_WRONLY|O_RDONLY);  // opens and returns small positive value
if(fo<0)
{
	perror("c1");
}
return 0;
}

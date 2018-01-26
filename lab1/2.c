#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int fo= open("2.txt",O_WRONLY|O_APPEND|O_RDWR|O_EXCL);  // opens and returns small positive value
if(fo<0)
{
	perror("c1");
 	exit(1);
}
printf("Opened the file= %d\n",fo);
int c=dup(fo);
write(c,"Some other text!\n",16);
write(fo,"Some more text to be written!\n",28);
return 0;
}

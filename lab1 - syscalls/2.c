#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{

int f= open("2.txt",O_WRONLY|O_APPEND);  // opens and returns small positive value
if(f<0)
{
	perror("c1");
 	exit(1);
}
printf("Opened the file= %d\n",f);
int c=dup(f);
write(c,"Some other text!\n",16);
write(f,"Some more text to be written!\n",28);
return 0;
}
/*
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
 
int main()
{
    // open() returns a file descriptor file_desc to a 
    // the file "dup.txt" here"
 
    int file_desc = open("23.txt", O_WRONLY | O_APPEND);
     
    if(file_desc < 0)
        printf("Error opening the file\n");
     
    // dup() will create the copy of file_desc as the copy_desc
    // then both can be used interchangeably.
 
    int copy_desc = dup(file_desc);
         
    // write() will write the given string into the file
    // referred by the file descriptors
 
    write(copy_desc,"This will be output to the file named dup.txt\n", 46);
         
    write(file_desc,"This will also be output to the file named dup.txt\n", 51);
     
    return 0;
}*/

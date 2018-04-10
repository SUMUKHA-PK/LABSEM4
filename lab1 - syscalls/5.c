#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    char mode[] = "0777";
    char buf[100] = "/home/student/Desktop/lab1/1.txt";
    int i;
    i = strtol(mode, 0, 8);
    if (chmod (buf,i) < 0)
    {
        fprintf(stderr, "error in chmod(%s, %s) - %d (%s)\n", buf, mode, errno, strerror(errno));
        exit(1);
    }
    else
      {
        printf("IT was a SUCCESS\n");
      }
    return(0);
}

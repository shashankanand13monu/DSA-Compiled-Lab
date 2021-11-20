
#include <time.h>
int hi()
{




    printf("\n\n\t\t*********************   Made by - Shashank Anand | 2029028 ******************\n\n");
    time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("\t\t-----> Date & Time : %d-%02d-%02d %02d:%02d:%02d\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("\n\n");
    // test();

    return 0;
}

#include <curses.h>
#include <time.h>
#include <string.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

#ifdef __linux__
#endif

typedef char* string;

int main() {
    FILE *f;
    f = fopen("result.txt", "a+");
    int symbol;
    char result[1024] = "";
    int n = 0;
    long int ttime1, ttime2;
    ttime1 = time(NULL);
    initscr();
    while(1){
        noecho();
        symbol = getchar();
        cbreak();
        result[n] = symbol;
        n++;
        ttime2 = time(NULL);
        if(ttime2 - ttime1 >= 5) {
            n = 0;
            ttime1 = ttime2;
            f = fopen("result.txt", "a+");
            struct tm *m_time;
            char str_t[128]="";
            m_time = localtime (&ttime2);
            strftime (str_t, 128, "Date:  %x %A %X %Z", m_time);
            fputs(str_t, f);
            fputs(" ", f);
            fputs(result, f);
            fputs("\n", f);
            fclose(f);
            memset(result, '\0', 1024);
        }
    }
    return 0;
}

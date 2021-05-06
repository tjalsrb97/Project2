#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main()
{
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1()
{
    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2()
{
    stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1()
{
    time1 = localtime(&(stat1.st_mtime));
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2()
{
    time2 = localtime(&(stat2.st_mtime));
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp()
{
    printf("size compare\n");
    if (stat1.st_size > stat2.st_size)
        printf("text1 is bigger\n\n");
    else if (stat1.st_size == stat2.st_size)
        printf("sizes are equal\n\n");
    else
        printf("text2 is bigger\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp()
{
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks)
        printf("text1 is bigger\n\n");
    else if (stat1.st_blocks == stat2.st_blocks)
        printf("sizes are equal\n\n");
    else
        printf("text2 is bigger\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp()
{
    int result1, result2;
    int tm_year1, tm_month1, tm_day1;
    int tm_year2, tm_month2, tm_day2;
    printf("date compare\n");

    time1 = localtime(&stat1.st_mtime);
    tm_year1 = (time1->tm_year + 1900);
    tm_day1 = time1->tm_yday;

    time2 = localtime(&stat2.st_mtime);
    tm_year2 = (time2->tm_year + 1900);
    tm_day2 = time2->tm_yday;

    result1 = tm_year1 + tm_day1;
    result2 = tm_year2 + tm_day2;

    if (result1 < result2)
    {
        printf("text1 is early\n");
    }
    else if (result1 > result2)
    {
        printf("text2 is early\n");
    }
    else
        printf("same time\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp()
{
    int result1, result2;
    int tm_hour1, tm_min1;
    int tm_hour2, tm_min2;
    printf("time compare\n");

    time1 = localtime(&stat1.st_mtime);
    tm_hour1 = (time1->tm_hour) * 60;
    tm_min1 = time1->tm_min;

    time2 = localtime(&stat2.st_mtime);
    tm_hour2 = (time2->tm_hour) * 60;
    tm_min2 = time2->tm_min;

    result1 = tm_hour1 + tm_min1;
    result2 = tm_hour2 + tm_min2;
    if (result1 < result2)
    {
        printf("text1 is early\n");
    }
    else if (result1 > result2)
    {
        printf("text2 is early\n");
    }
    else
        printf("same time\n");
}


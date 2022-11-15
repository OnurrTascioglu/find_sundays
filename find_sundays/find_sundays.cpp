#include <iostream>
#define NUMBEROFMONTHS 12
#define NUMBEROFDAYS 7

std::string days[] = { "Pzt","Sal","Car","Per","Cum","Cmt","Pzr"};
std::string months[] = {"Oca","Sub","Mar","Nis","May","Haz","Tem", "Agu", "Eyl", "Eki","Kas","Ara"};
int num_of_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct date{
    int day = 0;
    int month = 0;
    int year = 0;
    std::string start_day;
} startDate, endDate;

void findSundays(date startDate,date endDate) {
    int day = 0;
    for (int i = NUMBEROFDAYS ; i > 0; i--) {  
        if (startDate.start_day == days[i-1]) day = NUMBEROFDAYS - i;  // baslangic gununun pazar gunune ne kadar uzak oldugu bulunur
    }

    int first_month_of_year = 0;
    for (int i = startDate.year; i <= endDate.year; i++) {
        if (i == startDate.year) {                 // ilk yilda baslagic tarihi atanir.
            first_month_of_year = startDate.month-1;
            day += startDate.day;                  // ilk pazar gununun tarihi              
        }
        else {
            first_month_of_year = 0;
        }
        for (int j = first_month_of_year; j < NUMBEROFMONTHS; j++) {
            if (months[j] == "Sub") {        // subat ayinin 4 yilda 29 cekmesi
                if (i % 100 == 0 && i % 400 !=0)       // 100e kalansiz, 400e kalanli bolunen yillara artik gun eklenmez
                    num_of_days[j] = 28;
                else if (i % 4 == 0) 
                    num_of_days[j] = 29;
                else 
                    num_of_days[j] = 28;
            }
            std::cout << day << "." << months[j] << "." << i << std::endl;
            while (true) {
                day += NUMBEROFDAYS;
                if (day > num_of_days[j]) {
                    day %= num_of_days[j];     //bir sonraki ayin ilk pazari
                    break;
                }
            }
        }
    }
}

int main()
{
    startDate.day = 13;
    startDate.month = 6;
    startDate.year = 1900;
    startDate.start_day = "Car";

    endDate.day = 31;
    endDate.month = 12;
    endDate.year = 2022;

    findSundays(startDate,endDate);

    return 0;
}


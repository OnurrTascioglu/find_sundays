#include <iostream>
#define NUMBEROFMONTHS 12
#define NUMBEROFDAYS 7

const std::string days[] = { "Pzt","Sal","Car","Per","Cum","Cmt","Pzr"};
const std::string months[] = {"Oca","Sub","Mar","Nis","May","Haz","Tem", "Agu", "Eyl", "Eki","Kas","Ara"};
int num_of_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct date{
    int day = 0;
    int month = 0;
    int year = 0;
    std::string start_day;
} startDate, endDate;

class Month{
public:
    Month(){}
    Month(std::string name, int number_of_days) {
        this->name = name;
        this->number_of_days = number_of_days;
    }

    void setName(std::string s) {name = s;}
    std::string getName() {return name;}
    void setNumberOfDays(int n) { number_of_days = n;}
    int GetNumberOfDays() {return number_of_days;}

private:
    std::string name;
    int number_of_days = 0 ;
};

void findSundays(Month* months,date startDate,date endDate) {
    int count = 0;
    for (int i = 0; i < NUMBEROFDAYS; i++) {  // ilk pazar
        if (startDate.start_day != days[i]) count++;
        else break;
    }

    int total_years = endDate.year - startDate.year;
    int day = count;
    for (int i = startDate.year; i <= endDate.year; i++) {
        for (int j = 0; j < NUMBEROFMONTHS; j++) {
            if (months[j].getName() == "Sub" && i != 1900) {   // subat ayýnýn 4 yýlda bir kontrol edilmesi, 1900 yýlýnda þubat ayý 29 çekmemiþtir!
                if (i % 4 == 0) 
                    months[j].setNumberOfDays(29);
                else 
                    months[j].setNumberOfDays(28);
            }
            std::cout << day << "." << months[j].getName() << "." << i << std::endl;
            while (true) {
                day = day + NUMBEROFDAYS;
                if (day > months[j].GetNumberOfDays()) {
                    day = day % months[j].GetNumberOfDays();
                    break;
                }
            }
        }
    }
}

int main()
{
    startDate.day = 1;
    startDate.month = 1;
    startDate.year = 1900;
    startDate.start_day = "Pzt";

    endDate.day = 31;
    endDate.month = 12;
    endDate.year = 2022;

    Month m[NUMBEROFMONTHS];

    for (int i = 0; i < NUMBEROFMONTHS; i++) {
        m[i] = Month(months[i], num_of_days[i]);
    }

    findSundays(m, startDate,endDate);

    return 0;
}


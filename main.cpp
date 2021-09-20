#include "Date.h"

void task1()
{
    _ptr<Date> today(new Date(20, 9, 2021));

    std::cout << "Day: " << today->getDay() << std::endl;
    std::cout << "Month: " << today->getMonth() << std::endl;
    std::cout << "Year: " << today->getYear() << std::endl;
    std::cout << "today: " << *today << std::endl;

    _ptr<Date> date;

    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

    date = today;

    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

    std::cout << "date: " << *date << std::endl;
}

const _ptr<Date>& compares_dates(const _ptr<Date>& a, const _ptr<Date>& b)
{
    if (a->getYear() > b->getYear())
        return a;
    else if (a->getYear() < b->getYear())
        return b;
    else
    {
        if (a->getMonth() > b->getMonth())
            return a;
        else if (a->getMonth() < b->getMonth())
            return b;
        else
        {
            if (a->getDay() > b->getDay())
                return a;
            else
                return b;
        }
    }
}

void swap_dates(_ptr<Date>& a, _ptr<Date>& b)
{
    _ptr<Date> temp(a);
    a = b;
    b = temp;
}

void task2()
{
    _ptr<Date> date1(new Date(19, 9, 2022));
    _ptr<Date> date2(new Date(20, 9, 2022));
    _ptr<Date> date3(new Date(21, 9, 2022));

    std::cout << *compares_dates(date1, date2) << std::endl;
    swap_dates(date2, date3);
    std::cout << *compares_dates(date1, date2) << std::endl;
}

int main()
{
    task1();
    task2();

    return 0;
}


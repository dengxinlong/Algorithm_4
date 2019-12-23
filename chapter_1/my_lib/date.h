#ifndef __DATE_H__
#define __DATE_H__

#include <string>

using namespace std;

// class Date
// {
// public:
//     Date(int month, int day, int year)
//     : _month(month)
//     , _day(day)
//     , _year(year)
//     {}

//     int day(void)   {   return _day;    }
//     int month(void) { return _month; }
//     int year(void)  { return _year; }

//     string to_string(void)
//     {
//         return  std::to_string(_month) + "/" + std::to_string(_day) + "/" + std::to_string(_year);
//     }

// private:
//     const int _month;
//     const int _day;
//     const int _year;
// };


class Date
{
public:
    Date(int month, int day, int year)
    : _value(year * 512 + month * 32 + day)
    {}

    int day(void)   {   return _value % 32;    }
    int month(void) { return (_value / 32) % 16; }
    int year(void)  { return _value / 512; }

    string to_string(void)
    {
        return  std::to_string(month()) + "/" + std::to_string(day()) + "/" + std::to_string(year());
    }

private:
    const int _value;
};





#endif
#include <iostream>
#include <stdexcept>
#include <vector>

class Date {
  int32_t day, month, year;

public:
  [[nodiscard]] bool IsLeapYear(int32_t y) const {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
  }

  [[nodiscard]] int32_t CountLeapYears() const {
    int years = year;
    if (month <= 2) {
      years--;
    }

    return years / 4 - years / 100 + years / 400;
  }

  int32_t DaysInMonth(int32_t m, int32_t y) const {
    int32_t leap_year = IsLeapYear(y) ? 29 : 28;
    std::vector<int32_t> days{31, leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m - 1];
  }

  Date(int32_t d, int32_t m, int32_t y) {
    if (y < 1970 || y > 2099) {
      throw std::invalid_argument("Invalid date");
    }

    if (m < 0 || m > 12) {
      throw std::invalid_argument("Invalid date");
    }

    if (d < 0 || d > DaysInMonth(m, y))  {
      throw std::invalid_argument("Invalid date");
    }

    day = d;
    month = m;
    year = y;
  }

  int32_t GetDay() const {
    return day;
  }

  int32_t GetMonth() const {
    return month;
  }

  int32_t GetYear() const {
    return year;
  }

  Date& operator++() {
    int32_t days_in_month = DaysInMonth(month, year);
    if (day + 1 > days_in_month) {
      if (month == 12) {
        day = 1;
        month = 1;
        year++;
      } else {
        day = 1;
        month++;
      }
    } else {
      day++;
    }

    return *this;
  }

  Date& operator--() {
    if (day == 1) {
      if (month == 1) {
        year--;
        month = 12;
        day = 31;
      } else {
        month--;
        day = DaysInMonth(month, year);
      }
    } else {
      day--;
    }

    return *this;
  }

  Date operator+(int32_t d_to_add) const {
    Date date{day, month, year};
    while (d_to_add-- > 0) {
      ++date;
    }

    return date;
  }

  Date operator-(int32_t d_to_remove) const {
    Date date{day, month, year};
    while (d_to_remove-- > 0) {
      --date;
    }

    return date;
  }

  int32_t operator-(const Date& rhs) const {
    int32_t days_lhs = year * 365 + day;
    for (int i = 0; i < month - 1; i++) {
      if (i == 1) {
        days_lhs += 28;
      } else {
        days_lhs += DaysInMonth(i + 1, year);
      }
    }
    days_lhs += CountLeapYears();

    int32_t days_rhs = rhs.year * 365 + rhs.day;
    for (int i = 0; i < rhs.month - 1; i++) {
      if (i == 1) {
        days_rhs += 28;
      } else {
        days_rhs += DaysInMonth(i + 1, rhs.year);
      }
    }
    days_rhs += rhs.CountLeapYears();

    return days_lhs - days_rhs;
  }
};
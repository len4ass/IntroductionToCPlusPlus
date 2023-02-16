#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>

class Date {
  int32_t day;

public:
  explicit Date(int32_t d) {
    day = d;
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

    day = DifferenceBetweenCorrectDates(d, m, y, 1, 1, 1970);
  }

  [[nodiscard]] static bool IsLeapYear(int32_t y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
  }

  [[nodiscard]] static int32_t DaysInMonth(int32_t m, int32_t y) {
    int32_t leap_year = IsLeapYear(y) ? 29 : 28;
    std::vector<int32_t> days{31, leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m - 1];
  }

  [[nodiscard]] static int32_t CountLeapYears(int32_t month, int32_t year) {
    if (month <= 2) {
      year--;
    }

    return year / 4 - year / 100 + year / 400;
  }

  [[nodiscard]] std::tuple<int32_t, int32_t, int32_t> GetDate() const {
    std::vector<int32_t> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int32_t current_day = 0;
    int32_t d = 1, m = 1, y = 1970;

    while (current_day++ != day) {
      bool is_leap_year = IsLeapYear(y);
      days[1] = is_leap_year ? 29 : 28;

      if (d + 1 > days[m - 1]) {
        if (m == 12) {
          d = 1;
          m = 1;
          y++;
        } else {
          d = 1;
          m++;
        }
      } else {
        d++;
      }
    }

    return std::tie(d, m, y);
  }

  [[nodiscard]] int32_t GetDay() const {
    const auto& [d, m, y] = GetDate();
    return d;
  }

  [[nodiscard]] int32_t GetMonth() const {
    const auto& [d, m, y] = GetDate();
    return m;
  }

  [[nodiscard]] int32_t GetYear() const {
    const auto& [d, m, y] = GetDate();
    return y;
  }

  Date& operator++() {
    day++;
    return *this;
  }

  Date& operator--() {
    day--;
    return *this;
  }

  Date operator+(int32_t d_to_add) const {
    Date date{day};
    while (d_to_add-- > 0) {
      ++date;
    }

    return date;
  }

  Date operator-(int32_t d_to_remove) const {
    Date date{day};
    while (d_to_remove-- > 0) {
      --date;
    }

    return date;
  }

  int32_t operator-(const Date& rhs) const {
    return day - rhs.day;
  }

  [[nodiscard]] static int32_t DifferenceBetweenCorrectDates(
      int32_t lhs_d, int32_t lhs_m, int32_t lhs_y,
      int32_t rhs_d, int32_t rhs_m, int32_t rhs_y) {
    int32_t days_lhs = lhs_y * 365 + lhs_d;
    for (int i = 0; i < lhs_m - 1; ++i) {
      if (i == 1) {
        days_lhs += 28;
      } else {
        days_lhs += DaysInMonth(i + 1, lhs_y);
      }
    }
    days_lhs += CountLeapYears(lhs_m, lhs_y);

    int32_t days_rhs = rhs_y * 365 + rhs_d;
    for (int i = 0; i < rhs_m - 1; ++i) {
      if (i == 1) {
        days_rhs += 28;
      } else {
        days_rhs += DaysInMonth(i + 1, rhs_y);
      }
    }
    days_rhs += CountLeapYears(rhs_m, rhs_y);

    return days_lhs - days_rhs;
  }
};
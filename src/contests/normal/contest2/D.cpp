#include <iostream>
#include <vector>

struct Time {
  int32_t day;
  int32_t hour;
  int32_t minute;

public:
  Time(int32_t d, int32_t h, int32_t m) {
    day = d;
    hour = h;
    minute = m;
  }
};

int32_t operator-(Time &lhs, Time &rhs) {
  int32_t lhs_minutes = lhs.day * 24 * 60 + lhs.hour * 60 + lhs.minute;
  int32_t rhs_minutes = rhs.day * 24 * 60 + rhs.hour * 60 + rhs.minute;

  if (rhs.day == 0) {
    if (lhs.hour * 60 + lhs.minute <= rhs.hour * 60 + rhs.minute) {
      return rhs.hour * 60 + rhs.minute - lhs.hour * 60 - lhs.minute;
    }

    return 60 * 24 + rhs.hour * 60 + rhs.minute - lhs.hour * 60 - lhs.minute;
  }

  if (rhs_minutes >= lhs_minutes) {
    return rhs_minutes - lhs_minutes;
  }

  return 7 * 24 * 60 + rhs_minutes - lhs_minutes;
}

int main() {
  int32_t k, d, h, m;
  std::cin >> d >> h >> m >> k;
  Time main = Time(d, h, m);

  int32_t current_day, current_hour, current_minute;
  int32_t best_day, best_hour, best_minute;
  int32_t nigger_t = 1e9;

  for (int i = 0; i < k; i++) {
    std::cin >> current_day >> current_hour >> current_minute;
    Time t = Time(current_day, current_hour, current_minute);

    int32_t diff = main - t;
    if (diff < nigger_t) {
      nigger_t = diff;

      best_hour = current_hour;
      best_minute = current_minute;

      if (current_day == 0 && diff > 12 * 60) {
        if ((d + 1) % 7 == 0) {
          current_day = 7;
        } else {
          current_day = (d + 1) % 7;
        }
      } else if (current_day == 0) {
        current_day = d;
      }

      best_day = current_day;
    }
  }

  std::cout << best_day << " " <<  best_hour << " " << best_minute << std::endl;
  return 0;
}
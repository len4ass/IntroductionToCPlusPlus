#include <iostream>
#include <vector>
#include <cmath>

struct Person {
  std::string name;
  std::string last_name;
  int day;
  int month;
  int year;

public:
  Person(std::string n, std::string ln, int d, int m, int y) {
    name = n;
    last_name = ln;
    day = d;
    month = m;
    year = y;
  }
};

bool sort_lex(Person first, Person second) {
  if (first.last_name == second.last_name) {
    if (first.name == second.name) {
      if (first.year == second.year) {
        if (first.month == second.month) {
          if (first.day == second.day) {
            return false;
          } else {
            return first.day < second.day;
          }
        } else {
          return first.month < second.month;
        }
      } else {
        return first.year < second.year;
      }
    } else {
      return first.name < second.name;
    }
  } else {
    return first.last_name < second.last_name;
  }
}

bool sort_day(Person first, Person second) {
  if (first.day == second.day && first.month == second.month && first.year == second.year) {
    if (first.last_name == second.last_name) {
      if (first.name == second.name) {
        return false;
      } else {
        return first.name < second.name;
      }
    } else {
      return first.last_name < second.last_name;
    }
  } else {
    if (first.year == second.year) {
      if (first.month == second.month) {
        if (first.day == second.day) {
          return false;
        } else {
          return first.day < second.day;
        }
      } else {
        return first.month < second.month;
      }
    } else {
      return first.year < second.year;
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<Person> people;
  for (int i = 0; i < n; ++i) {
    std::string name, last_name;
    int day, month, year;
    std::cin >> name >> last_name >> day >> month >> year;

    Person person = Person(name, last_name, day, month, year);
    people.push_back(person);
  }

  std::string type;
  std::cin >> type;
  if (type == "date") {
    std::sort(people.begin(), people.end(), &sort_day);
  } else if (type == "name") {
    std::sort(people.begin(), people.end(), &sort_lex);
  }

  for (const auto &person : people) {
    std::cout << person.name << " "
              << person.last_name << " " << person.day << "." << person.month << "."
              << person.year << std::endl;
  }

  return 0;
}
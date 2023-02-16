#include <iostream>
#include <map>
#include <utility>
#include <vector>

struct Student {
  std::string name, surname;
  int32_t day, month, year, points;
  std::vector<std::string> university_list;
};

bool SortForApplications(const Student& lhs, const Student& rhs) {
  if (lhs.points == rhs.points) {
    return std::tie(lhs.year, lhs.month, lhs.day, lhs.surname, lhs.name) <
           std::tie(rhs.year, rhs.month, rhs.day, rhs.surname, rhs.name);
  }

  return lhs.points > rhs.points;
}

bool SortForOutput(const Student& lhs, const Student& rhs) {
  return std::tie(lhs.surname, lhs.name, lhs.year, lhs.month, lhs.day) <
         std::tie(rhs.surname, rhs.name, rhs.year, rhs.month, rhs.day);
}

void GetUniversities(std::map<std::string, int32_t>& u_map) {
  int32_t universities_amount;
  std::cin >> universities_amount;

  std::string university_name;
  int32_t university_slots;
  for (int32_t i = 0; i < universities_amount; ++i) {
    std::cin >> university_name >> university_slots;
    u_map[university_name] = university_slots;
  }
}

void GetStudents(std::vector<Student>& students) {
  int32_t students_amount;
  std::cin >> students_amount;

  std::string name, surname, current_university;
  int32_t day, month, year, points, universities_count;
  std::vector<std::string> universities;

  for (int32_t i = 0; i < students_amount; ++i) {
    std::cin >> name >> surname >> day >> month >> year >> points >> universities_count;

    universities.resize(universities_count);
    for (int32_t j = 0; j < universities_count; ++j) {
      std::cin >> current_university;
      universities[j] = current_university;
    }

    Student student{name, surname, day, month, year, points, std::move(universities)};
    students.push_back(student);
    universities.clear();
  }
}

int main() {
  std::vector<Student> students;
  std::map<std::string, int32_t> university_map;
  std::map<std::string, std::vector<Student>> output_result;

  GetUniversities(university_map);
  GetStudents(students);

  std::sort(students.begin(), students.end(), SortForApplications);
  for (const auto& student : students) {
    for (const auto& u_name : student.university_list) {
      if (university_map[u_name] > 0) {
        output_result[u_name].push_back(student);
        --university_map[u_name];
        break;
      }
    }
  }

  // std::sort(output_result.begin(), output_result.end());
  for (auto& [key, value] : university_map) {
    if (output_result.find(key) == output_result.end()) {
      output_result[key] = {};
    }
  }
  for (auto& university : output_result) {
    std::sort(university.second.begin(), university.second.end(), SortForOutput);
    std::cout << university.first;

    for (const auto& student_applied : university.second) {
      std::cout << "\t" << student_applied.name << " " << student_applied.surname;
    }
    std::cout << std::endl;
  }
  return 0;
}
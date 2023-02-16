#include <map>
#include <stdexcept>
#include <string>
#include <vector>

class Monitor {
private:
  // удобные псевдонимы типов для краткости:
  using Ptr = StudentResults*;
  using ConstPtr = const StudentResults*;

  std::map<std::string, Ptr> by_student;
  std::map<std::string, std::vector<ConstPtr>> by_group;
  std::vector<ConstPtr> all_results;

public:
  Monitor() = default;
  Monitor(const Monitor&) = delete;
  Monitor& operator=(const Monitor&) = delete;

  Ptr RegisterStudent(const std::string& login, const std::string& group) {
    if (by_student.contains(login)) {
      throw std::invalid_argument("Student is already registered");
    }
    // Добавить новую запись о студенте и вернуть ее
    Ptr student_ptr = new StudentResults(login, group);
    by_student[login] = student_ptr;
    by_group[group].push_back(student_ptr);
    all_results.push_back(student_ptr);
    return student_ptr;
  }

  Ptr GetStudentResults(const std::string& login) {
    return by_student.at(login);
  }

  ConstPtr GetStudentResults(const std::string& login) const {
    return by_student.at(login);
  }

  std::vector<ConstPtr> GetGroupResults(const std::string& group) const {
    return by_group.at(group);
  }

  std::vector<ConstPtr> GetAllResults() const {
    return all_results;
  }

  ~Monitor() {
    for (auto result : all_results) {
      delete result;
    }
  }
};
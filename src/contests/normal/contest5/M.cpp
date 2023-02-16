#include <iostream>
#include <string>

class Vim {
  bool edit_mode = false;
  size_t text_position = 0;
  std::string text;

public:
  Vim() = default;

  void Replace(std::string& s, const std::string& to_replace, const std::string& replacement) {
    size_t position = s.find(to_replace);
    while (position != std::string::npos) {
      s.replace(position, to_replace.size(), replacement);
      position = s.find(to_replace, position + replacement.size());
    }
  }

  void Parse(std::string& input) {
    Replace(input, "<ESC>", ";");
    for (char c : input) {
      if (!edit_mode) {
        if (c == 'i') {
          edit_mode = true;
          continue;
        } else if (c == 'h') {
          if (text_position - 1 != std::numeric_limits<size_t>::max()) {
            text_position--;
            continue;
          }
        } else if (c == 'l') {
          if (text_position + 1 <= text.size()) {
            text_position++;
            continue;
          }
        }
      } else {
        if (c == ';') {
          edit_mode = false;
          continue;
        } else {
          text = text.insert(text_position, 1, c);
          text_position++;
          continue;
        }
      }
    }
  }

  std::string GetText() {
    return text;
  }
};

int main() {
  std::string s;
  std::getline(std::cin, s);

  Vim v;
  v.Parse(s);

  std::cout << v.GetText() << std::endl;
}
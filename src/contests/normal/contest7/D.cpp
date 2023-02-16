#include "classifiers.h"
#include <memory>
#include <iostream>

class CombinedClassifier {
public:
  CombinedClassifier(const std::string& s, const std::string& s2) {
    init_datas1_ = s;
    f_cl = std::make_unique<FastClassifier>(init_datas1_);

    init_datas2_ = s2;
  }

  double classify(const string& s) {
    double result;
    try {
      result = f_cl->classify(s);
    } catch (TooHardObjectException& v) {
      if (m_cl == nullptr) {
        m_cl = std::make_unique<MainClassifier>(init_datas2_);
      }

      result = m_cl->classify(s);
    }

    return result;
  }
private:
  std::string init_datas1_;
  std::string init_datas2_;
  std::unique_ptr<FastClassifier> f_cl;
  std::unique_ptr<MainClassifier> m_cl;
};
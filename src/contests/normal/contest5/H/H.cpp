#include <cmath>

class Complex {
  double real, imaginary;

public:
  explicit Complex(double r) {
    real = r;
    imaginary = 0;
  }

  Complex(double r, double i) {
    real = r;
    imaginary = i;
  }

  [[nodiscard]] double Re() const {
    return real;
  }

  [[nodiscard]] double Im() const {
    return imaginary;
  }

  Complex operator+() const {
    return *this;
  }

  Complex operator-() const {
    return {-real, -imaginary};
  }

  Complex operator+(const Complex& rhs) const {
    return {real + rhs.real, imaginary + rhs.imaginary};
  }

  Complex operator+(const double rhs) const {
    return {real + rhs, imaginary};
  }

  Complex operator-(const Complex& rhs) const {
    return {real - rhs.real, imaginary - rhs.imaginary};
  }

  Complex operator-(const double rhs) const {
    return {real - rhs, imaginary};
  }

  Complex operator*(const Complex& rhs) const {
    return {real * rhs.real - imaginary * rhs.imaginary,
            real * rhs.imaginary + imaginary * rhs.real};
  }

  Complex operator*(const double rhs) const {
    return {real * rhs, imaginary * rhs};
  }

  Complex operator/(const Complex& rhs) const {
    return {(real * rhs.real + imaginary * rhs.imaginary) /
                (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary),
            (rhs.real * imaginary - real * rhs.imaginary) /
                (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary)};
  }

  Complex operator/(const double rhs) const {
    return {real / rhs, imaginary / rhs};
  }

  bool operator==(const Complex& rhs) const {
    return real == rhs.real && imaginary == rhs.imaginary;
  }

  bool operator!=(const Complex& rhs) const {
    return real != rhs.real || imaginary != rhs.imaginary;
  }
};

Complex operator+(const double lhs, const Complex& rhs) {
  return {lhs + rhs.Re(), rhs.Im()};
}

Complex operator-(const double lhs, const Complex& rhs) {
  return {lhs - rhs.Re(), rhs.Im()};
}

Complex operator*(const double lhs, const Complex& rhs) {
  return {lhs * rhs.Re(), lhs * rhs.Im()};
}

Complex operator/(const double lhs, const Complex& rhs) {
  return {(lhs * rhs.Re()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()),
          (-lhs * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im())};
}

double Abs(const Complex& comp) {
  return std::sqrt(comp.Re() * comp.Re() + comp.Im() * comp.Im());
}


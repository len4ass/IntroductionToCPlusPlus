#include <iostream>
#include <numeric>
class Rational {
  int32_t numerator, denominator;

public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int32_t n) {
    numerator = n;
    denominator = 1;
  }

  Rational(int32_t n, int32_t d) {
    if (n == 0) {
      numerator = 0;
      denominator = 1;
    } else {
      numerator = n;
      denominator = d;
      Reduce();
    }
  }

  void Reduce() {
    int32_t gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  [[nodiscard]] int32_t Numerator() const {
    return numerator;
  }

  [[nodiscard]] int32_t Denominator() const {
    return denominator;
  }

  Rational operator+() {
    return *this;
  }

  Rational operator-() {
    Rational r{-numerator, denominator};
    r.Reduce();
    return r;
  }

  friend Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational r{lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator};
    r.Reduce();
    return r;
  }

  friend Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational r{lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator};
    r.Reduce();
    return r;
  }

  friend Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational r{lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator};
    r.Reduce();
    return r;
  }

  friend Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational r{lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator};
    r.Reduce();
    return r;
  }

  Rational& operator+=(const Rational& rhs) {
    numerator *= rhs.denominator;
    numerator += (rhs.numerator * denominator);
    denominator *= rhs.denominator;
    Reduce();
    return *this;
  }

  Rational& operator-=(const Rational& rhs) {
    numerator *= rhs.denominator;
    numerator -= (rhs.numerator * denominator);
    denominator *= rhs.denominator;
    Reduce();
    return *this;
  }

  Rational& operator*=(const Rational& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    Reduce();
    return *this;
  }

  Rational& operator/=(const Rational& rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    Reduce();
    return *this;
  }

  Rational& operator++() {
    numerator += denominator;
    Reduce();
    return *this;
  }

  Rational& operator--() {
    numerator -= denominator;
    Reduce();
    return *this;
  }

  Rational operator++(int) {
    Rational r{numerator, denominator};
    r.Reduce();
    operator++();
    return r;
  }

  Rational operator--(int) {
    Rational r{numerator, denominator};
    r.Reduce();
    operator--();
    return r;
  }

  bool operator==(const Rational& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
  }

  bool operator!=(const Rational& rhs) const {
    return numerator != rhs.numerator || denominator != rhs.denominator;
  }
};
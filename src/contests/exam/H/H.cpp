class Figure {
public:
  virtual int Perimeter() const = 0;
  virtual ~Figure() {}
};

class Rectangle : public Figure {
  int a, b;
public:
  Rectangle(int A, int B): a(A), b(B) {}

  int Perimeter() const override {
    return 2 * (a + b);
  }
};

class Triangle : public Figure {
  int a, b, c;
public:
  Triangle(int A, int B, int C): a(A), b(B), c(C) {}

  int Perimeter() const override {
    return a + b + c;
  }
};


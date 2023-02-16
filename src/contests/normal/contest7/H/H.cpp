template<typename T>
class IntegrationMethod {
public:
  virtual double Integrate(T f, double x, double y, int n) = 0;

  virtual ~IntegrationMethod() = default;
};

template<typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
  double Integrate(T f, double x, double y, int n) override {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      double x_k = x + ((y - x) / n) * i;
      double x_k_1 = x + ((y - x) / n) * (i + 1);
      sum += f((x_k + x_k_1) / 2) * (x_k_1 - x_k);
    }
    return sum;
  }

  virtual ~RectangleRule() = default;
};

template<typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
  double Integrate(T f, double x, double y, int n) override {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      double x_k = x + ((y - x) / n) * i;
      double x_k_1 = x + ((y - x) / n) * (i + 1);
      sum += ((f(x_k) + f(x_k_1)) / 2) * (x_k_1 - x_k);
    }
    return sum;
  }

  virtual ~TrapezoidalRule() = default;
};
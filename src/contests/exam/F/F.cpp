class B : public A {
private:
  A a_class;
public:
  B(): A(42), a_class(17) {}
};
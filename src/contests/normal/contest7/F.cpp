class ConstantExpression: public Expression {
public:
  ConstantExpression(int32_t val): constant(val) {}

  std::string ToString() const override {
    return std::to_string(constant);
  }

  int Evaluate() const override {
    return constant;
  }

private:
  int32_t constant;
};

class OperationExpression: public Expression {
public:
  OperationExpression(ExpressionPtr lhs, ExpressionPtr rhs): left_operand(lhs), right_operand(rhs) {}

  ExpressionPtr GetLeftOperand() const {
    return left_operand;
  }

  ExpressionPtr GetRightOperand() const {
    return right_operand;
  }

private:
  ExpressionPtr left_operand;
  ExpressionPtr right_operand;
};

class SumOperation: public OperationExpression {
public:
  SumOperation(ExpressionPtr lhs, ExpressionPtr rhs): OperationExpression(lhs, rhs) {}

  std::string ToString() const override {
    return GetLeftOperand()->ToString() + " + " + GetRightOperand()->ToString();
  }

  int Evaluate() const override {
    return GetLeftOperand()->Evaluate() + GetRightOperand()->Evaluate();
  }
};

class ProductOperation: public OperationExpression {
public:
  ProductOperation(ExpressionPtr lhs, ExpressionPtr rhs): OperationExpression(lhs, rhs) {}

  std::string ToString() const override {
    std::string left = dynamic_cast<SumOperation*>(GetLeftOperand().get())
                           ? "(" + GetLeftOperand()->ToString() + ")"
                           : GetLeftOperand()->ToString();
    std::string right = dynamic_cast<SumOperation*>(GetRightOperand().get())
                            ? "(" + GetRightOperand()->ToString() + ")"
                            : GetRightOperand()->ToString();

    return left + " * " + right;
  }

  int Evaluate() const override {
    return GetLeftOperand()->Evaluate() * GetRightOperand()->Evaluate();
  }
};

ExpressionPtr Const(int32_t v) {
  return ExpressionPtr(new ConstantExpression(v));
}

ExpressionPtr Sum(ExpressionPtr lhs, ExpressionPtr rhs) {
  return ExpressionPtr(new SumOperation(lhs, rhs));
}

ExpressionPtr Product(ExpressionPtr lhs, ExpressionPtr rhs) {
  return ExpressionPtr(new ProductOperation(lhs, rhs));
}
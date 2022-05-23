class Expression
{
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

class Number : public Expression
{
public:
    Number(double Value)  { value = Value;  }
    ~Number() {};
    double evaluate() const { return value; }


private:
    double value;
};

class BinaryOperation : public Expression
{
    BinaryOperation(Expression const* Left, char Op, Expression const* Right) {
        left = Left;
        right = Right;
        op = Op;
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() const {

        if (op == '+') {
            return (left->evaluate() + right->evaluate());
        }
        else if (op == '-') {
            return (left->evaluate() - right->evaluate());
        }
        else if (op == '*') {
            return (left->evaluate() * right->evaluate());
        }
        else if (op == '/') {
            return (left->evaluate() / right->evaluate());
        }

    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};
#include <iostream>

class Expression {
public:

	virtual double evaluate() const = 0;

	virtual ~Expression()
	{

	}
};

class Number :public Expression {

public:
	Number(double Value)
	{
		value = Value;
	}

	double evaluate() const
	{
		return value;
	}

private:
	double value;
};


class BinaryOperation :public Expression {

	Expression const* left;
	Expression const* right;
	char op;

public:
	BinaryOperation(Expression const* Left, char Op, Expression const* Right)
	{
		left = Left;
		right = Right;
		op = Op;
	}
	double evaluate() const
	{
		double k = left->evaluate();

		if (op == '+')
			k += right->evaluate();

		else if (op == '-')
			k -= right->evaluate();

		else if (op == '*')
			k *= right->evaluate();

		else if (op == '/')
			k /= right->evaluate();

		return k;
	}

	~BinaryOperation()
	{
		delete left;
		delete right;
	}
};


bool check_equals(Expression const* left, Expression const* right)
{
	return (*((size_t*)left) == *((size_t*)right));
}



int main()
{
	Expression* prod = new BinaryOperation(new Number(2), '*', new Number(5));

	Expression* lalk = new BinaryOperation(new BinaryOperation(new Number(2), '*', new Number(5)), '+', new BinaryOperation(new Number(2), '*', new Number(5)));

	Expression* x = new Number(5);
	std::cout << lalk->evaluate() << std::endl;

	if (check_equals(lalk, prod))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	if (check_equals(lalk, x))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	delete lalk;
	delete x;

	return 0;
}
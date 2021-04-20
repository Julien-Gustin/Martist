#include "Expression.hpp"
#include <memory>
#include <iostream>
#include <math.h>
#include <vector>
#include <functional>
#include <time.h>
#include <tuple>
// #include "Expressions/Avg_expr.hpp"
// #include "Expressions/Cos_expr.hpp"
// #include "Expressions/Mult_expr.hpp"
// #include "Expressions/Sin_expr.hpp"

std::shared_ptr<Expression> Expression::create_expression(std::string &expression)
{
	char c = expression.back();
	expression.pop_back();

	switch (c)
	{
	case 'x':
		return std::make_shared<X_expr>();
		break;

	case 'y':
		return std::make_shared<Y_expr>();
		break;

	case 's':
		return std::make_shared<Sin_expr>(expression);
		break;

	case 'c':
		return std::make_shared<Cos_expr>(expression);
		break;

	case '*':
		return std::make_shared<Mult_expr>(expression);
		break;

	case 'a':
		return std::make_shared<Avg_expr>(expression);
		break;

	default:
		return nullptr;
		break;
	}
}

std::shared_ptr<Expression> Expression::generate_expression(std::size_t depth, unsigned int *seed, std::string &string_expression)
{
	srand((*seed)++);
	size_t nb_of_try = 1; // in order to allow to have a depth that is not to short 
	std::size_t pos;
	do
	{
		std::size_t limit = depth == 0 ? 2 : 6;
		pos = rand() % limit; // return a number between (0, limiu)
	}while(pos <= 1 && nb_of_try-- > 0);

	switch (pos)
	{
	case 0:
		return std::make_shared<X_expr>(string_expression);
		break;

	case 1:
		return std::make_shared<Y_expr>(string_expression);
		break;

	case 2:
		return std::make_shared<Mult_expr>(depth - 1, seed, string_expression);
		break;

	case 3:
		return std::make_shared<Avg_expr>(depth - 1, seed, string_expression);
		break;

	case 4:
		return std::make_shared<Cos_expr>(depth - 1, seed, string_expression);
		break;

	case 5:
		return std::make_shared<Sin_expr>(depth - 1, seed, string_expression);
		break;

	default:
		return nullptr;
		break;
	}
}

Avg_expr::Avg_expr(std::string &expression)
{
	child_r = Expression::create_expression(expression);
	child_l = Expression::create_expression(expression);
}

double Avg_expr::compute(double x, double y)
{
	return (child_l->compute(x, y) + child_r->compute(x, y)) / 2;
}

std::size_t Avg_expr::get_depth(size_t depth)
{
	return std::max(child_l->get_depth(depth + 1), child_r->get_depth(depth + 1));
}

Avg_expr::Avg_expr(std::size_t depth, unsigned int *seed, std::string &string_expression)
{
	std::string tmp_expression;
	child_r = Expression::generate_expression(depth, seed, tmp_expression);
	string_expression += tmp_expression;
	tmp_expression.clear();
	child_l = Expression::generate_expression(depth, seed, tmp_expression);
	string_expression += tmp_expression;
	string_expression.push_back('a');
}

Cos_expr::Cos_expr(std::string &expression)
{
	child = Expression::create_expression(expression);
}

Cos_expr::Cos_expr(std::size_t depth, unsigned int *seed, std::string &string_expression)
{
	child = Expression::generate_expression(depth, seed, string_expression);
	string_expression.push_back('c');
}

double Cos_expr::compute(double x, double y)
{
	return std::cos(M_PI * child->compute(x, y));
	;
}

std::size_t Cos_expr::get_depth(size_t depth)
{
	return child->get_depth(depth + 1);
}

Sin_expr::Sin_expr(std::string &expression)
{
	child = Expression::create_expression(expression);
}

Sin_expr::Sin_expr(std::size_t depth, unsigned int *seed, std::string &string_expression)
{
	child = Expression::generate_expression(depth, seed, string_expression);
	string_expression.push_back('s');
}

std::size_t Sin_expr::get_depth(size_t depth)
{
	return child->get_depth(depth + 1);
}

double Sin_expr::compute(double x, double y)
{
	return std::sin(M_PI * child->compute(x, y));
}

Mult_expr::Mult_expr(std::string &expression)
{
	child_r = Expression::create_expression(expression);
	child_l = Expression::create_expression(expression);
}

Mult_expr::Mult_expr(std::size_t depth, unsigned int *seed, std::string &string_expression)
{
	std::string tmp_expression;
	child_r = Expression::generate_expression(depth, seed, tmp_expression);
	string_expression += tmp_expression;
	tmp_expression.clear();
	child_l = Expression::generate_expression(depth, seed, tmp_expression);
	string_expression += tmp_expression;
	string_expression.push_back('*');
}

std::size_t Mult_expr::get_depth(size_t depth)
{
	return std::max(child_l->get_depth(depth + 1), child_r->get_depth(depth + 1));
}

double Mult_expr::compute(double x, double y)
{
	return (child_l->compute(x, y) * child_r->compute(x, y));
}

X_expr::X_expr(std::string &string_expression) { string_expression.push_back('x'); }
X_expr::X_expr() {}

std::size_t X_expr::get_depth(size_t depth)
{
	return depth;
}

double X_expr::compute(double x, double y)
{
	return x;
}

Y_expr::Y_expr(std::string &string_expression) { string_expression.push_back('y'); }

double Y_expr::compute(double x, double y)
{
	return y;
}

std::size_t Y_expr::get_depth(size_t depth)
{
	return depth;
}

Y_expr::Y_expr() {}

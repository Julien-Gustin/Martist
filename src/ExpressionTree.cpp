#include "ExpressionTree.hpp"

#include <math.h>
#include <string.h>

std::unique_ptr<ExpressionTree> ExpressionTree::createNode(std::string &expression)
{
    const char c = expression.back();
    expression.pop_back();

    switch (c)
    {
    case 'x':
        return std::make_unique<X_expr>();

    case 'y':
        return std::make_unique<Y_expr>();

    case 's':
        return std::make_unique<Sin_expr>(expression);

    case 'c':
        return std::make_unique<Cos_expr>(expression);

    case '*':
        return std::make_unique<Mult_expr>(expression);

    case 'a':
        return std::make_unique<Avg_expr>(expression);

    default:
        return nullptr;
    }
}

std::unique_ptr<ExpressionTree> ExpressionTree::generateRandomeTree(const std::size_t depth, std::string &expression)
{
    size_t nb_of_try = 2; // in order to allow to have a depth that is not to short
    std::size_t pos;
    do
    {
        std::size_t limit = depth == 1 ? 2 : NB_OF_EXPRESSION;
        pos = rand() % limit; // return a number between (0, limit)
    } while (pos <= 1 && nb_of_try-- > 0);

    switch (pos)
    {
    case 0:
        return std::make_unique<X_expr>(expression);

    case 1:
        return std::make_unique<Y_expr>(expression);

    case 2:
        return std::make_unique<Mult_expr>(depth - 1, expression);

    case 3:
        return std::make_unique<Avg_expr>(depth - 1, expression);

    case 4:
        return std::make_unique<Cos_expr>(depth - 1, expression);

    case 5:
        return std::make_unique<Sin_expr>(depth - 1, expression);

    default:
        return nullptr;
    }
}

/****************************
 *         Avg_expr         *
 ****************************/

Avg_expr::Avg_expr() {_representation = 'a';}

Avg_expr::Avg_expr(std::string &expression) : Avg_expr()
{
    child_r = ExpressionTree::createNode(expression);
    child_l = ExpressionTree::createNode(expression);
}

Avg_expr::Avg_expr(const std::size_t depth, std::string &string_expression) : Avg_expr()
{
    std::string right_expression, left_expression;
    child_r = ExpressionTree::generateRandomeTree(depth, right_expression);
    child_l = ExpressionTree::generateRandomeTree(depth, left_expression);

    string_expression += right_expression + left_expression + _representation;
}

std::size_t Avg_expr::getDepth(const std::size_t depth) { return std::max(child_l->getDepth(depth + 1), child_r->getDepth(depth + 1)); }

double Avg_expr::compute(const double x, const double y) { return (child_r->compute(x, y) + child_l->compute(x, y)) / 2; }

/****************************
 *         Cos_expr         *
 ****************************/

Cos_expr::Cos_expr() {_representation = 'c';}

Cos_expr::Cos_expr(std::string &expression) : Cos_expr()
{
    child = ExpressionTree::createNode(expression);
}

Cos_expr::Cos_expr(const std::size_t depth, std::string &string_expression) : Cos_expr()
{
    child = ExpressionTree::generateRandomeTree(depth, string_expression);
    string_expression += _representation;
}

std::size_t Cos_expr::getDepth(const std::size_t depth) { return child->getDepth(depth + 1); }

double Cos_expr::compute(const double x, const double y) { return std::cos(M_PI * child->compute(x, y)); }

/****************************
 *         Sin_expr         *
 ****************************/

Sin_expr::Sin_expr() {_representation = 's';}

Sin_expr::Sin_expr(std::string &expression) : Sin_expr()
{
    child = ExpressionTree::createNode(expression);
}

Sin_expr::Sin_expr(const std::size_t depth, std::string &string_expression) : Sin_expr()
{
    child = ExpressionTree::generateRandomeTree(depth, string_expression);
    string_expression += _representation;
}

std::size_t Sin_expr::getDepth(const size_t depth) { return child->getDepth(depth + 1); }

double Sin_expr::compute(const double x, const double y) { return std::sin(M_PI * child->compute(x, y)); }

/****************************
 *         Mult_expr        *
 ****************************/

Mult_expr::Mult_expr() {_representation = '*';}

Mult_expr::Mult_expr(std::string &expression) : Mult_expr()
{
    child_r = ExpressionTree::createNode(expression);
    child_l = ExpressionTree::createNode(expression);
}

Mult_expr::Mult_expr(const std::size_t depth, std::string &string_expression) : Mult_expr()
{
    std::string right_expression, left_expression;
    child_r = ExpressionTree::generateRandomeTree(depth, right_expression);
    child_l = ExpressionTree::generateRandomeTree(depth, left_expression);

    string_expression += right_expression + left_expression + _representation;
}

std::size_t Mult_expr::getDepth(const size_t depth) { return std::max(child_l->getDepth(depth + 1), child_r->getDepth(depth + 1)); }

double Mult_expr::compute(const double x, const double y) { return child_r->compute(x, y) * child_l->compute(x, y); }

/*************************
 *        X_expr         *
 ************************/

X_expr::X_expr() {_representation = 'x';}

X_expr::X_expr(std::string &string_expression) : X_expr() { string_expression.push_back(_representation); }

std::size_t X_expr::getDepth(const size_t depth) { return depth; }

double X_expr::compute(const double x, const double y) { return x; }

/*************************
 *        Y_expr         *
 ************************/

Y_expr::Y_expr() {_representation = 'y';}

Y_expr::Y_expr(std::string &string_expression) : Y_expr() { string_expression.push_back(_representation); }

std::size_t Y_expr::getDepth(const size_t depth) { return depth; }

double Y_expr::compute(const double x, const double y) { return y; }

/*************************
 *      Const_expr       *
 ************************/

Const_expr::Const_expr(double constant) : _constant(constant) {_representation = constant;}

std::size_t Const_expr::getDepth(const std::size_t depth) { return depth; }

double Const_expr::compute(const double x, const double y) { return _constant; }
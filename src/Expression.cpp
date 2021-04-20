#include "Expression.hpp"

Expression::Expression(std::string expression) : _expression(expression)
{
    _computation_tree = ExpressionTree::createNode(expression);
}

Expression::Expression(std::size_t max_depth, unsigned int *seed)
{
    // if max_depth == 0, the value of each pixels of that colors should be 0, and as there is a mapping between the
    // the result of the expression and the image we need to deal with that
    srand((*seed)++);
    _computation_tree = max_depth == 0 ? std::make_unique<Const_expr>(-1) : ExpressionTree::generateRandomeTree(max_depth, _expression);
}

double Expression::compute(double x, double y) const { return _computation_tree->compute(x, y); }

std::size_t Expression::getDepth() { return _computation_tree->getDepth(1); }

std::string Expression::toString() { return _expression; }
#ifndef __EXPRESSIONTREE__
#define __EXPRESSIONTREE__

#include <functional>
#include <memory>
#include <string>

#define NB_OF_EXPRESSION 6

/**
 * @brief Abstract class that represent an expression
 *          This class should be herited, to represent a node of an expression
 * 
 */
class ExpressionTree
{
protected:
    char _representation; // char representing the kind of expression

public:
    /**
     * @brief Get the depth of the tree
     * 
     * @param depth: the current depth
     * @return std::size_t, the depth of the tree
     */
    std::size_t virtual getDepth(const std::size_t depth) = 0;

    /**
     * @brief Compute the result of the expression tree 
     * 
     * @param x: the first parameter of the expression
     * @param y: the second parameter of the expression
     * @return double, the result of computation from that nodes down to the leaf
     */
    double virtual compute(const double x, const double y) = 0;

    /**
     * @brief Create a Node new node
     * 
     * @param expression: the string representation of the tree
     * @return std::unique_ptr<ExpressionTree>, a pointer to the result tree
     */
    static std::unique_ptr<ExpressionTree> createNode(std::string &expression);

    /**
     * @brief Generate a randome tree, with at most a depth of `depth`
     * 
     * @param depth: the maximum depth of the tree 
     * @param seed: a seed to set the randomised of the tree
     * @param string_expression: the string representation of the tre
     * @return std::unique_ptr<ExpressionTree>,  a pointer to the result tree
     */
    static std::unique_ptr<ExpressionTree> generateRandomeTree(const std::size_t depth, std::string &string_expression);
};

class Avg_expr : public ExpressionTree
{
private:
    std::unique_ptr<ExpressionTree> child_l;
    std::unique_ptr<ExpressionTree> child_r;

public:
    /**
     * @brief Construct a new Avg_expr object
     * 
     */
    Avg_expr();

    /**
     * @brief Construct a new Avg_expr object
     * 
     * @param expression: children expression of this
     */
    Avg_expr(std::string &expression);

    /**
     * @brief Construct a new Avg_expr object
     * 
     * @param depth: the maximum depth allowed of the children 
     * @param string_expression: the string representation of the tree
     */
    Avg_expr(const std::size_t depth, std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class Cos_expr : public ExpressionTree
{
private:
    std::unique_ptr<ExpressionTree> child;

public:
    /**
     * @brief Construct a new Cos_expr object
     * 
     */
    Cos_expr();

    /**
     * @brief Construct a new Cos_expr object
     * 
     * @param expression: child's expression of this
     */
    Cos_expr(std::string &expression);

    /**
     * @brief Construct a new Cos_expr object
     * 
     * @param depth: the maximum depth allowed of the child 
     * @param string_expression: the string representation of the tree
     */
    Cos_expr(const std::size_t depth, std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class Sin_expr : public ExpressionTree
{
private:
    std::unique_ptr<ExpressionTree> child;

public:
    /**
     * @brief Construct a new Sin_expr object
     * 
     */
    Sin_expr();

    /**
     * @brief Construct a new Sin_expr object
     * 
     * @param expression: child's expression of this
     */
    Sin_expr(std::string &expression);

    /**
     * @brief Construct a new Sin_expr object
     * 
     * @param depth: the maximum depth allowed of the child 
     * @param string_expression: the string representation of the tree
     */
    Sin_expr(const std::size_t depth, std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class Mult_expr : public ExpressionTree
{
private:
    std::unique_ptr<ExpressionTree> child_l;
    std::unique_ptr<ExpressionTree> child_r;

public:
    /**
     * @brief Construct a new Mult_expr object
     * 
     */
    Mult_expr();

    /**
     * @brief Construct a new Mult_expr object
     * 
     * @param expression 
     */
    Mult_expr(std::string &expression);

    /**
     * @brief Construct a new Mult_expr object
     * 
     * @param depth: the maximum depth allowed of the children 
     * @param string_expression: the string representation of the tree
     */
    Mult_expr(const std::size_t depth, std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class X_expr : public ExpressionTree
{
private:
public:
    /**
     * @brief Construct a new x expr object
     * 
     */
    X_expr();

    /**
     * @brief Construct a new x expr object
     * 
     * @param string_expression: the string representation of the tree
     */
    X_expr(std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class Y_expr : public ExpressionTree
{
private:
public:
    /**
     * @brief Construct a new y expr object
     * 
     */
    Y_expr();

    /**
     * @brief Construct a new y expr object
     * 
     * @param string_expression: the string representation of the tree
     */
    Y_expr(std::string &string_expression);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

class Const_expr : public ExpressionTree
{
private:
    const double _constant;

public:
    /**
     * @brief Construct a new Const_expr object
     * 
     */
    Const_expr(double constant);

    std::size_t getDepth(const std::size_t depth);
    double compute(const double x, const double y);
};

#endif
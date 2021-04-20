#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <string>
#include <memory>
#include "ExpressionTree.hpp"

/**
 * @brief Proxy class 
 * 
 * The goal of this class is to be more modular and having one more level of abstraction between the image and the associated expression for each colors
 *  indeed if we want to modify the way our tree is represented, or if we use somethings else than a tree we just need to do little modification in this class.
 *  Also this class deal with some "issue" such that dealing with reference when creating a tree given an expression, deal with max-depth of 0 etc.
 * (kind of adaptor between expression tree and Image)
 * 
 */
class Expression
{
private:
    std::unique_ptr<ExpressionTree> _computation_tree;
    std::string _expression;

public:
    /** 
     * @brief Give the spec of the expressions 
     * 
     * @return std::string spec
     */
    std::string toString();

    /**
     * @brief Compute the result of the expression 
     * 
     * @param x: the first parameter of the expression
     * @param y: the second parameter of the expression
     * @return double, the result of computation 
     */
    double compute(double x, double y) const;

    /**
     * @brief Construct a new Expression object, given an `expression`
     * 
     * @param expression: a string representing an expression 
     */
    Expression(std::string expression);

    /**
     * @brief Construct a new Expression objectn given the maximum depth of an expression
     * 
     * @param max_depth: the maximum depth of the tree 
     * @param seed: a seed to set the randomised of the tree
     */
    Expression(std::size_t max_depth, unsigned int *seed);

    /**
     * @brief Get the exact depth of the expression
     * 
     * @return std::size_t, the depth of the expression 
     */
    std::size_t getDepth();
};

#endif
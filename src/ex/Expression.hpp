#include <string>
#include <memory>

class Expression
{
private:
    char representation;
public:
    static std::shared_ptr<Expression> create_expression(std::string& expression);
    static std::shared_ptr<Expression> generate_expression(std::size_t max_depth, unsigned int *seed, std::string& string_expression);
    double virtual compute(double x, double y) = 0;
    std::size_t virtual get_depth(size_t depth) = 0;
};

class Avg_expr: public Expression
{
private:
    std::shared_ptr<Expression> child_l;
    std::shared_ptr<Expression> child_r;
public:
    std::size_t get_depth(size_t depth);
    Avg_expr(std::string& expression);
    Avg_expr(std::size_t depth, unsigned int *seed, std::string& string_expression);
    double compute(double x, double y);
};

class Cos_expr: public Expression
{
private:
    std::shared_ptr<Expression> child;
public:
    std::size_t get_depth(size_t depth);
    Cos_expr(std::string& expression);
    Cos_expr(std::size_t depth, unsigned int *seed, std::string& string_expression);
    double compute(double x, double y);
};

class Sin_expr: public Expression
{
private:
    std::shared_ptr<Expression> child;
public:
    std::size_t get_depth(size_t depth);
    Sin_expr(std::string& expression);
    Sin_expr(std::size_t depth, unsigned int *seed, std::string& string_expression);
    double compute(double x, double y);
};

class Mult_expr: public Expression
{
private:
    std::shared_ptr<Expression> child_l;
    std::shared_ptr<Expression> child_r;
public:
    std::size_t get_depth(size_t depth);
    Mult_expr(std::string& expression);
    Mult_expr(std::size_t depth, unsigned int *seed, std::string& string_expression);
    double compute(double x, double y);
};

class X_expr: public Expression
{
private:

public:
    std::size_t get_depth(size_t depth);
    X_expr();
    X_expr(std::string& string_expression);
    double compute(double x, double y);
};

class Y_expr: public Expression
{
private:

public:
    std::size_t get_depth(size_t depth);
    Y_expr();
    Y_expr(std::string& string_expression);
    double compute(double x, double y);
};





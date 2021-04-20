// #include "Martist.hpp"
// #include <string>
// #include <memory>
// #include <tuple>
// #include <vector>

// #define ENDL "\n"
// #define MAX_RGB 255

// /**
//  * @brief Rescale `y` to [-1, 1]
//  * 
//  * @param x: [0, height-1]
//  * @param height: 
//  * @return double, the rescaled y
//  */
// inline static double down_scaling_y(const size_t y, const size_t height)
// {
//   return (((double)y) / (double)(height - 1)) * -2 + 1; // ?? -1 ??
// }

// /**
//  * @brief Rescale `x` to [-1, 1]
//  * 
//  * @param x: [0, width-1]
//  * @param width: 
//  * @return double, the rescaled x
//  */
// inline static double down_scaling_x(const size_t x, const size_t width)
// {
//   return (((double)x) / (double)(width - 1)) * 2 - 1;
// }

// /**
//  * @brief draw a new image from different the RGB expression of martist to its buffer
//  * 
//  * @param martist the Martist
//  */
// void DrawingFromExpression(const Martist &martist)
// {
//   const std::vector<std::shared_ptr<Expression>> expressions = {martist.prec_red_expr, martist.prec_green_expr, martist.prec_blue_expr};
//   const size_t nb_colors = 3;

//   for (size_t y = 0; y < martist.height; ++y)
//   {
//     for (size_t x = 0; x < martist.width; ++x)
//     {
//       for (size_t expr = 0; expr < nb_colors; ++expr)
//         martist.buffer[(martist.width * nb_colors) * y + (nb_colors * x) + expr] = 
//         (expressions[expr]->compute(down_scaling_x(x, martist.width), down_scaling_y(y, martist.height)) + 1) * ((double)MAX_RGB / 2);
//     }
//   }
// }

// Martist::Martist(std::uint8_t *buffer, std::size_t width, std::size_t height, std::size_t redDepth, std::size_t greenDepth, std::size_t blueDepth)
// {
//   (*this).width = width;
//   (*this).height = height;
//   (*this).buffer = buffer;
//   (*this)._redDepth = redDepth;
//   (*this)._greenDepth = greenDepth;
//   (*this)._blueDepth = blueDepth;
// }

// void Martist::redDepth(std::size_t depth) { _redDepth = depth; }
// std::size_t Martist::redDepth() const { return _redDepth; }

// void Martist::greenDepth(std::size_t depth) { _greenDepth = depth; }
// std::size_t Martist::greenDepth() const { return _greenDepth; }

// void Martist::blueDepth(std::size_t depth) { _blueDepth = depth; }
// std::size_t Martist::blueDepth() const { return _blueDepth; }

// void Martist::changeBuffer(std::uint8_t *buffer, std::size_t width, std::size_t height)
// {
//   (*this).buffer = buffer;
//   (*this).width = width;
//   (*this).height = height;
// }

// void Martist::paint()
// {
//   prec_red_expr = std::make_shared<Expression>(_redDepth, &_seed);
//   prec_green_expr = std::make_shared<Expression>(_greenDepth, &_seed);
//   prec_blue_expr = std::make_shared<Expression>(_blueDepth, &_seed);

//   DrawingFromExpression(*this);
// }

// void Martist::seed(unsigned int seed) { _seed = seed; }

// std::istream &operator>>(std::istream &in, Martist &martist)
// {
//   std::vector<std::string> expressions(3);

//   char c;
  
//   if(!in){
//     return in;
//   }

//   in >> expressions[0];
//   in >> expressions[1];
//   in >> expressions[2];

//   martist.prec_red_expr = std::make_shared<Expression>(expressions[0]);
//   martist.prec_green_expr = std::make_shared<Expression>(expressions[1]);
//   martist.prec_blue_expr = std::make_shared<Expression>(expressions[2]);

//   martist.redDepth(martist.prec_red_expr->getDepth());
//   martist.greenDepth(martist.prec_green_expr->getDepth());
//   martist.blueDepth(martist.prec_blue_expr->getDepth());

//   DrawingFromExpression(martist);

//   return in;
// }

// std::ostream &operator<<(std::ostream &out, const Martist &martist)
// {
//   if(martist.prec_red_expr == nullptr || martist.prec_green_expr == nullptr || martist.prec_blue_expr == nullptr){
//     out << "undefined";
//     return out;
//   }

//   out << martist.prec_red_expr->getExpression() << std::endl
//       << martist.prec_green_expr->getExpression() << std::endl
//       << martist.prec_blue_expr->getExpression() << std::endl;
//   return out;
// }
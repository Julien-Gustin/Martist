#include "Image.hpp"
#include <vector>

#define NB_COLORS 3
#define MAX_RGB 255
#define ENDL '\n'

/**
 * @brief Rescale `x` to scale in [-1, 1], [0, size-1] -> [-1, 1]
 * 
 * @param x: [0, width-1]
 * @param size: 
 * @return double, the rescaled x
 */
inline static double down_scaling(const size_t x, const size_t size)
{
	return (1.0 / (double)size) + ((double)x * (2.0 / (double)size)) - 1;
}

/**
 * @brief Map `x` to [-1, 1], [-1, 1] -> [0, length-1]
 * 
 * @param x: [-1, 1]
 * @param length: 
 * @return double, the mapped x
 */
inline static double mapping(const double x)
{
	return (x + 1) * ((double)MAX_RGB / 2);
}

Image::Image(std::uint8_t *buffer, std::size_t width, std::size_t height) : _buffer(buffer), _width(width), _height(height) {}

void Image::changeBuffer(std::uint8_t *buffer, std::size_t width, std::size_t height)
{
	_buffer = buffer; 
	_width = width;
	_height = height;
}

void Image::generateRandomeImage(std::size_t red_depth, std::size_t green_depth, std::size_t blue_depth, unsigned int *seed)
{
	_red_expression = std::make_unique<Expression>(red_depth, seed);
	_green_expression = std::make_unique<Expression>(green_depth, seed);
	_blue_expression = std::make_unique<Expression>(blue_depth, seed);

	draw();
}

void Image::generateImage(std::string red_expression, std::string green_expression, std::string blue_expression)
{
	_red_expression = std::make_unique<Expression>(red_expression);
	_green_expression = std::make_unique<Expression>(green_expression);
	_blue_expression = std::make_unique<Expression>(blue_expression);

	draw();
}

std::size_t Image::getRedDepth()
{
	return _red_expression->getDepth();
}
std::size_t Image::getGreenDepth()
{
	return _green_expression->getDepth();
}
std::size_t Image::getBlueDepth()
{
	return _blue_expression->getDepth();
}

void Image::draw()
{
	for (std::size_t y = 0; y < _height; ++y)
	{
		for (std::size_t x = 0; x < _width; ++x)
		{
			_buffer[_width * NB_COLORS * y + (NB_COLORS * x) + Red] = mapping(_red_expression->compute(down_scaling(x, _width), -down_scaling(y, _height)));
			_buffer[_width * NB_COLORS * y + (NB_COLORS * x) + Green] = mapping(_green_expression->compute(down_scaling(x, _width), -down_scaling(y, _height)));
			_buffer[_width * NB_COLORS * y + (NB_COLORS * x) + Blue] = mapping(_blue_expression->compute(down_scaling(x, _width), -down_scaling(y, _height)));
		}
	}
}

bool Image::isEmpty() const { return _red_expression == nullptr || _green_expression == nullptr || _blue_expression == nullptr; }

std::string Image::toString() const
{
	if (isEmpty())
		return "";

	return _red_expression->toString() + ENDL + _green_expression->toString() + ENDL + _blue_expression->toString() + ENDL;
}

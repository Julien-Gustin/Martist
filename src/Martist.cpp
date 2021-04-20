#include "Martist.hpp"
#include <string>
#include <memory>
#include <tuple>
#include <vector>

Martist::Martist(std::uint8_t *buffer, std::size_t width, std::size_t height, std::size_t redDepth, std::size_t greenDepth, std::size_t blueDepth)
    : _rgb_image(buffer, width, height)
{
    (*this)._redDepth = redDepth;
    (*this)._greenDepth = greenDepth;
    (*this)._blueDepth = blueDepth;
}

void Martist::redDepth(std::size_t depth) { _redDepth = depth; }
std::size_t Martist::redDepth() const { return _redDepth; }

void Martist::greenDepth(std::size_t depth) { _greenDepth = depth; }
std::size_t Martist::greenDepth() const { return _greenDepth; }

void Martist::blueDepth(std::size_t depth) { _blueDepth = depth; }
std::size_t Martist::blueDepth() const { return _blueDepth; }

void Martist::changeBuffer(std::uint8_t *buffer, std::size_t width, std::size_t height)
{
    _rgb_image.changeBuffer(buffer, width, height);
}

void Martist::paint(){_rgb_image.generateRandomeImage(_redDepth, _greenDepth, _blueDepth, &_seed);}

void Martist::seed(unsigned int seed) { _seed = seed; }

std::istream &operator>>(std::istream &in, Martist &martist)
{
    if (!in)
        return in;

    std::string red_expr, green_expr, blue_expr;

    in >> red_expr;
    in >> green_expr;
    in >> blue_expr;

    martist._rgb_image.generateImage(red_expr, green_expr, blue_expr);

    martist.redDepth(martist._rgb_image.getRedDepth());
    martist.greenDepth(martist._rgb_image.getGreenDepth());
    martist.blueDepth(martist._rgb_image.getBlueDepth());

    return in;
}

std::ostream &operator<<(std::ostream &out, const Martist &martist)
{
    if (martist._rgb_image.isEmpty())
    {
        out << "undefined";
        return out;
    }

    out << martist._rgb_image.toString();
    
    return out;
}
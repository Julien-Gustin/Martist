#ifndef __MARTIST__
#define __MARTIST__

#include <cstdint>
#include <iostream>

#include "Image.hpp"

class Martist
{
private:
    // max depth of the differents color's expression
    std::size_t _redDepth, _greenDepth, _blueDepth;

    // image of the lastest paint
    Image _rgb_image;

    // define the randomness of the paint
    unsigned int _seed;

public:
    friend std::istream &operator>>(std::istream &in, Martist &Martist);
    friend std::ostream &operator<<(std::ostream &out, const Martist &martist);
    
    /**
     * @brief Construct a new Martist object
     * 
     * @param buffer: Buffer of pixel (should be of size width * height * 3)
     * @param width: Horizontal dimension of the image in pixel 
     * @param height: Vertical dimension of the image in pixel 
     * @param redDepth: The maximum allowed depth for the red color (if == 0, the corresponding expression must have a constant value of 0)
     * @param greenDepth: The maximum allowed depth for the green color (if == 0, the corresponding expression must have a constant value of 0)
     * @param blueDepth: The maximum allowed depth for the blue color (if == 0, the corresponding expression must have a constant value of 0)
     */
    Martist(std::uint8_t *buffer, std::size_t width, std::size_t height,
                     std::size_t redDepth, std::size_t greenDepth, std::size_t blueDepth);

    /**
     * @brief set the depth of the red color to `depth`
     * 
     * @param depth: the new depth of the red color
     */
    void redDepth(std::size_t depth);

    /**
     * @brief return the maximum depth allowed for the red color
     * 
     * @return std::size_t, the depth of the red color
     */
    std::size_t redDepth() const;

    /**
     * @brief set the depth of the green color to `depth`
     * 
     * @param depth: the new depth of the green color
     */
    void greenDepth(std::size_t depth);

    /**
     * @brief return the maximum depth allowed for the green color
     * 
     * @return std::size_t, the depth of the green color
     */
    std::size_t greenDepth() const;

    /**
     * @brief set the depth of the blue color to `depth`
     * 
     * @param depth: the new depth of the blue color
     */
    void blueDepth(std::size_t depth);

    /**
     * @brief return the maximum depth allowed for the blue color
     * 
     * @return std::size_t, the depth of the blue color
     */
    std::size_t blueDepth() const;

    /**
     * @brief change the buffer that contains the painting 
     * 
     * @param buffer: the new buffer
     * @param width: horizontal dimension of that `buffer`
     * @param height: vertical dimension of that `buffer'
     */
    void changeBuffer(std::uint8_t *buffer, std::size_t width, std::size_t height);

    /**
     * @brief generate a new (randome) image and paint it to the buffer
     * 
     */
    void paint();

    /**
     * @brief Seeds the randomness, for a given `seed` the sequence of images generated by `paint()` should
     *          always be the same.
     * 
     * @param seed: the new seed
     */
    void seed(unsigned int seed);
};

/**
 * @brief read an image spec from a stream, updating the depths of expressions and redrawing the image buffer
 *          i.e. `xys*c` >> `martist', where `xys*c` = cos(pi(x * sin(pi * y))) (and this for each color seperated by an '\n')
 * 
 * @param in: the input stream
 * @param martist: the Martist 
 * @return std::istream&, the input stream
 */
std::istream &operator>>(std::istream &in, Martist &martist); // const Martistyty

/**
 * @brief write the last painted image spec to a stream. Writing a martist that has not yes been painted is undefined.
 * 
 * @param out: the output stream
 * @param martist: the Martist
 * @return std::ostream&, the output stream
 */
std::ostream &operator<<(std::ostream &out, const Martist &martist);

#endif
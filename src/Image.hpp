#ifndef __IMAGE__
#define __IMAGE__

#include "Expression.hpp"
#include <cstdint>

#define NB_COLORS 3
#define MAX_RGB 255
#define ENDL '\n'

typedef enum
{
    Red,
    Green,
    Blue
} Color;

/**
 * @brief A class representing an Image
 * 
 */
class Image
{
private:
    std::uint8_t *_buffer;
    std::size_t _width;
    std::size_t _height;

    std::unique_ptr<Expression> _red_expression = nullptr;
    std::unique_ptr<Expression> _green_expression = nullptr;
    std::unique_ptr<Expression> _blue_expression = nullptr;

    void draw();

public:
    /**
     * @brief Construct a new Image object
     * 
     * @param buffer: a buffer of size (width * height * 3) containing all the pixels of an image
     * @param width: the width of the image
     * @param height: the height of the image
     */
    Image(std::uint8_t *buffer, std::size_t width, std::size_t height);

    /**
     * @brief Replace the buffer by a new one 
     * 
     * @param buffer: a buffer of size (width * height * 3) containing all the pixels of an image
     * @param width: the width of the image
     * @param height: the height of the image
     */
    void changeBuffer(std::uint8_t *buffer, std::size_t width, std::size_t height);

    /**
     * @brief Generate a new image to the `_buffer` given the depth of expression of the differents color, and a seed
     * 
     * @param red_depth: depth of the red expression
     * @param green_depth: depth of the green expression
     * @param blue_depth: depth of the blue expression
     * @param seed: set the randomised of the tree
     */
    void generateRandomeImage(std::size_t red_depth, std::size_t green_depth, std::size_t blue_depth, unsigned int *seed);

    /**
     * @brief Generate a new image given the color expression
     * 
     * @param red_expression: the string expression of the red color
     * @param green_expression: the string expression of the green color
     * @param blue_expression: the string expression of the blue color
     */
    void generateImage(std::string red_expression, std::string green_expression, std::string blue_expression);

    /**
     * @brief Get the depth's expression of the red color
     * 
     * @return std::size_t, the depth
     */
    std::size_t getRedDepth();

    /**
     * @brief Get the depth's expression of the green color
     * 
     * @return std::size_t, the depth
     */
    std::size_t getGreenDepth();

    /**
     * @brief Get the depth's expression of the blue color
     * 
     * @return std::size_t, the depth
     */
    std::size_t getBlueDepth();

    /**
     * @brief Give the spec. of an image 
     * 
     * @return std::string, spec
     */
    std::string toString() const;

    /**
     * @brief Tell whether the image is empty or not
     * 
     * @return true: No image
     * @return false: An image exist
     */
    bool isEmpty() const;
};

#endif
#include "Martist.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>
#include <stack>

using namespace std;

#include <memory>

void to_pnm(std::uint8_t *buffer, size_t width, size_t height)
{
  ofstream myfile;
  myfile.open("pnm/out.pnm");
  myfile << "P3\n" << height << " " << width <<"\n255\n";
  char c;

  for (size_t y = 0; y < height; ++y)
  {
    for (size_t x = 0; x < width; ++x)
    {
      for (size_t expr = 0; expr < 3; ++expr)
        myfile << (int)buffer[(width * 3) * y + (3 * x) + expr] << " ";

      myfile << " ";
    }
    myfile << "\n";
  }
}

int main(int argc, char const *argv[])
{
  const char error_msg[] = "All parameters should be integer";

  size_t width;
  size_t height;

  size_t redDepth;
  size_t greenDepth;
  size_t blueDepth;

  try{
    cout << "Dimension of the squared picture (int) => ";
    cin >> width;
    height = width;

    cout << "Depth of the red color expression (int) => ";
    cin >> redDepth;

      cout << "Depth of the green color expression (int) => ";
    cin >> greenDepth;

      cout << "Depth of the blue color expression (int) => ";
    cin >> blueDepth;
  }catch(exception& e)
  {
    cout << error_msg << endl;
    return -1;
  }

  std::uint8_t *buffer = new uint8_t[width * height * 3];

  Martist m(buffer, width, height, redDepth, greenDepth, blueDepth);

  char tmp;

  while (1) 
  {
    m.paint();
    to_pnm(buffer, width, height);
    cout << m;
    cout << "See the generated pictures in `pnm/out.png`\n\tContinue? [y/n] ";
    cin >> tmp;
    if(tmp != 'y')
      return 1;
  }

  return 0;
}



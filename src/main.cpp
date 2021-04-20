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

  string test = "xyays*";
  size_t width = 1000;
  size_t height = 1000;
  std::uint8_t *buffer = new uint8_t[width * height * 3];
  Martist m(buffer, width, height, stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));

  cout << m << endl; // test 

  char tmp;

  while (1) // comment this loop if you want to try your own spec on command line
  {
    m.paint();
    to_pnm(buffer, width, height);
    cout << m;

    cin >> tmp; // clic a char and enter
  }

  cin >> m;
  cout << m << endl;

  to_pnm(buffer, width, height);
  /* code */
  return 0;
}



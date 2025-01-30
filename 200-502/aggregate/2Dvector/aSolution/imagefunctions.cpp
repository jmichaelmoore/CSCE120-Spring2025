#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>
#include "imagefunctions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;
using std::string;
using std::vector;

/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-vector of Pixels (structs)
 *  Return value: updated version of 2D vector
 */
// You should not modify this function unless you add another processing option. //
void processImage(char choice)
{
  string originalImageFilename;

  // get filename, width and height from user
  cout << "Image filename: ";
  cin >> originalImageFilename;

  try
  {
    // declare/define image vector of vector of Pixel
    vector<vector<Pixel>> image;
    // load image
    image = loadImage(originalImageFilename);

    string outputImageFilename;

    // modify image
    switch (toupper(choice))
    {
    case 'G':
      image = grayscaleImage(image);
      outputImageFilename = "grey." + originalImageFilename;
      break;
    case 'S':
      image = sepiaImage(image);
      outputImageFilename = "sepia." + originalImageFilename;
      break;
    case 'R':
      image = reverseGrayscaleImage(image);
      outputImageFilename = "reverse_grey." + originalImageFilename;
      break;
    }

    // output image
    outputImage(outputImageFilename, image);
  }
  catch (std::exception &e)
  {
    cout << e.what() << endl;
  }
}

/*  Function loadImage
 *  filename: string which is the ppm file to read
 *  image: 2d-vector of Pixels (structs)
 *  return: updated version of 2D vector based on image file
 */
vector<vector<Pixel>> loadImage(const string filename)
{
  cout << "Loading image..." << endl;
  ifstream ifs(filename); // input file stream opened with filename 

  // check if it's open
  if (!ifs.is_open()) {
    throw std::invalid_argument("Unable to open file: " + filename);
  }

  // we were able to open the file

  // read in Image type, for us it must be P3
  string type;
  ifs >> type;

  // read in width and height
  unsigned int fileWidth = 0, fileHeight = 0;
  ifs >> fileWidth >> fileHeight;

  // read in maximum color value, for us it must be 255
  unsigned int maxColor = 0;
  ifs >> maxColor;

  // create empty image vector of needed size
  // TODO
  vector<vector<Pixel>> image(fileWidth, vector<Pixel>(fileHeight, {0, 0, 0}));

  // read the color values into the 2D array in Column Major Order
  // TODO
  for (unsigned int row=0; row<fileHeight; ++row) {
    for (unsigned int col=0; col<fileWidth; ++col) {
      unsigned int r, g, b;
      ifs >> r >> g >> b;
      image.at(col).at(row) = {r, g, b};
    }
  }

  // return image
  // TODO
  return image;
}

/*  Function grayscale
 *  image: 2d-vector of Pixels (structs)
 *  Return value: updated version of 2D vector with greyscale values
 */
vector<vector<Pixel>> grayscaleImage(vector<vector<Pixel>> image)
{
  cout << "Making grayscale image... " << endl;
  // iterate through 2d image of Pixels and convert them to grayscale
  // use opposite outer loop than load and output just to be different
  // TODO
  for (size_t col=0; col<image.size(); ++col) {
    for (size_t row=0; row<image.at(col).size(); ++row) {
      unsigned int gray = image.at(col).at(row).r;
      gray += image.at(col).at(row).g;
      gray += image.at(col).at(row).b;
      gray /= 3;
      image.at(col).at(row) = {gray, gray, gray};
    }
  }
  
  return image;
 }

/*  Function sepiaImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: updated version of 2D vector with sepia values
 */
// You should write this function. //
vector<vector<Pixel>> sepiaImage(vector<vector<Pixel>> image)
{
  cout << "Making sepia image... " << endl;
  // iterate through 2d image of Pixels and convert them to sepia
  // try on your own
  return image;
}

/*  Function reverseGrayscaleImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: updated version of 2D vector with reverse grayscale values
 */
// You should write this function. //
vector<vector<Pixel>> reverseGrayscaleImage(vector<vector<Pixel>> image)
{
  cout << "Making reverse grayscale image... " << endl;
  // iterate through 2d image of Pixels and convert them to reverse grayscale
  // try on your own
  return image;
}

/*  Function outputImage
 *  filename: filename to write to
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but ppm file should be created
 */
void outputImage(const string filename, vector<vector<Pixel>> image)
{
  cout << "Outputting image..." << endl;

  // open output file
  ofstream ofs(filename);

  if (!ofs.is_open()) {
    throw std::invalid_argument("Unable to create output file: " + filename);
  }

  // output image type, P3 for us
  ofs << "P3" << endl;

  // output width and height, don't forget to separate by a space
  // TODO 
  ofs << image.size() << " " << image.at(0).size() << endl;

  // output max color value, for us 255
  ofs << 255 << endl;

  // output from column major order array into row major PPM file
  // TODO
  for (size_t row=0; row<image.at(0).size(); ++row) {
    for (size_t col=0; col<image.size(); ++col) {
      ofs << image.at(col).at(row).r << " ";
      ofs << image.at(col).at(row).g << " ";
      ofs << image.at(col).at(row).b << " ";
    }
    ofs << endl;
  }
}
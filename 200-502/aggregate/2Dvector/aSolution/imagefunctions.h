#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

// a Pixel struct representing a single red, green, blue pixel value for an image
struct Pixel {
  unsigned int r = 0; // red
  unsigned int g = 0; // green
  unsigned int b = 0; // blue
};

void processImage(char choice);

std::vector<std::vector<Pixel>> loadImage(const std::string filename);

void outputImage(const std::string filename, std::vector<std::vector<Pixel>>);

std::vector<std::vector<Pixel>> grayscaleImage(std::vector<std::vector<Pixel>>);

std::vector<std::vector<Pixel>> sepiaImage(std::vector<std::vector<Pixel>>);

std::vector<std::vector<Pixel>> reverseGrayscaleImage(std::vector<std::vector<Pixel>>);

#endif
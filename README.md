# TopGrayscalePixels

## Overview

**TopGrayscalePixels** is a C++ program designed to efficiently identify the 50 brightest pixels in a grayscale image stored in memory. The image is expected to use 16-bit unsigned integers for each pixel value. The program outputs both the pixel values and their locations (coordinates) within the image.

## Features

- **High Performance:** Optimized to quickly scan large grayscale images.
- **Flexible Input:** Accepts images stored in raw memory arrays (16-bit per pixel).
- **Precise Output:** Reports the top 50 pixel values along with their (row, column) positions.

## Use Case

This tool is useful for image analysis tasks such as:

- Identifying regions of interest in scientific imaging (e.g., astronomy, medical scans).
- Locating hotspots in thermal or intensity images.
- Preprocessing for further image segmentation or enhancement.

## Getting Started

### Prerequisites

- C++17 or newer compiler (e.g., GCC, Clang, MSVC)
- CMake (optional, for building)
- The image data must be provided as a 2D array of `uint16_t` values.

### Building

1. Clone this repository:
   ```bash
   git clone https://github.com/DariusWigglesworth/TopGrayscalePixels.git
   cd TopGrayscalePixels
   ```

2. Compile (example using g++):
   ```bash
   g++ -std=c++17 -O2 -o top_pixels main.cpp
   ```

### Usage

The main function expects a grayscale image loaded into memory. You can adapt the example below to load your image:

```cpp
#include "top_grayscale_pixels.h"

// Example: Find top 50 pixels in a 512x512 image
const size_t width = 512, height = 512;
std::vector<uint16_t> image(width * height);

// Load your image data into 'image' here

auto top_pixels = find_top_pixels(image.data(), width, height, 50);

// Output results
for (const auto& p : top_pixels) {
    std::cout << "Pixel value: " << p.value << " at (" << p.row << ", " << p.col << ")\n";
}
```

## API

- `find_top_pixels(const uint16_t* image, size_t width, size_t height, size_t top_n)`
  - **image:** Pointer to the pixel data (row-major order).
  - **width, height:** Dimensions of the image.
  - **top_n:** Number of top pixels to find (e.g., 50).
  - **Returns:** A list of structures containing pixel value and position.

## License

This project is licensed under the MIT License.

## Author

Created by [DariusWigglesworth](https://github.com/DariusWigglesworth).

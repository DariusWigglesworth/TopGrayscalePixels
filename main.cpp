// Required includes and namespaces
#include <iostream>
#include <vector>

using namespace std;

// Pixel class with coordinate and value data
class Pixel {
    public:
        uint16_t greyscaleValue = -1;
        int pixelNum = -1;

    // Default constructor
    Pixel(uint16_t greyscaleValue, int pixelNum){
        this->greyscaleValue = greyscaleValue;
        this->pixelNum = pixelNum;
    }
};

// Given a vector of 16bit greyscale pixels, return the top 
vector<Pixel> findTopPixels(vector<uint16_t>& greyscaleImage){
    // Initialize the vector for the top 50 highest pixels and the number of pixels in the image
    vector<Pixel> highestPixels;
    int totalPixels = greyscaleImage.size();

    for(int i = 0; i < totalPixels; i++){
        Pixel currentPixel(image[i], i);

        // Insert the current pixel by highest pixel value
        vector<Pixel>::iterator it = highestPixels.begin();
        while(it != highestPixels.end() && it->value > currentPixel.value){
            it++;
        }
        highestPixels.insert(it, currentPixel);

        // If there are more than 50 pixels, remove the lightest pixel
        if(highestPixels.size() > 50){
            highestPixels.pop_back();
        }
    }
    
    return highestPixels;
}

int main(){
    // Sample greyscale pixel data in memory for an image with 16 pixels
    vector<uint16_t> greyscaleImage = {28936, 12345, 54321, 4321, 40000, 534, 64232, 25643, 17890, 60000, 45678, 9831, 32000, 10000, 62222, 19000};

    // Call findTopPixels, returning the highest 50 values in the image
    vector<Pixel> highestPixels = findTopPixels(greyscaleImage);

    // Output the top pixels and their locations
    for(Pixel& p: highestPixels){
        cout << "Greyscale Value: " << p.greyscaleValue << " Pixel Number: " << p.pixelNum << endl;
    }

    return 0;
}

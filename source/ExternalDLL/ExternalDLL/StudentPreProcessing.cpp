#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "algorithm"

IntensityImage *StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
    auto intesityImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
    Intensity pixelIntensity = 0;

    char method = 2;  // Specify the method you want to use

    for (int x = 0; x < image.getWidth(); x++) {
        for (int y = 0; y < image.getHeight(); y++) {
            RGB CPixel = image.getPixel(x, y);

            if (method == 1) {
                // average method
                pixelIntensity = (CPixel.r + CPixel.g + CPixel.b) / 3;
            } else if (method == 2) {
                // colorimetric (perceptual luminance) method
                pixelIntensity = (Intensity)((double)(CPixel.r * 0.21) + (double)(CPixel.g * 0.72) + (double)(CPixel.b * 0.07));
            } else if (method == 3) {
                // lightness method
                pixelIntensity = (std::max(std::max(CPixel.r, CPixel.g), CPixel.b) + std::min(std::min(CPixel.r, CPixel.g), CPixel.b)) / 2;
            }

            intesityImage->setPixel(x, y, pixelIntensity);
        }
    }
    return intesityImage;
}

IntensityImage *StudentPreProcessing::stepScaleImage(const IntensityImage &image) const { return nullptr; }

IntensityImage *StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const { return nullptr; }

IntensityImage *StudentPreProcessing::stepThresholding(const IntensityImage &image) const { return nullptr; }
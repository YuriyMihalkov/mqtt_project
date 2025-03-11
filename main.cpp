#include "CField.hpp"
#include "GrayscaleImage.hpp"
#include "ImageRGB.hpp"
#include "exttypes.h"
#include <cmath>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    fs::path resourcesPath = fs::path(__FILE__).parent_path() / "resources" ;
    fs::path outPath = fs::path(__FILE__).parent_path() / "out";
    if (!fs::exists(outPath)) {
        fs::create_directories(outPath);
    }
    CField cfield;
    cfield.setOEIFileName(resourcesPath / "15_ChromaDuMonde_12_4.jpg");
    cfield.setRelFileName(resourcesPath / "tif.tif");
    CameraOrientation camera;

    camera.mEye.x = 4;
    camera.mEye.y = 4;
    camera.mEye.z = -4;
    camera.mCenter.x = 16;
    camera.mCenter.y = 16;
    camera.mCenter.z = -16;
    // Вектор  mEye и mCenter коллинеарны друг другу
    // Вектор mUp им должен быть компланарен
    camera.mUp.x = 16;
    camera.mUp.y = 16;
    camera.mUp.z = 16;
    // Угол обзора в градусах
    camera.mYFov = 36;
    camera.mAspect = 1;
    camera.mImgHiehgt = static_cast<int>(cfield.getImagePlane().getHeight());
    camera.mImgWidth = static_cast<int>(cfield.getImagePlane().getWidth());

    SMM::GrayscaleImage grayImage;
    WGS84Coord wGS84Coord{};
    SMM::GrayscaleImage grayImage1 = cfield.getImagePlane().to_grayscale();
    grayImage1.save_to_jpg(outPath / "result1.jpg");
    cfield.convertRastr(camera, cfield.getImagePlane().to_grayscale(), grayImage, wGS84Coord);
    ImageRGB image;
    image.setDataGreyScale(grayImage);
    image.save_to_jpg(outPath / "result2.jpg");
    return 0;
}   
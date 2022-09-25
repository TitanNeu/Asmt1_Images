#include <iostream>
#include <fstream>
#include "src/MyImageClass.h"

int main() {
    std::string inPath = "/Users/hunterdick/CLionProjects/Asmt1-Images/source/p6/hkd.ppm";
    MyImageClass img1(inPath);

    std::string inPath2 = "/Users/hunterdick/CLionProjects/Asmt1-Images/source/p6/Lenna.ppm";
    MyImageClass img2(inPath2);


    MyImageClass imgNew = img1 + img2;

    std::string outPth1 = "/Users/hunterdick/CLionProjects/Asmt1-Images/out/rgb/hkdOut3.ppm";
    std::string outPth2= "/Users/hunterdick/CLionProjects/Asmt1-Images/out/rgb/LennaOut.ppm";
    imgNew.save(outPth1);


}

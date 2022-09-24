#include <iostream>
#include <fstream>
#include "src/MyImageClass.h"

int main() {
    std::string in = "/Users/hunterdick/CLionProjects/Asmt1-Images/source/p6/hkd.ppm";
    MyImageClass img(in);

    std::string out = "/Users/hunterdick/CLionProjects/Asmt1-Images/out/rgb/hkdOut.ppm";
    img.save(out);


}

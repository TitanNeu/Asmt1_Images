#include <iostream>
#include <fstream>

int main() {
    std::string s;
    int width, height, max;
    std::ifstream infile("/Users/hunterdick/CLionProjects/Asmt1-Images/source/p6/Lenna.ppm");  // open input file

    infile >> s >> width >> height >> max;
    std::cout << s << std::endl;

}

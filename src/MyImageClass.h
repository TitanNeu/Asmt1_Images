//
// Created by Hunter Dick on 2022/9/23.
//
#ifndef ASMT1_IMAGES_MYIMAGECLASS_H
#define ASMT1_IMAGES_MYIMAGECLASS_H
#define P5 "P5"
#define P2 "P2"
#define P6 "P6"
#define P3 "P3"
#define SPACE " "


#include <string>
#include <vector>

using std::string;
using std::vector;

class MyImageClass {
private:
    string magicNum;
    int height;
    int width;
    int maxPixVal;
    vector<unsigned char> data;

    void readBinaryImg(std::ifstream &infile);

    void readASCImg(std::ifstream &infile);


public:
    explicit MyImageClass(const string &imgPath);

    MyImageClass();

    void operator+=(const MyImageClass &img2);

    MyImageClass operator+(const MyImageClass &img2);

    void operator>>(std::ifstream in);

    void operator<<(std::ofstream out);

    void save(const string &outPath);
};


#endif //ASMT1_IMAGES_MYIMAGECLASS_H

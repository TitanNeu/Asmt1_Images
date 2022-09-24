//
// Created by Hunter Dick on 2022/9/23.
//
#ifndef ASMT1_IMAGES_MYIMAGECLASS_H
#define ASMT1_IMAGES_MYIMAGECLASS_H
#define P5 "P5"
#define P2 "P2"
#define P6 "P6"
#define P3 "P3"


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

    void readBinaryImg(const string &magicNum, std::ifstream &infile);

    void readASCImg(const string &magicNum, std::ifstream &infile);


public:
    explicit MyImageClass(const string &imgPath);

    MyImageClass();

//    MyImageClass operator+(const MyImageClass& img2);
    void operator+=(const MyImageClass &img2);

    void operator>>(std::ifstream in);

    void operator<<(std::ofstream out);

    void save(const string &outPath);
};


#endif //ASMT1_IMAGES_MYIMAGECLASS_H

//
// Created by Hunter Dick on 2022/9/23.
//
#ifndef ASMT1_IMAGES_MYIMAGECLASS_H
#define ASMT1_IMAGES_MYIMAGECLASS_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class MyImageClass {
private:
    string inputPath;
    string outputPath;
    string magicNum;
    int height;
    int width;
    int maxPixVal;
    vector<vector<vector<unsigned char>>> data;

public:
    explicit MyImageClass(const string& imgPath);
    MyImageClass();
//    MyImageClass operator+(const MyImageClass& img2);
    void operator+=(const MyImageClass& img2);
    void operator>>(std::ifstream in);
    void operator<<(std::ofstream out);
    void save(const string& outPath);
};


#endif //ASMT1_IMAGES_MYIMAGECLASS_H

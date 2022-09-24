//
// Created by Hunter Dick on 2022/9/23.
//

#include "MyImageClass.h"

#include <utility>
#include <fstream>
#include <iostream>


//MyImageClass MyImageClass::operator+(const MyImageClass &img2) {
//    return nullptr;
//}


MyImageClass::MyImageClass(const string &imgPath) {
    this->inputPath = imgPath;
    std::ifstream infile(inputPath, std::ios::in | std::ios::binary);
    infile >> this->magicNum >> this->width >> this->height >> this->maxPixVal;
    int size = height * width * 3;
    data.resize(size);
    // read content of infile
    infile.read(reinterpret_cast<char *>(&data[0]), size);
    infile.close();


    infile.close();

}

void MyImageClass::operator>>(std::ifstream in) {

}

MyImageClass::MyImageClass() = default;

void MyImageClass::save(const string &imgPath) {
    this->outputPath = imgPath;
    std::ofstream outfile(outputPath, std::ios::out | std::ios::binary);
    outfile << this->magicNum << "\n";
    outfile << this->width << " " << this->height << "\n";
    outfile << this->maxPixVal;


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //像素坐标
            int pixel = i * width + j;
            //计算像素(i,j)的开头rgb在vector的一维坐标
            int rgbIndex = pixel * 3;
            for (int k = 0; k < 3; k++) {
                //分别存像素(i,j)的rgb字节
                outfile << data.at(rgbIndex + k);
            }
        }
    }

    //输出对比原始图片二进制data，总是末尾少一个0x50字节
    //不加输出就是黑的，加上就是显示出图
    char temp = 0x50;
    outfile << temp;


    outfile.close();

}

void MyImageClass::operator<<(std::ofstream out) {

}

void MyImageClass::operator+=(const MyImageClass &img2) {

}


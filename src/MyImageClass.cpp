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
    std::ifstream infile(imgPath);
    infile >> this->magicNum >> this->width >> this->height >> this->maxPixVal;
    //转大写
    transform(magicNum.begin(), magicNum.end(), magicNum.begin(), ::toupper);
    //流的方式读ppm和pgm
    if (magicNum == P6 || magicNum == P5) {
        readBinaryImg(magicNum, infile);
    } else if (magicNum == P2 || magicNum == P3) {
        readASCImg(magicNum, infile);
    }
    infile.close();

}

void MyImageClass::operator>>(std::ifstream in) {

}

MyImageClass::MyImageClass() = default;

void MyImageClass::save(const string &imgPath) {
    std::ofstream outfile(imgPath);
    outfile << this->magicNum << "\n";
    outfile << this->width << " " << this->height << "\n";
    outfile << this->maxPixVal;

    //ppm rgb
    if(magicNum == P6) {
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
    } else if (magicNum == P3) {

    } else if (magicNum == P5) {

    } else {
        try{

        }catch (std::exception e) {
            e.what();
        }
    }
    //输出对比原始图片二进制data，总是末尾少一个字节,任意加一个输出就行
    //不加输出就是黑的，加上就是显示出图
    char temp = 0x00;
    outfile << temp;
    outfile.close();

}

void MyImageClass::operator<<(std::ofstream out) {

}

void MyImageClass::operator+=(const MyImageClass &img2) {

}

//读取二进制文件
void MyImageClass::readBinaryImg(const string &flag, std::ifstream &infile) {

    //默认ppm, p6二进制rgb，每个像素3颜色
    int factor = 3;
    if (flag == P5) {
        //pgm p5灰度二进制，每像素一个0～255的值
        factor = 1;
    }
    int size = height * width * factor;
    data.resize(size);
    // read content of infile
    infile.read(reinterpret_cast<char *>(&data[0]), size);


}
//读取ascii码文件
void MyImageClass::readASCImg(const string &magicNum, std::ifstream &infile) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp;
            //ppm ascii 方式存储rgb, 没素材没测
            if (magicNum == P3) {
                for (int k = 0; k < 3; k++) {
                    infile >> temp;
                    data.push_back(temp);
                }
            } else {
                //灰度pgm只存一个值
                infile >> temp;
                data.push_back(temp);
            }
        }
    }
}


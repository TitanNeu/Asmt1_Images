//
// Created by Hunter Dick on 2022/9/23.
//

#include "MyImageClass.h"

#include <utility>
#include <fstream>
#include <iostream>


MyImageClass::MyImageClass(const string &imgPath) {
    std::ifstream infile(imgPath);
    infile >> magicNum >> width >> height >> maxPixVal;
    //转大写
    transform(magicNum.begin(), magicNum.end(), magicNum.begin(), ::toupper);
    //流的方式读ppm和pgm
    if (magicNum == P6 || magicNum == P5) {
        readBinaryImg(infile);
    } else if (magicNum == P2 || magicNum == P3) {
        readASCImg(infile);
    }
    infile.close();

}

MyImageClass::MyImageClass() = default;

//只测了P6的文件
void MyImageClass::save(const string &imgPath) {
    if (data.empty()) {
        std::cout << "illegal ppm/pgm data is empty!!" << std::endl;
        return;
    }
    std::ofstream outfile(imgPath);
    outfile << magicNum << "\n";
    outfile << width << " " << height << "\n";
    outfile << maxPixVal << "\n";
    int colors = 1;
    try {
        //ppm and pgm binary
        if (magicNum == P6 || magicNum == P5) {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    //像素坐标
                    int pixel = i * width + j;

                    //像素(i,j)的开头色彩的一维坐标，默认灰度
                    int rgbIndex = pixel;
                    if (magicNum == P6) {
                        colors = 3;
                        //(i,j)的rgb组在vector的一维坐标起点
                        rgbIndex = pixel * colors;
                    }
                    for (int k = 0; k < colors; ++k) {
                        //分别存像素(i,j)的rgb字节
                        outfile << data.at(rgbIndex + k);
                    }
                }
            }
        } else if (magicNum == P3) {
            //ppm ascii
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    //像素坐标
                    int pixel = i * width + j;
                    //计算像素(i,j)的开头rgb在vector的一维坐标
                    int rgbIndex = pixel * 3;
                    for (int k = 0; k < 3; ++k) {
                        //分别存像素(i,j)的rgb字节
                        outfile << data.at(rgbIndex + k);
                        outfile << SPACE;
                    }
                    outfile << SPACE;
                }
                outfile << "\n";
            }

        } else {
            //pgm ascii P2 and others
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    int pixel = i * width + j;
                    outfile << data.at(pixel);
                    outfile << SPACE;
                }
                outfile << "\n";
            }
        }

        /*总是末尾少一个字节,任意加一个，
        不加输出就是黑图*/
        char temp = 0x00;
        outfile << temp;
        outfile.close();
        std::cout << "out successful" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}


//读取二进制文件
void MyImageClass::readBinaryImg(std::ifstream &infile) {
    //默认ppm, p6二进制rgb，每个像素3颜色
    int colors = 3;
    if (magicNum == P5) {
        //pgm p5灰度二进制，每像素一个0～255的值
        colors = 1;
    }
    int size = height * width * colors;
    data.resize(size);
    // read content of infile
    infile.read(reinterpret_cast<char *>(&data[0]), size);
}

//读取ascii码文件
void MyImageClass::readASCImg(std::ifstream &infile) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            unsigned char temp;
            //ppm ascii 方式存储rgb, 没素材没测
            if (magicNum == P3) {
                for (int k = 0; k < 3; ++k) {
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

//处理p6的，其他的类似
MyImageClass MyImageClass::operator+(const MyImageClass &img2) {
    if (magicNum != P6) {
        std::cout << "illegal input!!!" << std::endl;
        return {};
    }
    if (magicNum != img2.magicNum) {
        std::cout << "illegal input!!!" << std::endl;
        return {};
    }
    MyImageClass imgNew;

    //最大的作为长宽
    imgNew.height = std::max(this->height, img2.height);
    imgNew.width = std::max(this->width, img2.width);
    int size = imgNew.height * imgNew.width * 3;
    imgNew.data.resize(size);

    //新图和当前类型保持一致
    imgNew.magicNum = magicNum;
    imgNew.maxPixVal = 255;

    int colors = 3;
    try {
        for (int i = 0; i < imgNew.height; ++i) {
            for (int j = 0; j < imgNew.width; ++j) {
                //转一维坐标
                int colorIndex = (i * imgNew.width + j) * colors;
                int colorIdx1 = (i * this->width + j) * colors;
                int colorIdx2 = (i * img2.width + j) * colors;
                for (int k = 0; k < 3; ++k) {
                    unsigned char val1 = 0x00;
                    unsigned char val2 = 0x00;
                    if (colorIdx1 + k < this->data.size()) {
                        val1 = data.at(colorIdx1 + k);
                    }
                    if (colorIdx2 + k < img2.data.size()) {
                        val2 = img2.data.at(colorIdx2 + k);
                    }
                    unsigned val = (val1 + val2) % 255;
                    if (colorIndex + k < imgNew.data.size()) {
                        imgNew.data[colorIndex + k] = val;
                    }
                }
            }
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    return imgNew;

}


void MyImageClass::operator<<(std::ofstream out) {

}

void MyImageClass::operator+=(const MyImageClass &img2) {

}


void MyImageClass::operator>>(std::ifstream in) {

}
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
    std::ifstream infile(inputPath,std::ios::in | std::ios::binary);
    infile >> this->magicNum >> this->width >> this->height >> this->maxPixVal;
    unsigned char temp = '0';
    string line;

    for(int i = 0; i < height; i++) {
        vector<vector<unsigned char>> lineArray;
        for(int j = 0; j < width; j++) {
            vector<unsigned char> pixel;
            for(int k = 0; k < 3; k++) {
                infile >> temp;
                pixel.push_back(temp);
            }
            lineArray.push_back(pixel);
        }
        this->data.push_back(lineArray);
    }

}

void MyImageClass::operator>>(std::ifstream in) {

}

MyImageClass::MyImageClass() = default;

void MyImageClass::save(const string &imgPath) {
    this->outputPath = imgPath;
    std::ofstream outfile(outputPath,std::ios::out | std::ios::binary);
    outfile << this->magicNum << "\n";
    outfile << this->width << " " << this->height << "\n";
    outfile << this->maxPixVal << "\n";

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
                outfile << data.at(i).at(j).at(k);
                outfile << " ";
            }
        }
        outfile << "\n";
    }

}

void MyImageClass::operator<<(std::ofstream out) {

}

void MyImageClass::operator+=(const MyImageClass &img2) {

}


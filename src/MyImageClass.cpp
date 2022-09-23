//
// Created by Hunter Dick on 2022/9/23.
//

#include "MyImageClass.h"

#include <utility>
#include <fstream>


MyImageClass MyImageClass::operator+(const MyImageClass &img2) {
    return nullptr;
}


MyImageClass::MyImageClass(const string &imgPath) {
    this->inputPath = imgPath;
}

void MyImageClass::operator>>(std::ifstream in) {

}

MyImageClass::MyImageClass() = default;

void MyImageClass::save(const string &imgPath) {

}

void MyImageClass::operator<<(std::ofstream out) {

}

void MyImageClass::operator+=(const MyImageClass &img2) {

}


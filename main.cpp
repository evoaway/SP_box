#include <iostream>
#include <iomanip>
#include "SPbox.h"

void printVector(std::vector<unsigned char> v){
    for (unsigned char i : v) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i) << " ";
    }
    std::cout << std::endl;
}

void Test() {
    SPbox spbox;

    //spbox.printSbox();
    //spbox.printInvSbox();
    //spbox.printPbox();
    //spbox.printInvPbox();

    std::vector<unsigned char> data = {0x14, 0x0f, 0x55};
    std::vector<unsigned char> result = spbox.Sbox(data);
    std::vector<unsigned char> inverse = spbox.invSbox(result);
    if(equal(data.begin(), data.end(), inverse.begin())){
        std::cout << "Passed!" << std::endl;
    }
    else {
        std::cout << "Fail!" << std::endl;
    }
    //printVector(data);
    //printVector(result);
    //printVector(inverse);

    data = {0xff, 0xab, 0x65, 0xfa, 0xff, 0x01, 0x20};
    result = spbox.Sbox(data);
    inverse = spbox.invSbox(result);
    if(equal(data.begin(), data.end(), inverse.begin())){
        std::cout << "Passed!" << std::endl;
    }
    else {
        std::cout << "Fail!" << std::endl;
    }

    data = {0xff, 0xab, 0x65, 0xfa, 0xff, 0x01, 0x20};
    result = spbox.Pbox(data);
    inverse = spbox.invPbox(result);
    if(equal(data.begin(), data.end(), inverse.begin())){
        std::cout << "Passed!" << std::endl;
    }
    else {
        std::cout << "Fail!" << std::endl;
    }

    data = {0x45, 0x88, 0x68, 0xf1, 0x1, 0x01, 0x35, 0xdb};
    result = spbox.Pbox(data);
    inverse = spbox.invPbox(result);
    if(equal(data.begin(), data.end(), inverse.begin())){
        std::cout << "Passed!" << std::endl;
    }
    else {
        std::cout << "Fail!" << std::endl;
    }
    //printVector(data);
    //printVector(result);
    //printVector(inverse);
}

int main() {
    Test();
}

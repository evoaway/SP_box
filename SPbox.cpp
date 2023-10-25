#include "SPbox.h"

void SPbox::CheckLength(int len) {
    if (len == 0) {
        throw std::length_error("Array is empty!");
    }
}

std::vector<unsigned char> SPbox::Sbox(std::vector<unsigned char> data) {
    CheckLength(data.size());
    std::vector<unsigned char> result;
    result.reserve(data.size());
    for (unsigned char i : data) {
        result.push_back(getSboxValue(i));
    }
    return result;
}

unsigned char *SPbox::Sbox(const unsigned char data[]) {
    unsigned int len = sizeof(data) / sizeof(int);
    CheckLength(len);
    unsigned char *result = new unsigned char[len];
    for (int i = 0; i < len; ++i) {
        result[i] = getSboxValue(data[i]);
    }
    return result;
}
std::vector<unsigned char> SPbox::invSbox(std::vector<unsigned char> data) {
    CheckLength(data.size());
    std::vector<unsigned char> result;
    result.reserve(data.size());
    for (unsigned char i : data) {
        result.push_back(getInvSboxValue(i));
    }
    return result;
}

unsigned char *SPbox::invSbox(const unsigned char *data) {
    unsigned int len = sizeof(data) / sizeof(int);
    CheckLength(len);
    unsigned char *result = new unsigned char[len];
    for (int i = 0; i < len; ++i) {
        result[i] = getInvSboxValue(data[i]);
    }
    return result;
}

unsigned char SPbox::getSboxValue(unsigned char ch) {
    unsigned char p1 = ch >> 4;
    unsigned char p2 = ch & 0x0F;
    return sbox[p1][p2];
}

void SPbox::setInvSbox() {
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; ++j) {
            unsigned char row = sbox[i][j] / 16;
            unsigned char col = sbox[i][j] % 16;
            inv_sbox[row][col] = i * 16 + j % 16;
        }
    }
}

unsigned char SPbox::getInvSboxValue(unsigned char ch) {
    setInvSbox();
    unsigned char p1 = ch >> 4;
    unsigned char p2 = ch & 0x0F;
    return inv_sbox[p1][p2];
}

std::vector<unsigned char> SPbox::Pbox(std::vector<unsigned char> data) {
    CheckLength(data.size());
    std::vector<unsigned char> result;
    result.reserve(data.size());
    for (unsigned char i : data) {
        result.push_back(getPboxValue(i));
    }
    return result;
}

unsigned char SPbox::getPboxValue(unsigned char ch) {
    int binary[8];
    int Pbinary[8];
    for(int n = 0; n < 8; n++) {
        binary[7 - n] = (ch >> n) & 1;
    }
    for (int i = 0; i < 8; ++i) {
        Pbinary[i] = binary[pbox[i]];
    }
    unsigned char result = 0;
    for (int i = 0; i < 8; ++i) {
        result <<= 1;
        if (Pbinary[i] == 1)
            result += 1;
    }
    return result;
}

std::vector<unsigned char> SPbox::invPbox(std::vector<unsigned char> data) {
    CheckLength(data.size());
    std::vector<unsigned char> result;
    result.reserve(data.size());
    for (unsigned char i : data) {
        result.push_back(getInvPboxValue(i));
    }
    return result;
}

void SPbox::setInvPbox() {
    for (int i = 0; i < 8; i++)
    {
        inv_pbox[pbox[i]] = i;
    }
}
unsigned char SPbox::getInvPboxValue(unsigned char ch) {
    setInvPbox();
    int binary[8];
    int Pbinary[8];
    for(int n = 0; n < 8; n++) {
        binary[7 - n] = (ch >> n) & 1;
    }
    for (int i = 0; i < 8; ++i) {
        Pbinary[i] = binary[inv_pbox[i]];
    }
    unsigned char result = 0;
    for (int i = 0; i < 8; ++i) {
        result <<= 1;
        if (Pbinary[i] == 1)
            result += 1;
    }
    return result;
}

void SPbox::printSbox() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(sbox[i][j]) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void SPbox::printInvSbox() {
    setInvSbox();
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(inv_sbox[i][j]) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void SPbox::printPbox() {
    for (int i = 0; i < 8; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pbox[i]) << ' ';
    }
    std::cout << std::endl;
}

void SPbox::printInvPbox() {
    setInvPbox();
    for (int i = 0; i < 8; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(inv_pbox[i]) << ' ';
    }
    std::cout << std::endl;
}





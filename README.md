# Project information
This project was created for educational purposes. The topic of the project is related to the study of [S-box](https://en.wikipedia.org/wiki/S-box) and [P-box](https://en.wikipedia.org/wiki/Permutation_box). These two methods are the basic components of symmetric encryption algorithms.

# Description
The repository contains a library with the SPbox class, which implements forward and reverse conversion of 8-bit data using substitution and permutation.
### S-box
The S-box is specified in the library as a 16x16 table used in AES ([Rijndael S-box](https://en.wikipedia.org/wiki/Rijndael_S-box)). For substitution, the input data is divided into two tetrads (4-bits each). For the reverse conversion, the `setInvSbox()` function is used, which calculates the reverse table of constants (it is necessary according to the conditions of the task, but it would be more efficient to immediately set the value of inverted table).\
There are methods:

* `std::vector<unsigned char> Sbox(std::vector<unsigned char> data)` - substitution for vector of 8-bit data
* `unsigned char *Sbox(const unsigned char data[])` - substitution for dynamic array of 8-bit data
* `std::vector<unsigned char> invSbox(std::vector<unsigned char> data)` - inverse substitution for an 8-bit vector
* `unsigned char *invSbox(const unsigned char data[])` - inverse substitution for dynamic array of 8-bit data
### P-box
An array of 8 elements is used for permutation `const unsigned char pbox[8] = {0x6, 0x0, 0x4, 0x1, 0x7, 0x2, 0x5, 0x3}`. As in S-box, the `setInvPbox()` function is used here to calculate the inverted array of constants.\
There are methods:
* `std::vector<unsigned char> Pbox(std::vector<unsigned char> data)` - permutation for vector of 8-bit data
* `unsigned char *Sbox(const unsigned char data[])` - inverse permutation for dynamic array of 8-bit data
### Additional functions
* `void CheckLength(int len)` - checking the length of data passed to the class
output of S-box and P-box tables
* `void printSbox()`
* `void printInvSbox()`
* `void printPbox()`
* `void printInvPbox()`

# Usage
### S-box
Forward
```c++
SPbox spbox;
std::vector<unsigned char> data = {0x14, 0x0f, 0x55};
std::vector<unsigned char> result = spbox.Sbox(data); // fa 76 fc
```
Reverse
```c++
SPbox spbox;
std::vector<unsigned char> data = {0xff, 0xec, 0x1e, 0xf5, 0xff, 0x08, 0x04};
std::vector<unsigned char> result = spbox.invSbox(data); // 7d 83 e9 77 7d bf 30
```
### S-box
Forward
```c++
SPbox spbox;
std::vector<unsigned char> data = {0xab, 0x65, 0xfa, 0xff, 0x01, 0x20};
std::vector<unsigned char> result = spbox.Pbox(data); // ec 1e f5 ff 08 04
```
Reverse
```c++
SPbox spbox;
std::vector<unsigned char> data = {0x45, 0x88, 0x68, 0xf1, 0x1, 0x01, 0x35, 0xdb};
std::vector<unsigned char> result = spbox.invPbox(data); // b0 03 89 da 10 10 78 d7
```

#include <iostream>

#include "huffman_encoding/huffman_code.h"
#include "huffman_encoding/huffman_code_sec.hpp"

int main() {

    std::cout << "Hello, World!" << std::endl;
    // test huffman coding
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffManCodes_C(arr, freq, size);
    using namespace Cpp;
    HuffmanCodes_Cpp(arr, freq, size);
    return 0;
}
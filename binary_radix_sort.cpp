#include <iostream>

void countingSortByBit(unsigned char* A, unsigned char* B, int size, int k) {
    int C[2] = {0, 0};
    
    for (int i = 0; i < size; i++) {
        bool bit = (A[i] >> k) & 1;
        C[bit]++;
    }
    
    C[1] += C[0];
    
    for (int i = size - 1; i >= 0; i--) {
        bool bit = (A[i] >> k) & 1;
        B[--C[bit]] = A[i];
    }
    
    for (int i = 0; i < size; i++) {
        A[i] = B[i];
    }
}

void printBinary(unsigned char num) {
    for (int k = 7; k >= 0; k--) {
        std::cout << ((num >> k) & 1);
    }
}

void binaryRadixSort(unsigned char* A, int size) {
    unsigned char* B = new unsigned char[size];

    std::cout << "Binarna predstavitev: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << (int)A[i] << " = ";
        printBinary(A[i]);
        std::cout << std::endl;
    }

    for (int k = 0; k < 8; k++) {
        countingSortByBit(A, B, size, k);
    }

    std::cout << "Binarna predstavitev: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << (int)A[i] << " = ";
        printBinary(A[i]);
        std::cout << std::endl;
    }
    
    delete[] B;
}



int main() {
    int size;
    std::cout << "Vnesite število elementov: ";
    std::cin >> size;
    
    unsigned char* A = new unsigned char[size];
    
    std::cout << "Vnesite " << size << " števil (0-255):" << std::endl;
    for (int i = 0; i < size; i++) {
        int input;
        std::cin >> input;
        if (input < 0 || input > 255) {
            std::cout << "Neveljavna vrednost! Vnesite število med 0 in 255." << std::endl;
            i--;
            continue;
        }
        A[i] = static_cast<unsigned char>(input);
    }
    
    std::cout << "\nOriginalno polje: ";
    for (int i = 0; i < size; i++) {
        std::cout << (int)A[i] << " ";
    }
    std::cout << std::endl;

    binaryRadixSort(A, size);


    
    delete[] A;
    
    return 0;
}






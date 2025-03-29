#include <iostream>

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
    
    delete[] A;
    
    return 0;
}

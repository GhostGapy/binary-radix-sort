#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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
        cout << ((num >> k) & 1);
    }
}

void binaryRadixSort(unsigned char* A, int size) {
    unsigned char* B = new unsigned char[size];

    for (int k = 0; k < 8; k++) {
        countingSortByBit(A, B, size, k);
    }
    
    delete[] B;
}



int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uporaba: " << argv[0] << " <vhodna datoteka>" << endl;
        return 1;
    }
    
    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cerr << "napaka pri odpiranju datoteke" << argv[1] << endl;
        return 1;
    }
    
    vector<unsigned char> numbers;
    int num;
    while (input_file >> num) {
        if (num < 0 || num > 255) {
            cerr << "stevilo " << num << " ni v območju 0-255" << endl;
            continue;
        }
        numbers.push_back(static_cast<unsigned char>(num));
    }
    input_file.close();
    

    if (numbers.empty()) {
        cerr << "v datoteki ni dobrih stevil za to" << endl;
        return 1;
    }
    
    int size = numbers.size();
    unsigned char* A = new unsigned char[size];
    
    for (int i = 0; i < size; i++) {
        A[i] = numbers[i];
    }
     
    binaryRadixSort(A, size);
    
    
    ofstream output_file("out.txt");
    if (!output_file.is_open()) {
        cerr << "do napake je prislo pri ustvarjanju out.txt" << endl;
        delete[] A;
        return 1;
    }
    
    for (int i = 0; i < size; i++) {
        output_file << static_cast<int>(A[i]);
        if (i < size - 1) {
            output_file << " ";
        }
    }
    output_file.close();
    
    delete[] A;
    
    return 0;
}






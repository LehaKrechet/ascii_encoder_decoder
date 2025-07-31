#include <iostream>
#include <string> 
#include <cstdlib>
#include <locale>

int key_create(std::string key){
    int out_key = 0;
    for (int i = 0; i < key.size(); i += 1) {
        out_key += key[i];  
    }
    return out_key;
}


std::string encode(std::string in, int key){
    int* arr = new int[in.size()];
    std::string out;
    for (int i = 0; i < in.size(); i += 1) arr[i] = (32 + key + int(in[i]))%128;
    for (int i = 0; i < in.size(); i += 1) out+=char(arr[i]);
    return out;
    delete[] arr;

}

std::string decode(std::string in, int key){
    int* arr = new int[in.size()];
    std::string out;
    for (int i = 0; i < in.size(); i += 1) {
        arr[i] = 128 - abs(key - (int(in[i])-32))%128;
    }
    for (int i = 0; i < in.size(); i += 1) out+=char(arr[i]);
    return out;
    delete[] arr;

}


int main(int argc, char* argv[]){
    

    

    std::string mode = argv[1];
    int key = key_create(argv[2]);
    std::cout << key << std::endl;
    

    if (mode == "encode"){
        std::string in;
        getline(std::cin, in);

        std::cout << encode(in, key) << std::endl; 
    }else if (mode == "decode"){
        std::string in;
        getline(std::cin, in);

        std::cout << decode(in, key) << std::endl; 
    }

    


}
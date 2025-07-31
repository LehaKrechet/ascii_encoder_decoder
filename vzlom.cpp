#include <iostream>
#include <string>

int main(){
    std::string in;
    getline(std::cin, in);
    std::string out;

    for (int i = 32; i < 128; i += 1){
        for (int j = 0; j < in.size(); j += 1){
            out += 128 - abs(i - (int(in[j])-32))%128;
        }
        // char condition = ;
        // if (out[0] == 'H'){
            std::cout << out << " " << "key: " << i << std::endl;
        // }
        out = "";
        
    }
}
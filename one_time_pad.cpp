#include <fstream>
#include "./one_time_pad.h"

namespace one_time_pad{
    std::string load_file(std::string path) {
        std::ifstream file;
        file.open(path);
        std::string data = "";
        getline(file, data);
        return data;
    }

    std::string encrypt(std::string key, std::string plain_text){
        std::string encrypted = "";
        for(int i = 0; i < plain_text.size(); i++){
            encrypted += modular_encode(key[i], plain_text[i]);
        }
        return encrypted;
    }

    std::string decrypt(std::string key, std::string encrypted){
        std::string plain_text = "";
        for(int i = 0; i < encrypted.size(); i++){
            plain_text += modular_decode(encrypted[i], key[i]);
        }
        return plain_text;
    }

    char modular_encode(int key_value, int plain_value) {
        int sum = modular_reduce(key_value + plain_value);
        return sum;
    }

    char modular_decode(int encoded_value, int key_value){
        key_value = modular_reduce(key_value);
        return encoded_value - key_value;
    }

    int modular_reduce(int value){
        if(value > MODULAR_SCALE){
            return value - MODULAR_SCALE;
        }else{
            return value;
        }
    }
}

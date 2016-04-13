#include <fstream>
#include "./one_time_pad.h"

const int MODULAR_SCALE = 'Z';

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

    char modular_encode(int key_value, int plain_value){
        char sum = key_value + plain_value;
        if(sum > MODULAR_SCALE){
            sum -= MODULAR_SCALE;
        }
        return sum;
    }

    char modular_decode(int encoded_value, int key_value){
        if(key_value > MODULAR_SCALE){
            key_value -= MODULAR_SCALE;
        }
        return (char)(encoded_value - key_value);
    }
}

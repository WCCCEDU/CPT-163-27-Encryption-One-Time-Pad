namespace one_time_pad{
    const int MODULAR_SCALE = 'z';
    std::string load_file(std::string path);
    std::string encrypt(std::string key, std::string plain_text);
    std::string decrypt(std::string key, std::string encrypted);
    char modular_encode(char key_value, char plain_value);
    char modular_decode(char encoded_value, char key_value);
    char modular_reduce(char value);
}

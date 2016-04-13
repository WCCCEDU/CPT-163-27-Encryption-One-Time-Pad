#include <iostream>
#include <fstream>
#include "./one_time_pad.h"


/*
 * The one time pad cypher is a character substitution algorithm
 * whose keyspace (password or cypher) must be at least the same
 * size or larger than the crib or plaintext to be encrypted
 */

const std::string KEY_FILE = "key_file.txt";
const std::string PLAIN_TEXT_FILE = "plain_text.txt";
const std::string ENCODED_TEXT_FILE = "output.txt";
const std::string CONFIRM_DECODE_TEXT_FILE = "confirm.txt";

int main() {

    char letter_a_cypher = 'a';
    char letter_b_plain = 'b';
    char encoded = one_time_pad::modular_encode(letter_a_cypher, letter_b_plain);
    char confirmation = one_time_pad::modular_decode(encoded, letter_a_cypher);

    std::cout << letter_a_cypher
        << " " << letter_b_plain
        << " " << encoded
        << " " << confirmation << std::endl;

    std::string key_space = one_time_pad::load_file(KEY_FILE);
    std::string plain_text = one_time_pad::load_file(PLAIN_TEXT_FILE);

    std::string encrypted_text = one_time_pad::encrypt(key_space, plain_text);

    std::ofstream out;
    out.open(ENCODED_TEXT_FILE);
    out << encrypted_text;
    out.close();

    std::string encoded_text = one_time_pad::load_file(ENCODED_TEXT_FILE);
    std::string decrypted_text = one_time_pad::decrypt(key_space, encoded_text);

    std::ofstream confirm;
    confirm.open(CONFIRM_DECODE_TEXT_FILE);
    confirm << decrypted_text;
    confirm.close();

    return 0;
}

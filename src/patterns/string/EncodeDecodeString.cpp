#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(const vector<string> &strs) {
    string encoded_string = "";

    for (auto &str : strs) {
      const uint8_t str_len = str.size();
      strncpy(encoded_string.data() + encoded_string.size(), reinterpret_cast<const char *>(&str_len), sizeof(str_len));
      encoded_string += str;
    }

    return encoded_string;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(const string s) {
    vector<string> decoded_strings;
    size_t it = 0;

    while (it < s.size()) {
      const uint8_t *str_len = reinterpret_cast<const uint8_t *>(s.data() + it);
      it += 8;
      string decoded_string{s.data() + it, s.data() + it + *str_len};

      decoded_strings.emplace_back(move(decoded_string));
    }

    return decoded_strings;
  }
};

int main() {
  {
    Codec encoder;
    string msg = encoder.encode({"Hello", "World"});

    Codec decoder;
    vector<string> strs = decoder.decode(msg);
  }

  {
    Codec encoder;
    string msg = encoder.encode({""});

    Codec decoder;
    vector<string> strs = decoder.decode(msg);
  }
}

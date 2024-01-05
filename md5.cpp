#include "md5.h"
#include <openssl/md5.h>

std::string md5(const std::string& str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    char mdString[33];

    MD5((unsigned char*)str.c_str(), str.size(), digest);

    for(int i = 0; i < 16; i++) {
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    return std::string(mdString);
}

#ifndef MD5_H
#define MD5_H

#include <string>
#include <openssl/md5.h>

extern std::string md5(const std::string& str);

#endif // MD5_H

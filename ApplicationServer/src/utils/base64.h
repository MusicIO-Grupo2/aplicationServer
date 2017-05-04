//
// Created by Nicolas Alvarez on 5/3/17.
//

#ifndef APPLICATIONSERVER_BASE64_H
#define APPLICATIONSERVER_BASE64_H
#include <string>
std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);
#endif //APPLICATIONSERVER_BASE64_H

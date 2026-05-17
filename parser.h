#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <memory>
#include "user.h"
#include "post.h"

struct ParsedData {
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::shared_ptr<post>> posts;
};

class Parser
{
public:
    Parser();
    ParsedData parse(const std::string& json_string);
};

#endif // PARSER_H

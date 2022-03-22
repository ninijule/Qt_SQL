#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <regex>


class Utils{
public:
    bool is_email_valid(const std::string& email)
    {
       // define a regular expression
        const std::regex pattern
              ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");


       // try to match the string with the regular expression
       if(std::regex_match(email, pattern)){
           return true;
       } else{
           return false;
       }
    }
};



#endif // UTILS_H

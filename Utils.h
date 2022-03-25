#ifndef UTILS_H
#define UTILS_H

#include "string"


class Utils
{
public:
    Utils();
    void sendMessageBox(std::string title, std::string message);
    bool is_email_valid(const std::string& email);

private:

};

#endif // UTILS_H

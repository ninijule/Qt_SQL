#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <regex>
#include "QMessageBox"
#include "QWidget"

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

    void sendMessageBox(QWidget *parent, std::string title, std::string message){
        QMessageBox msgbox;
        msgbox.setText(title.c_str());
        msgbox.setInformativeText(message.c_str());
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.exec();

    }
};



#endif // UTILS_H

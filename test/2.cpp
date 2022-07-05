//
// Created by 成翔昊 on 2022/5/23.
//

#include <iostream>
using namespace std;

class Message {
public:
    Message() {
        this->s = "";
        this->type = "Default";
        cout << this->type << endl;
    }
    Message(string s) {
        this->s = s;
        this->type = "Parameter";
        cout << this->type << endl;
    }
    Message(const Message &msg) {
        this->s = msg.s;
        this->type = "Copy";
        cout << this->type << endl;
    }
    ~Message() {
        cout << "Release " << this->type << endl;
    }
private:
    string s;
    string type;
};

Message run(Message msg) {
    return msg;
}

int main() {
    Message msg("Hello");
    run(msg);
}

/**
 * Parameter
 * Copy
 * Copy
 * Release Copy
 * Release Copy
 * Release Parameter
 * */
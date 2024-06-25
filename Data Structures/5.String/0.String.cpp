#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int len;

public:
    String();
    String(const char* s);
    String(const String &s);
    ~String();
    size_t length() const;
    char operator[](size_t index) const;
    String &operator=(const String &s);
    bool operator==(const String &s) const;
    bool operator!=(const String &s) const;
    String copy() const;
    String operator+(const String &s);
    friend ostream &operator<<(ostream &os, const String &s);
};

String::String() {
    str = new char[1];
    str[0] = '\0';
    len = 0;
}

String ::String(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

String::String(const String &s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}

String::~String() {
    delete[] str;
}

size_t String::length() const {
    return len;
}

char String::operator[](size_t index) const {
    if (index >= len) {
        throw out_of_range("Index out of range");
    }
    return str[index];
}

String &String::operator=(const String &s) {
    if (this == &s) {
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

bool String::operator==(const String &s) const {
    return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(str, s.str) != 0;
}

String String::copy() const {
    String s(*this);
    printf("%p %p", s.str, this->str);
    return s;
}

String String::operator+(const String &s) {
    char* newStr = new char[len + s.len + 1];
    strcpy(newStr, str);
    strcat(newStr, s.str);
    String newString(newStr);
    delete[] newStr;
    return newString;
}

ostream &operator<<(ostream &os, const String &s) {
    os << s.str;
    return os;
}

int main() {
    String s("12345d");
    cout << s << endl;
    cout << s.length() << endl;
    cout << s + "445" << endl;
    cout << s << endl;
    cout << s[2] << endl;
    cout << (s == "12345d") << endl;
    cout << (s != "12345d") << endl;

    s = s + "asd";
    cout << s << endl;

    String s2 = s.copy();
    cout << s2 << endl;

    return 0;
}

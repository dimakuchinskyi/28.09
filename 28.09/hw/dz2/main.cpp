#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class String {
protected:
    char* _data;
    size_t _length;

public:
    String()
    {
        _data = nullptr;
        _length = 0;
    }

    String(const char* str) {
        _length = strlen(str);
        _data = new char[_length + 1];
        strcpy(_data, str);
    }

    String(String& other) {
        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;

        delete[] _data;
        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);

        return *this;
    }

    size_t Length() const {
        return _length;
    }

    void Clear() {
        delete[] _data;
        _data = new char[1];
        _data[0] = '\0';
        _length = 0;
    }

    virtual ~String() {
        delete[] _data;
    }

    String operator+(const String& other) const {
        String result;
        result._length = _length + other._length;
        delete[] result._data;
        result._data = new char[result._length + 1];
        strcpy(result._data, _data);
        strcat(result._data, other._data);
        return result;
    }

    String& operator+=(const String& other) {
        _length += other._length;
        char* new_data = new char[_length + 1];
        strcpy(new_data, _data);
        strcat(new_data, other._data);
        delete[] _data;
        _data = new_data;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(_data, other._data) == 0;
    }

    bool operator!=(const String& other) const {
        return strcmp(_data, other._data) != 0;
    }

    void Print() const {
        cout << _data << endl;
    }
};


class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* str) {
        if (IsValidBitString(str)) {
            _length = strlen(str);
            _data = new char[_length + 1];
            strcpy(_data, str);
        }
        else {
            _length = 0;
            _data = new char[1];
            _data[0] = '\0';
        }
    }

    BitString(BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this == &other) return *this;
        String::operator=(other);
        return *this;
    }

    ~BitString() override {}

    void Negate() {
        for (size_t i = 0; i < _length; ++i) {
            _data[i] = (_data[i] == '0') ? '1' : '0';
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result;
        result._length = _length + other._length;
        result._data = new char[result._length + 1];
        strcpy(result._data, _data);  
        strcat(result._data, other._data);  
        return result;
    }


    BitString& operator+=(const BitString& other) {
        String::operator+=(other);
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }

    bool IsValidBitString(const char* str) {
        for (size_t i = 0; i < strlen(str); ++i) {
            if (str[i] != '0' && str[i] != '1') return false;
        }
        return true;
    }
};

int main() {

    String str1("Hello");
    String str2(" World");
    str1 += str2;
    str1.Print();

    BitString bitStr1("1010");
    BitString bitStr2("0101");
    BitString bitSum = bitStr1 + bitStr2;
    bitSum.Print();

    bitStr1.Negate();
    bitStr1.Print();

    return 0;
}

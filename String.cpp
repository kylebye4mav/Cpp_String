#include <cstring>
#include <stdexcept>
#include "String.h"


///
/// Memory Tracker
///

int String::created = 0;
int String::destroyed = 0;

///
/// Getters
///

char *String::getBuffer() const {
    return buffer;
}

unsigned int String::getSize() const {
    return size;
}

///
/// Setters
///

void String::setSize(unsigned int &sizeIn) {
    size = sizeIn;
}

///
/// Functions
///

String String::concatenate(const String &other) {
    //  The size of the return String object
    //  will be the sum of characters of both this
    //  instance and 'other' instance. Does not include
    //  null char.
    int totalSize = size+other.getSize();
    char *rS_buffer = new char[totalSize+1];

    //  Fill the contents of this string first.
    for (int i = 0; i < size; ++i) rS_buffer[i] = (*this)[i];

    //  Fill the contents of the 'other' string.
    int x = 0;
    for (unsigned int i = size; i < totalSize; ++i) {
        char c = (other)[x];
        rS_buffer[i] = c;
        ++x;
    }
    rS_buffer[totalSize] = '\0';

    //  Constructor, String(const char*), will be implcitly called. 
    return rS_buffer;
}

bool String::contains(const char &toFind) {
    for (int i = 0; i<size; ++i) if (buffer[i] == toFind) return true;
    return false;
}

/*  W.I.P
bool String::contains(const String &toFind) {
    if (toFind.getSize() == 0) return false;

    for (int i = 0; i<size; ++i) {
        if (buffer[i] == toFind[0]) {
            int x = i + 1;
            for (int j = 0; j<toFind.getSize(); ++j) {
                if (x >= size) continue;
                if (buffer[x] != toFind[x]) break;
                if (j = toFind.getSize()-1) return true;
            }
        }
    }
    return false;
}
*/

int String::indexOf(const char &toFind) {
    for (int i = 0; i<size; ++i) if (buffer[i] == toFind) return i;
    return -1;
}

int String::lastIndexOf(const char &toFind) {
    for (int i = size-1; i >= 0; --i) if (buffer[i] == toFind) return i;
    return -1;
}

String String::substring(const unsigned int beginIndex, const unsigned int endExclusiveIndex) {
    if (beginIndex < endExclusiveIndex) {
        int returnSize = endExclusiveIndex-beginIndex;
        char returnBuffer[returnSize];
        int x = 0;
        for (int i = beginIndex; i<endExclusiveIndex; ++i) {
            returnBuffer[x] = buffer[i];
            ++x;
        }
        return returnBuffer;
    }
    else if (beginIndex < endExclusiveIndex) {
        return "";
    }
    else {
        throw std::invalid_argument("beginIndex > endExclusiveIndex in String class when using substring(int,int)");
    }
}

bool String::equals(const String &other) {
    if (size != other.getSize()) return false;

    for (int i = 0; i<size; ++i) {
        if (buffer[i] != other[i]) return false;
    }

    return true;
}

///
/// Operator Overloads
///

char &String::operator [](unsigned int index) {
    if (index >= size) {
        throw std::invalid_argument("Index out of bounds in String class when using [] operator.");
    }
    return buffer[index];
}

char &String::operator[](unsigned int index) const {
    if (index >= size) {
        throw std::invalid_argument("Index out of bounds in String class when using [] operator.");
    }
    return buffer[index];
}

std::ostream &operator << (std::ostream &os, String const &m) {
    return os << m.buffer;
}

String String::operator +(const String &other) {
    return concatenate(other);
}

String &String::operator +=(const String &other) {
    int newSize = size+other.getSize();
    char *tempBuffer = new char[newSize+1];

    //  Copy 'this' each string char.
    for (int i = 0; i<size; ++i) tempBuffer[i] = (*this)[i];

    //  Copy 'other' chars.
    int x = 0;
    for (int i = size; i<newSize; ++i) {
        tempBuffer[i] = other[x];
        ++x;
    }
    tempBuffer[newSize] = '\0';

    //  Assign values to 'this' instance.
    char *oldBuffer = this->buffer;
    buffer = tempBuffer;
    size = newSize;
    delete oldBuffer;

    return (*this);
}

String &String::operator +=(const char &c) {
    int newSize = size + 1;
    char *tempBuffer = new char[newSize + 1];

    // Copy 'this' chars to tempBuffer.
    for (int i = 0; i<size; ++i) tempBuffer[i] = (*this)[i];

    //  Copy the new char to tempBuffer.
    tempBuffer[size] = c;
    tempBuffer[newSize] = '\0';

    //  Assign values to 'this' instance;
    char *oldBuffer = this->buffer;
    buffer = tempBuffer;
    size = newSize;
    delete oldBuffer;

    return (*this);
}

bool String::operator ==(const String &other) {
    return equals(other);
}

///
/// Constructors
///

String::String() {
    ++created;
    buffer = new char[1];
    buffer[0] = '\0';
    size = 0;
}

String::String(const String &other) : buffer(nullptr), size(other.getSize()) {
    ++created;
    buffer = new char[size + 1];
    memcpy(buffer, other.getBuffer(), size + 1);
    buffer[size] = '\0';
}

String::String(const char *cStr) : buffer(nullptr), size(strlen(cStr)) {
    ++created;
    buffer = new char[size + 1];
    memcpy(buffer, cStr, size + 1);
    buffer[size] = '\0';
}

///
/// Destructor
///

String::~String() {

    ++destroyed;
    delete[] buffer;

}
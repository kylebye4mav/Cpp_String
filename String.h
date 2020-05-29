#include <iostream>

///
/// Forward Declaration
///

class String;

///
/// String Class
///

/**
 * @author byekv1 
 */
class String {

public:

    ///
    /// Memory Tracker
    ///
    
    static int created;
    static int destroyed;

private:

    ///
    /// Properties
    ///

    char *buffer;
    unsigned int size;

public:

    ///
    /// Getters
    ///

    char *getBuffer() const;
    unsigned int getSize() const;

    ///
    /// Setters
    ///

    void setSize(unsigned int &sizeIn);

    ///
    /// Functions
    ///
    
    String concatenate(const String &other);
    bool contains(const char &toFind);
    //bool contains(const String &toFind);  W.I.P
    int indexOf(const char &toFind);
    int lastIndexOf(const char &toFind);
    String substring(const unsigned int beginIndex, const unsigned int endExclusiveIndex);
    bool equals(const String &other);

    ///
    /// Operator Overloads
    ///

    char &operator[](unsigned int index);
    char &operator[](unsigned int index) const;
    String operator +(const String &other);
    String &operator +=(const String &other);
    String &operator +=(const char &c);
    bool operator ==(const String &other);

    // Allow String to be used with std::cout function
    friend std::ostream &operator << (std::ostream &os, String const &m);
    
    ///
    /// Constructors
    ///

    String();
    String(const String &other);
    String(const char *cStr);

    ///
    /// Destructors
    ///

    ~String();
    
};
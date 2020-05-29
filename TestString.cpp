#include <iostream>
#include "String.h"

void analyze(String &str);

int main() {
    
{
    String s1 = "Hello";
    analyze(s1);

    String s2 = s1;
    s2[3] = 'N';
    analyze(s2);

    analyze(s1);

    String defaultConst;
    analyze(defaultConst);    

    String s4 = "World";
    analyze(s4);

    String s5 = s1.concatenate(s4);

    analyze(s5);

    
    String s6 = s1 + s5;
    analyze(s6);

    s6 += s4;
    analyze(s6);
}

{
    String s;
    for (int i = 0; i<255; ++i) {
        s += 'a';
        analyze(s);
    }
}

{
    String search = "Hello";
    char toFind;

    std::cout << search.contains('l') << std::endl;
    std::cout << search.contains('h') << std::endl;
}

{
    String search = "Hello";

    std::cout << search.indexOf('a') << std::endl;
    std::cout << search.indexOf('l') << std::endl;
    std::cout << search.lastIndexOf('l') << std::endl;
    std::cout << search.lastIndexOf('H') << std::endl;
    std::cout << search.indexOf('\0') << std::endl;
}

{
    String wholeString = "Hello World!";
    String helloString = wholeString.substring(0, 5);
    String worldString = wholeString.substring(6,11);
    String wholeString2 = helloString + " " + worldString + "!";

    std::cout << helloString << " " << worldString << "!" << std::endl;
    std::cout << wholeString2 << std::endl;
    std::cout << wholeString.equals(wholeString2) << std::endl;
    std::cout << wholeString.equals("hello World!") << std::endl;
    std::cout << wholeString.equals("Hello World! ") << std::endl;
    std::cout << (wholeString == "Hello World!") << std::endl;
}

/*
{
    String wholeString = "Hello World!";
    std::cout << wholeString.contains("Hello!") << std::endl;
    std::cout << wholeString.contains("WorldX") << std::endl;
}
*/

{
    std::cout << "Created String Objects: " << String::created << std::endl;
    std::cout << "Destroyed String Objects: " << String::destroyed << std::endl;
    if (String::created == String::destroyed) std::cout << "No Memory Leaks! :)" << std::endl;
    else std::cout << "Memory Leak! :(" << std::endl;
}

    //  Term...
    std::cout << "END..."; 
    std::cin.get();
}

void analyze(String &str) {
    std::cout << "String = " << "\"" << str << "\"" << std::endl;
    std::cout << "\tSize = " << str.getSize() << std::endl;
}
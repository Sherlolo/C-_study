#include <iostream>
#include <string>

class Book
{
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author) : _no(no), _name(name), _author(author){}
private:
    unsigned _no;
    std::string _name;
    std::string _author;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
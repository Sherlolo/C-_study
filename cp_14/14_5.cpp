#include "14_5.h"

std::istream& operator>>(std::istream& in, Book& book)
{
    in >> book._no >> book._name >> book._author;
    if(!in)
        book = Book();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
    out << " : " << book._no << " : " << book._name << " : " << book._author << std::endl;
    return out;
}

int main()
{
	Book book1(123, "CP5", "Lippman");
	Book book2(123, "CP5", "Lippman");

	
	std::cout << book1 << std::endl;
    system("pause");
    return 0;
}
#ifnedf STRING_H_
#define STRING_H_

#include <string>
#include <algorithm>
#include <memory>

class String
{
public:
    String();
    String(const char* s)
    {
        auto s1 = const_cast<char*>(s); //转换为非常量的指针
        while(*s1)
        {
            ++s1;
        }
        range_initializer(s, s1);
    }
    String(const String&);
    String& operator=(const String&);
    ~String()
    {
        free();
    }
private:
    void free()
    {
        if(element)
        {
            for_each(element, end, [this](char& rhs){alloc.destroy(&rhs);});
            alloc.deallocate(element, end - element);
        }
    }

    std::pair<char*, char*> alloc_n_copy(const char* a, const char* b)
    {
        auto s1 = alloc.allocate(b - a);
        auto s2 = std::uninitialized_copy(a, b, s1);
        return std::make_pair(s1, s2);
    }

    void range_initializer(const char* c , const char* d)
    {
        auto p = alloc_n_copy(d, c);
        element = p.first;
        end = p.second;
    }
private:
    std::allocator<char> alloc;
    char *element;
    char *end;
};

#endif
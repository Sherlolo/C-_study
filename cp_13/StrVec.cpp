#include "StrVec.h"

StrVec::StrVec(const StrVec& rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    if(this == &rhs)
        return *this;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

//move
StrVec::StrVec(StrVec&& s) : elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
    std::cout << "StrVec(StrVec&& s) " << std::endl;
    s.elements = s.first_free = s.cap = nullptr;    //令s进入析构函数是安全的
}

StrVec& StrVec::operator=(StrVec &&rhs)
{
    std::cout << "StrVec::operator=(StrVec &&rhs) " << std::endl;
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    free();
}


void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t new_cap)
{
    if(new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string& s) 
{
    if(count > size())
    {
        if(count > capacity())
            reserve(count * 2);
        for(size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        while(first_free != elements + count)
            alloc.destroy(--first_free);
    }
}


//--------------内部接口--------------//
std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string* start_str, const std::string* end_str)
{
    auto data = alloc.allocate(end_str - start_str);
    return {data, std::uninitialized_copy(start_str, end_str, data)};
}

void StrVec::free() 
{
    if(elements)    //初始化的alloc时，elements为null，alloc没有分配空间
    {
        for(auto p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcap = size() ? 2*size() : 1;
    alloc_n_move(newcap);
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;  
}



#ifndef STRVEC_H_
#define STRVEC_H_
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&); 
    StrVec(StrVec&&);
    StrVec& operator=(StrVec &&rhs);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);
private:
    //工具函数，被拷贝控制成员所调用
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*); //对指针范围分配新的空间并拷贝
    void free(); //销毁元素并释放
    void chk_n_alloc(){if(size() == capacity()) reallocate();} //检查是否需要分配新的内存空间
    void reallocate();  //重新分配新空间
    void alloc_n_move(size_t new_cap);  //将原始数据移动拷贝过来
private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    std::allocator<std::string> alloc; //alloc只是一个构造器 无需拷贝和初始化
};

#endif
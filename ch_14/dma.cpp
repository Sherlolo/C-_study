#include "dma.h"
#include <cstring>

DMA::DMA(const char *cn)
{
    classname = new char[std::strlen(cn) + 1];
    std::strcpy(classname, cn);
}

DMA::DMA(const DMA &rs)
{
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
}

DMA &DMA::operator=(const DMA &rs)
{
    if(this == &rs)
        return *this;
    delete [] classname;
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
    return *this;
}

DMA::~DMA()
{
    delete [] classname;
}


baseDMA::baseDMA(const char * l, int r, const char *cn) : DMA(cn)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const char * l, int r, const DMA &rs) : DMA(rs)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) : DMA(rs)
{
    //DMA(rs.show_classname());
    //DMA(rs);
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

void baseDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "label: " << label << std::endl;
    std::cout << "rating: " << rating << std::endl;
}

baseDMA &baseDMA::operator=(const baseDMA &rs)
{
    if(this == &rs)
        return *this;
    //DMA::operator=(DMA)rs; //rs为const 不能转换
    DMA::operator=(rs);
    delete label;
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

lacksDMA::lacksDMA(const char* c, const char *cn) : DMA(cn)
{
    std::strncpy(color, c, 40);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const DMA &rs) : DMA(rs)
{
    std::strncpy(color, c, 40);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &ls) : DMA(ls)
{
    std::strncpy(color, ls.color, 40);
    color[39] = '\0';
}

lacksDMA::~lacksDMA()
{

}

void lacksDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "color: " << color << std::endl;
}

lacksDMA &lacksDMA::operator=(const lacksDMA &ls)
{
    if(this == &ls)
        return *this;
    // DMA::operator=(const DMA &)ls;
    DMA::operator=(ls);
    std::strncpy(color, ls.color, 40);
    color[39] = '\0';
    return *this;
}


hasDMA::hasDMA(const char* s, const char* cn) : DMA(cn)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const DMA &rs) : DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : DMA(hs)
{
    // DMA(hs.show_classname());
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "style:  " << style << std::endl;
}

hasDMA &hasDMA::operator=(const hasDMA &rs)
{
    if(this == &rs)
        return *this;
    // DMA::operator=(const DMA &)rs;
    DMA::operator=(rs);
    delete [] style;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}



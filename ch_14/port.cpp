#include "port.h"

Port::Port()
{
    band = new char[5];
    std::strcpy(band,"Null");
    std::strcpy(style, "Null style");
    std::cout << "port constrution \n";
    bottles = -1;
}

Port::Port(const char * br, const char * st, int b)
{
    band = new char[std::strlen(br) + 1];
    std::strcpy(band,br);
    std::strncpy(style, st, 20);
    std::cout << "Port() yes\n";
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port& p)
{
    band = new char[std::strlen(p.band) + 1];
    std::strcpy(band, p.band);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
}

Port::~Port()
{
    delete [] band;
}

Port& Port::operator=(const Port& p)
{
    if(this == &p)
        return *this;
    delete [] band;
    band = new char[std::strlen(p.band) + 1];
    std::strcpy(band, p.band);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port& Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << band << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    os << p.band << " , " << p.style << " , " << p.bottles << std::endl;
    return os;
}

// VintagePort::VintagePort() //: Port() //error
// {
//     nickname = new char[5];
//     std::strcpy(nickname,"Null");
//     year = -1;
// }

VintagePort::VintagePort() : Port() //Port("none", "vintage", 0) // ???
{

    nickname = new char[5];
    std::strcpy(nickname,"Null");
    year = -1;
    std::cout << "vintagePort constrution\n";
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort::~VintagePort()
{
    delete [] nickname;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "nickname: " << nickname << std::endl;
    std::cout << "year: " << year << std::endl;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if(this == &vp)
        return *this;
    Port::operator=(vp);
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << (const Port&)vp;
    os << "nickname: " << vp.nickname << std::endl;
    os << "year: " << vp.year << std::endl;
    return os;
}
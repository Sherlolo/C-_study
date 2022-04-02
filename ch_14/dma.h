#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA
{
private:
    char *classname;    //设为一个char指针保存要指向的类名
protected:
    const char* show_classname() const {return classname;}
public:
    DMA(const char *cn = "null");
    DMA(const DMA & rs);
    DMA &operator=(const DMA &rs);
    virtual ~DMA();
    virtual void View() const = 0;
};

class baseDMA : public DMA
{
private:
    char *label;
    int rating;
public:
    baseDMA(const char *l = "null", int r = 0, const char *cn = "null");
    baseDMA(const char *l, int r, const DMA &rs);
    baseDMA(const baseDMA &rs);
    baseDMA &operator=(const baseDMA &rs);
    virtual void View() const;
    virtual ~baseDMA();
};

class lacksDMA : public DMA
{
private:
    enum{COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char *cn = "null");
    lacksDMA(const char * c, const DMA &rs);
    lacksDMA(const lacksDMA &ls);
    lacksDMA &operator=(const lacksDMA &ls);
    virtual ~lacksDMA();
    virtual void View() const;
};

class hasDMA : public DMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char *cn = "null");
    hasDMA(const char * s, const DMA &rs);
    hasDMA(const hasDMA &hs);
    hasDMA &operator=(const hasDMA &rs);
    virtual void View() const;
    virtual ~hasDMA();
};

#endif
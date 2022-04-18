#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class ABS_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    ABS_emp() = default;
    ABS_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;
    virtual void SetAll();   
    friend std::ostream& operator<<(std::ostream& os, const ABS_emp& e);
    virtual ~ABS_emp() = 0;
};

class employee : public ABS_emp
{
public:
    employee() : ABS_emp() {}
    employee(const std::string& fn, const std::string& ln, const std::string& j) : ABS_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class mananger : virtual public ABS_emp
{
private:
    int inchargeof; //number of emps managed
protected:
    int InChargeOf() const {return inchargeof;} //output
    int& InChargeOf(){return inchargeof;}   //input
public:
    mananger() : ABS_emp() {}
    mananger(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0)
    : ABS_emp(fn, ln, j), inchargeof(ico) {}
    mananger(const ABS_emp& e, int ico) : ABS_emp(e), inchargeof(ico) {}
    mananger(const mananger& m) : ABS_emp(m), inchargeof(m.inchargeof) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};


class fink: virtual public ABS_emp
{
private:
    std::string report;
protected:
    const std::string Report() const {return report;}
    std::string& Report() {return report;}
public:
    fink() : ABS_emp() {}
    fink(const std::string& fn, const std::string& ln, const std::string& j, std::string rpo)
    : ABS_emp(fn, ln, j), report(rpo) {}
    fink(const ABS_emp& e, std::string rpo) : ABS_emp(e), report(rpo) {};
    fink(const fink& f) : ABS_emp(f), report(f.report) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public mananger, public fink
{
public:
    highfink() : ABS_emp(), mananger(), fink() {}
    highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, const int ico)
    : ABS_emp(fn, ln, j), mananger(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const mananger& m, const std::string& rpo, int ico) : ABS_emp(m), mananger(m,ico), fink(m, rpo) {}
    highfink(const fink& f, const int ico) : ABS_emp(f), mananger((const ABS_emp&)f, ico), fink(f) {}
    highfink(const mananger& m, const std::string& rpo) : ABS_emp(m), mananger(m), fink((const ABS_emp&)m, rpo) {}
    highfink(const highfink& hf) : ABS_emp(hf), mananger(hf), fink(hf) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};
#endif
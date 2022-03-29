#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
    char name[20];
    int CI;
public:
    Plorg(const char news[] = "Plorga", const int var = 50);
    void set_ci(const int var);
    void show_plorg() const;
};

#endif
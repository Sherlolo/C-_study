//14_35 14_36
#include <iostream>
#include <string>
#include <vector>

class GetInput
{
public:
    GetInput(std::istream& i = std::cin) : is(i), vec_str(std::vector<std::string>()){}
    std::string operator()()
    {
        std::string str;
        std::getline(is, str);
        str = is ? str : std::string();
        vec_str.push_back(str);
        return str;
    }
    void Print() const
    {
        for(auto str : vec_str)
        {
            std::cout << str << std::endl;
        }
    }
private:
    std::istream& is;
    std::vector<std::string> vec_str;
};

int main()
{
    GetInput getInput;
    std::cout << getInput() << std::endl;
    std::cout << getInput() << std::endl;
    getInput.Print();
    system("pause");
    return 0;
}
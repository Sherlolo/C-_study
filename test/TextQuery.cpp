#include "TextQuery.h"
#include <iostream>
#include <sstream>

TextQuery::TextQuery(std::ifstream& ifs) : file(new std::vector<std::string>)
{
    using std::string;
    string text;
    while(getline(ifs, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        string word;
        while(line >> word)
        {
            auto& lines = wm[word]; //先创建再赋值
            if(!lines)
                lines.reset(new std::set<int>);
            lines->insert(n); //使用set 会自动将相同元素归并
        }
    }
}

TextQueryResult TextQuery::query(const std::string& obj_string) const
{
    static std::shared_ptr<std::set<int>> nodata(new std::set<int>); //static 避免重复分配资源
    auto loc = wm.find(obj_string);
    if(loc == wm.end())
    {
        return TextQueryResult(obj_string, file, nodata);
    }
    else
    {
        return TextQueryResult(obj_string, file, loc->second);
    }
}

void Print_result(const TextQueryResult& result)
{
    printf("%s occurs %d times\n", result.obj_string.c_str(), result.line->size());
    auto file_ptr = result.file;
    for(auto item : *result.line)
    {
        printf("\t (line %d) %s\n", item, (*file_ptr)[item].c_str());
       // printf("\t (line %d) %s\n", item, (file_ptr->[item]).c_str());
    }
}
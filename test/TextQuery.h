#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class TextQueryResult;

class TextQuery
{
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<int>>> wm;
public:
    TextQuery(std::ifstream& ifs);
    TextQueryResult query(const std::string& obj_string) const;
};

class TextQueryResult
{
private:
    std::string obj_string;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<int>> line;
public:
    friend void Print_result(const TextQueryResult& result);
    TextQueryResult(std::string s, std::shared_ptr<std::vector<std::string>> f, std::shared_ptr<std::set<int>> l) : obj_string(s), file(f), line(l) {}
};

void Print_result(const TextQueryResult& result);

#endif
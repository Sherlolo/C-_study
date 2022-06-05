#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

class QueryResult;

class TextQuery
{
public:
    using line_type = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string& s) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_type>>> wm; //记录每个单词所在行
};


class QueryResult
{
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_type>> p, std::shared_ptr<std::vector<std::string>> f)
    : sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_type>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif

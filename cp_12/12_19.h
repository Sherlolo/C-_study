#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;

class StrBlobPtr;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob() : data(std::make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

    size_type size() const {return data->size();}

    void push_back(const string& s)
    {
        data->push_back(s);
    }

    void pop_back()
    {
        check(0, "pop_back on empty strblob");
        data->pop_back();
    }

    std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

    std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

    const std::string& front() const //right value?
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const std::string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg) const
	{
		if (i >= data->size())
			std::cout << msg << std::endl;
	}
};


class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p){return p.curr != curr;}
    string& deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr()
    {
        check(curr, "increment past end of strblobptr");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            std::cout << "unbound StrBlobPtr";
        if (i >= ret->size())
            std::cout << msg << std::endl;
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
} 
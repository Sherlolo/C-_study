#ifndef CP_13_34_H_
#define CP_13_34_H_

#include <string>
#include <set>

class Folder;

class Message
{
    friend void swap(Message &, Message &);
    friend class Folder;
public:
    explicit Message(const std::string& str = " ") : contents(std){}
    Message(const Message& );
    Message& operator=(const Message&)
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message& );   //将本message添加到指向参数的folder中
    void remove_from_Folders(); //从folder中的每个Folder中删除本message

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder
{
    friend void swap(Folder&, Folder&);
    friend class Message;
public:
    Folder() = default;
private:
    std::set<Message*> msgs;
    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder &, Folder &);

#endif
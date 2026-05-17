#ifndef POST_H
#define POST_H
#include <string>
#include <vector>
#include <cstdlib>
class post
{
private:
    std::string post_id;
    std::vector <std::string> topics;
    std::string post_content;
    std::string user_id;
public:
    post(std::string uid,std::string POST_content,std::string str = "NO_INPUT");
    void addTopic(std::string topic);
    void writePostContent(std::string post_c);
    std::string getID() const { return post_id; }
    std::string getUserID() const { return user_id; }
    std::string getContent() const { return post_content; }
    std::vector<std::string> getTopics() const { return topics; }
};

#endif // POST_H

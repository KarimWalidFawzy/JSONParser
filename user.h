#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
class User
{
    private:
    std::string name;
    std::string id;
    std::vector<std::string> posts_ids;
    std::vector <User*> followers;
public:
    User(std::string name, std::string id="NO_INPUT");
    std::string getName() const { return name; }
    std::string getID() const { return id; }
    std::vector<std::string> getPostIDs() const { return posts_ids; }
    std::vector<User*> getFollowers() const { return followers; }
};

#endif // USER_H

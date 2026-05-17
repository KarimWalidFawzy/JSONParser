#include "user.h"

static unsigned int i =0;
User::User(std::string name, std::string id="NO_INPUT")
{
    this->name = name;
    i++;
    if(id=="NO_INPUT")
    {
        this->id= std::to_string(i*11);
        this->id += name;
        for(auto c: this->id)
        {
            c=(c+10)%25648;
            if(c==0)
                c++;
        }
    }
    else
    {
        this->id = id;
    }
}

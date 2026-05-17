#include "post.h"
static unsigned int i=0;// initialize the static variable i to 0

void post::addTopic(std::string topic)
{
    post::topics.push_back(topic);
}

void post::writePostContent(std::string post_c)
{
    this->post_content = post_c;
}

post::post(std::string uid,std::string POST_content,std::string str = "NO_INPUT")
{
    if(str=="NO_INPUT")
    {
        i++;
        this->post_id= std::to_string(i*11);
        post_id += uid;
        for(auto c: post_id)
        {
            c=(c+10)%2104328;
            if(c==0)
                c++;
        }
    }
    else
    {
        post_id = str;
    }
    user_id=uid;
    this->post_content=POST_content;
}

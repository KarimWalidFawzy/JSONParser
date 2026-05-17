#include "parser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

Parser::Parser()
{
}

ParsedData Parser::parse(const std::string& json_string)
{
    ParsedData data;
    
    QJsonDocument doc = QJsonDocument::fromJson(QString::fromStdString(json_string).toUtf8());
    
    if (!doc.isObject()) {
        return data;
    }
    
    QJsonObject root = doc.object();
    
    // Parse users
    if (root.contains("users") && root["users"].isArray()) {
        QJsonArray usersArray = root["users"].toArray();
        for (const QJsonValue& userValue : usersArray) {
            if (userValue.isObject()) {
                QJsonObject userObj = userValue.toObject();
                std::string name = userObj["name"].toString().toStdString();
                std::string id = userObj["id"].toString().toStdString();
                
                auto user = std::make_shared<User>(name, id);
                data.users.push_back(user);
            }
        }
    }
    
    // Parse posts
    if (root.contains("posts") && root["posts"].isArray()) {
        QJsonArray postsArray = root["posts"].toArray();
        for (const QJsonValue& postValue : postsArray) {
            if (postValue.isObject()) {
                QJsonObject postObj = postValue.toObject();
                std::string uid = postObj["user_id"].toString().toStdString();
                std::string content = postObj["post_content"].toString().toStdString();
                std::string postId = postObj["post_id"].toString().toStdString();
                
                auto p = std::make_shared<post>(uid, content, postId);
                
                // Add topics if they exist
                if (postObj.contains("topics") && postObj["topics"].isArray()) {
                    QJsonArray topicsArray = postObj["topics"].toArray();
                    for (const QJsonValue& topicValue : topicsArray) {
                        p->addTopic(topicValue.toString().toStdString());
                    }
                }
                
                data.posts.push_back(p);
            }
        }
    }
    
    return data;
}

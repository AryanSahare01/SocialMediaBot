#include <iostream>
#include <string>
#include <memory>

class SocialMediaBot
{
public:
    std::string username;
    std::string platform;

    virtual void postUpdate(const std::string &message) = 0;
    virtual void respondToMessage(const std::string &message) = 0;
    virtual void analyzeTrend(const std::string &query) = 0;

    SocialMediaBot(const std::string &username,
                   const std::string &plaform) : username(username),
                                                 platform(platform){};
};

class InstagramBot : public SocialMediaBot
{
public:
    void postUpdate(const std::string &message) override
    {
        std::cout << username << " posted on Instagram: " << message << std::endl;
    }

    void respondToMessage(const std::string &message) override
    {
        std::cout << "Sending a direct message on Instagram..." << std::endl;
    }

    void analyzeTrend(const std::string &query) override
    {
        std::cout << "Analyzing Instagram trend for \"" << query << "\"" << std::endl;
    }

    InstagramBot(const std::string &username) : SocialMediaBot(username, "Instagram"){};
};

int main()
{

    std::unique_ptr<SocialMediaBot> bot = std::make_unique<InstagramBot>("InstaBot");

    bot->postUpdate("Test Message from InstaBot.");

    std::string message = "Hi there, How can I help you ?";
    bot->respondToMessage(message);

    bot->analyzeTrend("Photography");
}
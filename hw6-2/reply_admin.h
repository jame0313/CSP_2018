#define NUM_OF_CHAT 10
#include <string>
#include <iostream>
using namespace std;
class ReplyAdmin{
    private:
        string * chats;
    public:
        ReplyAdmin(){
            chats = new string[NUM_OF_CHAT];
        }
        ~ReplyAdmin(){
            delete[] chats;
        }
        int getChatCount();
        bool addChat(string _chat);
        bool removeChat(int _index);
        bool removeChat(int* _indices, int _count);
        bool removeChat(int _start, int _end);
        void show();
};

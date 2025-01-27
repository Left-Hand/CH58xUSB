#ifndef __NODE__HPP__

#include<vector>
#include<string.h>
#include<stdint.h>

using std::string;

namespace tinyGD{

class Node{
    private:
        vector<* Node> children;

    public:
        string name;
        Node * get_child(uint8_t index){return }
}

}
#endif // !__NODE__HPP__
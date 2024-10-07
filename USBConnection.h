#include <iostream>
#include <stack>
class USBConnection
{
private:
    int ID;
    USBConnection(int a) { ID = a; }
    static std::stack<int> ids;

public:
    static USBConnection *CreateUsbConnection()
    {
        if (ids.empty())
        {
            return nullptr;
        }
        else
        {
            int id = ids.top();
            USBConnection *a = new USBConnection(id);
            return a;
        }
    }
    ~USBConnection()
    {
        ids.push(ID);
    }
    int get_id() { return ID; }
};
std::stack<int> USBConnection::ids({3, 2, 1});

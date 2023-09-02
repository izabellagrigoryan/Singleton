// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Singleton
{
private:
    Singleton() { std::cout << "This is constructor" << std::endl; }
    ~Singleton(){ std::cout << "This is destructor" << std::endl; }
    static Singleton* ptr;
    int data;
 public:
    
    static Singleton* create_single()
    {
        if (ptr == nullptr)
        {
            ptr = new Singleton();
            return ptr;
        }
        else
        {
            std::cout << "You can't create more than one Object" << std::endl;
            return nullptr;
        }
    }

    static void destroy_single() 
    { 
        if (ptr != nullptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    int get_data() const
    {
        return data;
    }
    void set_data(int data)
    {
        this->data = data;
    }
};
Singleton* Singleton::ptr = nullptr;

int main()
{
    Singleton* single = Singleton::create_single();
    Singleton* single1 = Singleton::create_single();

    single->set_data(45);
    int d = single->get_data();
    Singleton::destroy_single();
    return 0;
}

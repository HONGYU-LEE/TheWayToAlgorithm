/*
    意义不明的题，最大的难度就是麻烦，浪费时间

    只需要分别维护一个猫狗队列以及一个计数器记录当前序号即可。
    我们在每个节点中标记当前的序号，然后按照序号出队即可
*/

#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Pet
{
public:
    Pet(const string& type)
        : _type(type)
    {}
    
    string _type;
};

class Dog : public Pet
{
public:
    Dog()
        : Pet("dog")
    {}
};

class Cat : public Pet
{
public:
    Cat()
        : Pet("cat")
    {}
};

class PetNode
{
public:
    PetNode(Pet pet, int id, int count)
        : _count(count)
        , _pet(pet)
        , _id(id)
    {}

    Pet _pet;
    int _id;
    int _count;
};

class CatDogQueue
{
public:
    void add(const string& type, int id)
    {
        if(type == "dog")
        {
            dog.push(PetNode(Dog(), id, _count++));
        }
        else
        {
            cat.push(PetNode(Cat(), id, _count++));
        }
    }
    
    void pollDog()
    {
        while(!dog.empty())
        {
            PetNode temp = dog.front();
            cout << temp._pet._type << " " << temp._id << endl;
            dog.pop();
        }
    }
    
    void pollCat()
    {
        while(!cat.empty())
        {
            PetNode temp = cat.front();
            cout << temp._pet._type << " " << temp._id << endl;
            cat.pop();
        }
    }
    
    void pollAll()
    {
        while(!dog.empty() && !cat.empty())
        {
            if(dog.front()._count > cat.front()._count)
            {
                cout << cat.front()._pet._type << " " << cat.front()._id << endl;
                cat.pop();
            }
            else 
            {
                cout << dog.front()._pet._type << " " << dog.front()._id << endl;
                dog.pop();
            }
        }
        if(!dog.empty())
        {
            pollDog();
        }
        if(!cat.empty())
        {
            pollCat();
        }
    }
    
    void isEmpty()
    {
        if(dog.empty() && cat.empty())
        {
            cout << "yes" << endl;
        }
        else 
        {
            cout << "no" << endl;
        }
    }
    
    void isDogEmpty()
    {
        if(dog.empty())
        {
            cout << "yes" << endl;
        }
        else 
        {
            cout << "no" << endl;
        }
    }
    
    void isCatEmpty()
    {
        if(cat.empty())
        {
            cout << "yes" << endl;
        }
        else 
        {
            cout << "no" << endl;
        }
    }
private:
    queue<PetNode> dog;    //保存最小值的栈
    queue<PetNode> cat;   //保存数据的栈
    int _count = 0;
};

int main()
{
    int count = 0, num;
    string str;
    CatDogQueue q;
    
    while(cin >> count)
    {
        for(int i = 0; i < count; i++)
        {
            if(cin >> str)
            {
                if(str == "pollAll")
                {
                    q.pollAll();
                }
                else if(str == "pollDog")
                {
                    q.pollDog();
                }
                else if(str == "pollCat")
                {
                    q.pollCat();
                }
                else if(str == "add")
                {
                    cin >> str >> num;
                    q.add(str, num);
                }
                else if(str == "isEmpty")
                {
                    q.isEmpty();
                }
                else if(str == "isCatEmpty")
                {
                    q.isCatEmpty();
                }
                else if(str == "isDogEmpty")
                {
                    q.isDogEmpty();
                }
            }
        }
    }
    return 0;
}

#include <iostream>
#include <list>
#include <unordered_map>


class LRUcache{
    
    private:
    
    int cap;
    std::list<int> cachelist;  // front: most recent, back: least recent
    
    //declares an unordered map named cacheMap. It stores key-value pairs where:
    //The key is an integer (int).
    //The value is an iterator pointing to an element within a list of integers (std::list<int>::iterator).
    std::unordered_map<int,std::list<int>::iterator> cacheMap;

    
    public:
    
    LRUcache(int capacity)
    {
        if(capacity == 0 )
        {
            throw std::invalid_argument("Capacity cannot be 0");
        }
        cap = capacity;
    }
    
    void access(int key)
    {
        if(cacheMap.find(key) != cacheMap.end())
        {
            //list.erase returns iterator
            cachelist.erase(cacheMap[key]); //remove it from current position
            cacheMap.erase(key); //erase from map also so no duplicates are allowed
        }
        else if(cachelist.size() >= cap)
        {
            int lru = cachelist.back();  //gets last element of list 
            cachelist.pop_back(); //removes LRC item
            cacheMap.erase(lru); //removes entry of lru item
        }
        cachelist.push_front(key); //insert at front
        cacheMap[key] = cachelist.begin(); 
    }
    
    void display()
    {
        for(int i : cachelist)
        {
            std::cout << i << " ";
        }
         std::cout << "\n";
    }
    
};

int main()
{
    LRUcache lru(4);
    lru.access(5);
    lru.access(4);
    lru.access(9);
    lru.access(10);
    lru.display();
    lru.access(10);
    lru.access(9);
    lru.access(9);
    lru.access(100);
    lru.display();

    return 0;
}

/*validation gaps in my code
1. Duplicate access of key already in cache
2. What when capacity =0
3.*/
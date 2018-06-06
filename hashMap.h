
#include "HashList.h"

template <typename K, typename V>
class HashMap
{
public:
    HashMap(int n) : length(n), rowsSize(0)
    {
        table = new HashList<K, V> [length];
    }
    HashMap() : length(10), rowsSize(0)
    {
        table = new HashList<K, V> [length];
    }
    ~HashMap()
    {
        delete []table;
        table = nullptr;
    }
   
    bool put(K key, V value)
    {
        if(get(key, value))
        {
            return false;
        }
            int index = hash(key);
            if(!table[index].size())
            {
                ++rowsSize;
            }
            if(index >= 0)
            {
                table[index].push_back(key, value);
            }
        return true;
    }
    bool remove(K key, V value)
    {
        if(get(key, value))
        {
            int i = hash(key);
            table[i].remove(key, value);
            return true;
        }
        return false;
    }
    void empty()
    {
        int i = 0;
        while(i < length)
        {
            if(table[i].size())
            {
                table[i].empty();
            }
            ++i;
        }
        rowsSize = 0;
    }
    HashNode<K, V>* get(K key)
    {
        int index = hash(key);
        if(index >= 0 && table[index].size())
        {
            return table[index].find(key);
        }
    }
    HashNode<K, V>* get(K key, V value)
    {
        HashNode<K, V>*tmp = new HashNode<K, V>;
        tmp = get(key);
        if(tmp && tmp->value_ == value)
        {
            return tmp;
        }   
        return nullptr;
    }
    int size()
    {
        int s = 0;
        for(int i = 0; i< length; ++i)
        {
            s += table[i].size();
        }
        return s;
    }
    void print()
    {
        int i = 0, j = 0;
        if(rowsSize)
        {
            while(i < length)
            {
                if(table[i].size())
                { 
                    cout << "index: " << i << "   ";
                    table[i].print();
                }
                ++i;
            }
        }
    }
private:
    int length;
    int rowsSize;
    HashList<K, V>* table;
     int hash(string s)
    {
        if(!s.length())
        {
            return -1;
        }
        int i=0;
        int sum = 0;
        while(i < s.length())
        {
            sum += int(s[i]);
            ++i;
        }
        sum %= length;
        return sum;
    }
    int hash(int elem)
    {
        int sum = 0;
        while(elem/10)
        {
            sum += elem%10;
            elem /= 10;
        }
        sum += elem;
        sum %= length;
        return sum;
    }
    int hash(char c)
    {
        int sum = int(c);
        sum %=length;
        return sum;
    }
};
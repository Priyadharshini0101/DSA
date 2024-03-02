#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename K, typename V>

class HashMap{
    public:
    int capacity = 10;
    double loadFactor = 0.75;
    std::vector<std::list<std::pair<K,V>>> table;

    std::size_t hashFunction(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }
    
    HashMap(){
        table.resize(capacity);
    }
    
    int hash(const K& key){
        return hashFunction(key);
    }
    
    void put(const K& key,const V& value){
        int index =hash(key);
        table[index].push_back({key,value});
        if((double)size()/capacity >= loadFactor){
            resize();
        }
    }
    
    int get(const K& key){
        int index = hash(key);
        for(const std::pair<K,V>& p:table[index]){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
    }
    
    bool contains(const K& key){
        return get(key) != -1;
    }
    
    void removeElement(const K& key){
        int index = hash(key);
        for(auto it = table[index].begin(); it != table[index].end(); ++it){
            if(it -> first == key){
                table[index].erase(it);
                return;
            }
        }
    }
    
    int size(){ 
        int count = 0;
        for(const std::list<std::pair<K,V>>& bucket:table){
            count += bucket.size();
        }
        return count;
    }
    
    private:
    void resize(){
        capacity *= 2;
        vector<std::list<std::pair<K,V>>> newTable(capacity);
        for(const std::list<std::pair<K,V>>& bucket: table){
            for(const std::pair<K,V>& p:bucket){
                int newIndex = hash(p.first);
                newTable[newIndex].push_back(p);
            }
        }
        table = newTable;
    }
};

int main(){
    HashMap<int,int> hashMap;

    hashMap.put(100,10);
    hashMap.put(200,20);
    hashMap.put(500,30);

    std::cout<<hashMap.get(500)<<"\n";

    hashMap.removeElement(100);

    std::cout<<"Contains : "<<hashMap.contains(100)<<"\n";

    std::cout<<hashMap.size()<<"\n";
    
    return 0;
}

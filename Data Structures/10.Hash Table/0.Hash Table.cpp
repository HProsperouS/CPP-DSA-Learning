#include <iostream>
using namespace std;

template <typename KeyType, typename ValueType>
class HashNode {
public:
    KeyType key;
    ValueType value;
    HashNode *next;
    HashNode(const KeyType &key, const ValueType &value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

template <typename KeyType, typename ValueType>
class HashTable{
private:
    HashNode<KeyType, ValueType> **table;
    int size;
    int hash(const KeyType &key) const{
        int hashKey = key % size;
        if(hashKey < 0){
            hashKey += size;
        }
        return hashKey;
    }
public:
    HashTable(int size=256);
    ~HashTable();
    void insert(const KeyType &key, const ValueType &value);
    void remove(const KeyType &key);
    bool find(const KeyType &key, ValueType &value) const;
};

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(int size){
    this->size = size;
    table = new HashNode<KeyType, ValueType>*[size];
    for(int i=0; i<size; i++){
        table[i] = NULL;
    }
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable(){
    for(int i=0; i<size; i++){
        HashNode<KeyType, ValueType> *entry = table[i];
        while(entry != NULL){
            HashNode<KeyType, ValueType> *prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value){
    int hashKey = hash(key);
    HashNode<KeyType, ValueType> *prev = NULL;
    HashNode<KeyType, ValueType> *entry = table[hashKey];
    while(entry != NULL){
        prev = entry;
        entry = entry->next;
    }
    if(entry == NULL){
        entry = new HashNode<KeyType, ValueType>(key, value);
        if(prev == NULL){
            table[hashKey] = entry;
        }else{
            prev->next = entry;
        }
    }else{
        entry->value = value;
    }
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType &key){
    int hashKey = hash(key);
    HashNode<KeyType, ValueType> *prev = NULL;
    HashNode<KeyType, ValueType> *entry = table[hashKey];
    while(entry != NULL && entry->key != key){
        prev = entry;
        entry = entry->next;
    }
    if(entry == NULL){
        return;
    }
    if(prev == NULL){
        table[hashKey] = entry->next;
    }else{
        prev->next = entry->next;
    }
    delete entry;
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::find(const KeyType &key, ValueType &value) const{
    int hashKey = hash(key);
    HashNode<KeyType, ValueType> *entry = table[hashKey];
    while(entry != NULL){
        if(entry->key == key){
            value = entry->value;
            return true;
        }
        entry = entry->next;
    }
    return false;
}

int main(){
    HashTable<int, int> hashTable;
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);
    hashTable.insert(4, 40);
    hashTable.insert(5, 50);
    hashTable.insert(6, 60);
    hashTable.insert(7, 70);
    hashTable.insert(8, 80);
    hashTable.insert(9, 90);
    hashTable.insert(10, 100);
    int value;
    if(hashTable.find(1, value)){
        cout << "Key 1 found with value " << value << endl;
    }else{
        cout << "Key 1 not found" << endl;
    }
    hashTable.remove(1);
    if(hashTable.find(1, value)){
        cout << "Key 1 found with value " << value << endl;
    }else{
        cout << "Key 1 not found" << endl;
    }
    return 0;
}

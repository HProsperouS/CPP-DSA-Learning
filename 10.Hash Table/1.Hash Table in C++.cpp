#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main () {
    unordered_map<string, int> umap;
    umap["Aaaa"] = 6;
    umap["Xxxx"] = 9;

    cout << umap["Aaaa"] << endl;
    umap["Aaaa"]++;
    cout << umap["Aaaa"] << endl;
    cout << umap["Xxxx"] << endl;

    umap.erase("Aaaa");
    if(umap.find("Aaaa") == umap.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    return 0;
    
}
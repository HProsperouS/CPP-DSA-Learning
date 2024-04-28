// Vector in C++
#include <iostream> 
#include <vector>   // Include the vector library
using namespace std; 

int main(){ // Main function
    vector<int> ret = {1,2,3,4,5}; // Define a vector ret containing integers 1 to 5
    for(int i=0; i < ret.size(); i++){ // Loop through the elements of ret
        cout << ret[i] << ' '; // Output each element followed by a space
    }
    cout<<endl; // Output a newline
    
    cout << ret.size() << endl; // Output the size of ret
    ret.push_back(1024); // Add the integer 1024 to the end of ret
    cout << ret.size() << endl; // Output the updated size of ret
    cout << ret[0] << endl; // Output the first element of ret
}

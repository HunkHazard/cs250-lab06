#include <iostream>
#include <vector>
using namespace std;


//a function to display an array/vector
void display(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


//a simple bubble sort
vector<int> moveMin(vector<int> v){
    int temp;
    for (int i = 0; i < v.size(); i++){
        for (int j = i; j < v.size(); j++){
            if(v[i]>v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    return v;
}


int main(){
    vector<int> arr{3, 5, 12, 24, 25, 27, 15 };
    display(arr);
    arr = moveMin(arr);
    display(arr);
    return 0;
}
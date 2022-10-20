#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;


vector<int> vectorGenerator(int size){
    vector<int> v;
    for (int i = 0; i < size; ++i)
    {
        v.push_back((rand()%100)+1); //generation of random numbers from 1-100
    }
    return v;
}


void display(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

//sorting an almost sorted vector using a single loop
vector<int> moveMin(vector<int> v){
    int temp;
    for (int i = 0; i < v.size(); i++){
        //the final element gets compared with the element of current index and gets interchanged if it is smaller
        if(v[(v.size())-1] < v[i]){
                temp = v[i];
                v[i] = v[(v.size())-1];
                v[(v.size())-1] = temp;
            }
        }
    return v;
}

//simple bubble sort algorithm implementation
// vector<int> moveMin(vector<int> v){
//     int temp;
//     for (int i = 0; i < v.size(); i++){
//         for (int j = i; j < v.size(); j++){
//             if(v[i]>v[j]){
//                 temp = v[i];
//                 v[i] = v[j];
//                 v[j] = temp;
//             }
//         }
//     }
//     return v;
// }


bool testMoveMin(){
    //the original test vector gets initialized with random generated values
    vector<int> v_in;
    v_in = vectorGenerator(10000);
    cout << "Generated Vector:\n";
    display(v_in);

    //the original vector is then sorted using the sort function(not minMove())
    sort(v_in.begin(),v_in.end());
    cout << "After Built-In Sort:\n";
    display(v_in);

    //a random number is appended at the end of sortd original vector creating an almost sorted vector
    v_in.push_back((rand()%100)+1);
    cout << "Afer Random Number Insertion at End:\n";
    display(v_in);

    //the almost sorted original vector is then copied to another vector
    vector<int> v_out = v_in;

    //the original vector is then sorted using built in sort function
    sort(v_in.begin(),v_in.end());
    cout << "In-Vector after Built-In sorting:\n";
    display(v_in);

    //the dummy vector is then sorted using our fucntion (moveMin())
    //the time taken by both algos will be measured here
    // N = 100    Bubble-Sort =  4.9e-05 sec   New Sort = 5e-06 sec
    // N = 1000   Bubble-Sort =  0.005651 sec  New Sort = 3.3e-05
    // N = 10000  Bubble-Sort =  0.432444 sec  New Sort = 0.000119
    clock_t start,stop;
    cout << "Out-Vector after Implemented Function Sorting:\n";

    start = clock();
    v_out = moveMin(v_out);
    stop = clock();

    double time_taken = double(stop - start)/double(CLOCKS_PER_SEC);
    cout << "Time Taken by Algorithm : " << time_taken << endl;
    display(v_out);

    //then we check whether the origial sorted vector is the same as the sorted dummy vector (using the implemented function)
    bool flag = true;
    for (int i = 0; i < v_in.size(); i++)
    {
        if(!(v_in[i]==v_out[i])){
            flag = false;
            break;
        }
    }

    //returns true if original and dummy vector are same after sorting else false
    return flag;
}

int main(){
    //seeding
    srand(time(0));
    bool flag = testMoveMin();
    if (flag==true)
        cout << "Test Passed\n";
    else
        cout << "Test Failed\n";

    return 0;
}
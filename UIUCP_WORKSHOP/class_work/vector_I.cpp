#include <bits/stdc++.h>
///#include <vector>

using namespace std;

int main(){

    /// Reading input from file
    freopen("vector_I_inputs.txt", "r", stdin);

    /// Vector initialization
    /// STL < data type > variable Name;
    vector <int> v;

    // Vector Input
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }

    /// Vector print way : 1 
    cout << "Given Vector : " <<endl;
    for (int i=0; i<v.size(); i++){
        cout<< v[i] << " ";
    }
    cout << endl;

    /// sort the elements of the vector in ascending order
    sort(v.begin(), v.end());

    /// Vector print way : 2
    cout << "Sorted (ascending) Vector print : " <<endl;
    for (auto x : v){
        cout << x << " ";
    }
    cout<<endl;

    /// sort the elements of the vector in descending order
    sort(v.begin(), v.end(), greater<int>());

    cout << "Sorted (descending) Vector print : " <<endl;
    for (auto x : v){
        cout << x << " ";
    }
    cout<<endl;

    /// Reverse the vector
    reverse(v.begin(), v.end());

    cout << "Reversed Vector print : " <<endl;
    for (auto x : v){
        cout << x << " ";
    }
    cout<<endl;

    // Remove element from the end of a vector.
    cout<<"Vector last element : "<< v[v.size()-1]<<" and vector size : "<< v.size()<<endl;
    
    v.pop_back();
    
    cout<<"After pop operation :"<<endl;
    cout<<"Vector last element : "<< v[v.size()-1]<<" and vector size : "<< v.size()<<endl;

    // erase function of vector
    cout << "Vector before eraseing elements with index 0, 1 : " <<endl;
    for (auto x : v){
        cout << x << " ";
    }
    cout<<endl;
    
    v.erase(v.begin(), v.begin()+2);
    
    cout << "Vector After eraseing elements with index 0, 1 : " <<endl;
    for (auto x : v){
        cout << x << " ";
    }
    cout<<endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T,N,x,peaks=0;
    cin>> T;
    vector<int> h;
    
    for(int i=0;i<T;i++){
        cin>> N;
        peaks=0;
        h.clear();
        for(int j=0;j<N;j++){
            cin>>x;  
            h.push_back(x);
        }
        int head = 1;
        while(head<h.size()-1){
            
            if( h[head] > h[head-1] && h[head] > h[head+1])
                peaks++;
            head++;  
            
                //cout<<"Case #"<<i<<": "<<0<<endl;
        }
        cout<<"Case #"<<i+1<<": "<<peaks<<endl;
    }
}

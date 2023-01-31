#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first < b.first);
}
bool areOverlapping(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second>=b.first);
}

pair<int ,int> mergeOverlapping(const pair<int,int> &a, const pair<int,int> &b){
    return {a.first,max(a.second,b.second)};
}


vector<pair<int,int>> merge(vector<pair<int,int> > &intervals){
    if(intervals.size()<=1){
        return intervals;
    }

    vector<pair<int,int> > result;
    sort(intervals.begin(), intervals.end(),comparator);
    result.push_back(intervals[0]);
    for(int i=1; i<=intervals.size();i++){
        if(areOverlapping(result.back(), intervals[i])){
            pair<int,int> overlapped = mergeOverlapping(result.back(), intervals[i]);
            result.pop_back();
            result.push_back(overlapped);
        }else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main(){
    vector<pair<int,int> > intervals = {{1,3},{2,4},{3,8}};
    vector<pair<int,int> > result ;
   result = merge(intervals);
    for(auto ele:result) {
       cout<<ele.first<<" "<<ele.second<<endl;
       
    }
    return 0;
}
// basically updating val in the whole give range {1,5} range add +5 to the whole range



#include <bits/stdc++.h>
using namespace std;


void BuildTree(vector<int> & Tree,vector<int> & arr,int i,int l,int r){
    if(l == r){
        Tree[i] = arr[r];
        return;
    }
    int mid = (l + r)/2;
    BuildTree(Tree,arr,2*i + 1,l,mid);
    BuildTree(Tree,arr,2*i + 2,mid + 1,r);
    
    Tree[i] = Tree[2*i + 1] + Tree[2*i + 2];
}


void UpdateQuery(vector<int> &Tree,vector<int> &Lazy,int start,int end,int i,int l,int r,int val){
    if(Lazy[i] != 0){
        Tree[i] += (r-l+1) * Lazy[i];
        if(l != r){
            Lazy[2*i + 1] += Lazy[i];
            Lazy[2*i + 2] += Lazy[i];
        }
        Lazy[i] = 0;
    }
    
    if(r < start || l > end) return;
    
    if(l >= start && r <= end){
        Tree[i] += (r-l+1) * val;
        
        if(l != r){
            Lazy[2*i + 1] += val;
            Lazy[2*i + 2] += val;
        }
        return;
    }
    int mid = (l+r)/2;
    UpdateQuery(Tree,Lazy,start,end,2*i + 1,l,mid,val);
    UpdateQuery(Tree,Lazy,start,end,2*i + 2,mid + 1,r,val);
    
    Tree[i] = Tree[2*i + 1] + Tree[2*i + 2];
}

int Query(vector<int> &Tree,int start,int end,int i,int l,int r){
    if(r < start || l > end) return 0;
    
    if(l >= start && r <= end){
        return Tree[i];
    }
    int mid = (l + r)/2;
    return Query(Tree,start,end,2*i + 1,l,mid) + Query(Tree,start,end,2*i + 2,mid + 1,r);
}




int main()
{
    vector<int> arr = {4,6,3,1,5,7};
    vector<vector<int>> query = {{1,3,3},{2,5,4}};
    int n = arr.size();
    vector<int> Tree(4*n,0);
    vector<int> Lazy(4*n,0);
    vector<int> res;
    BuildTree(Tree,arr,0,0,n-1);
    
    for(int i = 0;i < query.size();i++){
        int start = query[i][0];
        int end = query[i][1];
        int val = query[i][2];
        UpdateQuery(Tree,Lazy,start,end,0,0,n-1,val);
        int ans = Query(Tree,start,end,0,0,n-1);
        res.push_back(ans);
        
    }
    
    
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}
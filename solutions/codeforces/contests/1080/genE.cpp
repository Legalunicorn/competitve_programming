#include <algorithm>
#include <bits/stdc++.h>
#include <random>
using namespace std;

int RND(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1])); // seed from command line

    cout << 1 << endl; // 1 test case

    int n = RND(1, 50); // small n for demo; use up to 300001 for real stress
    if (n % 2 == 0) n++; // ensure n is odd
    cout << n << endl;

    vector<int> nodes;
    for(int i=2;i<=n;i++) nodes.push_back(i); // nodes remaining to assign

    vector<pair<int,int>> tree(n+1, {0,0});
    tree[0] = {1,0}; // root always has child 1

    queue<int> internal; 
    internal.push(1); // node 1 can still get children

    // shuffle remaining nodes for randomness
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(nodes.begin(), nodes.end(), g);

    

    while(!nodes.empty()){
        int parent = internal.front(); internal.pop();

        if (nodes.size() >= 2){
            int l = nodes.back(); nodes.pop_back();
            int r = nodes.back(); nodes.pop_back();
            tree[parent] = {l, r};
            internal.push(l);
            internal.push(r);
        } else {
            // leaf node
            tree[parent] = {0,0};
        }
    }

    // any remaining internal nodes become leaves
    while(!internal.empty()){
        tree[internal.front()] = {0,0};
        internal.pop();
    }

    // output the tree in required format
    for(int i=1;i<=n;i++){
        cout << tree[i].first << " " << tree[i].second << endl;
    }

    return 0;
}

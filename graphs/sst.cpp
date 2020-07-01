#include <fstream>
#include <vector>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
struct graph {
    int a, b, weigth;
};

struct DSU {
    int root;
};

std::vector<graph> g, ans;
bool used[100000];
std::vector<int> vertices;
std::vector<DSU> trees;

void sort(int l, int r) {
    int x = g[l + (r - l) / 2].weigth;
    int i = l;
    int j = r;
    while(i <= j) {
        while(g[i].weigth < x) i++;
        while(g[j].weigth > x) j--;
        if(i <= j) {
            std::swap(g[i], g[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        sort(i, r);
    if (l<j)
        sort(l, j);
}

int find(int a) {
    int temp = trees[a - 1].root;
    if (temp == a) {
        return a;
    }
    return trees[a - 1].root = find(trees[a - 1].root);
    return a;
}

void makeSet(int a) {
    DSU temp;
    temp.root = a;
    trees.push_back(temp);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    trees[a - 1].root = b;
}

int main() {
    int n, m, cost = 0;
    graph t1;
    fin >> n >> m;
    for (int i = 1; i <= n; i++){
        vertices.push_back(i);
        makeSet(i);
    }

    for (int i = 0; i < m; i++) {
        fin >> t1.a >> t1.b >> t1.weigth;
        g.push_back(t1);
    }

    sort(0, g.size() - 1);

    for (int i = 0; i < m; i++){
        if (find(g[i].a) != find(g[i].b)) {
            ans.push_back(g[i]);
            unite(g[i].a, g[i].b);
        }
    }
    int sst = 0;
    if ((ans.size() + 1) < n)
        fout << -1;
    else{
        for (int i = 0; i < ans.size(); i++){
            sst+=ans[i].weigth;
        }
        fout << sst;
    }

}

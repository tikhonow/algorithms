#include <fstream>
#include <set>
#include <vector>
#include <iterator>



int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int N, K,counter = 0;
    fin >> N >> K;

    std::set<std::pair<int, int>>::iterator back, now;
    std::set<std::pair<int, int>> order;
    std::set<std::pair<int, int>> cart;
    std::vector<int> rack(N);
    std::vector<int> dist(N);

    for (int i = 0; i < N; ++i)
    {
        fin >> rack[i];
        dist[i] = INT_MAX;
        order.insert({rack[i], i});
    }

    back = order.begin();
    
    for (now = order.begin(); now != order.end(); now++)
    {
        if (now->first == back->first)
            dist[back->second] = now->second;
        else
            dist[back->second] = INT_MAX;
        back = now;
    }

    dist[back->second] = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        now = cart.lower_bound({i, -1});

        if (now == cart.end() || now->first != i)
        {
            if (cart.size() == K)
                cart.erase(--cart.end());
            counter++;
        }
        else
            cart.erase(now);

        cart.insert({dist[i], i});
    }

    fout << counter;
}
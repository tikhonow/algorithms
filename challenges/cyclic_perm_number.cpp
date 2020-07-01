#include <fstream>
#include <map>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::map<std::string, int> mymap;
    int cont = 0;
    std::string A, aux = "";
    fin >> A;
    mymap[A]++;
    cont++;
    for (int iA = 1; iA < A.length(); iA++) {
        for (int iB = 0, iC = iA; iB < A.length(); iB++, iC++) {
            if (iC == A.length()) {
                iC = 0;
            }
            aux += A[iC];
        }
        if (mymap[aux] == 0) {
            cont++;
            mymap[aux]++;
        }
        aux = "";
    }
    int i = 0;
    for (auto& item : mymap)
    {
        if (item.first == A)
        {
            fout << i;
            return 0;
        }
        item.second = item.second + i;
        i++;
    }
    return 0;
}
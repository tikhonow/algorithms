#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> bucket_sort(std::vector<std::string> mass_words)
{

    for (int i = 2; i > -1; i--)
    {
        std::vector<std::vector<std::string>> support_mass;
        support_mass.resize(256);

        for (int j = 0; j < mass_words.size(); j++)
        {
            std::string letter = mass_words[j];
            support_mass[(unsigned char)letter[i]].push_back(letter);
        }

        mass_words.clear();

        for (int j = 0; j < support_mass.size(); j++)
        {
            if (support_mass[j].size() > 0)
            {
                for (int l = 0; l < support_mass[j].size(); l++)
                {
                    mass_words.push_back(support_mass[j][l]);
                }
            }
        }
    }
    return mass_words;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    std::vector<std::string> mass_of_words;
    std::string word;

    for (int i = 0; i < n; i++)
    {
        fin >> word;
        mass_of_words.push_back(word);
    }

    std::vector<std::string> sorted_mass;

    sorted_mass = bucket_sort(mass_of_words);

    for (int i = 0; i < n; i++)
    {
        fout << sorted_mass[i] << std::endl;
    }
}
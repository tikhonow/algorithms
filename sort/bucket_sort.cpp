#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> bucket_sort(std::vector<std::string> array_words)
{

    for (int i = 2; i > -1; i--)
    {
        std::vector<std::vector<std::string>> support_array;
        support_array.resize(123);

        for (int j = 0; j < array_words.size(); j++)
        {
            std::string letter = array_words[j];
            support_array[(int)letter[i]].push_back(letter);
        }

        array_words.clear();

        for (int j = 0; j < support_array.size(); j++)
        {
            if (support_array[j].size() > 0)
            {
                for (int l = 0; l < support_array[j].size(); l++)
                {
                    array_words.push_back(support_array[j][l]);
                }
            }
        }
    }
    return array_words;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    std::vector<std::string> array_of_words;
    std::string word;

    for (int i = 0; i < n; i++)
    {
        fin >> word;
        array_of_words.push_back(word);
    }

    std::vector<std::string> sorted_array;

    sorted_array = bucket_sort(array_of_words);
    for (int i = 0; i < n; i++)
    {
        fout << sorted_array[i] << std::endl;
    }
}
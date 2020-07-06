#include <stdio.h>
#include <stdlib.h>
#include <vector>


void f()
{
    FILE *gp = _popen("gnuplot -persist", "w");;
    FILE *fout1 = fopen("data1.dat", "w");
    std::vector<float> a = {1,2,2,2,2,2,2,2,2,22};
    for (size_t i = 0; i < 40;i ++)
    {
        fprintf(fout1, "%lf\n", a[i]);
    }
    fprintf(gp, "plot  'data1.dat' with lines \n");
    fprintf(gp, "%s\n", "e");
    fflush(gp);
}
int main()
{
    f();
}


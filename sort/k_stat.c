#include <stdio.h>
#include <stdlib.h>

int qs(int *array, int first, int last,int k)
{
    if (first < last)
    {
        int left = first, right = last, supporting_element = array[(left + right) / 2];
        if (supporting_element == k) return array[k - 1];
        do
        {
            while (array[left] < supporting_element) left++;
            while (array[right] > supporting_element) right--;
            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(array, first, right,k);
        qs(array, left, last,k);
    }
}
int main(){
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
int n;
int k;
    fscanf(fin,"%d%d", &n, &k);
int a[n];
for (int i = 0; i < n; i++){
    fscanf (fin,"%d", &a[i]);
}
qs(a,0,n-1,k);
}

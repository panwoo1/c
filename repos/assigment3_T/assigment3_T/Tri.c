#include <stdio.h>

void sort(int arr[], int size);

int main()
{
    int num, min;
    int is_Tri = 0;
    int Tri[45] = { 0, };
    int result_2[45][3] = { 0, };

    for (int i = 1; i < 46; i++)
    {
        Tri[i-1] = i * (i + 1) / 2;
    }
    
    scanf("%d", &num);

    for (int i = 0; i < 45; i++)
    {
        if (Tri[i] > num) break;
        for (int j = 0; j < 45; j++) 
        {
            if (Tri[j] > num) break;
            for (int r = 0; r < 45;r++) 
            {
                if (Tri[r] > num) break;
                if (Tri[i] + Tri[j] + Tri[r] == num)
                {
                    result_2[i][0] = Tri[i];
                    result_2[i][1] = Tri[j];
                    result_2[i][2] = Tri[r];
                    sort(result_2[i], 3);

                    is_Tri = 1;
                    break;
                }
            }
        }
    }
    if (is_Tri == 1)
    {
        for (int i = 0; i < 45; i++)
        {
            if (result_2[i][0] != 0)
            {
                min = result_2[i][0];
                if (result_2[i][0] < min)
                {
                    min = result_2[i][0];
                    printf("%d %d %d", min, result_2[i][1], result_2[i][2]);
                }
                else
                    printf("%d %d %d", min, result_2[i][1], result_2[i][2]);
                break;
            }
        }
    }
    else
        printf("%d", -1);

    return 0;
}
void sort(int arr[], int size)
{
    int i, j, temp, least;

    for (i = 0; i < size - 1; i++)
    {
        least = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[least])
                least = j;
        }
        temp = arr[i];
        arr[i] = arr[least];
        arr[least] = temp;
    }
}
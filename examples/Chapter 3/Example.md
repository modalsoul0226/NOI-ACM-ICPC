**Ex. 3-2** 开灯问题。有n盏灯， 编号为1～n。第1个人把所有灯打开， 第2个人按下所有编号为2的倍数的开关（这些灯将被关掉）， 第3个人按下所有编号为3的倍数的开关（其中关掉的灯将被打开， 打开的灯将被关闭）， 以此类推。 一共有k个人， 问最后有哪些灯开着？ 输入n和k， 输出开着灯的编号。 `k<=n<=1000`。
```C
#include <stdio.h>
#include <string.h>

int main()
{
    int k = 0, n = 0;
    scanf("%d %d", &k, &n);
    if (k > n) 
    {
        fprintf(stderr, "Invalid input.\n");
    }

    int lights[n + 1];
    memset(lights, 0, sizeof(int) * (n + 1));

    for (int i = 1; i <= k; i++) 
    {
        for (int j = 1; j <= n / i; j++)
        {
            lights[j * i] = 1 - lights[j * i];
        }
    }

    int kase = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (lights[i])
        {
            if (kase++) printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");
}

```

<p align="center"><em>程序3-2 开灯问题</em></p>

</br></br>
**Ex. 3-3** 蛇型填数。 在`n×n`方阵中填入1,2，...，n×n， 要求填成蛇型。
```C
#include <stdio.h>
#include <string.h>
#define maxn 20
int a[maxn][maxn];
int main()
{
    int n, x, y, tot = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    tot = a[x = 0][y = n - 1] = 1;
    while (tot < n * n)
    {
        while (x + 1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while (y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
        while (x - 1 < n && !a[x-1][y]) a[--x][y] = ++tot;
        while (y + 1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++) printf("%3d", matrix[x][y])
        printf("\n");
    }

    return 0;
}
```

<p align="center"><em>程序3-3 蛇型填空</em></p></br></br>
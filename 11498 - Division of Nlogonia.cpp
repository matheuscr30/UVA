#include <stdio.h>
#include <string.h>

int main()
{
    int K, N, M, X, Y, i;
    scanf("%d", &K);

    while (K > 0)
    {
        scanf("%d %d", &N, &M);

        for (i = 0; i < K ; i++)
        {
            scanf("%d %d", &X, &Y);

            if (X == N || Y == M || X == M || Y == N)
                printf("divisa\n");
            else if (X > N && Y > M)
                printf("NE\n");
            else if (X > N && Y < M)
                printf("SE\n");
            else if (X < N && Y > M)
                printf("NO\n");
            else
                printf("SO\n");
        }

        scanf("%d", &K);
    }
    return 0;
}

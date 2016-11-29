#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int>escadas;
    map<int, int>jogador;
    int t, a, dado, b, c, in, fin;
    cin >> t;

    while(t--)
    {
        escadas.clear();
        jogador.clear();
        cin >> a >> b >> c;

        while(b--)
        {
            cin >> in >> fin;
            escadas[in] = fin;
        }

        for (int i = 1; i <= a; i++)
            jogador[i] = 1;

        int vez = 1;
        bool parou = false;
        for (int i = 1; i <= c; i++)
        {
            cin >> dado;

            if (!parou)
            {
                jogador[vez] += dado;
                if (escadas.count(jogador[vez]))
                    jogador[vez] = escadas[jogador[vez]];

                if (jogador[vez] >= 100)
                {
                    jogador[vez] = 100;
                    parou = true;
                }

                vez++;
                if (vez > a)
                    vez = 1;
            }

        }

        for (int i = 1; i <= a; i++)
            cout << "Position of player " << i << " is " << jogador[i] << "." << endl;
    }
    return 0;
}

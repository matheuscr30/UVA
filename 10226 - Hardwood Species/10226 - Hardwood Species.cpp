#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int N, cont=0;
    double total;
    char nome[32];
    map<string, int>arvores;
    map<string, int>::iterator it;

    cin >> N;
    cin.ignore();

    while (N--)
    {
        arvores.clear();
        total = 0;

        if (cont != 0)
        {
            cout << endl;
        }
        else
        {
             gets(nome);
        }

        while (gets(nome) && nome[0] != '\0')
        {
            arvores[nome]++;
            total++;
        }

        for (it = arvores.begin(); it != arvores.end(); it++)
        {
            cout << it->first << " " << fixed << setprecision(4) << (it->second * 100 * 1.0)/total << endl;
        }

        cont++;
    }
    return 0;
}

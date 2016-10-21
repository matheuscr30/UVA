#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool eh_pilha, eh_fila, eh_fila_prior;
    stack<int> pilha;
    queue<int> fila;
    priority_queue<int> fila_prior;

    int n, comando, x;

    while (cin >> n)
    {
        eh_fila = true;
        eh_pilha = true;
        eh_fila_prior = true;

        while (!pilha.empty())
                pilha.pop();

            while (!fila.empty())
                fila.pop();

            while (!fila_prior.empty())
                fila_prior.pop();

        while (n--)
        {
            cin >> comando >> x;



            if (comando == 1)
            {
                pilha.push(x);
                fila.push(x);
                fila_prior.push(x);
            }
            else
            {
                if (x == pilha.top())
                    pilha.pop();
                else
                    eh_pilha = false;

                if (x == fila.front())
                    fila.pop();
                else
                    eh_fila = false;

                if (x == fila_prior.top())
                    fila_prior.pop();
                else
                    eh_fila_prior = false;
            }
        }

        if (eh_pilha && !eh_fila && !eh_fila_prior)
            cout << "stack" << endl;
        else if (!eh_pilha && eh_fila && !eh_fila_prior)
            cout << "queue" << endl;
        else if (!eh_pilha && !eh_fila && eh_fila_prior)
            cout << "priority queue" << endl;
        else if (!eh_pilha && !eh_fila && !eh_fila_prior)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }
    return 0;
}

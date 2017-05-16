#include <bits/stdc++.h>

using namespace std;

int main()
{
    string entrada;
    list<char> lista;
    list<char>::iterator it;

    while(cin >> entrada)
    {
        lista.clear();
        it  = lista.end();

        for (int i = 0; i < entrada.size(); i++)
        {
            if (entrada[i] == '[')
                it = lista.begin();
            else if (entrada[i] == ']')
                it = lista.end();
            else
                lista.insert(it, entrada[i]);
        }

        for (it = lista.begin(); it != lista.end(); it++)
            cout << (*it);
        cout << endl;
    }
    return 0;
}

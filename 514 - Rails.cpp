#include <bits/stdc++.h>

using namespace std;

int main() {
    int tam, aux;
    int num;

    while (1) {

        cin >> tam;
        if (tam == 0) break;

        while (1) {
            cin >> num;

            if (num == 0) break;

            stack <int> estacao;
            aux = 1;

            for(int i = 1 ; i <= tam ; i++) {
                estacao.push(i);
                while (!estacao.empty() && estacao.top() == num) {
                    estacao.pop();
                    if (aux < tam) {
                        cin >> num;
                        aux++;
                    }
                }
            }

            if (estacao.empty() && aux == tam)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

            while (aux < tam) {
                cin >> num;
                aux++;
            }
        }

        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

main()
{
  bool visitados[100][100][100];
  set<int>nums;

  for(int i = 0; i <= 20; i++)
  {
    nums.insert(i);
    nums.insert(i*2);
    nums.insert(i*3);
  }
  nums.insert(50);
  vector<int>numeros(nums.begin(), nums.end());

  int score, perm = 0, cont = 0;

  while(cin >> score && score > 0)
  {
    perm = cont = 0;
    memset(visitados, false, sizeof visitados);
    for (int i = 0; i < numeros.size(); i++)
      for (int j = 0; j < numeros.size(); j++)
        for (int k = 0; k < numeros.size(); k++)
        {
          if (numeros[i] + numeros[j] + numeros[k] == score)
          {
            if (!visitados[numeros[i]][numeros[j]][numeros[k]])
            {
              cont++;
              visitados[numeros[i]][numeros[j]][numeros[k]] = true;
              visitados[numeros[i]][numeros[k]][numeros[j]] = true;
              visitados[numeros[j]][numeros[i]][numeros[k]] = true;
              visitados[numeros[j]][numeros[k]][numeros[i]] = true;
              visitados[numeros[k]][numeros[i]][numeros[j]] = true;
              visitados[numeros[k]][numeros[j]][numeros[i]] = true;
            }

            perm++;
          }
        }

    if (perm != 0)
    {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << cont << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perm << "." << endl;
    }
    else
      cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;

    cout << "**********************************************************************" << endl;
  }

  cout << "END OF OUTPUT" << endl;
}

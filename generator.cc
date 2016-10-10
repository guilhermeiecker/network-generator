#include <iostream>
#include <fstream>
#include <iomanip>                      // std::setprecision

#include "Network.h"

#define TPOWER 300      // Transmission Power (Default: 300mW)
#define INCRMT 0.05     // Area side increment
#define NODES 4         // Max different number of node values
#define LINKS 61        // Number of links (from 4 to LINKS + 4)
#define RUNS 100        // Number of networks for every combination of n and m
#define AREA 30000      // Initial area side value

using namespace std;

int main()
{
  Network* network;
  ofstream f;

  double networks[NODES][LINKS][RUNS];
  int count[NODES][LINKS];
  int flag[NODES];

  int n, m, seed;
  double area;

  for(int i = 0; i < NODES; i++)
  {
    area = AREA;
    n = int(pow(2, i + NODES));
    cout << "Finding networks for n=" << n << endl;
    srand(n);

    do {
      //seed = (int)(100*area);
      //srand(seed);
      network = new Network(n, area, TPOWER);
      m = network->get_links().size();

      if((m > 3) && (m < 65))
      {
        if(count[i][m - 4] < RUNS)
        {
          cout << "n=" << n << " m=" << m << " seed=" << seed << " area=" << area << endl;
          networks[i][m - 4][count[i][m - 4]] = area;
          count[i][m - 4]++;
        }

        if(count[i][m - 4] == RUNS)
        {
          flag[i]++;
          cout << "All 100 networks with n=" << n << " and m=" << m << " are already found." << endl;
        }
      }
      area = area - INCRMT;
    } while((area>0.0)&&(flag[i]<LINKS));
  }

  f.open("network.txt");
  for(int i = 0; i < NODES; i++)
  {
    f << (int)pow(2, i + NODES) << endl;
    for(int j = 0; j < LINKS; j++)
    {
      for(int k = 0; k < RUNS; k++)
      {
        f << fixed << setprecision(6) << networks[i][j][k] << "\t";
      }
      f << endl;
    }
    f << endl;
  }

  f.close();

  return 0;
}

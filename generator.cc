#include <iostream>
#include <iomanip>                      // std::setprecision

#include "Network.h"

#define TPOWER 300

using namespace std;

int main(int argc, char** argv)
{
  int m;
  int n = atoi(argv[1]);
  double a = (double)atof(argv[2]);

  srand((int)(a*100));

  Network* network;
  network = new Network(n, a, TPOWER);

  m = network->get_links().size();

  if((m > 3) && (m < 65))
    cout << fixed << setprecision(2) << n << "\t" << m << "\t" << a << endl;

  delete network;

  return 0;
}

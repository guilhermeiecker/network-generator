#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "Network.h"

#define NETWORK_PATH "./data/"

using namespace std;

void print_network_json(Network*);

int main(int argc, char** argv)
{
	if(argc != 4)
	{
		cout << "Missing arguments!" << endl;
		cout << "USAGE: ./main <number of nodes> <area side> <round>" << endl;
	
		return 0;
	}

	uint64_t n = atoi(argv[1]);
        double area = (double)atof(argv[2]);
        uint64_t run = atoi(argv[3]);
        double tpower = 300.0;
	
	srand(run);
	
	Network* network;
        network = new Network(n, area, tpower);
	
	string name;
        name = NETWORKS_PATH + to_string(n) + "-" + to_string((int)area) + "-" + to_string(run) + ".dat";

	print_network_json(network, name);

	return 0;
}

void print_network_json(Network* r, string name)
{
	ofstream o;
	o.open(name);

	o << "{\n";
	o << "\t\"nodes\": [\n";
	
	for (vector<Node>::iterator i = r->get_nodes().begin(); i != r->get_nodes().end(); ++i)
	{
		o << "\t{\n";
		o << "\t\t\"id\":\"" << i->get_id() << "\",\n";
		o << "\t\t\"x\" :\"" << i->get_x()  << "\",\n";
		o << "\t\t\"y\" :\"" << i->get_y()  << "\"\n";
		o << "\t},\n";
	}
}

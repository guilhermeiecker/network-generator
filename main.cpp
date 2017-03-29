#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "Network.h"

#define NETWORK_PATH "./data/"

using namespace std;

void print_network_json(Network*, string);

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
        name = NETWORK_PATH + to_string(n) + "-" + to_string((int)area) + "-" + to_string(run) + ".json";

	print_network_json(network, name);

	return 0;
}

void print_network_json(Network* r, string name)
{
	vector<Node> nodes = r->get_nodes();
	vector<Link> links = r->get_links();

	ofstream o;
	o.open(name);

	o << "{\n";
	o << "\t\"nodes\": [\n";
	
	for (vector<Node>::iterator i = nodes.begin(); i != nodes.end(); ++i)
	{
		o << "\t\t{\n";
		o << "\t\t\t\"id\": \"" << i->get_id() << "\",\n";
                o << "\t\t\t\"label\": \"" << i->get_id() << "\",\n";
		o << "\t\t\t\"x\" : \"" << i->get_x()  << "\",\n";
		o << "\t\t\t\"y\" : \"" << i->get_y()  << "\",\n";
                o << "\t\t\t\"size\": \"1\"\n";
			

                if((i != nodes.end()) && (next(i) == nodes.end()))	
			o << "\t\t}\n";
		else
			o << "\t\t},\n";
	}
	
	o << "\t],\n\t\"edges\": [\n";

	for (vector<Link>::iterator i = links.begin(); i != links.end(); ++i)
	{
		o << "\t\t{\n";
		o << "\t\t\t\"id\": \"" << i->get_id() << "\",\n";
                o << "\t\t\t\"source\" : \"" << i->get_sender()->get_id()  << "\",\n";
                o << "\t\t\t\"target\" : \"" << i->get_recver()->get_id()  << "\"\n";

		if((i != links.end()) && (next(i) == links.end()))
			o << "\t\t}\n";
		else
			o << "\t\t},\n";
	}

	o << "\t]\n}" << flush;

	o.close();
}

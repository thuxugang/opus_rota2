#include <iostream> 
#include <string> 
#include <vector> 
#include <map>
#include <time.h>
#include "atom.h"
#include "residue.h"
#include "pdb.h"
#include "angle.h"
#include "peptideBuilder.h"
#include "redis.h"
#include "geometry.h"
#include "potential.h"
#include "config.h"
#include "MonteCarlo.h"
#include "file.h"

using namespace std;

int main(){

	cout << "Start..." << endl;

	//read config
	readConfigFile("./rota2.ini");

	cout << "Input dir: " << CONFIG["inputlist"] << endl;
	cout << "Output dir: " << CONFIG["outputdir"] << endl;
	if(stoi(CONFIG["optimized"])){
		cout << "Optimized: true" << endl;
		cout << "Optimization times: " << CONFIG["optimization_times"] << endl;
	}else{
		cout << "Optimized: false" << endl;
	}
	
	cout << "Connect database..." << endl;
	//connect redis
	Redis r = Redis();
	cout << "Successed!" << endl;

	time_t star_time = time(NULL);

	vector<string> files = getFiles(CONFIG["inputlist"]);
	int length = files.size();
	for(int i=0; i< length; i++){
		cout << files[i] << endl;
		string input_file = files[i];
		vector<string> names = split(files[i], "/");
		string output_file = CONFIG["outputdir"]+"/rota2_"+names[names.size()-1];

		//get main chain atom from pdb
		vector<Atom> ad = readPDB(input_file);
		vector<Residue> rd = atomToResidue(ad);
		//init geo
		vector<Geo*> gd = initGeoChain(rd);

		//add phipsi information to residuedata
		addPhiPsi(rd);

		//add rotamer information to residuedata
		addRotamersInfo(rd, r);

		//add dasf information to residuedata
		addDASFInfo(rd, gd, r);
		//get contact list
		vector<Contact> contact_list = getContactList(gd, rd);
		//add all rotamer potentials to residuedata.RotamerLib
		initAllPotentials(gd, rd);
		//sampling
		getBestStructure(rd);

		//rebuild from m_rl_id
		vector<Atom> ad_rebulid = rebuildSideChain(gd, rd);
		//output
		outputPDB(output_file, ad_rebulid);
		//free Geo*
		int gd_length = gd.size();
		for(int j=0; j<gd_length; j++){
			delete(gd[j]);
		}
		
	}

	time_t end_time = time(NULL);
	cout << "Total time: " << (end_time - star_time) << "s" << endl;

	r.destroy();

	cout << "Done!" << endl;

	return 0;
}
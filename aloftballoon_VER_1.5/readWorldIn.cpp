#include <iostream>
#include <fstream>
#include <sstream>

#include "World.h"
using namespace std;

int main(int argc, char* argv[])
{
    cout << "extracting file" << endl;
    if(argc == 1){cout << "incorrect usage" << endl; return 1;}
    string filename = argv[1];
    ifstream a;
    a.open(filename);
    if(!a.is_open()){cout << "file not opened" << endl; return 1;}

    World final;
    a >> final.PlayerName;
    a >> final.CapitalCity;
    cout << "Player: " << final.PlayerName << " town: " << final.CapitalCity << endl;
    //use getline from here
    string townline = "";
    a.ignore();//NOTE: IGNORE THE NEXT ENDLINE
    getline(a, townline);
    stringstream townString(townline);
    
    int ID = 0;
    string TOWNNAME;
    while(townString >> ID)
    {
        townString >> TOWNNAME;
        final.town.push_back(TOWNNAME);
    }
    cout << endl;
    final.printListOfTowns();

    string npcline = "";
    getline(a, npcline);
    stringstream npcstream(npcline);

    string NPCNAME;
    string NPCDIALOUGE;
    int NPCTOWNID;
    while(npcstream >> ID)
    {
        npcstream >> NPCNAME >> NPCDIALOUGE >> NPCTOWNID;
        Dude temp;
        temp.name = NPCNAME;
        temp.dialogue = NPCDIALOUGE;
        temp.town_id_for_npc = NPCTOWNID;
        final.npc.push_back(temp);
    }
    cout << endl << "NPCS" << endl;
    final.printNPCs();

    string routeline = "";
    getline(a, routeline);
    stringstream routestream(routeline);

    while(routestream >> ID)
    {
        int start;
        int end;
        char garbage;
        routestream >> garbage;//(
        routestream >> start;
        routestream >> garbage;//,
        routestream >> end;
        routestream >> garbage;//)

        IDpair temp;
        temp.start = start;
        temp.end = end;
        final.routes.push_back(temp);
    }

    cout << endl << "routes" << endl;
    final.printRoutes();

    //IMPLEMENTED UP TO ROUTES, NEED TO ADD MONSTERS AND ITEMS
}
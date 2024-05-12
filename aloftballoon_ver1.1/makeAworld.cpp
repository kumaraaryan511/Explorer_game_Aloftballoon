#include <iostream>
#include <fstream>
#include "World.h"

using namespace std;

//NOTE: to compile, run g++ makeAworld.cpp World.cpp -o worldCreator

int main(int argc, char* argv[])
{
    //
    for(int i = 0; i < 5; i++)
    {
        cout << "..." << endl;
    }
    cout << "HuH? Oh, hey. Are you here to make a world? Well let me tell you this pal... you're in the right place." << endl;
    cout << "I, aloftballoon, am the BEST world creator! I can help guide you." << endl;
    if(argc == 1)
    {
        cout << "BUT... it doesnt look like you gave me a file to write into. That makes me sad." << endl;
        cout << "If you want my help, you're going to need to include the filename after your executable call, like this:" << endl; 
        cout << "./worldCreator filename" << endl;
        cout << "And make sure the file is a text file, understand?" << endl;
        return 1;
    }
    string filename = argv[1];
    cout << "Alright, let start! I'm going to write into " << filename << ", ok?" << endl; 
    ofstream a;
    a.open(filename);
    if(!a.is_open())
    {
        cout << "OH SHOOT SOMETHING WENT WRONG ALRIGHT IM GONNA RUN AWAY NOW AHHHHHHHHHHH!" << endl;
        return 1;
    }
    cout << "OK, WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOSSSSSSSSSSSSSSSSHHHHHHHHHHHH!!!!" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    //world creation started
    
    cout << "For now, please use an underscore instead of any spaces. spaces make the program go crazy" << endl;
    
    World final;
    final.getCityName();
    final.getPlayerName();
    final.getTowns();
    final.getNPCs();
    final.getRoutes();
    final.getMonsters();
    final.getItems();

    cout << "YEAHHHHHHHHH!!! Lets go! You made a world, here is its summary! See you later, alligator!" << endl;

    cout << "List of towns" << endl;
    final.printListOfTowns();
    cout << "List of routes" << endl;
    final.printRoutes();
    cout << "List of NPCs" << endl;
    final.printNPCs();
    cout << "List of monsters" << endl;
    final.printMonsters();
    cout << "List of items" << endl;
    final.printItems();
}
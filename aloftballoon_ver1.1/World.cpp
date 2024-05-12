#include "World.h"

#include <iostream>
#include <cassert>

using namespace std;

void World::getCityName()
{
    cout << "First of all, what is the name of your central city?" << endl;
    string name;
    cin >> name;
    //input check function here
    CapitalCity = name;
}

void World::getPlayerName()
{
    cout << "Next, what is YOUR name?" << endl;
    string name;
    cin >> name;
    //input check function here
    PlayerName = name;
}

void World::getTowns()
{
    string townName = "";
    cout << "Next, what is the name of the towns in your map? Enter them one by one, and type q to quit" << endl;
    while(true)
    {
        cin >> townName;
        //input check
        if(townName == "q"){break;}
        town.push_back(townName);
    }
}

void World::getNPCs()
{
    cout << "Time for NPCs!" << endl;
    while(true)
    {
        if(!cin){throw runtime_error("cin broke lol");}
        cout << "Name of NPC (enter q to quit)" << endl;
        string name = "";
        cin >> name;
        if(name == "q"){break;}
        cout << "Enter town ID for NPC (enter -1 to print list of towns and thier IDS)" << endl;
        int ID = 0;
        while(true)
        {
            
            cin >> ID;
            if(ID == -1)
            {printListOfTowns();}

            else{break;}
        }
        string talk = "";
        cout << "Enter thier dialouge(Note: for now, seperate all spaces with an underscore)" << endl;
        cin >> talk;
        if(ID < 0 || ID >= town.size()){cout << "ID was invalid, NPC not added." << endl;}
        else
        {
            Dude a;
            a.name = name;
            a.dialogue = talk;
            a.town_id_for_npc = ID;
            npc.push_back(a);
        }
    }
}//

void World::printListOfTowns()
{
    for(int i = 0; i < town.size(); i++)
    {
        cout << "ID: " << i << ", name: " << town.at(i) << endl;
    }
}

void World::getRoutes()
{
    cout << "Time for routes mate! Enter -1 to quit. You'll need routes to go from one town to another. Make sure you have a way to get to every town! Speaking of places, I just remembered that I'm running out of milk. I'm gonna go to the store to pick some up after this." << endl;
    while(true)
    {
        cout << "Enter ID of the first town(enter -1 to quit and -2 to get the list of towns and IDs)" << endl;
        int one = 0;
        cin >> one;
        if(one == -1){break;}
        while(true)
        {
            if(one != -2){break;}
            printListOfTowns();
            cin >> one;
        }
        cout << "Enter ID of the second town(enter -1 to exit or -2 to see list of towns and thier IDs)" << endl;
        int two = 0;
        cin >> two;
        if(two == -1){break;}
        while(true)
        {
            if(two != -2){break;}
            printListOfTowns();
            cin >> two;
        }
        if(one == two || one < 0 || two < 0 || one >= town.size() || two >= town.size())
        {
            cout << "Invalid IDs" << endl;
        }
        bool duplicate = false;
        for(int i = 0; i < routes.size(); i++)//check to see if there is a duplicate route
        {
            if(routes.at(i).start == one && routes.at(i).end == two){duplicate = true;}
        }
        if(duplicate){cout << "Invalid IDs" << endl;}
        else
        {
            IDpair a;
            IDpair b;
            a.start = one;
            b.start = two;
            a.end = two;
            b.end = one;
            routes.push_back(a);
            routes.push_back(b);//NOTE: adding both one to two and two to one to keep the graph "biderictional"
        }
    }    
}

void World::getMonsters()
{
    cout << "Time for monsters!!! OOooooooohhh... Scary, right? You can add monsters on any route.";
    while(true)
    {
        cout << "Enter name of monster, or enter q to quit" << endl;
        string name = "";
        cin >> name;
        if(name == "q"){break;}
        cout << "Enter HP of monster" << endl;
        int HP = 0;
        cin >> HP;
        cout << "Enter attack of monster" << endl;
        int attack = 0;
        cin >> attack;
        cout << "Enter IDs of routes monster will be found on, ending with a -1 to continue. Enter -2 to see the list of routes" << endl;
        vector<int> houses;
        while(true)
        {
            int a = 0;
            cin >> a;
            if(a == -1){break;}
            if(a == -2){printRoutes();}
            else if(a < 0 || a >= routes.size()/2){cout << "Invalid Route!" << endl;}
            else{houses.push_back(a);}
        }
        if(HP < 1 || attack < 1){cout << "stats were invalid"<< endl;}
        else
        {
            Monster aloft;
            aloft.name = name;
            aloft.attack = attack;
            aloft.HP = HP;
            aloft.locations = houses;
            monster.push_back(aloft);
        }
    }
}

void World::printRoutes()
{
    for(int i = 0; i < routes.size(); i += 2)
    {
        cout << "ID: " << (i/2) << ", route connects " << town.at(routes.at(i).start) << " and " << town.at(routes.at(i).end) << endl;
    }
}

void World::getItems()
{
    cout << "Time for items!!! Each item has a name, a value at which it can be sold, an attack power with which it can be used to attack, and a varition which determines other factors about it (like how often it will miss/do a crit hit)." << endl;
    cout << "A high variation means its kinda like a wild card, and a low variotion is a sweet, swift, reliable weapon." << endl;
    while(true)
    {
        //
        cout << "Enter name of item, or q to quit" << endl;
        string name = "";
        cin >> name;
        if(name == "q"){break;}
        cout << "Enter its attack" << endl;
        int attack = 0;
        cin >> attack;
        cout << "Enter its value" << endl;
        int value = 0;
        cin >> value;
        cout << "Enter its variablity" << endl;
        int var = 0;
        cin >> var;
        if(var < 0 || attack < 0 || value < 0)
        {
            cout << "That is invalid!" << endl;
        }
        else
        {
            cout << "Enter 0 if this item will be sold by NPCs, or 1 if it will be dropped by monsters" << endl;
            int sold = 0;//npcs by defualt
            cin >> sold;
            int ID = -1;
            cout << "Enter ID of NPC or monster" << endl;
            if(sold == 0){printNPCs();}
            else{printMonsters();}
            cin >> ID;
            if(ID < 0 || (ID >= npc.size() && sold == 0) || (ID >= monster.size() && sold != 0))
            {
                cout << "Invalid ID!" << endl;
            }
            else
            {
                itemGame a;
                a.soldByNPC = (sold != 0);
                a.value = value;
                a.attackForce = attack;
                a.variation = var;
                a.ID = ID;
                a.name = name;
                item.push_back(a);
            }
            //build the item before here
        }
    }
}


void World::printNPCs()
{
    for(int i = 0; i < npc.size(); i++)
    {
        cout << "ID: " << i << ", name of npc: " << npc.at(i).name << endl;
    }
}

void World::printMonsters()
{
    for(int i = 0; i < monster.size(); i++)
    {
        cout << "ID: " << i << ", name of monster: " << monster.at(i).name << endl;
    }
}

void World::printItems()
{
    for(int i = 0; i < item.size(); i++)
    {
        cout << "ID: " << i << ", Item name: " << item.at(i).name << ", item is found through ";
        if(!item.at(i).soldByNPC){cout << "NPC" << npc.at(item.at(i).ID).name;}
        else{cout << "monster";}
        cout << endl;
    }
}
#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct IDpair
{
    int start = 0;;
    int end = 0;
};

struct itemGame
{
    bool soldByNPC = false;//true means sold by npc, false means dropped by monster
    int value = 0;
    int attackForce = 0;
    int variation = 0;
    string name = "";
    int ID = -1;
};

struct Monster
{
    int HP = 0;
    int attack = 0;
    string name;
    vector<int> locations;
};

struct Dude
{
    string name;
    string dialogue;
    int town_id_for_npc = 0;
};

struct World
{
    string PlayerName = "";
    string CapitalCity = "";
    vector<string> town;
    vector<itemGame> item;
    vector<Dude> npc;
    vector<Monster> monster;
    vector<IDpair> routes;

    void getCityName();
    void getPlayerName();
    void getTowns();
    void getNPCs();
    void getRoutes();
    void getMonsters();
    void getItems();

    void printListOfTowns();
    void printRoutes();
    void printMonsters();
    void printNPCs();
    void printItems();
};
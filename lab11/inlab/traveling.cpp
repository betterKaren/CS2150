/**
* @author Yu Du, yd2am
* @filename traveling.cpp
* @date 2019.12.3
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/**
* @brief main method
* @details 
* @param argc number of arguments
* @param **argv user input arguments (should be 5 so that the program can run)
*/
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    string start = dests[0];
    // sort the dest cities, but leave the start city out
    // if not sort, print out the opposite order..
    sort(dests.begin()+1, dests.end());
    vector<string> result = dests;
    float minDist = computeDistance(me, start, dests);

    while(next_permutation(dests.begin()+1, dests.end())) {
        float curDist = computeDistance(me, start, dests);
        if(curDist < minDist) {
            minDist = curDist;
            result = dests;
        }
    }

    cout << "Your journey will take you along the path ";
    printRoute(start, result);
    cout << "and will have length " << minDist << endl;

    return 0;
}


/**
* @brief This method computes the full distance of the cycle that starts
* at the 'start' parameter, goes to each of the cities in the dests
* vector IN ORDER, and ends back at the 'start' parameter.
* @param me MiddleEarch reference
* @param start the city where the traveling cycle starts and ends
* @param dests the cities visted INORDER while traveling
* @return distance of a traveling cycle
*/
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    float dist = 0.0;
    for(int i=0; i<dests.size(); i++) {
        dist += me.getDistance(start, dests[i]);
        start = dests[i];
    }

    // also need to add the distance from the last visting city to the start city
    dist += me.getDistance(dests[dests.size()-1], dests[0]);
    return dist;
}

/**
* @brief This method will print the entire route, starting and ending at the 'start' parameter.
* @param start the city where the traveling cycle starts and ends
* @param dests the cities visted INORDER while traveling
*/
void printRoute (string start, vector<string> dests) {
    // The output should be of the form:
    // Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
    for(int i=0; i<dests.size(); i++) {
        cout << dests[i] << " -> ";
    }
    cout << start << endl;
}

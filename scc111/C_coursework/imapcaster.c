#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LOCATIONS 10

struct location 
{
    char name[20];
    int latitude;
    int longitude;
};

void addNewLocation (char name[], int lat, int longt, struct location locations[], int *nums);
void print_locations(struct location locations[], int num);


int main()
{
    int numberOfLocs = 0;
    int *numptr = &numberOfLocs;
    struct location locations[MAX_LOCATIONS];

    addNewLocation("RomanRuins", 234, 567, locations, numptr);
    print_locations(locations, numberOfLocs);
}

void addNewLocation (char name[], int lat, int longt, struct location locations[], int *nums)
{
    struct location newLocation = {"", lat, longt};
    strcpy(newLocation.name, name);
    locations[*nums] = newLocation;
    *nums += 1;
}

void print_locations(struct location locations[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("Location %d: %s at %d, %d\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

#include "Framework\console.h"
#include "map.h"

extern Console g_Console;


// filenames for all the maps
char maps[][128] =
{
	"map.txt",
	"level2.map"
};

/* ==========================================================================================================
 *	Function	:		load_map(int level) 
 *	Parameters	:		level : map level 
 *	Output		:		PMAP  : pointer to the map structure 
 *
 * ========================================================================================================== */

PMAP load_map(int level)
{
	MAP* map; 

	char*filename = maps[level-1];

	
	ifstream infile; 
	int nrow, ncol, i; 

	infile.open(filename); 	
	if (!infile)
	{
		cout << "Error Opening" << filename << endl ; 
		exit(1); 
	}


	if (infile.good())
	{

		// get nrow and ncol at 1st line of the file  
		infile >> nrow >> ncol; 		

		// allocate the MAP structure and memory to hold the map data 
		map = new MAP(nrow, ncol+1); // extra column for null terminating character 

		// read back the map data 
		i= 0; 
		while(infile.good())
		{
			string line; 
			getline(infile, line); 
			if (line.length())
			{
				memcpy(map->data[i],line.c_str(), sizeof(map->data[i])); 
				map->data[i][ncol] = 0;
				i++;
			}
		}
	}
	infile.close(); 
	

	return map; 
}


void free_map(PMAP pmap)
{
	delete pmap; 
}

void render_map(PMAP pmap, COORD pos, WORD color)
{
	int i, j; 


	for (i=0;i<pmap->nrow;i++) 
	{	
		g_Console.writeToBuffer(pos.X, pos.Y + i, pmap->data[i], color);
	}
}
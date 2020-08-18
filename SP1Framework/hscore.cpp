
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


#include <stdio.h> 
#include <string.h> 

#include "hscore.h"


// ==========================================================================
// load_hscore function 
//
//	input	:	char*	filename		: filename of hscore 
//				PHSCORE	pHSCoreArr		: Highscore array
//
//	out		:	no of highscore currently in the file
//
// 
// Remark	:	Apllication need to call the write_hscore function at the end 
//				of the game.
//
// ==========================================================================
int load_hscore(char* filename, PHSCORE pHScore)
{
	ifstream infile; 
	int i=0; 

	
	double	time; 
	int		nsteps;

	infile.open(filename);

	if (!infile)
	{
		cout << "Error Opening" << filename << endl;
		exit(1);
	}

	while (infile.good())
	{
		int score; 

		infile >> time >> nsteps;

		pHScore[i].dtime = time;
		pHScore[i++].isteps = nsteps; 
	}
	

	return i; 
}

void write_hscore(char* filename, PHSCORE pHScore)
{
	
}


//
int update_hscore(double times, int steps, PHSCORE pHScore, int icur)
{
	int i , icheck; 


	// icur haben reach max highscore 
	if (icur < MAX_HSCORE)
		icheck = icur;

	
	for (i = 0; i < icheck; i++)
	{
		if (times < pHScore[i].dtime)
			break;
	}

	// within the highscore -
	// update the highscore array 
	if (icheck < MAX_HSCORE-1)
	{
		if (i < icheck)
		{
			pHScore[i].dtime = times;
			pHScore[i].isteps= steps;

			for (int j = i; j < icheck; j++)
			{
				
			}
		}
		else
		{
			pHScore[icur].dtime = times; 
			pHScore[icur].isteps = steps;
		}

	}
	else
	{

		pHScore[i].dtime = times;
		pHScore[i].isteps = steps; 

		//
		for (i = i - 1; i < MAX_HSCORE - 1; i++)
		{
				pHScore[i + 1] = pHScore[i];
		}

	}

	return icur; 
}

 
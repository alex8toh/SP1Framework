#ifndef _HSCORE_H__
#define _HSCORE_H__


#include <stdio.h> 
#include <string.h> 

#define MAX_HSCORE 10

typedef struct sHScore
{
	double  dtime; 
	int		isteps;
	//char	szname[20];


	// default contstructor 
	sHScore()
	{
		//memset(szname, 0, sizeof(szname));
		dtime = 0;
		isteps = 0;
	}

	// constructor 
	sHScore(double times, int steps)
	{
		//strcpy(szname, name);
		dtime = times; 
		isteps = steps; 
	}

	// destructor 
	~sHScore()
	{
		//memset(szname, 0, sizeof(szname));
		isteps = 0;
		dtime = 0; 
	}
}
HSCORE, * PHSCORE; 

extern HSCORE highscores[MAX_HSCORE];


// ==========================================================================
// load_hscore function 
//
//	input	:	char*	filename		: filename of hscore 
//				PHSCORE	pHSCoreArr		: Highscore array
//
//	out		:	MAP* MAP pointer	: Pointer to is Map data structure 
//
// 
// Remark	:	Apllication need to call the free_map function to release the 
//				memory for 
//
// ==========================================================================
int load_hscore(char* filename, PHSCORE pHScore );

void write_hscore(char* filename, PHSCORE pHScore);

void update_hscore(int score, PHSCORE pHScore);


#endif 
/*
	==================================================
	Workshop #6 (Part-1):
	==================================================

	+------------------------------------------------+
                       IMPORTANT
                       =========
             *** DO NOT MODIFY THIS FILE ***
	+------------------------------------------------+
*/

#include <stdio.h>

#include "w6p1.h"

#define TEST_NEG	-1
#define TEST_ZERO	0
#define TEST_INT	24
#define TEST_DBL	82.5

// ---------------------------------------
// Function prototypes
// ---------------------------------------
int testIntFunction(void);
int testDoubleFunction(void);

// ---------------------------------------
// Main entry-point to the program
// ---------------------------------------
int main(void)
{
	int preTestFailed = 0;

	printf("============================\n");
	printf("Pre-testing Helper Functions\n");
	printf("============================\n\n");
	
	preTestFailed += testIntFunction();
	preTestFailed += testDoubleFunction();

	if (preTestFailed)
	{
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("  Pretesting revealed ERRORS in the helper functions.\n");
		printf("  Review where the tests failed and fix these errors\n");
		printf("  before continuing.\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
	}
	else
	{
		printf("===========================\n");
		printf("Starting Main Program Logic\n");
		printf("===========================\n\n");

		// Entry-point to program logic
		start();
	}

	return 0;
}

// ---------------------------------------
// Function definitions
// ---------------------------------------
int testIntFunction(void)
{
	int intA = 0, intB = 0, fail=0;

	printf("------------------------\n");
	printf("Function: getIntPositive\n");
	printf("------------------------\n");
	printf("For each of these tests, enter the following\n");
	printf("three values (space delimited):  %d %d %d\n\n", TEST_NEG, TEST_ZERO, TEST_INT);

	//-----------------------------------
	// Test-1: argument and return value
	printf("TEST-1: ");
	intB = getIntPositive(&intA);
	if (intA == intB && intA == TEST_INT)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-2: return value only
	intA = intB = 0;
	printf("TEST-2: ");
	intA = getIntPositive(NULL);
	if (intA == TEST_INT)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-3: argument only
	intA = intB = 0;
	printf("TEST-3: ");
	getIntPositive(&intA);
	if (intA == TEST_INT)
	{
		printf("<PASSED>\n\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}
	
	return fail;
}

int testDoubleFunction(void)
{
	double dblA = 0.0, dblB = 0.0;
	int fail = 0;

	printf("---------------------------\n");
	printf("Function: getDoublePositive\n");
	printf("---------------------------\n");
	printf("For each of these tests, enter the following\n");
	printf("three values (space delimited):  %d %d %.1lf\n\n", TEST_NEG, TEST_ZERO, TEST_DBL);

	//-----------------------------------
	// Test-1: argument and return value
	printf("TEST-1: ");
	dblB = getDoublePositive(&dblA);
	if (dblA == dblB && dblA == TEST_DBL)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-2: return value only
	dblA = dblB = 0.0;
	printf("TEST-2: ");
	dblA = getDoublePositive(NULL);
	if (dblA == TEST_DBL)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-3: argument only
	dblA = dblB = 0.0;
	printf("TEST-3: ");
	getDoublePositive(&dblA);
	if (dblA == TEST_DBL)
	{
		printf("<PASSED>\n\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n\n");
		fail++;
	}
	
	return fail;
}

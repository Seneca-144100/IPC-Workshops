/*
    ==================================================
	Workshop #6 (Part-2):
	==================================================

	+------------------------------------------------+
                      IMPORTANT
                      =========
            *** DO NOT MODIFY THIS FILE ***
	+------------------------------------------------+
*/

#include <stdio.h>

#include "w6p2.h"

#define TEST_NEG	-1
#define TEST_ZERO	0
#define TEST_INT	24
#define TEST_DBL	82.5
#define TEST_LBSKG  2.20462
#define TEST_LBSG	2494
#define TEST_LBS	5.5

// ---------------------------------------
// Function prototypes
// ---------------------------------------
int testIntFunction(void);
int testDoubleFunction(void);
int testConvertLbsKg(void);
int testConvertLbsG(void);
int testConvertLbs(void);

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
	preTestFailed += testConvertLbsKg();
	preTestFailed += testConvertLbsG();
	preTestFailed += testConvertLbs();

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
	int intA = 0, intB = 0, fail = 0;

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
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	return fail;
}

int testConvertLbsKg(void)
{
	double dblA, dblB, lbs= TEST_LBS;
	int fail = 0;

	printf("---------------------------\n");
	printf("Function: convertLbsKg\n");
	printf("---------------------------\n");

	// Test-1: argument and return value
	dblA = dblB = 0.0;
	printf("Test-1: ");
	dblB = convertLbsKg(&lbs, &dblA);
	if (dblA == dblB && dblA == lbs / TEST_LBSKG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}
	// Test-2: return value only
	dblA = dblB = 0.0;
	printf("Test-2: ");
	dblA = convertLbsKg(&lbs, NULL);
	if (dblA == lbs / TEST_LBSKG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	// Test-3: argument only
	dblA = dblB = 0.0;
	printf("Test-3: ");
	convertLbsKg(&lbs, &dblA);
	if (dblA == lbs / TEST_LBSKG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	return fail;
}

int testConvertLbsG(void)
{
	double lbs = TEST_LBS;
	int intA, intB, fail = 0;

	printf("---------------------------\n");
	printf("Function: convertLbsG\n");
	printf("---------------------------\n");

	// Test-1: argument and return value
	intA = intB = 0;
	printf("Test-1: ");
	intB = convertLbsG(&lbs, &intA);
	if (intA == intB && intA == TEST_LBSG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}
	// Test-2: return value only
	intA = intB = 0;
	printf("Test-2: ");
	intA = convertLbsG(&lbs, NULL);
	if (intA == TEST_LBSG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	// Test-3: argument only
	intA = intB = 0;
	printf("Test-3: ");
	convertLbsG(&lbs, &intA);
	if (intA == TEST_LBSG)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	return fail;
}

int testConvertLbs(void)
{
	double lbs = TEST_LBS, dblA = 0.0;
	int intB = 0, fail = 0;

	printf("---------------------------\n");
	printf("Function: convertLbs\n");
	printf("---------------------------\n");

	printf("Test-1: ");
	convertLbs(&lbs, &dblA, &intB);
	if ((dblA == lbs / TEST_LBSKG) && (intB == TEST_LBSG))
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

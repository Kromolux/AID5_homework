#include "../inc/Punkt2D.hpp"

void	printTestCat(const char *prompt);
void	printTestNr(const char *prompt);

void	testPunkt2D( void )
{
	printf("\n\nTestprogram for points in a 2D-room\n");

	printTestCat("Constructors");
	{
		printTestNr("Standard-Constructor ==> Punkt2D P0;");
		Punkt2D	P0;

		printTestNr("Init-Constructor ==> Punkt2D P1(10,5);");
		Punkt2D	P1(10,5);

		printTestNr("Copy-Constructor ==> Punkt2D P2(P1);");
		Punkt2D	P2(P1);

		printTestNr("Deconstructor ==> }");
	}

	printTestCat("Set-ter and get-ter");
	{
		Punkt2D P0;
		printTestNr("setX setY ==> P0.setX(15);P0.setY(9);");
		P0.setX(15);
		P0.setY(9);

		printTestNr("getX getY ==> printf(\"%i %i\", P0.getX(), P0.getY());");
		printf("%i %i", P0.getX(), P0.getY());

		printTestNr("setXY ==> P0.setXY(INT_MIN, INT_MAX);");
		P0.setXY(INT_MIN, INT_MAX);

		printTestNr("getX getY ==> printf(\"%i %i\", P0.getX(), P0.getY());");
		printf("%i %i", P0.getX(), P0.getY());
	}

	printTestCat("IO-Methods");
	{
		Punkt2D P0;

		printTestNr("input ==> P0.input();");
		P0.input();

		printTestNr("print ==> P0.print();");
		P0.print();

		printTestNr("info ==> P0.info();");
		P0.info();
	}

	printTestCat("workmethods for points");
	{
		Punkt2D	P0(10,50);
		Punkt2D	P1(5,25);

		printf("\n -> check points P0 and P1");
		P0.print();
		P1.print();

		printTestNr("move ==> P0.move(P1);");
		P0.move(P1);

		printf("\n -> check points P0 and P1 again after move");
		P0.print();
		P1.print();

		printTestNr("move ==> P1.move(-5, -15);");
		P1.move(-5, -15);

		printf("\n -> check points P0 and P1 again after 2. move");
		P0.print();
		P1.print();
	}

	printTestCat("Operators");
	{
		Punkt2D	P0(0, 0);
		Punkt2D	P1(1, 1);

		printf("\n -> check points P0 and P1");
		P0.print();
		P1.print();

		printTestNr("operator= ==> P0 = P1;");
		P0 = P1;

		printf("\n -> check points P0 and P1 after assignement");
		P0.print();
		P1.print();

		printTestNr("operator= self assignement ==> P1 = P1;");
		P1 = P1;

		printf("\n -> check points P0 and P1 after self assignement");
		P0.print();
		P1.print();

		printTestNr("operator== ==> if (P0 == P1)");
		if (P0 == P1)
			printf("\nP0 and P1 are equal");
		else
			printf("\n P0 and P1 are unequal");

		printTestNr("operator!= ==> if (P0 != P1)");
		if (P0 != P1)
			printf("\nP0 and P1 are unequal");
		else
			printf("\n P0 and P1 are equal");

		printf("\n changing value of P0 to (5,5)");
		P0.setXY(5,5);

		printTestNr("operator== ==> if (P1 == P0)");
		if (P1 == P0)
			printf("\nP0 and P1 are equal");
		else
			printf("\n P0 and P1 are unequal");

		printTestNr("operator!= ==> if (P1 != P0)");
		if (P1 != P0)
			printf("\nP0 and P1 are unequal");
		else
			printf("\n P0 and P1 are equal");
		

		printf("\n -> check points P0 and P1");
		P0.print();
		P1.print();
		printTestNr("operator+ ==> Punkt2D P2 = P0 + P1;");
		Punkt2D P2 = P0 + P1;

		printf("\n -> check P2");
		P2.print();

		printf("\n changing value of P2 to (-5,-5)");
		P2.setXY(-5,-5);

		printf("\n -> check P2");
		P2.print();

		printTestNr("operator+ ==> P0 = P1 + P2;");
		P0 = P1 + P2;

		printf("\n -> check all points");
		P0.print();
		P1.print();
		P2.print();

		printTestNr("operator+= ==> P1 += P2;");
		P1 += P2;

		printf("\n -> check all points");
		P0.print();
		P1.print();
		P2.print();

		printTestNr("operator- ==> P0 = P0 - P1;");
		P0 = P0 - P1;

		printf("\n -> check all points");
		P0.print();
		P1.print();
		P2.print();

		printTestNr("operator-= ==> P1 -= P2;");
		P1 -= P2;

		printf("\n -> check all points");
		P0.print();
		P1.print();
		P2.print();
	}
}

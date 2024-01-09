#include "../inc/Punkt3D.hpp"

void	printTestCat(const char *prompt);
void	printTestNr(const char *prompt);

void	testPunkt3D( void )
{
	printf("\n\nTestprogram for points in a 3D-room\n");

	printTestCat("Constructors");
	{
		printTestNr("Standard-Constructor ==> Punkt3D P0;");
		Punkt3D	P0;

		printTestNr("Init-Constructor ==> Punkt3D P1(10, 5, 9);");
		Punkt3D	P1(10, 5, 9);

		printTestNr("Copy-Constructor ==> Punkt3D P2(P1);");
		Punkt3D	P2(P1);

		printTestNr("Copy-2D-Constructor ==> Punkt3D P3( Punkt2D(9, 9));");
		Punkt3D	P3( Punkt2D(9, 9));

		printTestNr("Deconstructor ==> }");
	}

	printTestCat("Set-ter and get-ter");
	{
		Punkt3D P0;
		printTestNr("setX setY setZ ==> P0.setX(15);P0.setY(9);P0.setZ(19);");
		P0.setX(15);
		P0.setY(9);
		P0.setZ(19);

		printTestNr("getX getY getZ ==> printf(\"%i %i %i, P0.getX(), P0.getY(), P0.getZ());");
		printf("%i %i %i", P0.getX(), P0.getY(), P0.getZ());

		printTestNr("setXYZ ==> P0.setXY(INT_MIN, INT_MAX, 42);");
		P0.setXYZ(INT_MIN, INT_MAX, 42);

		printTestNr("getX getY getZ ==> printf(\"%i %i %i, P0.getX(), P0.getY(), P0.getZ());");
		printf("%i %i %i", P0.getX(), P0.getY(), P0.getZ());
	}

	printTestCat("IO-Methods");
	{
		Punkt3D P0;

		printTestNr("input ==> P0.input();");
		P0.input();

		printTestNr("print ==> P0.print();");
		P0.print();

		printTestNr("info ==> P0.info();");
		P0.info();
	}

	printTestCat("workmethods for points");
	{
		Punkt3D	P0(10, 50, 42);
		Punkt3D	P1(5, 25, 420);

		printf("\n -> check points P0 and P1");
		P0.print();
		P1.print();

		printTestNr("move ==> P0.move(P1);");
		P0.move(P1);

		printf("\n -> check points P0 and P1 again after move");
		P0.print();
		P1.print();

		printTestNr("move ==> P1.move(-5, -15, -9);");
		P1.move(-5, -15, -42);

		printf("\n -> check points P0 and P1 again after 2. move");
		P0.print();
		P1.print();
	}

	printTestCat("Operators");
	{
		Punkt3D	P0(0, 0, 0);
		Punkt3D	P1(1, 1, 1);

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

		printf("\n changing value of P0 to (5, 5, 5)");
		P0.setXYZ(5, 5, 5);

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

		printTestNr("operator+ ==> Punkt3D P2 = P0 + P1;");
		Punkt3D P2 = P0 + P1;

		printf("\n -> check P2");
		P2.print();

		printf("\n changing value of P2 to (-5, -5, -5)");
		P2.setXYZ(-5, -5, -5);

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

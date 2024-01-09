#include "../inc/Strecke3D.hpp"

void	printTestCat(const char *prompt);
void	printTestNr(const char *prompt);

void	testStrecke3D( void )
{
	printf("\n\nTestprogram for a route in a 3D-room\n");

	printTestCat("Constructors");
	{
		printTestNr("Standard-Constructor ==> Strecke3D	S0;;");
		Strecke3D	S0;

		printTestNr("Init-Constructor ==> Strecke3D	S1(Punkt3D(), Punkt3D(10, 5, 9));");
		Strecke3D	S1(Punkt3D(), Punkt3D(10, 5, 9));

		printTestNr("Copy-Constructor ==> Strecke3D	S2(S1);");
		Strecke3D	S2(S1);

		printTestNr("Deconstructor ==> }");
	}

	printTestCat("Set-ter and get-ter");
	{
		Strecke3D	S0(Punkt3D(), Punkt3D(2, 0, 0));
		Strecke3D	S1(Punkt3D(2, 2, 2), Punkt3D());
		printf("\ncheck S0 and S1");
		S0.print();
		S1.print();

		printTestNr("\ngetLength ==> printf(\\n\"length: %lf\", S0.getLength());");
		printf("\nlength: %lf", S0.getLength());
		printf("\nlength: %lf", S1.getLength());

		printTestNr("getMidPoint ==> Punkt3D midPoint(S0.getMidPoint());");
		Punkt3D midPoint0(S0.getMidPoint());
		Punkt3D midPoint1(S1.getMidPoint());

		printf("\nmidPoint0: ");
		midPoint0.print();
		printf("\nmidPoint1: ");
		midPoint1.print();

		printTestNr("getDirectionVector ==> Punkt3D directionVector(S0.getDirectionVector());");
		Punkt3D directionVector0(S0.getDirectionVector());
		Punkt3D directionVector1(S1.getDirectionVector());

		printf("\ndirectionVector0: ");
		directionVector0.print();
		printf("\ndirectionVector1: ");
		directionVector1.print();
	}

	printTestCat("IO-Methods");
	{
		Strecke3D	S0(Punkt3D(), Punkt3D(10, 5, 9));

		printTestNr("print ==> S0.print();");
		S0.print();

		printTestNr("info ==> S0.info();");
		S0.info();
	}

	printTestCat("Operators");
	{
		Strecke3D	S0(Punkt3D(), Punkt3D(10, 5, 9));
		Strecke3D	S1(Punkt3D(), Punkt3D(1, 1, 1));

		printf("\n -> check S0 and S1");
		S0.print();
		S1.print();

		printf("\noperator= ==> S0 = S1");
		S0 = S1;

		printf("\n -> check S0 and S1 after assignement");
		S0.print();
		S1.print();

		printTestNr("operator== ==> if (S0 == S1)");
		if (S0 == S1)
			printf("\nS0 and S1 are equal");
		else
			printf("\n S0 and S1 are unequal");

		printTestNr("operator!= ==> if (S0 != S1)");
		if (S0 != S1)
			printf("\nS0 and S1 are unequal");
		else
			printf("\n S0 and S1 are equal");

		printf("\n changing startPoint value of S0 to (5, 5, 5)");
		S0.startPoint.setXYZ(5, 5, 5);

		printTestNr("operator== ==> if (S1 == S0)");
		if (S1 == S0)
			printf("\nS0 and S1 are equal");
		else
			printf("\n S0 and S1 are unequal");

		printTestNr("operator!= ==> if (S1 != S0)");
		if (S1 != S0)
			printf("\nS0 and S1 are unequal");
		else
			printf("\n S0 and S1 are equal");
	}
	//...
}

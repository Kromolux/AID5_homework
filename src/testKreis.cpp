#include "../inc/Kreis.hpp"

void	printTestCat(const char *prompt);
void	printTestNr(const char *prompt);

void	testKreis( void )
{
	printf("\n\nTestprogram for a circle in a 2D-room\n");

	printTestCat("Constructors");
	{
		printTestNr("Standard-Constructor ==> Kreis	K0;");
		Kreis	K0;

		printTestNr("Init-Constructor ==> Kreis	K1(10, 5, 9);");
		Kreis	K1(10, 5, 9);

		printTestNr("Copy-Constructor ==> Kreis	K2(K1);");
		Kreis	K2(K1);

		printTestNr("Deconstructor ==> }");
	}

	printTestCat("set-ter and get-ter");
	{
		Kreis K0;
		printTestNr("setR ==> K0.setR(15);");
		K0.setR(15);

		printTestNr("getR ==> printf(\"%i\", K0.getR());");
		printf("%i", K0.getR());

		printTestNr("setXYR ==> K0.setXYR(INT_MIN, INT_MAX, 42);");
		K0.setXYR(INT_MIN, INT_MAX, 42);

		printTestNr("getR ==> printf(\"%i\", K0.getR());");
		printf("%i", K0.getR());

		printf("\nK0.setArea(1);");
		K0.setR(1);

		printTestNr("getArea ==> printf(\"%d\", K0.getArea();)");
		printf("%lf", K0.getArea());

		printTestNr("getScope ==> printf(\"%d\", K0.getScope();)");
		printf("%lf", K0.getScope());
	}

	printTestCat("IO-Methods");
	{
		Kreis K0;

		printTestNr("input ==> K0.input();");
		K0.input();

		printTestNr("print ==> K0.print();");
		K0.print();

		printTestNr("info ==> K0.info();");
		K0.info();
	}

	printTestCat("Operators");
	{
		Kreis	K0(0, 0, 0);
		Kreis	K1(1, 1, 1);

		printf("\n -> check circles K0 and K1");
		K0.center.print();
		K0.print();
		K1.center.print();
		K1.print();

		printTestNr("operator= ==> K0 = K1;");
		K0 = K1;

		printf("\n -> check circle K0 and K1 after assignement");
		K0.center.print();
		K0.print();
		K1.center.print();
		K1.print();

		printTestNr("operator= self assignement ==> K1 = K1;");

		printf("\n -> check points K0 and K1 after self assignement");
		K0.center.print();
		K0.print();
		K1.center.print();
		K1.print();

		printTestNr("operator== ==> if (K0 == K1)");
		if (K0 == K1)
			printf("\nK0 and K1 are equal");
		else
			printf("\nK0 and K1 are unequal");

		printTestNr("operator!= ==> if (K0 != K1)");
		if (K0 != K1)
			printf("\nK0 and K1 are unequal");
		else
			printf("\nK0 and K1 are equal");

	}
	//...
}

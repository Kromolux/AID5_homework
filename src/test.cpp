#include "../inc/Punkt3D.hpp"
#include "../inc/Kreis.hpp"

// Testprogram for point in 2D-room and 3D-room

void	printTestCat(const char *prompt);
void	printTestNr(const char *prompt);

void	testPunkt2D( void );
void	testPunkt3D( void );
void	testKreis( void );
void	testStrecke3D( void );

int	testCat = 0;
int	testNr = 0;

int	main( int argc, char **argv )
{
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v')
		{
			Punkt2D::setVerbose( true );
			//Kreis::setVerbose( true );
		}
	} else
	{
		Punkt2D::setVerbose( false );
		//Kreis::setVerboseKreis( false );
	}

	testPunkt2D();

	testPunkt3D();
	
	testKreis();

	testStrecke3D();

	#ifdef WINDOWS
		_getch();
	#endif
	return (0);
}

void	printTestCat(const char *prompt)
{
	printf("\n\n*** Test %i %s ***\n", ++testCat, prompt);
	testNr = 0;
}

void	printTestNr(const char *prompt)
{
	printf("\n\n--> Test %i.%i %s\n", testCat, ++testNr, prompt);
}

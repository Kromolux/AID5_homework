/* Implementation of the Kreis class */
#include "../inc/Kreis.hpp"

// Constructors
Kreis::Kreis( void ) // always sets values to the origin
{
	this->r = 0;

	// if ( verbose )
	// {
	// 	printf("\nclass [Kreis]: Standard-Constructor at   %p", this );
	// 	print();
	// }
}

Kreis::Kreis( int x, int y, int r ) : center(x, y)
{
	this->r = r;

	// if ( verboseKreis )
	// {
	// 	printf("\nclass [Kreis]: Init-Constructor at       %p", this );
	// 	print();
	// }
}

Kreis::Kreis( const Kreis & copy ) : center(copy.center)
{
	this->r = copy.r;

// 	if ( verboseKreis )
// 	{
// 		printf("\nclass [Kreis]: Copy-Constructor at       %p", this );
// 		print();
// 	}
}

Kreis::~Kreis( void )
{
	// if ( verboseKreis )
	// {
	// 	printf("\nclass [Kreis]: Destructor at             %p", this );
	// 	print();
	// }
}

// Operators
Kreis & Kreis::operator=( const Kreis & rhs )
{
	// if ( verboseKreis )
	// 	printf("\nclass [Kreis]: operator= at              %p", this );

	if (this != &rhs)
	{
		this->center = rhs.center;
		this->r = rhs.r;
	}
	return (*this);
}

bool	Kreis::operator==( const Kreis & rhs ) const
{
	// if ( verboseKreis )
	// 	printf("\nclass [Kreis]: operator== at             %p", this );

	return (this->center == rhs.center && this->r == rhs.r);
}

bool	Kreis::operator!=( const Kreis & rhs ) const
{
	// if ( verboseKreis )
	// 	printf("\nclass [Kreis]: operator!= at             %p", this );

	return !(*this == rhs);
}

void	Kreis::operator++( void )
{
	// if ( verboseKreis )
	// 	printf("\nclass [Kreis]: operator++ at             %p", this );

	++this->r;
}

void	Kreis::operator--( void )
{
	// if ( verboseKreis )
	// 	printf("\nclass [Kreis]: operator-- at             %p", this );

	--this->r;
}

// set-ter and get-ter
void	Kreis::setR( int r )
{
	this->r = r;
}

void	Kreis::setXYR( int x, int y, int r)
{
	this->center.setXY(x, y);
	this->r = r;
}

int		Kreis::getR( void ) const
{
	return (this->r);
}

double	Kreis::getArea( void ) const
{
	return ( M_PI * this->r * this->r );
}

double	Kreis::getScope( void ) const
{
	return ( 2.0 * M_PI * this->r );
}

// IO-Methods
void	Kreis::input( void ) // userinput for x, y and r
{
	this->center.input();
	this->r = getUserIntInput("radius");
}

void	Kreis::print( void ) const  // output in terminal "(x|y)r"
{
	printf(" (%i|%i)%i", this->center.getX(), this->center.getY(), this->r);
}

void	Kreis::info( void ) const
{
	printf("\nI am an object of the class [Kreis] at   %p", this);
}

// static Method for verboseKreis
// void	Kreis::setVerbose( bool status )
// {
// 	verbose = status;
// }

// internal workmethod
int	Kreis::getUserIntInput( const char *prompt ) const
{
	int		tmp = 0;
	char	in[20] = "";
	char	*errptr = NULL;

	// Command prompt for value
	// as long as ...
	do
	{
		// Read value with error handling
		printf("\n%s (Ganzzahl) : ", prompt);
		fgets( in, 20, stdin );
		if ( in[ strlen(in) -1 ] == LF )
			in[ strlen(in) -1 ] = '\0';
		fflush(stdin);

		// convert
		tmp = (int)strtol( in, &errptr, 10 );

		// error ?
		if ( *errptr )
		{
			printf("\nFalsche Eingabe bei Zeichen '%c'!"
					"\n\t Geben Sie eine korrekte Ganzzahl ein : ", *errptr );
		}
	// ... until no error
	} while ( *errptr );

	return (tmp);
}

std::ostream & operator<<(std::ostream & output, const Kreis & obj )
{
	output << "(" << obj.center.getX() << ":" << obj.center.getY() << ") " << obj.getR();
	return (output);
}

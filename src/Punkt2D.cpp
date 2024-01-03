/* Implementation of the Point2D class */
#include "../inc/Punkt2D.hpp"

bool Punkt2D::verbose = true;

// Constructors:
Punkt2D::Punkt2D( void )
{
	this->x = 0;
	this->y = 0;

	if ( verbose )
	{
		printf("\nclass [Punkt2D]: Standard-Constructor at   %p", this );
		print();
	}
}

Punkt2D::Punkt2D( int x, int y )
{
	this->x = x;
	this->y = y;

	if ( verbose )
	{
		printf("\nclass [Punkt2D]: Init-Constructor at       %p", this );
		print();
	}
}

Punkt2D::Punkt2D( const Punkt2D & copy )
{
	this->x = copy.x;
	this->y = copy.y;

	if ( verbose )
	{
		printf("\nclass [Punkt2D]: Copy-Constructor at     %p", this );
		print();
	}
}

Punkt2D::~Punkt2D( void )
{
	if ( verbose )
	{
		printf("\nclass [Punkt2D]: Destructor at             %p", this );
		print();
	}
}


	// Operators
Punkt2D &	Punkt2D::operator=( const Punkt2D & rhs )
{
	if ( verbose )
		printf("\nclass [Punkt2D]: operator= at              %p", this );

	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return (*this);
}

bool	Punkt2D::operator==( const Punkt2D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt2D]: operator== at             %p", this );

	if (this->x == rhs.x && this->y == rhs.y)
		return (true);
	return (false);
}

bool	Punkt2D::operator!=( const Punkt2D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt2D]: operator!= at             %p", this );

	if (this->x != rhs.x || this->y != rhs.y)
		return (true);
	return (false);
}

Punkt2D	Punkt2D::operator+( const Punkt2D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt2D]: operator+ at              %p", this );

	return ( Punkt2D( (this->x + rhs.x), (this->y + rhs.y) ) );
}

Punkt2D	Punkt2D::operator-( const Punkt2D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt2D]: operator- at              %p", this );

	return ( Punkt2D( (this->x - rhs.x), (this->y - rhs.y) ) );
}

// set-ter and get-ter
void	Punkt2D::setX( int x )
{
	this->x = x;
}

void	Punkt2D::setY( int y )
{
	this->y = y;
}

void	Punkt2D::setXY( int x, int y )
{
	this->x = x;
	this->y = y;
}

int	Punkt2D::getX( void ) const
{
	return (x);
}

int	Punkt2D::getY( void ) const
{
	return (y);
}

// IO-Methods
void	Punkt2D::input( void )
{
	this->x = getUserIntInput("x-Koordinate");
	this->y = getUserIntInput("y-Koordinate");
}

void	Punkt2D::print(void) const
{
	printf(" (%i|%i)", this->x, this->y );
}

void	Punkt2D::info( void ) const
{
	printf("\nI am an object of the class [Punkt2D] at   %p", this);
}

// workmethods for points
void	Punkt2D::move( const Punkt2D& mv_p )
{
	move(mv_p.x, mv_p.y);
}

void	Punkt2D::move( int mv_x, int mv_y )
{
	this->x += mv_x;
	this->y += mv_y;
}

// static Method for verbose
void	Punkt2D::setVerbose( bool status )
{
	verbose = status;
}

// internal workmethod
int	Punkt2D::getUserIntInput( const char *prompt ) const
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

std::ostream & operator<<(std::ostream & output, const Punkt2D & obj )
{
	output << "(" << obj.getX() << ":" << obj.getY() << ")";
	return (output);
}

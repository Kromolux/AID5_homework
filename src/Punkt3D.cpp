/* Implementation of the Point3D class */
#include "../inc/Punkt3D.hpp"

// Constructors:
Punkt3D::Punkt3D( void ) : Punkt2D()
{
	this->z = 0;

	if ( verbose )
	{
		printf("\nclass [Punkt3D]: Standard-Constructor at   %p", this );
		print();
	}
}

Punkt3D::Punkt3D( int x, int y, int z ) : Punkt2D(x, y)
{
	this->z = z;

	if ( verbose )
	{
		printf("\nclass [Punkt3D]: Init-Constructor at       %p", this );
		print();
	}
}

Punkt3D::Punkt3D( const Punkt3D & copy ) : Punkt2D(copy)
{
	this->z = copy.z;

	if ( verbose )
	{
		printf("\nclass [Punkt3D]: Copy-Constructor at       %p", this );
		print();
	}
}

Punkt3D::Punkt3D( const Punkt2D & copy ) : Punkt2D(copy)
{
	this->z = 0;

	if ( verbose )
	{
		printf("\nclass [Punkt3D]: Copy-2D-Constructor at    %p", this );
		print();
	}
}

Punkt3D::~Punkt3D( void )
{
	if ( verbose )
	{
		printf("\nclass [Punkt3D]: Destructor at             %p", this );
		print();
	}
}

// Operators
Punkt3D &	Punkt3D::operator=( const Punkt3D & rhs )
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator= at              %p", this );

	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}
	return (*this);
}

bool		Punkt3D::operator==( const Punkt3D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator== at             %p", this );

	return (Punkt2D::operator==( rhs ) && this->z == rhs.z);
}

bool		Punkt3D::operator!=( const Punkt3D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator!= at             %p", this );

	return !(*this == rhs);
}

Punkt3D		Punkt3D::operator+( const Punkt3D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator+ at              %p", this );

	Punkt3D tmp(*this);
	tmp.Punkt2D::operator+=(rhs);
	tmp.z += rhs.z;

	return ( tmp );
}

Punkt3D	&	Punkt3D::operator+=( const Punkt3D & rhs )
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator+= at             %p", this );

	this->Punkt2D::operator+=(rhs);
	this->z += rhs.z;

	return ( *this );
}

Punkt3D		Punkt3D::operator-( const Punkt3D & rhs ) const
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator- at              %p", this );

	Punkt3D tmp(*this);
	tmp.Punkt2D::operator-=(rhs);
	tmp.z -= rhs.z;

	return ( tmp );
}

Punkt3D	&	Punkt3D::operator-=( const Punkt3D & rhs )
{
	if ( verbose )
		printf("\nclass [Punkt3D]: operator-= at              %p", this );

	this->Punkt2D::operator-=(rhs);
	this->z -= rhs.z;

	return ( *this );
}

// set-ter and get-ter
void	Punkt3D::setZ( int z)
{
	this->z = z;
}

void	Punkt3D::setXYZ( int x, int y, int z )
{
	setXY(x, y);
	this->z = z;
}

int		Punkt3D::getZ( void ) const
{
	return (this->z);
}

// IO-Methods
void	Punkt3D::input( void ) // userinput for x, y and z
{
	this->Punkt2D::input();
	this->z = getUserIntInput("z-Koordinate");
}

void	Punkt3D::print( void ) const  // output in terminal "(x|y|z)"
{
	printf(" (%i|%i|%i)", this->x, this->y, this->z );
}

void	Punkt3D::info( void ) const
{
	printf("\nI am an object of the class [Punkt3D] at   %p", this);
}

// workmethods for points
void	Punkt3D::move( const Punkt3D& movePoint )
{
	Punkt2D::move(movePoint);
	this->z += movePoint.z;
}

void	Punkt3D::move( int x_move, int y_move, int z_move )
{
	Punkt2D::move( x_move, y_move);
	this->z += z_move;
}

std::ostream & operator<<(std::ostream & output, const Punkt3D & obj )
{
	output << "(" << obj.getX() << ":" << obj.getY() << ":" << obj.getZ() << ")";
	return (output);
}
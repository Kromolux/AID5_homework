
/* Implementation of the Kreis class */
#include "../inc/Strecke3D.hpp"

// Constructors
Strecke3D::Strecke3D( void ) // always sets values to the origin
{
}

Strecke3D::Strecke3D( Punkt3D startPoint, Punkt3D endPoint ) : startPoint(startPoint), endPoint(endPoint)
{
}

Strecke3D::Strecke3D( const Strecke3D & copy ) : startPoint(copy.startPoint), endPoint(copy.endPoint)
{
}

Strecke3D::~Strecke3D( void )
{
}


// Operators
Strecke3D & Strecke3D::operator=( const Strecke3D & rhs )
{
	if (this != &rhs)
	{
		this->startPoint = rhs.startPoint;
		this->endPoint = rhs.endPoint;
	}
	return (*this);
}

bool	Strecke3D::operator==( const Strecke3D & rhs ) const
{
	return (startPoint == rhs.startPoint && endPoint == rhs.endPoint);
}

bool	Strecke3D::operator!=( const Strecke3D & rhs ) const
{
	return !(*this == rhs);
}

// set-ter and get-ter
double	Strecke3D::getLength( void ) const
{
	Punkt3D	diff = endPoint - startPoint;
	return ( std::sqrt( diff.getX() * diff.getX() +
					    diff.getY() * diff.getY() +
					    diff.getZ() * diff.getZ() ) );
}

Punkt3D	Strecke3D::getMidPoint( void ) const
{
	return Punkt3D( (startPoint.getX() + endPoint.getX()) / 2,
					(startPoint.getY() + endPoint.getY()) / 2,
					(startPoint.getZ() + endPoint.getZ()) / 2 );
}

Punkt3D	Strecke3D::getDirectionVector( void ) const
{
	return (endPoint - startPoint);
}

// IO-Methods
void	Strecke3D::print( void ) const  // output in terminal "(x|y)r"
{
	printf("\nStrecke3D: startPoint: ");
	startPoint.print();
	printf(" endPoint: ");
	endPoint.print();
}

void	Strecke3D::info( void ) const
{
	printf("\nI am an object of the class [Strecke3D] at %p", this);
}

std::ostream & operator<<( std::ostream & output, const Strecke3D & obj )
{
	output << obj.startPoint << " -> " << obj.endPoint;
	return (output);
}

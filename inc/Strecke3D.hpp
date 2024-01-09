/*! \class Strecke3D
	for points in a 3-dimensional, integer coordinate system
*/
// uses the class Punkt3D

#include "./Punkt3D.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef __Strecke3D_defined__
# define __Strecke3D_defined__

class Strecke3D
{
public:
	Punkt3D	startPoint;
	Punkt3D	endPoint;

	// Constructors
	Strecke3D( void ); // always sets values to the origin
	Strecke3D( Punkt3D startPoint, Punkt3D endPoint );
	Strecke3D( const Strecke3D & copy );
	~Strecke3D( void );

	// Operators
	Strecke3D & operator=( const Strecke3D & rhs );

	bool	operator==( const Strecke3D & rhs ) const;
	bool	operator!=( const Strecke3D & rhs ) const;

	// set-ter and get-ter
	// This method calculates and returns the length of the 3D line segment using the Euclidean distance formula.
	double	getLength( void ) const;
	// This method calculates and returns the midpoint of the 3D line segment.
	Punkt3D	getMidPoint( void ) const;
	// This method calculates and returns the direction vector of the 3D line segment.
	Punkt3D	getDirectionVector( void ) const;
	
	// IO-Methods
	void	print( void ) const;  // output in terminal "(x|y)r"
	void	info( void ) const;

};

std::ostream & operator<<( std::ostream & output, const Strecke3D & obj );
#endif

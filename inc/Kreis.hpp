/*! \class Kreis
	for circles in a 2-dimensional, integer coordinate system
*/
// uses the class Punkt2D

#include "./Punkt2D.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef __Kreis_defined__
# define __Kreis_defined__

class Kreis
{
public:
	Punkt2D	center;

protected:
	int		r;
	static bool	verbose;

public:
	// Constructors
	Kreis( void ); // always sets values to the origin
	Kreis( int x, int y, int r );
	Kreis( const Kreis & copy );
	~Kreis( void );

	// Operators
	Kreis & operator=( const Kreis & rhs );

	bool	operator==( const Kreis & rhs ) const;
	bool	operator!=( const Kreis & rhs ) const;
	void	operator++( void );
	void	operator--( void );

	// set-ter and get-ter
	void	setR( int r );
	void	setXYR( int x, int y, int r);
	int		getR( void ) const;

	double	getArea( void ) const;
	double	getScope( void ) const;

	// IO-Methods
	void	input( void ); // userinput for x, y and r
	void	print( void ) const;  // output in terminal "(x|y)r"
	void	info( void ) const;

	// static Method for verbose
	//static void	setVerbose( bool status );

	// internal workmethods
protected:
	int	getUserIntInput( const char *prompt ) const;
};

std::ostream & operator<<( std::ostream & output, const Kreis & obj );
#endif
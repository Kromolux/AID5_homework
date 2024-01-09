/*! \class Punkt2D
	for points in a 2-dimensional, integer coordinate system
*/

#if defined(_WIN32) || defined(_WIN64)
# define WINDOWS
# include <conio.h>
# include <string.h>
# include <stdlib.h>
#elif defined(__unix__)
# define LINUX
# include <iostream>
# include <cstring>
# include <cstdlib>
#endif

#include <stdio.h>
#include <limits.h>
//#include <string.h>

#ifndef __Punkt2D_defined__
# define __Punkt2D_defined__

# define LF '\n'

class Punkt2D
{
protected:
	int	x;	/*!< var int x*/
	int	y;	/*!< var int y*/
	static bool	verbose;

public:
	// Constructors
	Punkt2D( void ); // always sets values to the origin
	Punkt2D( int x, int y );
	Punkt2D( const Punkt2D & copy );
	~Punkt2D( void );

	// Operators
	Punkt2D &	operator=( const Punkt2D & rhs );

	bool		operator==( const Punkt2D & rhs ) const;
	bool		operator!=( const Punkt2D & rhs ) const;
	Punkt2D		operator+( const Punkt2D & rhs ) const;
	Punkt2D	&	operator+=( const Punkt2D & rhs );
	Punkt2D		operator-( const Punkt2D & rhs ) const;
	Punkt2D	&	operator-=( const Punkt2D & rhs );

	// set-ter and get-ter
	void	setX( int x );
	void	setY( int y );
	void	setXY( int x, int y );

	int		getX( void ) const;
	int		getY( void ) const;

	// IO-Methods
	void	input( void ); // userinput for x and y
	void	print( void ) const; // output in terminal "(x|y)"
	void	info( void ) const;

	// workmethods for points
	void	move( const Punkt2D & movePoint );
	void	move( int x_move, int y_move );

	// static Method for verbose
	static void	setVerbose( bool status );

	// internal workmethods
	protected:
	int	getUserIntInput( const char *prompt ) const;
};

std::ostream & operator<<( std::ostream & output, const Punkt2D & obj );

#endif
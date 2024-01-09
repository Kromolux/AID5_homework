/**
 * @file Punkt3D.h
 *
 * @brief Definition of the Punkt3D class for 3D points in a coordinate system.
 */

/*! \class Punkt3D
	for points in a 3-dimensional, integer coordinate system
*/
// Inherits the class Punkt2D

#include "./Punkt2D.hpp"

#ifndef __Punkt3D_defined__
# define __Punkt3D_defined__

class Punkt3D : public Punkt2D
{
protected:
	int	z;

public:
	// Constructors
	Punkt3D( void ); // always sets values to the origin
	Punkt3D( int x, int y, int z );
	Punkt3D( const Punkt3D & copy );
	Punkt3D( const Punkt2D & copy );
	~Punkt3D( void );

	// Operators
	Punkt3D &	operator=( const Punkt3D & rhs );

	bool		operator==( const Punkt3D & rhs ) const;
	bool		operator!=( const Punkt3D & rhs ) const;
	Punkt3D		operator+( const Punkt3D & rhs ) const;
	Punkt3D	&	operator+=( const Punkt3D & rhs );
	Punkt3D		operator-( const Punkt3D & rhs ) const;
	Punkt3D	&	operator-=( const Punkt3D & rhs );

	// set-ter and get-ter
	void	setZ( int z);
	void	setXYZ( int x, int y, int z );
	int		getZ( void ) const;

	// IO-Methods
	void	input( void ); // userinput for x, y and z
	void	print( void ) const;  // output in terminal "(x|y|z)"
	void	info( void ) const;

	// workmethods for points
	void	move( const Punkt3D& movePoint );
	void	move( int x_move, int y_move, int z_move );
};

std::ostream & operator<<( std::ostream & output, const Punkt3D & obj );

#endif
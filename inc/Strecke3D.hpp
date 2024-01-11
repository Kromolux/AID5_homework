/*! \file
 *
 * @brief Declaration of the class Strecke3D: a route in a 3D coordinate system.
 */

/*! \class Strecke3D
	for a route in a 3-dimensional, integer coordinate system
*/
// uses the class Punkt3D

#ifndef STRECKE3D_HPP
# define STRECKE3D_HPP

#include "./Punkt3D.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

class Strecke3D
{
public:
	Punkt3D	startPoint;	/**< The starting point of the 3D line segment. */
	Punkt3D	endPoint;	/**< The ending point of the 3D line segment. */

	// Constructors
	/** \brief Default constructor. Sets both points to the origin. */
	Strecke3D( void ); // always sets values to the origin

	/**
	 * \brief Parameterized constructor.
	 * \param startPoint The starting point of the 3D line segment.
	 * \param endPoint The ending point of the 3D line segment.
	 */
	Strecke3D( Punkt3D startPoint, Punkt3D endPoint );

	/**
	 * \brief Copy constructor.
	 * \param copy The Strecke3D object to be copied.
	 */
	Strecke3D( const Strecke3D & copy );

	/** \brief Destructor. */
	~Strecke3D( void );

	// Operators
	/**
	 * \brief Assignment operator.
	 * \param rhs The Strecke3D object to be assigned.
	 * \return Reference to the assigned Strecke3D object.
	 */
	Strecke3D & operator=( const Strecke3D & rhs );

	/**
	 * \brief Equality operator.
	 * \param rhs The Strecke3D object to be compared for equality.
	 * \return True if the objects are equal, false otherwise.
	 */
	bool	operator==( const Strecke3D & rhs ) const;

	/**
	 * \brief Inequality operator.
	 * \param rhs The Strecke3D object to be compared for inequality.
	 * \return True if the objects are not equal, false otherwise.
	 */
	bool	operator!=( const Strecke3D & rhs ) const;

	// set-ter and get-ter
	/**
	 * \brief Calculates and returns the length of the 3D line segment.
	 * This method calculates and returns the length of the 3D line segment using the Euclidean distance formula.
	 * \return The length of the 3D line segment.
	 */
	double	getLength( void ) const;
	
	/**
	 * \brief Calculates and returns the midpoint of the 3D line segment.
	 * This method calculates and returns the midpoint of the 3D line segment.
	 * \return The midpoint of the 3D line segment.
	 */
	Punkt3D	getMidPoint( void ) const;

	/**
	 * \brief Calculates and returns the direction vector of the 3D line segment.
	 * This method calculates and returns the direction vector of the 3D line segment.
	 * \return The direction vector of the 3D line segment.
	 */
	Punkt3D	getDirectionVector( void ) const;
	
	// IO-Methods
	/** \brief Prints the 3D line segment in the terminal in the format "(x|y)r". */
	void	print( void ) const;  // output in terminal "(x|y)r"

	/** \brief Outputs information about the 3D line segment. */
	void	info( void ) const;

};

/**
 * \brief Overloaded stream insertion operator for Strecke3D objects.
 * \param output The output stream.
 * \param obj The Strecke3D object to be output.
 * \return The output stream.
 */
std::ostream & operator<<( std::ostream & output, const Strecke3D & obj );

#endif

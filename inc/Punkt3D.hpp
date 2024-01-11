/*! \file
 *
 * @brief Declaration of the class Punkt3D: 3D points in a coordinate system

 */


#ifndef PUNKT3D_HPP
# define _PUNKT3D_HPP

#include "./Punkt2D.hpp"

/** \class Punkt3D
 *  @brief Class representing points in a 3-dimensional, integer coordinate system.
 *  Inherits from class the class Punkt2D
 * 
 *  This class is derived from the Punkt2D class.
 */
class Punkt3D : public Punkt2D
{
protected:
	int	z;	/**< The z-coordinate of the 3D point. */

public:
	// Constructors
	/**
	* @brief Default constructor. Initializes the point to the origin (0, 0, 0).
	*/
	Punkt3D( void ); // always sets values to the origin

	/**
	 * @brief Parameterized constructor to initialize the point with specific coordinates.
	 * @param x The x-coordinate.
	 * @param y The y-coordinate.
	 * @param z The z-coordinate.
	 */
	Punkt3D( int x, int y, int z );

	/**
	 * @brief Copy constructor to create a new point as a copy of an existing Punkt3D object.
	 * @param copy The Punkt3D object to be copied.
	 */
	Punkt3D( const Punkt3D & copy );

	/**
	 * @brief Copy constructor to create a new point from a Punkt2D object by setting z to 0.
	 * @param copy The Punkt2D object to be copied.
	 */
	Punkt3D( const Punkt2D & copy );

	/**
	 * @brief Destructor for the Punkt3D class.
	 */
	~Punkt3D( void );

	// Operators
	/**
	 * @brief Assignment operator to copy the values of another Punkt3D object.
	 * @param rhs The Punkt3D object on the right-hand side of the assignment.
	 * @return Reference to the assigned Punkt3D object.
	 */
	Punkt3D &	operator=( const Punkt3D & rhs );

	/**
	 * @brief Equality operator to check if two Punkt3D objects are equal.
	 * @param rhs The Punkt3D object on the right-hand side of the comparison.
	 * @return True if the points are equal, false otherwise.
	 */
	bool		operator==( const Punkt3D & rhs ) const;

	/**
	 * @brief Inequality operator to check if two Punkt3D objects are not equal.
	 * @param rhs The Punkt3D object on the right-hand side of the comparison.
	 * @return True if the points are not equal, false otherwise.
	 */
	bool		operator!=( const Punkt3D & rhs ) const;

	/**
	 * @brief Addition operator to add two Punkt3D objects.
	 * @param rhs The Punkt3D object on the right-hand side of the addition.
	 * @return A new Punkt3D object representing the sum of the two points.
	 */
	Punkt3D		operator+( const Punkt3D & rhs ) const;

	/**
	 * @brief Compound addition operator to add another Punkt3D object to the current object.
	 * @param rhs The Punkt3D object on the right-hand side of the addition.
	 * @return Reference to the modified current Punkt3D object.
	 */
	Punkt3D	&	operator+=( const Punkt3D & rhs );

	/**
	 * @brief Subtraction operator to subtract another Punkt3D object from the current object.
	 * @param rhs The Punkt3D object on the right-hand side of the subtraction.
	 * @return A new Punkt3D object representing the difference of the two points.
	 */
	Punkt3D		operator-( const Punkt3D & rhs ) const;

	/**
	 * @brief Compound subtraction operator to subtract another Punkt3D object from the current object.
	 * @param rhs The Punkt3D object on the right-hand side of the subtraction.
	 * @return Reference to the modified current Punkt3D object.
	 */
	Punkt3D	&	operator-=( const Punkt3D & rhs );

	// set-ter and get-ter
	/**
	 * @brief Set the z-coordinate of the point.
	 * @param z The new z-coordinate.
	 */
	void	setZ( int z);

	/**
	 * @brief Set all coordinates of the point.
	 * @param x The new x-coordinate.
	 * @param y The new y-coordinate.
	 * @param z The new z-coordinate.
	 */
	void	setXYZ( int x, int y, int z );

	/**
	 * @brief Get the z-coordinate of the point.
	 * @return The z-coordinate of the point.
	 */
	int		getZ( void ) const;

	// IO-Methods
	/**
	 * @brief Read user input for x, y, and z coordinates of the point.
	 */
	void	input( void ); // userinput for x, y and z

	/**
	 * @brief Print the coordinates of the point in the terminal.
	 */
	void	print( void ) const;  // output in terminal "(x|y|z)"

	/**
	 * @brief Display information about the point.
	 */
	void	info( void ) const;

	// workmethods for points
	/**
	 * @brief Move the point by the coordinates of another Punkt3D object.
	 * @param movePoint The Punkt3D object representing the movement.
	 */
	void	move( const Punkt3D& movePoint );

	/**
	 * @brief Move the point by specified amounts along the x, y, and z axes.
	 * @param x_move The movement along the x-axis.
	 * @param y_move The movement along the y-axis.
	 * @param z_move The movement along the z-axis.
	 */
	void	move( int x_move, int y_move, int z_move );
};

/**
 * @brief Overloaded output stream operator to print the coordinates of a Punkt3D object.
 * @param output The output stream.
 * @param obj The Punkt3D object to be printed.
 * @return The output stream containing the printed Punkt3D object.
 */
std::ostream & operator<<( std::ostream & output, const Punkt3D & obj );

#endif
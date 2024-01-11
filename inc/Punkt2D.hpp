/*! \file
 *
 * @brief Declaration of the class Punkt2D: 2D points in a coordinate system
 */

/*! \class Punkt2D
    \brief Represents points in a 2-dimensional, integer coordinate system.

    This class provides functionalities for working with points in a 2-dimensional, integer coordinate system. 
    It includes basic operations such as addition, subtraction, and movement of points.

    \note For Windows, the code includes necessary headers and defines a macro 'WINDOWS'. 
          For Unix-like systems, it includes appropriate headers and defines a macro 'LINUX'.
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

#ifndef PUNKT2D_HPP
# define PUNKT2D_HPP

#include <stdio.h>
#include <limits.h>
//#include <string.h>

# define LF '\n'

/*! \var static bool Punkt2D::verbose
    \brief A static boolean variable to control verbosity for all instances of the class.
*/
class Punkt2D
{
protected:
	int	x;	/*!< X-coordinate of the point. */
	int	y;	/*!< Y-coordinate of the point. */
	static bool	verbose; /*!< Static boolean variable to control verbosity for all instances of the class. */

public:
	// Constructors
	/*!
		\brief Default constructor.
		
		Initializes the point with coordinates (0, 0).
	*/
	Punkt2D( void ); // always sets values to the origin

	/*!
		\brief Parameterized constructor.

		Initializes the point with the specified coordinates.
		
		\param x X-coordinate.
		\param y Y-coordinate.
	*/
	Punkt2D( int x, int y );

	/*!
		\brief Copy constructor.

		Creates a copy of the given Punkt2D object.
		
		\param copy The Punkt2D object to be copied.
	*/
	Punkt2D( const Punkt2D & copy );

	/*!
		\brief Destructor.

		Cleans up resources allocated for the Punkt2D object.
	*/
	~Punkt2D( void );

	// Operators
	/*!
		\brief Assignment operator.

		Assigns the coordinates of the given Punkt2D object to the current object.

		\param rhs The Punkt2D object on the right-hand side of the assignment.

		\return Reference to the current Punkt2D object after assignment.
	*/
	Punkt2D &	operator=( const Punkt2D & rhs );

	/*!
		\brief Equality operator.

		Checks if the coordinates of the current Punkt2D object are equal to the coordinates
		of the given Punkt2D object.

		\param rhs The Punkt2D object on the right-hand side of the comparison.

		\return True if the coordinates are equal, false otherwise.
	*/
	bool		operator==( const Punkt2D & rhs ) const;

	/*!
		\brief Inequality operator.

		Checks if the coordinates of the current Punkt2D object are not equal to the coordinates
		of the given Punkt2D object.

		\param rhs The Punkt2D object on the right-hand side of the comparison.

		\return True if the coordinates are not equal, false otherwise.
	*/
	bool		operator!=( const Punkt2D & rhs ) const;

	/*!
		\brief Addition operator.

		Adds the coordinates of the given Punkt2D object to the coordinates of the current object.

		\param rhs The Punkt2D object on the right-hand side of the addition.

		\return A new Punkt2D object with coordinates equal to the sum of the two points.
	*/
	Punkt2D		operator+( const Punkt2D & rhs ) const;

	/*!
		\brief Compound addition operator.

		Adds the coordinates of the given Punkt2D object to the coordinates of the current object.

		\param rhs The Punkt2D object on the right-hand side of the addition.

		\return Reference to the current Punkt2D object after addition.
	*/
	Punkt2D	&	operator+=( const Punkt2D & rhs );

	/*!
		\brief Subtraction operator.

		Subtracts the coordinates of the given Punkt2D object from the coordinates of the current object.

		\param rhs The Punkt2D object on the right-hand side of the subtraction.

		\return A new Punkt2D object with coordinates equal to the difference of the two points.
	*/
	Punkt2D		operator-( const Punkt2D & rhs ) const;

	/*!
		\brief Compound subtraction operator.

		Subtracts the coordinates of the given Punkt2D object from the coordinates of the current object.

		\param rhs The Punkt2D object on the right-hand side of the subtraction.

		\return Reference to the current Punkt2D object after subtraction.
	*/
	Punkt2D	&	operator-=( const Punkt2D & rhs );

	// set-ter and get-ter
	/*!
		\brief Sets the X-coordinate of the point.

		\param x New X-coordinate value.
	*/
	void	setX( int x );

	/*!
		\brief Sets the Y-coordinate of the point.

		\param y New Y-coordinate value.
	*/
	void	setY( int y );

	/*!
		\brief Sets both X and Y coordinates of the point.

		\param x New X-coordinate value.
		\param y New Y-coordinate value.
	*/
	void	setXY( int x, int y );

	/*!
		\brief Gets the X-coordinate of the point.

		\return X-coordinate value.
	*/
	int		getX( void ) const;

	/*!
		\brief Gets the Y-coordinate of the point.

		\return Y-coordinate value.
	*/
	int		getY( void ) const;

	// IO-Methods
	/*!
		\brief Takes user input for X and Y coordinates.

		Prompts the user to enter values for X and Y coordinates.
	*/
	void	input( void ); // userinput for x and y

	/*!
		\brief Prints the point coordinates to the console.

		Outputs the point coordinates in the format "(x|y)" to the console.
	*/
	void	print( void ) const; // output in terminal "(x|y)"

	/*!
		\brief Displays information about the point.

		Outputs the point coordinates and additional information to the console.
	*/
	void	info( void ) const;

	// workmethods for points
	/*!
		\brief Moves the point by the specified amount.

		\param movePoint The point by which the current point is moved.
	*/
	void	move( const Punkt2D & movePoint );

	/*!
		\brief Moves the point by the specified amounts along the X and Y axes.

		\param x_move Amount to move along the X-axis.
		\param y_move Amount to move along the Y-axis.
	*/
	void	move( int x_move, int y_move );

	// static Method for verbose
	/*!
		\brief Sets the verbosity status for all instances of the class.

		\param status The new verbosity status.
	*/
	static void	setVerbose( bool status );

	static bool getVerbose( void );

	// internal workmethods
	protected:
	/*!
		\brief Gets integer input from the user.

		\param prompt The prompt message to display to the user.

		\return User-inputted integer value.
	*/
	int	getUserIntInput( const char *prompt ) const;
};

/*!
    \brief Overloaded stream insertion operator for Punkt2D objects.

    \param output The output stream.
    \param obj The Punkt2D object to be printed.

    \return Reference to the output stream.
*/
std::ostream & operator<<( std::ostream & output, const Punkt2D & obj );

#endif
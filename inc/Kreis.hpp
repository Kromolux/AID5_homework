/*! \file
 *
 * @brief Declaration of the class Kreis: circle in a 2D coordinate system.
 */

/*! \class Kreis
	\brief for circles in a 2-dimensional, integer coordinate system
	uses the class Punkt2D
*/

#ifndef KREIS_HPP
# define KREIS_HPP

#include "./Punkt2D.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

class Kreis
{
public:
	Punkt2D	center;	/*!< The center point of the circle. */

protected:
	int		r;	/*!< The radius of the circle. */
	static bool	verbose; /*!< A static boolean flag for verbosity. */

public:
	// Constructors
	/*! \brief Default constructor.
		
		Sets the center to the origin (0, 0) and the radius to 0.
	*/
	Kreis( void ); // always sets values to the origin

	/*! \brief Parameterized constructor.

		\param x The x-coordinate of the center.
		\param y The y-coordinate of the center.
		\param r The radius of the circle.
	*/
	Kreis( int x, int y, int r );

	/*! \brief Copy constructor.

		\param copy The Kreis object to be copied.
	*/
	Kreis( const Kreis & copy );

	/*! \brief Destructor. */
	~Kreis( void );

	// Operators
	/*! \brief Assignment operator.

		\param rhs The Kreis object on the right-hand side of the assignment.
		\return A reference to the assigned Kreis object.
	*/
	Kreis & operator=( const Kreis & rhs );

	/*! \brief Equality operator.

		\param rhs The Kreis object on the right-hand side.
		\return True if the circles are equal, false otherwise.
	*/
	bool	operator==( const Kreis & rhs ) const;

	/*! \brief Inequality operator.

		\param rhs The Kreis object on the right-hand side.
		\return True if the circles are not equal, false otherwise.
	*/
	bool	operator!=( const Kreis & rhs ) const;

	/*! \brief Pre-Increment operator.

		Increases the radius of the circle by 1.
	*/
	Kreis &	operator++( void );

	/*! \brief Pre-Decrement operator.

		Decreases the radius of the circle by 1.
	*/
	Kreis &	operator--( void );


	/*! \brief Post-Increment operator.

		Increases the radius of the circle by 1.
	*/
	Kreis	operator++( int );

	/*! \brief Post-Decrement operator.

		Decreases the radius of the circle by 1.
	*/
	Kreis	operator--( int );

	// set-ter and get-ter
	/*! \brief Set the radius of the circle.

		\param r The new radius value.
	*/
	void	setR( int r );

	/*! \brief Set the center and radius of the circle.

		\param x The x-coordinate of the center.
		\param y The y-coordinate of the center.
		\param r The new radius value.
	*/
	void	setXYR( int x, int y, int r);

	/*! \brief Get the radius of the circle.

		\return The radius of the circle.
	*/
	int		getR( void ) const;

	/*! \brief Get the area of the circle.

		\return The area of the circle.
	*/
	double	getArea( void ) const;

	/*! \brief Get the circumference of the circle.

		\return The circumference of the circle.
	*/
	double	getScope( void ) const;

	// IO-Methods
	/*! \brief User input method.

		Prompts the user to input values for x, y, and r.
	*/
	void	input( void ); // userinput for x, y and r

	/*! \brief Print method.

		Outputs the circle's information in the format "(x|y)r".
	*/
	void	print( void ) const;  // output in terminal "(x|y)r"

	/*! \brief Information method.

		Outputs detailed information about the circle, including its center and radius.
	*/
	void	info( void ) const;

	// static Method for verbose
	//static void	setVerbose( bool status );

	// internal workmethods
protected:
	/*! \brief Internal method to get integer input from the user.

		\param prompt The prompt message for the user.
		\return The integer input from the user.
	*/
	int	getUserIntInput( const char *prompt ) const;
};

/*! \relates Kreis
	\brief Overloaded stream insertion operator for Kreis objects.

	\param output The output stream.
	\param obj The Kreis object to be printed.
	\return A reference to the output stream.
*/
std::ostream & operator<<( std::ostream & output, const Kreis & obj );
#endif
#pragma once

#include <sstream>
#include <stdexcept>


/// \brief Mixin for calculating the length (euclidian norm / distance) of a vector
// BONUS: Implement a mixin that calculates the length of a vector.
// Change the vector template to include this mixin.


/// \brief Template class for (math) vectors of variable length and type.
/// Works with all basic number types.
template<unsigned int Size, typename Element = float>
class Vector
{
public:

	// As always use const wherever meaningful!
	// This time you have to think about meaningful function signatures yourself.
	// However, the given documentation should make it clearly what these signatures should look like.
	// If your signature does not work with the given test-code but you're absolutely sure
	// that your signature fits the requirements, just alter the test-code accordingly! ;)


	/// Constructor that initializes all elements with zero.
	// Todo: Implement a constructor without any arguments that does exactly that.
	Vector(){
		for(unsigned int i = 0; i< Size; i++)
			elements[i] = 0;
	}
	/// Constructor that copies the vector
	// Todo: Implement a copy-constructor.
	Vector(const Vector<Size, Element>& toCopy){
		for(unsigned int i = 0; i< Size; i++)
			elements[i] = toCopy.elements[i];
	}
	/// Constructor that copies a vector of an arbitrary type with the same size.
	/// The type must be convertible by a static_cast to Element.
	// Todo: Implement a constructor that takes a reference to a vector with
	// an arbitrary element type. The right vector must have the same size - only
	// the element type differs.
	// Hint: Take the element type of the right vector as additional template argument
	// for the function.
template<typename aType>
Vector(const Vector<Size, aType>& toCopy){
	for(unsigned int i = 0; i< Size; i++)
		elements[i] = static_cast<Element>(toCopy.elements[i]);
}
	/// \brief Constructor that initializes the vector from a string.
	/// The string should contain values, separated by spaces. Uses stringstream for parsing.
	/// Will set all other elements to zero.
	// Todo: Implement a construction from std::string that fulfills the given documentation.
Vector(const std::string& s){
	std::stringstream stream(s);
	Element elem;
	for(unsigned int i = 0; i< Size; i++){
		elements[i] = stream >> elem ? elem : 0;
	}
}
	/// \brief Returns a string representation of the vector.
	// Todo: Implement a casting operator overload to std::string.
operator std::string() const{
	std::string str;
	for(unsigned int i = 0; i < Size; i++)
		str.append(std::to_string(elements[i]) + " ");
	return str;
}
	/// \brief Read access to an element.
	/// Checks for errors in debug mode - perform an error report of your choice
	// Todo: Implement a [] operator overload for reading!
const Element& operator[](const unsigned int i) const{
			#ifdef DEBUG
			if(i < 0 || i >= Size)
					 throw std::invalid_argument("Invalid Index!");
			#endif
			 return elements[i];
}

	/// \brief Write access to an element.
	/// Checks for errors in debug mode - perform an error report of your choice
	// Todo: Implement a [] operator overload for read/write access!
Element& operator[](const unsigned int i) {
		#ifdef DEBUG
		if(i < 0 || i >= Size)
				throw std::invalid_argument("Invalid Index!");
		#endif
			return elements[i];
	}
	/// \brief Adds to vectors of the same size and type element-wise.
	// Todo: Implement a + operator overload that takes a vector of same type and size.
Vector<Size, Element>& operator+(const Vector<Size, Element>& o){
		    Vector<Size, Element>* val = new Vector();
		    for(unsigned int i = 0; i < Size; i++)
		        val->elements[i] = elements[i] + o.elements[i];
	        return *val;
}

	/// \brief Simple template programming trick to make size accessible from outside.
	enum MetaInfo
	{
		SIZE = Size
	};

private:
	/// Intern data representation.
	Element elements[Size];
};

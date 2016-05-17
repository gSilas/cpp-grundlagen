#include "valuenode.hpp"


Node* Value::clone() const
{
	// Create a new instance with the same type and data. As you can see we
	// need to know the type ´Value´ that is why we cannot implement it
	// elsewhere.
	return new Value(m_val);
}

// TODO: evaluate implementation using string to int conversation functions
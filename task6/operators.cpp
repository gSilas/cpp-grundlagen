#include "operators.hpp"

#include <cassert>

// ************************************************************************* //
OpAdd::OpAdd(const Node& lhs, const Node& rhs)
{
	// TODO: implement
}

OpAdd::OpAdd(Node* lhs, Node* rhs)
{
	// TODO: implement
}

Node* OpAdd::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
	return new OpAdd(m_children[0]->clone(), m_children[1]->clone());
}


// TODO: the other methods


// ************************************************************************* //
OpMul::OpMul(const Node& lhs, const Node& rhs)
{
	// TODO: implement
}

OpMul::OpMul(Node* lhs, Node* rhs)
{
	// TODO: implement
}

Node* OpMul::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
	return new OpMul(m_children[0]->clone(), m_children[1]->clone());
}

// TODO: the other methods


// ************************************************************************* //
OpNegate::OpNegate(const Node& lhs)
{
	// TODO: implement
}


OpNegate::OpNegate(Node* rhs)
{
	// TODO: implement
}

Node* OpNegate::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
	return new OpNegate(m_child->clone());
}

// TODO: the other methods
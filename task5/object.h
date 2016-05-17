#pragma once
#include <iostream>
/// This object class serves basically as dummy for an "any object".
/// Later on we will learn different possibilities how we actually could store "anything" in here.
class Object
{
public:
	Object(const char* name);
	Object(const Object&);
  ~Object();

  /// Returns ID which was passed in the constructor.
  const char* GetName() const { return m_name; };
  /// Returns whether object is const or not
  const char* GetType() const { return "Const object"; };
  const char* GetType() { return "not const"; };
  /// Implementiert den angegebenen und die verwandten Operatoren
  bool operator==(Object& o)
  {
	  if (std::string(m_name) != std::string(o.GetName()))
		  return false;
	  return true;
  }

  Object& operator+=(Object& o) {
	  char* result = new char[strlen(m_name) + strlen(o.GetName()) + 1];
	  strcpy(result, m_name);
	  return Object(strcat(result, o.GetName()));
  }

private:

  char* m_name;

  // Here could be YOUR data!
};
/// Implementiert den angegebenen und die verwandten Operatoren
std::ostream& operator<< (std::ostream& stream, const Object&);
// implement < and > for dynamicobjectlist.sort()
bool operator< (const Object& o, const Object& o2);
bool operator> (const Object& o , const Object& o2);
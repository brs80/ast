#include "type.hpp"

#include <iostream>

static void
print_str(std::ostream& os, char const* str)
{
  os << str;
}

static void
print_ref(std::ostream& os, Ref_type const* t)
{
  os << "ref " << *t->get_referent_type();
}

void
print(std::ostream& os, Type const* t)
{
  switch (t->get_kind()) {
  case Type::bool_type:
    return print_str(os, "bool");
  
  case Type::int_type:
    return print_str(os, "int");
  
  case Type::ref_type:
    return print_ref(os, static_cast<Ref_type const*>(t));

  case Type::float_type:
    return print_str(os, "float");
  }
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  print(os, &t);
  return os;
}

static bool
equal_ref(Ref_type const* a, Ref_type const* b)
{
  return equal(a->get_referent_type(), b->get_referent_type());
}

bool
equal(Type const* a, Type const* b)
{
  if (a->get_kind() != b->get_kind())
    return false;

  switch (a->get_kind()) {
  case Type::bool_type:
    return true;
  
  case Type::int_type:
    return true;
  
  case Type::float_type:
    return true;
  
  case Type::ref_type:
    return equal_ref(static_cast<Ref_type const*>(a),
                     static_cast<Ref_type const*>(b));
  }
}

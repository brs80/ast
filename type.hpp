#pragma once

#include <iosfwd>

class Type;
class Bool_type;
class Int_type;
class Ref_type;
class Float_type;

class Type
{
public:
  enum Kind
  {
    bool_type,
    int_type,
    ref_type,
    float_type,
  };

protected:
  Type(Kind k) : m_kind(k) { }
  /// Constructs the type to have kind `k`.

public:
  Kind get_kind() const { return m_kind; }
  /// Returns the kind of the type.

private:
  Kind m_kind;
};

class Bool_type : public Type {
public:
  Bool_type()
    : Type(bool_type)
  { }
};

class Int_type : public Type
{
public:
  Int_type()
    : Type(int_type)
  { }
};

class Float_type : public Type
{
public:
  Float_type()
    : Type(float_type)
  { }
};

class Ref_type : public Type
{
public:
  Ref_type(Type* t)
    : Type(ref_type), m_ref(t)
  { }

  Type* get_referent_type() const { return m_ref; }

private:
  Type* m_ref;
};

// Operators

std::ostream& operator<<(std::ostream& os, Type const& t);

void print(std::ostream& os, Type const* t);

bool equal(Type const* a, Type const* b);

#pragma once

class Value
{
public:
  explicit Value(int n);

  int get_int() const;

  double get_float() const;

private:
  int m_value;
};

inline
Value::Value(int n)
  : m_value(n)
{ }

inline int
Value::get_int() const
{
  return m_value;
}

inline double
Value::get_float() const
{
  return m_value;
}


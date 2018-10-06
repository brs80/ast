#pragma once
#include <array>
#include <vector>

class Name;
class Type;
class Expr;
class Stmt;
class Printer;

struct Decl
{
public:
  enum Kind
  {
    prog_decl,
    obj_decl,
    ref_decl,
    fn_decl,
  };

protected:
  Decl(Kind k);

public:
  Kind get_kind() const { return m_kind; }

  bool is_object() const { return m_kind == obj_decl; }

  bool is_reference() const { return m_kind == ref_decl; }

  bool is_function() const { return m_kind == fn_decl; }

  virtual Name* get_name() const { return nullptr; }

  virtual Type* get_type() const { return nullptr; }

private:
  Kind m_kind;
};

inline
Decl::Decl(Kind k)
  : m_kind(k)
{ }

class Nullary_decl : public Decl
{
protected:
  Nullary_decl(Kind k);
};

inline
Nullary_decl::Nullary_decl(Kind k)
  : Decl(k)
{ }


class Kary_decl : public Decl
{
protected:
  Kary_decl(Kind k, std::initializer_list<Decl*> list);
  
  Kary_decl(Kind k, std::vector<Decl*> const& vec);
  
  Kary_decl(Kind k, std::vector<Decl*>&& vec);
};

inline
Kary_decl::Kary_decl(Kind k, std::initializer_list<Decl*> list)
  : Decl(k)
{ }

inline
Kary_decl::Kary_decl(Kind k, std::vector<Decl*> const& vec)
  : Decl(k)
{ }

inline
Kary_decl::Kary_decl(Kind k, std::vector<Decl*>&& vec)
  : Decl(k)
{ }


class Value_decl
{
protected:
  Value_decl(Name* n, Type* t);

public:
  Name* get_name() const { return m_name; }

  Type* get_type() const { return m_type; }

private:
  Name* m_name;

  Type* m_type;
};

inline
Value_decl::Value_decl(Name* n, Type* t)
  : m_name(n), m_type(t)
{ }

class Var_decl : public Value_decl
{
protected:
  Var_decl(Name* n, Type* t, Expr* e);

public:
  Expr* get_initializer() const { return m_init; }

private:
  Expr* m_init;
};

inline 
Var_decl::Var_decl(Name* n, Type* t, Expr* e)
  : Value_decl(n, t), m_init(e)
{ }

class Obj_decl : public Nullary_decl, public Var_decl
{
public:
  Obj_decl(Name* n, Type* t, Expr* e);

  Name* get_name() const override { return Var_decl::get_name(); }
  
  Type* get_type() const override { return Var_decl::get_type(); }  
};

inline
Obj_decl::Obj_decl(Name* n, Type* t, Expr* e)
  : Nullary_decl(obj_decl), Var_decl(n, t, e)
{ }


/// Represents declarations of the form `ref x : t = e`.
class Ref_decl : public Nullary_decl, public Var_decl
{
public:
  Ref_decl(Name* n, Type* t, Expr* e);

  Name* get_name() const override { return Var_decl::get_name(); }
  
  Type* get_type() const override { return Var_decl::get_type(); }  
};

inline
Ref_decl::Ref_decl(Name* n, Type* t, Expr* e)
  : Nullary_decl(ref_decl), Var_decl(n, t, e)
{ }


class Fn_decl : public Kary_decl, public Value_decl
{
public:
  Fn_decl(Name* n, Type* t, std::initializer_list<Decl*> list, Stmt* s);

  Fn_decl(Name* n, Type* t, std::vector<Decl*> const& vec, Stmt* s);
 
  Fn_decl(Name* n, Type* t, std::vector<Decl*>&& vec, Stmt* s);
  

  Name* get_name() const override { return Value_decl::get_name(); }
  

  Type* get_type() const override { return Value_decl::get_type(); }
 

  Stmt* get_body() const { return m_body; }

private:
  Stmt* m_body;
  /// The body of the function.
};

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::initializer_list<Decl*> list, Stmt* s)
  : Kary_decl(fn_decl, list), Value_decl(n, t), m_body(s)
{ }

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::vector<Decl*> const& vec, Stmt* s)
  : Kary_decl(fn_decl, vec), Value_decl(n, t), m_body(s)
{ }

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::vector<Decl*>&& vec, Stmt* s)
  : Kary_decl(fn_decl, vec), Value_decl(n, t), m_body(s)
{ }

class Prog_decl : public Kary_decl
{
public:
  Prog_decl(std::initializer_list<Decl*> list);

  Prog_decl(std::vector<Decl*> const& vec);
 
  Prog_decl(std::vector<Decl*>& vec);

};

inline
Prog_decl::Prog_decl(std::initializer_list<Decl*> list)
  : Kary_decl(prog_decl, list)
{ }

inline
Prog_decl::Prog_decl(std::vector<Decl*> const& vec)
  : Kary_decl(prog_decl, vec)
{ }

inline
Prog_decl::Prog_decl(std::vector<Decl*>& vec)
  : Kary_decl(prog_decl, vec)
{ }

void print(Printer& p, Decl const* d);

std::ostream& operator<<(std::ostream& os, Decl const& d);

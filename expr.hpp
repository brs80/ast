#pragma once

class Type;
class Decl; 

struct Expr {
public:
    enum Kind {
    bool_lit,
    int_lit,
    float_lit,
    id_expr,
    add_expr,
    sub_expr,
    mul_expr,
    div_expr,
    rem_expr,
    neg_expr,
    rec_expr,
    eq_expr,
    ne_expr,
    lt_expr,
    gt_expr,
    le_expr,
    ge_expr,
    cond_expr,
    and_expr,
    or_expr,
    not_expr,
    call_expr,
	};

  Expr(Kind k, Type* t);

  Kind get_kind() const { return m_kind; }

  Type* print_type() { 
		return this->m_type;
  }

  Kind m_kind;

  Type* m_type;
};

struct Nullary_expr : public Expr { 
protected:
	Nullary_expr(Kind k, Type* t) : Expr(k, t) { }
};

struct Unary_expr : public Expr {
protected:	
	Unary_expr(Kind k, Type* t, Expr* e) : Expr(k, t) { }
};

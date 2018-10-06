#pragma once

class Type;

class Expr {
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

protected:
  Expr(Kind k, Type* t);

public:
  Kind get_kind() const { return m_kind; }
  /// Returns the kind of expression.

  Type* print_type() { 
		return this->m_type;
  }

private:
  Kind m_kind;

  Type* m_type;
};

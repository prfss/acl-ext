
Matrix
#######

和・差・積・累乗などの演算を備えた行列クラスです

:doc:`matrix_verification`

.. code-block:: cpp

 template <typename T, T(*add)(T,T), T(*mul)(T,T), T(*zero)(), T(*one)(), bool has_subtraction = false> Matrix

``T`` は要素の型です. ``add``, ``zero`` は加算とその単位元, ``mul``, ``one`` は乗算とその単位元を表します. 
また ``has_subtraction == true`` の時, ``operator-`` を定義します.

制約
****
- :math:`\mathrm{add}(x,\text{zero}()) = \mathrm{add}(\text{zero}(),x) = x`
- :math:`\mathrm{mul}(x,\text{one}()) = \mathrm{mul}(\text{one}(),x) = x`

メンバ
******

コンストラクタ
==============
.. code-block:: cpp

 matrix(int n, int m, T init = zero()) // (1)
 matrix(const vector<vector<T>> list) // (2)

1. 要素を :math:`\mathrm{init}` で初期化した :math:`n \times m` 行列を返します.
2. :math:`(i,j)` 成分が :math:`\mathrm{list}[i][j]` であるような行列を返します.

制約
----
1. :math:`n,m \ge 1`
2. * :math:`\mathrm{list}[i] (0 \le i \lt \mathrm{list.size}())` の長さはすべて等しい 
   * リストは空ではない

identity
=========
.. code-block:: cpp

 static Matrix<T> identity(int n)

:math:`n` 次の単位行列 :math:`I_n` , すなわち

.. math::

   (I_n)_{ij} =
   \begin{cases}
   \mathrm{one}() & (i = j) \\
   \mathrm{zero}() & (\text{それ以外}) \\
   \end{cases}

を返します.

row_vector
==========
.. code-block:: cpp

 static Matrix row_vector(vector<T> row)

column_vector
=============
.. code-block:: cpp

 static Matrix column_vector(vector<T> col)

map
===
.. code-block:: cpp

 Matrix map(function<T(T,int,int)> f) const

transpose
=========
.. code-block:: cpp

 Matrix transpose() const


operator+
=========
.. code-block:: cpp

 Matrix operator+(const Matrix &other)

operator-
=========
.. code-block:: cpp

 Matrix operator-(const Matrix &other)

operator*
=========
.. code-block:: cpp

 Matrix operator*(const Matrix &other)

operator^
=========
.. code-block:: cpp

 Matrix operator^(ll x)

この行列を :math:`x` 乗した行列を返します.
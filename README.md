# Martist

Mathematical artist is a program that generate random *artistic* pictures using mathematical expression taking `x` and `y` positions as value.

# Expressions

- x - x
- y - y
- sin( $\pi \times$ *expr*) - s
- cos( $\pi \times$ *expr*) - c
- avg(*expr*, *expr*) - a
- product(*expr*, *expr*) - x

The expression formed is represented in a tree such that 

**xys*c** is $cos(\pi ( x \times sin(\pi y)))$

<p align="center">
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/expression.pdf?raw=true" />
  <br>
  <em style="text-align:center">(a) is the original image, (b) crushed's image (naive), (c) crushed's image with slimming</em>
</p>
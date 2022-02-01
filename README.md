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
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/tree.png?raw=true" />
  <br>
  <em style="text-align:center">Tree representation</em>
</p>

<img src="https://latex.codecogs.com/svg.latex?\Large&space;cos(\pi (x \times sin(\pi y)))" title="\Large cos(\pi (x \times sin(\pi y)))" />

The expression will be randomly generated for each RGB color by given the maximum depth for each of them

# How to use it?

`./run.sh`

The follow instruction on the prompt

The PNM image can then be converted to PNG by using the following command
`pnmtopng -phys [width] [height] 0 out.pnm > out.png`

# Example

<p align="center">
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/out1.png?raw=true" />
  <br>
  <em style="text-align:center">RGB depth: 5, dimension 1000x1000</em>
</p>


<p align="center">
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/out2.png?raw=true" />
  <br>
  <em style="text-align:center">RGB depth: 3, dimension 1000x1000</em>
</p>

<p align="center">
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/out3.png?raw=true" />
  <br>
  <em style="text-align:center">RGB depth: 10, dimension 1000x1000</em>
</p>
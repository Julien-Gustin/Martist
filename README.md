# Martist

Mathematical artist is a program that generate random *artistic* pictures using mathematical expression taking `x` and `y` positions as value.

# Expressions

- x - x
- y - y
- sin(pi * *expr*) - s
- cos(pi * *expr*) - c
- avg(*expr*, *expr*) - a
- product(*expr*, *expr*) - X

The expression formed is represented by a traversal expression. Exemple

**cos(pi(x * sin(pi y)))** => **xys*c** 

<p align="center">
  <img src="https://github.com/Julien-Gustin/Martist/blob/master/figures/tree.png?raw=true" />
  <br>
  <em style="text-align:center">cos(pi(x * sin(pi y)))</em>
</p>

The expression will be randomly generated for each RGB color by given the maximum depth for each of them

# How to use it?

```sh
./run.sh
```

Then follow instructions on the prompt

The PNM image can then be converted to PNG by using the following command
```sh
pnmtopng -phys [width] [height] 0 out.pnm > out.png
```
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
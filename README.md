
# Automata
configurable 'life-like' cellular automata in c/sdl

### Screenshots
######Conway's Game of Life `(-b23 -s3)`
![Standard Game of Life](/docs/screenshots/life.jpg?raw=true "Standard Game of Life")

######Life without Death `(-b3 -s123456780)`
![Life without Death Variation](/docs/screenshots/death.jpg?raw=true "Life without Death Variation")

### Compilation and Usage
```
$ git clone https://github.com/anavros/automata.git .
$ make
$ ./main [optional arguments]
```
While the simulation is running, `Space` pauses, `R` resets the seed, and `Q`,
`Esc` or `Capslock` exits the program. The board is toroidal, so any cells that
move past the boundary will show up on the other side unaffected. Cells that are
alive glow white, and each cell, dead or alive, glows a small amount extra when
they have more live neighbors. This produces a luminescent effect.

### Console Arguments
```
-b --birth [string of numbers 0-8]
================================================================================
Number of live neighbors an empty cell requires to be born.
Ex: -b238 -- a cell will turn on if it has 2, 3, or 8 live neighbors.
Numbers do not have to be in order -- -b823 is perfectly equivalent.

(Due to a bug in the current implimentation, '0' will be truncated if it is the
first digit. For now, simply add '0' at the end or in the middle of the string.)

-s --survival [string of numbers 0-8]
================================================================================
The number of live neighbors a live cell needs to continue living.
Ex: -s3690 -- a cell will stay on if it has 3, 6, 9, or 0 neighbors.

-f --frames-per-second [int]
================================================================================
Number of steps/graphical updates to make per second.
FPS is tied with simulation speed, so higher framerates beget faster simulations.
Ex: ./main -f 24

-r --seed-density [int]
================================================================================
Density of randomly-generated initial seed.
Higher values correlate to less dense boards.
Ex: ./main -r 200 -- 1 in 200 pixels will be seeded; -r 2 -- 1 in 2.

-c --cell-size [int]
================================================================================
Size of each cell in pixels. Cells are always square.
The screen will automatically adjust to approximately 800x800px.
This option is purely graphical, although it does change the size of the board.
Ex: ./main -c 4
```

## Interesting Presets
 Settings            | Description
---------------------|----------------------
`-b3 -s23`           | original game of life
`-b3 -s123456780`    | life without death
--------------------------------------------

See [wikipedia](https://en.wikipedia.org/wiki/Life-like_cellular_automaton) for more examples of life-like automata.











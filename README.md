
# Automata
configurable 'life-like' cellular automata in c/sdl

### Description
A [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) (plural: automata)
is a discrete mathematical simulation that follows simple rules. It takes place
on a two-dimensional board split into cells, where each cell is considered alive
(on), or dead (off). The game progresses in steps: for each step, each cell
counts the number of live neighbors it has and compares it to the established
birth (-b) and survival (-s) rules. If the cell is dead, and its number of live
neighbors is contained in the birth parameters, then the cell will be 'born',
and turn on. Likewise, if a cell is already alive, and its neighbor count is
within the survival parameters, it will stay alive; otherwise, it will die, and
turn off. The birth and survival parameters are set by you, the user, at the
beginning of each simulation.

This particular board is
[toroidal](https://en.wikipedia.org/wiki/Wraparound_(video_games)), so any cells
that move past the boundary will reappear immediately on the other side,
unaffected.

Graphically, live cells appear white, and dead cells dark grey. There is a small
glowing effect for each cell that intensifies with each live neighbor it has.

### Screenshots
######Conway's Game of Life `(-b3 -s23)`
![Standard Game of Life](/docs/screenshots/life.jpg?raw=true "Standard Game of Life")

######Life without Death `(-b3 -s123456780)`
![Life without Death Variation](/docs/screenshots/death.jpg?raw=true "Life without Death Variation")

### Compilation and Usage
```
$ git clone https://github.com/anavros/automata.git .
$ make
$ ./main [optional arguments]
```
Once the simulation is running, `Space` pauses, `R` resets the seed, and `Q`,
`Esc`, or `Capslock` exits the program.

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
`-b378 -s12456780`   | custom personal favorite
--------------------------------------------

See [wikipedia](https://en.wikipedia.org/wiki/Life-like_cellular_automaton) for
more examples of life-like automata.











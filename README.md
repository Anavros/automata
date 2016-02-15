
# Automata
configurable 'life-like' cellular automata in c/sdl

(picture)

## Usage
```
./main -b3 -s23
```

## Installation

## Details
#### Console Arguments
```
-b --birth-rate
number of live neighbors an empty cell requires to be born

-s --survival-rate
number of live neighbors a live cell needs to continue living

-f --frames-per-second
number of steps/graphical updates to make per second
fps is tied with simulation speed, so higher framerates cause higher simulation speed

-r --seed-density
density of randomly-generated initial seed
higher values correlate to less dense boards
```

#### Interesting Presets
 Settings            | Description
---------------------|----------------------
`-b3 -s23`           | original game of life
`-b3 -s123456780`    | life without death
--------------------------------------------

See [wikipedia](https://en.wikipedia.org/wiki/Life-like_cellular_automaton) for more examples of life-like automata.











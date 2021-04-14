# Filler
Second project of algorithm branch in 42 school curriculum in which you create a player for two players' algorithmic faceoff to fill the given board with given pieces. Player takes the map and piece they are given and then return the coordinates to which it wants the vm to put the piece. Both players take their turns to do this and the game stops when they both are unable to do so. One piece placed to the board equals one point and the winner is the player with most points at the end of the game.

![](filler.gif)

### Usage
```
make && cd resources/ && ./filler_vm_old -p1 ../mkarkaus.filler -p2 players/grati.filler -f maps/map01
```
** Note: some of the players provided in `resources/players/` folder don't work on Linux because they have been compiled in MacOS **

### Options of the filler_vm:
```
-p1 <player executable> indicates player number one
-p2 <player executable> indicates player number two
-f  indicates the map
```

## VM
In `resources`-folder there is the filler_vm which is the game executable itself. The VM takes one to two players and a map as arguments and passes said map to the player executables on their turn. VM also generates a piece which is passed along with the current map to the player next in turn. The VM takes the coordinates which the player gives, places the piece on the board and passes the updated map and a new piece for the next player.

There is also a filler_vm_old in the same folder which is older version of the vm and it is more stable and works better overall.

### Piece
Pieces that the vm generates consist of a line of piece's dimensions and then the actual piece:
```
Piece 4 7:
.......
.......
.**....
.***...
```
The `.` character indicates empty space and `*` characters the actual piece. The `.` are only useful in keeping the piece's shape intact.

### Map
In map player 1's pieces are as `O` characters and the pieces of player 2 are as `X` characters. There can also be seen same characters but in lowercase which indicates the last 
piece said player laid down.

This is how the map file's content looks like:
```
.................
.................
.................
.................
.................
.................
.................
.................
..O..............
.................
.................
.................
..............X..
.................
.................
```

This is what the map looks like when the vm passes it to a player at some point of the game:
```
Plateau 15 17:
    01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..OOOOO..........
009 ......OOO........
010 ........OOO...xxX
011 ...............XX
012 .............XXXX
013 .................
014 .................
```
The first line, just like in piece, is the dimensions of the map.

### Player
Player is a executable that is passed to the vm as a argument. There are couple restrictions on where the player can place it's piece on the board and they are:

- Exactly one block of the piece must be on block of a piece placed previously by that same player
- The Piece can't go over the dimensions of the board (the dots (`.`) of the piece can go over bounds)

#### Algorithm
My players algorithm starts with creating a heatmap of the map it has been passed. The heatmap is created by creating similarly sized map but this time with integers. Then in places of the opponents blocks we place `0`. Next we set every integer that hasn't yet been set surrounding the zeroes as `1` and after that every integer that hasn't been set surrounding the ones as `2` and so on.

In case the map looks like the one you saw at the end of 'Map'-section and my player is player 1 (with uppercase letter 'O') the heatmap would look like this:

```
 13 12 12 11 10 10 10 10 10 10 10 10 10 10 10 10 10
 13 12 11 11 10  9  9  9  9  9  9  9  9  9  9  9  9
 13 12 11 10 10  9  8  8  8  8  8  8  8  8  8  8  8
 13 12 11 10  9  9  8  7  7  7  7  7  7  7  7  7  7
 13 12 11 10  9  8  8  7  6  6  6  6  6  6  6  6  6
 13 12 11 10  9  8  7  7  6  5  5  5  5  5  5  5  5
 13 12 11 10  9  8  7  6  6  5  4  4  4  4  4  4  4
 13 12 11 10  9  8  7  6  5  5  4  3  3  3  3  3  3
 13 12 11 10  9  8  7  6  5  4  4  3  2  2  2  2  2
 13 12 11 10  9  8  7  6  5  4  3  3  2  1  1  1  1
 13 12 11 10  9  8  7  6  5  4  3  2  2  1  0  0  0
 13 12 11 10  9  8  7  6  5  4  3  2  1  1  1  0  0
 13 12 11 10  9  8  7  6  5  4  3  2  1  0  0  0  0
 13 12 11 10  9  8  7  6  5  4  3  2  1  1  1  1  1
 13 12 11 10  9  8  7  6  5  4  3  2  2  2  2  2  2
```

As you can see the numbers increase the further we go from enemy blocks. My algorithm tries to get next to the other player's pieces and corner it by placing all the pieces right beside opponent's. After creating the heatmap the rest of the task is relatively easy since we can just follow the numbers in the direction of the smaller ones.

The algorithm tries to fit the piece in every valid coordinate and adds the numbers of the heatmap which are caught under the piece. This sum is the number that determines which coordinate is the best to put the piece on. In our case smaller the better.

After my program has decided the coordinate based on the sum of the numbers it returns only the coordinates to the vm after which my player's turn has been concluded.

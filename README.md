# NBA Team Guessing Game

A terminal-based guessing game where you try to identify a mystery NBA team in 6 guesses. After each wrong guess, you get hints comparing your guess to the answer — conference, division, founding year, championships, and team colors.

## How to Play

1. Compile and run:
   ```bash
   g++ -g -Wall main.cpp game.cpp Hint.cpp -o game && ./game
   ```
2. Type an NBA team name exactly (e.g. `Golden State Warriors`)
3. Use the hints to narrow it down — you have 6 attempts

## Hints

Each wrong guess reveals 5 clues:
- **Conference** — same conference or which one the answer is in
- **Division** — same division or which one the answer is in
- **Founded** — whether the answer was founded earlier or later
- **Championships** — whether the answer has more or fewer titles
- **Colors** — how many team colors match

## Tech

Written in C++ using inheritance and polymorphism — each hint type is a subclass of a base `Hint` class.

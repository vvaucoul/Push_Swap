# Push_Swap

This project involves sorting a list of numbers using only 2 stacks and some actions.

- **sa**: Swap the first two numbers of stack A
- **sb**: Swap the first two numbers of stack B
- **ss**: Swap the first two numbers of stacks A and B
- **ra**: Turns the A stack up 
- **rb**: Turns the B stack up 
- **rr**: Turns stacks A and B upwards 
- **rra**: Turns A stack down 
- **rrb**: Turns B stack down 
- **rrr**: Turns stacks A and B downwards 
- **pa**: Sends the first number from stack B to stack A
- **pb**: Sends the first number from stack A to stack B

# Content 
- A visualizee to see the stack status for each action.
- A tester for the push_swap project !

I used a custom algorithm I named "Hunter Sort".

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Push_Swap && cd Push_Swap
```

- Compilation
```bash
make
```

# Visualizer

To do this visualizer, I used termcaps library.

![Animation](https://user-images.githubusercontent.com/66129673/198682652-2a392efc-f8f5-4773-91c7-8eb3bd3730c9.gif)

## Project

- Launch Push Swap
```bash
ARG="-1 4 3 0 -4" ; ./push_swap $ARG | ./checker $ARG
```

> ARG: list of numbers

You can easily generate random number with the file **generate_random_numbers.c**

- Generate Random Numbers
```bash
make random && ./random_nbr [Number of Numbers] [Min Value] [Max Value]
```

Usage :
- [1] - Nb numbers 		
- [2] - Min Value
- [3] - Max Value

Available flags:
- **c**: Display visualizer
- **v**: Display Last stack action


## Ressources

- [Push Swap Medium](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

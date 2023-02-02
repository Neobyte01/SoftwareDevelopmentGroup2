# Text adventure game

![build](https://github.com/Neobyte01/SoftwareDevelopmentGroup2/actions/workflows/test.yml/badge.svg)

A text-based rougelite (played from the CLI) where the player plays one of several characters stranded on a spaceship infested with monsters, with the end goal of escaping.
The player will be able to traverse the ship by moving from room to room (grid-based system), and different rooms will have contextually appropriate options to interact with. The player will also be able to gather items/equipment which enables new approaches to problems faced during the escape. The monsters will vary depending on what part of the ship they inhabit and their behaviour will also be different depending on type of monster (Some may be territorial and only patrol a particular part of the map, while others may relentlessly hunt the player).

---

## Language and build system
The program is to be built in C and uses no framework to allow the creation of a game. Simply put we're using the input and output functionality built into stdio.h for all user interaction. We are using make as our build system of choice to allow easy use of multiple targets assigned to different functions while developing.

## Installation instructions

### Windows
First we'll need to install some dependencies manually which are used either to install other dependencies via a command line or do some specific function while developing the project.

Install these first:

- **Chocolatey** - Install from [chocolatey.org](https://chocolatey.org/install). Powershell must be run in administrator.
- **Python** - Install from [python.org](https://www.python.org/downloads/). Remember to set it to add binaries to environment variables.
- **Indent** - Install from [sourceforge.net](https://sourceforge.net/projects/gnuwin32/) and then add C:\Program Files (x86)\GnuWin32\bin to PATH in your environment variables.

and then run:
```
$ choco install python make mingw
$ pip install gcovr
$ git clone https://github.com/Neobyte01/SoftwareDevelopmentGroup2
$ cd SoftwareDevelopmentGroup2
$ make setup
```
from a terminal. If "make setup" tells you that a directory called "bin" already exists, just ignore it. From there you can run the program via make (described in our running instructions).

### Mac
Installing on macos requires only homebrew to be manually installed. With it we can install everything else we'll need from the terminal.

Install this first:
- **Homebrew** - Install from [brew.sh](https://brew.sh/).

and then run:

```
$ brew install make llvm gnu-indent
$ git clone https://github.com/Neobyte01/SoftwareDevelopmentGroup2
$ cd SoftwareDevelopmentGroup2
$ make setup
```

from a terminal. If "make setup" tells you that a directory called "bin" already exists, just ignore it. From there you can run the program via make (descibed in our running instructions).

## Running instructions

The make instructions (targets) for handling this project. Works for both Macos and Windows.

*Compile and run program*
```
$ make run
```

*Compile and run tests*
```
$ make test
```

*Generate information about code coverage for performed tests*
```    
$ make coverage
```

*Run linter*
```
$ make lint
```

---

## Contributors
| Contributors   | Handle                     |
| -------------- | -------------------------- |
| Emil Wagman    | Neobyte01, Orpose Group AB |
| Isac Gustafson | Aaetpio                    |
| Sami Noroozi   | potatohunter69             |
| Darina Larsen  | darii99                    |
| Erik Wigert    | ErkWWW                     |

## Kanban Board
The link to the [kanban board](https://github.com/users/Neobyte01/projects/1/views/1) we use for project planning and overall management can be found [here](https://github.com/users/Neobyte01/projects/1/views/1).

## Declaration
I, Emil Wagman, declare that I am the sole author of the content I add to this repository. <br>
I, Erik Wigert, declare that I am the sole author of the content I add to this repository. <br>
I, Darina Larsen, declare that I am the sole author of the content I add to this repository. <br>
I, Sami Noroozi, declare that I am the sole author of the content I add to this repository. <br>
I, Isac Gustafsson, declare that I am the sole author of the content I add to this repository. <br>

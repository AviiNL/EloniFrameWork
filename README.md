EloniFramework
=

C++ Framework for linux with sqlite3 database management

### Requirements

##### Libraries

- boost
    - boost_system
    - boost_filesystem
- crypt
- sqlite3

##### Compiler
This library is created by the c++11 standards.

### Installation

Clone this repository to your development environment and cd into it
`cd EloniFramework`
run `./configure && make` to build the library
To install the library run `sudo make install`

Make sure that the library can be linked with.
By default it will be installed in `/usr/local/lib` and `/usr/local/include` 

Add `/usr/local/lib` to `/etc/ld.so.conf` and run `sudo ldconfig` as root

### Usage

Create a new cpp file eg. `main.cpp`

``` c++
#include <EloniFramework.h>

int main() {
	EloniFramework::Configuration()->setConfig("identifier", "somevalue");
	std::cout << EloniFramework::Configuration()->getConfig("identifier") << std::endl;
	std::cout << EloniFramework::Shell::Execute("whoami");
	return 0;
}
```

##### Compile the code
To build against the EloniFramework library you need the following parameters

``` bash
g++ -c -Wall -std=c++11 -I./inc -T/usr/local/include main.cpp
g++ -o example main.o -leloniframework -lboost_system -lboost_filesystem -lcrypt -lsqlite3
```
Run it: `./example`

Also take a look at the provided example in `example/` this shows all the functions the framework has.

This code should show `somevalue` on screen when ran.

###### Note that I do not include any of the standard libraries, as the EloniFramework takes care of that (see inc/Includes.h for more information). This is probably very bad, change if you wish, I just find it very useful.
###### If the above example does not work for you, please contact me and I will attempt to help and or fix any issues, have not tested it (yet) on a clean linux machine

##### Sidenotes for ShellManager
The ShellManager is created with the intent to run some shell commands as a different user.
To use the user swiching methods the program itself needs to be owned by root and have the sticky bit on.

``` bash
sudo chown root:root example
sudo chmod +s exmaple
./example
```
I know this is not regular behaviour for a program, but I was unable to figure out a 'safer' way to implement this functionality. If you know a way, please let me know.

***

#### If you have any questions or suggestions, don't hesitate to contact me.

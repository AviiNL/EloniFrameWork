SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./inc

EXTINC = -I/usr/local/include
EXTLIB = -leloniframework -lboost_system -lboost_filesystem -lcrypt -lsqlite3

CC = g++

EXEC = drushgui
SRC = $(wildcard $(SRCDIR)/*.cpp main.cpp)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))

CXX_FLAGS =-Wall -std=c++11 -I$(INCDIR) $(EXTINC) -Wall

all: link

.PHONY : compile
compile: $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CXX_FLAGS) $< -o $@

$(OBJDIR)/main.o: main.cpp
	$(CC) -c $(CXX_FLAGS) $< -o $@

.PHONY : link
link: compile
	$(CC) -o $(BINDIR)/$(EXEC) $(OBJ) $(EXTLIB)
	@chown root:root $(BINDIR)/$(EXEC)
	@chmod +s $(BINDIR)/$(EXEC)
	@echo
.PHONY : clean
clean:
	@find -type f -name "$(EXEC)" -delete
	@find -type f -name "*.o" -delete
	@find -type f -name "*~" -delete
	@echo Cleanup Complete.
install: compile
	@mkdir -p /opt/drushgui/
	@cp $(BINDIR)/$(EXEC) /opt/drushgui/$(EXEC) -rf
	@chown root:root /opt/drushgui -R
	@chmod +s /opt/drushgui/$(EXEC)
	@echo Install Complete.
	

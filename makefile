CC=g++
CPPFLAGS = -g -Wall -std=c++17
LDFLAGS = -lgtest -lgtest_main
EXECUTABLE=linked_list_test
INCLUDES = -I/usr/include/gtest -I/usr/include
SRCDIR=src
OBJDIR=obj

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(OBJDIR) $(OBJDIR)/$(EXECUTABLE)

$(OBJDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)/*.o $(OBJDIR)/$(EXECUTABLE)

rebuild: clean all

run: $(OBJDIR)/$(EXECUTABLE)
	./$(OBJDIR)/$(EXECUTABLE)

rebuild_and_run: rebuild run
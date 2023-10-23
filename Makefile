# Variables
CXX = clang++
CXXFLAGS = -O2 -g -Wall -Wextra
OBJDIR = ~/local/obj
BINDIR = ~/local/bin
SOURCE = markdown.cpp
OBJECT = $(OBJDIR)/markdown.o

# Rule for creating the object file
$(OBJECT): $(SOURCE)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule for creating the binary
$(BINDIR)/my_program: $(OBJECT)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean rule
clean:
	rm -f $(OBJECT) $(BINDIR)/my_program

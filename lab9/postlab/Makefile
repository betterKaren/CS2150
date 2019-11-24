# Yu Du, yd2am
# Makefile
# 2019.11.21

# Defines the C compiler we'll be using
CXX	= clang

# Defines the flags we'll be passing to the C compiler
CXXFLAGS	= -Wall


# All of the .o files for our program
OFILES	= linkedlist.c

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~
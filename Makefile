#
# Created by makemake (Darwin Feb 22 2012) on Wed Mar  7 00:20:20 2012
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c

########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb -Wall -ansi -pedantic
CFLAGS =	-ggdb -Wall -ansi -pedantic
BINDIR =.
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	player.cpp position.cpp solver.cpp takeaway.cpp takeawayboard.cpp takeawaysolver.cpp
C_FILES =	
S_FILES =	
H_FILES =	board.h defines.h player.h position.h solver.h takeawayboard.h takeawaysolver.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	player.o position.o solver.o takeawayboard.o takeawaysolver.o 

#
# Main targets
#

all:	${BINDIR}/takeaway 

${BINDIR}/takeaway:	takeaway.o $(OBJFILES)
	@mkdir -p ${BINDIR}/
	$(CXX) $(CXXFLAGS) -o ${BINDIR}/takeaway takeaway.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

player.o:	board.h defines.h player.h position.h solver.h
position.o:	board.h defines.h position.h solver.h
solver.o:	board.h defines.h position.h solver.h
takeaway.o:	board.h defines.h player.h position.h solver.h takeawayboard.h takeawaysolver.h
takeawayboard.o:	board.h defines.h position.h solver.h takeawayboard.h
takeawaysolver.o:	board.h defines.h position.h solver.h takeawaysolver.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) takeaway.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf ${BINDIR}/takeaway 

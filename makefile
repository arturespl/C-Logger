OUT		 = $(shell basename $(CURDIR)).out
CC 		 = g++

CPPFLAGS += -g
CPPFLAGS += -Iinc

INCDIR	 	= inc/
OBJDIR	 	= obj/
SRCDIR	 	= src/
INSTALLDIR	= /usr/local/bin/

SOURCES	= $(SRCDIR)*


OBJECTS += $(SOURCES:%.cpp=$(OBJDIR)%.o)

#INCLUDES += $(SOURCES:%.cpp=$(OBJDIR)%.hpp)


#################################################################################

__Start__: $(SOURCES) $(OUT)


$(OUT): $(OBJECTS)
	$(CC) -o $@ $(CPPFLAGS) $(OBJECTS) main.cpp 

$(SOURCES): $(INCDIR)$(@:%.cpp=%.hpp) $(SRCDIR)$@
	$(CC) -c $(CPPFLAGS) $@ -o $(OBJDIR)$(@:$(SRCDIR)%.cpp=%.o)

test:
	@$(MAKE) ${OUT} -B
	@$(MAKE) r

clean: 
	rm -f $(OUT) $(OBJDIR)*

r:
	./${OUT}	

gdb:
	@$(MAKE) ${OUT}
	@$(MAKE) r
	gdb ${OUT}

install:
	@$(MAKE) ${OUT}
	sudo mv ${OUT} ${INSTALLDIR}
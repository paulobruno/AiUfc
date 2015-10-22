# PAULO BRUNO DE SOUSA SERAFIM
# 2015, Fortaleza - CE, Brasil


OBJDIR  = .objs

CC		= g++
LFLAGS	= -flto
CFLAGS	= -c

ifeq ($(mode),debug)
	CFLAGS	+= -g -O0 -Wall -Wextra -DDEBUG -DWARNINGS -DERRORS -DLOGS
else ifeq ($(mode),devt)
	CFLAGS	+= -g -O2 -Wall -Wextra -DLOGS -DWARNINGS -DERRORS
else
	mode=release
	CFLAGS	+= -O2 -s
endif

RM		= rm -rf

EXEC 	= exec


SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))


all: build $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@ $(LFLAGS) 

$(OBJECTS): $(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@
	
build:
	@mkdir -p $(OBJDIR)
	
.PHONY: clean cleanall

clean:
	@$(RM) $(OBJDIR) *.o *~

cleanall:
	@$(RM) $(EXEC) $(OBJDIR) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make     : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all : O mesmo que make."
	@echo "# "
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README (todo)."
	@echo "# "

# Nome do executável final
TARGET = supertrunfo

# Compilador
CC = gcc

# Flags de compilação
# -Wall: Mostra todos os avisos (warnings)
# -Iinclude: Informa ao compilador para procurar arquivos .h na pasta 'include'
# -g: Adiciona informações de debug
CFLAGS = -Wall -g -Iinclude

# Pastas
SRCDIR = src
INCDIR = include

# Encontra todos os arquivos .c na pasta src
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Gera uma lista de arquivos objeto (.o) correspondentes aos .c
OBJECTS = $(SOURCES:.c=.o)

# Regra principal: o que fazer quando você digita 'make'
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra para compilar cada arquivo .c em um .o
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

.PHONY: all clean

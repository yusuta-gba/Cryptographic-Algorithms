# Variablen definieren
CXX = g++
CXXFLAGS = -Wall -Wextra -O2
TARGET_INIT = initializer
TARGET_PERM = permutation
SRCS_PERM = permutation.cpp main.cpp
OBJS_PERM = $(SRCS_PERM:.cpp=.o)
HEADERS = permutation.h

# Standard-Target: Baut und führt alles der Reihe nach aus
all: $(TARGET_INIT) run_initializer $(TARGET_PERM)

# 1. Kompilieren des Initializers
$(TARGET_INIT): initializer.cpp
	$(CXX) $(CXXFLAGS) initializer.cpp -o $(TARGET_INIT)

# 2. Ausführen des Initializers (wird nur getriggert, wenn all aufgerufen wird)
run_initializer: $(TARGET_INIT)
	./$(TARGET_INIT)

# 3. Linken des Hauptprogramms (wartet, bis die Objektdateien bereit sind)
$(TARGET_PERM): $(OBJS_PERM)
	$(CXX) $(CXXFLAGS) $(OBJS_PERM) -o $(TARGET_PERM)

# Einzelne Objektdateien kompilieren
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

permutation.o: permutation.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c permutation.cpp

# Aufräumen
clean:
	rm -f $(TARGET_INIT) $(OBJS_PERM) $(TARGET_PERM)

.PHONY: all run_initializer clean

# Définition du compilateur
CC = gcc

# Listes des fichiers source et du fichier de sortie
FILES = utilitaires.c puissance4.c
OUT_EXE = out_executable

# Règle par défaut pour construire le programme
# Cette règle indique que le fichier exécutable dépend des fichiers source
# et qu'il doit être construit en utilisant le compilateur GCC
build: $(OUT_EXE)

$(OUT_EXE): $(FILES)
    $(CC) -o $@ $^

# Règle pour nettoyer les fichiers générés pendant la construction
clean:
    rm -f $(OUT_EXE) *.o core

# Règle pour reconstruire le programme en nettoyant d'abord les fichiers
rebuild: clean build

# Déclaration de certaines règles comme des "phony targets"
# Cela indique à make que ces règles n'ont pas de dépendances physiques
# et doivent toujours être exécutées lorsqu'elles sont invoquées
.PHONY: build clean rebuild

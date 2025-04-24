# ➕ Implémentation du builtin `exit`

🚫 Aucun argument à gérer : juste `exit`

## 🎯 Objectif

Permettre à l’utilisateur de quitter le shell proprement quand il tape :
```bash
exit
```

## 🧠 Ce qu’on doit faire

1. Détecter si la commande tapée est `"exit"`.

2. Si oui, libérer la mémoire, fermer proprement et quitter le programme avec `exit(0)`.


## 🔹 Tâche 0.4 — Gestion du `exit` (builtin)

- Ajout de `handle_builtin()` dans `builtins.c` et appel dans `exec_cmd()`.

Compilation :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```
Exécution test :

```bash
$ ./simple_shell
$ ls
shell.c shell.h
$ exit
# → Doit quitter sans erreur

```
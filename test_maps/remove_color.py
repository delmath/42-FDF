import re

chemin_fichier = "vangog.fdf"
with open(chemin_fichier, 'r') as fichier:
    contenu = fichier.read()
contenu_modifie = re.sub(r',0x[0-9A-Fa-f]+', '', contenu)
with open(chemin_fichier, 'w') as fichier:
    fichier.write(contenu_modifie)

print("Les chaînes hexadécimales ont été supprimées du fichier.")

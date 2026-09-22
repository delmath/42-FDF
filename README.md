<div align="center">

# FDF — Fil de Fer

**Un moteur de rendu 3D temps réel écrit en C, propulsé par MiniLibX.**

Transforme n'importe quelle carte de hauteur en un monde filaire interactif :
projection isométrique ou perspective, transformations topologiques (tore, sphère),
dégradés de couleurs procéduraux et une caméra entièrement contrôlable à la souris.

[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![School](https://img.shields.io/badge/42-Lyon-000000?style=for-the-badge)](https://42lyon.fr)
[![Renderer](https://img.shields.io/badge/Renderer-MiniLibX-7B68EE?style=for-the-badge)](https://github.com/42Paris/minilibx-linux)
[![Status](https://img.shields.io/badge/Status-Done-success?style=for-the-badge)](#)
[![Norm](https://img.shields.io/badge/Norminette-✓-brightgreen?style=for-the-badge)](#)

<br>

<!-- 👉 REMPLACE cette image par ta plus belle vue (ex. persp_2.png) -->
![FDF hero](imgs/persp_2.png)

</div>

---

## Sommaire

- [Aperçu](#aperçu)
- [Fonctionnalités](#fonctionnalités)
- [Contrôles](#contrôles)
- [Format des cartes](#format-des-cartes)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Architecture](#architecture)
- [Pipeline de rendu](#pipeline-de-rendu)
- [Palettes de couleurs](#palettes-de-couleurs)
- [Auteur](#auteur)

---

## Aperçu

> *« FDF »* (Fil De Fer) prend un fichier texte décrivant une grille de hauteurs
> et en dessine le maillage en perspective. Chaque point du maillage est relié à
> ses voisins par une ligne tracée avec l'algorithme de **Bresenham**, le tout
> interpolé avec un dégradé de couleur en fonction de l'altitude.

<table>
<tr>
<td align="center" width="33%">

**Isométrique** — projection classique du sujet
![Isométrique](imgs/iso.png)

</td>
<td align="center" width="33%">

**Orthographique** — projection sans perspective
![Orthographique](imgs/ortho.png)

</td>
<td align="center" width="33%">

**Perspective** — caméra à focale réelle
![Perspective](imgs/persp_1.png)

</td>
</tr>
<tr>
<td align="center" width="50%">

**Sphère** — enroulement topologique
![Sphère](imgs/sphere.png)

</td>
<td align="center" width="50%">

**Tore** — géométrie en anneau
![Tore](imgs/torus.png)

</td>
</tr>
</table>

---

## Fonctionnalités

| Fonctionnalité | Détail |
|---|---|
| **Double projection** | Orthographique et perspective, commutables à chaud |
| **Caméra libre** | Rotation (yaw / pitch / roll), translation et zoom à la souris |
| **Transformations topologiques** | Maillage replié en **sphère** ou en **tore** |
| **Dégradés de couleurs** | Interpolation RGB sur l'altitude de chaque arête |
| **Presets de terrain** | Earth, Volcanic, Arctic, Martian |
| **Plans de clipping** | Near / far / z-near / z-far réglables |
| **HUD live** | Panneau d'informations affichant l'état de la scène en temps réel |
| **Bouton reset** | Réinitialisation caméra d'un clic |
| **Rendu par image** | Buffer d'image unique + double mise à l'échelle |

---

## Contrôles

### 🖱️ Souris

| Action | Effet |
|---|---|
| **Clic gauche + glisser** | Rotation de la caméra |
| **Clic droit + glisser** | Translation de la caméra |
| **Clic molette + glisser** | Translation sur l'axe Z *(projection non-isométrique)* |
| **Molette haut / bas** | Zoom avant / arrière |
| **Clic sur `reset`** | Réinitialise la position de la caméra |

### ⌨️ Clavier

| Touche | Effet |
|---|---|
| `Échap` | Quitter |
| `I` | Basculer mode isométrique ⟷ libre |
| `P` | Basculer orthographique ⟷ perspective *(mode libre)* |
| `T` | Changer la transformation : `none` → `torus` → `sphere` *(mode iso)* |
| `C` | Changer le preset de couleurs |
| `↑` / `↓` | Sélectionner le paramètre à modifier dans le HUD |
| `R` | Réinitialiser le paramètre sélectionné |
| `KP +` / `KP -` | Augmenter / diminuer le paramètre sélectionné |

### 🎛️ Paramètres modifiables (`↑`/`↓` + `KP +/-`)

```
0 → z_ratio         1 → near        2 → far
3 → z_near          4 → z_far       5 → mouse sensi
```

---

## Format des cartes

Une carte est un simple fichier `.fdf` : une grille de nombres où chaque valeur
représente l'**altitude** du point. Les couleurs optionnelles suivent la syntaxe
`z,0xRRGGBB`.

```text
0  0  0  0  0
0  1  1  1  0
0  1  2  1  0
0  1  1  1  0
0  0  0  0  0
```

Avec couleurs :

```text
0,0xFF0000   10,0x00FF00   0,0xFF0000
10,0x0000FF  20,0xFFFFFF   10,0x0000FF
0,0xFF0000   10,0x00FF00   0,0xFF0000
```

> Le dépôt fournit un large éventail de cartes de test dans `maps/` :
> montagnes, planisphères, portraits, fractales, etc.

---

## Compilation

### Dépendances

```bash
sudo apt-get install gcc make libx11-dev libxext-dev zlib1g-dev
```

### Build

```bash
git clone git@github.com:delmath/fdf.git
cd fdf
make
```

Le `Makefile` compile automatiquement `libft` et `minilibx-linux`, puis génère
le binaire `fdf` avec une barre de progression colorée.

```bash
make        # compile le projet
make clean  # supprime les .o
make fclean # supprime les .o, les libs et le binaire
make re     # recompile entièrement
```

---

## Utilisation

```bash
./fdf maps/42.fdf
```

Quelques cartes intéressantes :

```bash
./fdf maps/mars.fdf
./fdf maps/monalisa_colored.fdf
./fdf maps/hydrochoerus_hydrochaeris.fdf
./fdf maps/MGDS_WHOLE_WORLD_OCEAN1_L.fdf
```

---

## Architecture

```
fdf/
├── include/
│   └── fdf.h              # Structures, defines et prototypes
├── src/
│   ├── main.c             # Point d'entrée
│   ├── init/              # Initialisation scène, caméra, presets
│   ├── math/              # Matrices, projections, transformations
│   ├── mlx/               # Hooks MiniLibX & boucle d'événements
│   ├── render/            # Tracé des lignes, couleurs, HUD
│   └── utils/             # Parsing, math helpers, gestion souris
├── maps/                  # Cartes .fdf d'exemple
├── libft/                 # Bibliothèque C maison
├── minilibx-linux/        # MiniLibX
└── Makefile
```

---

## Pipeline de rendu

```text
 Carte .fdf
     │
     ▼
  Parsing ──► t_map (grille de t_coord)
     │
     ▼
 Transformation ──► sphère / tore (optionnel)
     │
     ▼
 Matrice caméra ──► repère monde ──► repère caméra
     │
     ▼
 Projection ──► orthographique | perspective (+ clipping)
     │
     ▼
 Rasterisation ──► Bresenham + dégradé RGB
     │
     ▼
  Buffer image ──► MiniLibX
```

- **Bresenham** : tracé de lignes incrémental, sans division flottante.
- **Z-order / clipping** : rejet des arêtes hors écran et hors plans de coupe.
- **Dégradé** : interpolation linéaire des canaux RGB le long de chaque arête.

---

## Palettes de couleurs

Chaque preset associe une couleur à cinq paliers d'altitude (très bas → très haut)
et interpole le dégradé le long de chaque arête. Appuie sur `C` pour les faire défiler.

<table>
<tr>
<td align="center" width="33%">
<b>Base</b> <em>(défaut)</em><br>
<img src="imgs/color - base.png" alt="Palette par défaut">
</td>
<td align="center" width="33%">
<b>Earth</b><br>
<img src="imgs/earth.png" alt="Palette Earth">
</td>
<td align="center" width="33%">
<b>Volcanic</b><br>
<img src="imgs/volcanic.png" alt="Palette Volcanic">
</td>
</tr>
<tr>
<td align="center" width="33%">
<b>Arctic</b><br>
<img src="imgs/arctic.png" alt="Palette Arctic">
</td>
<td align="center" width="33%">
<b>Martian</b><br>
<img src="imgs/martian.png" alt="Palette Martian">
</td>
<td></td>
</tr>
</table>

| Preset | Dégradé d'altitude |
|---|---|
| **Earth** | ![0A1F44](https://img.shields.io/badge/-0A1F44-0A1F44?style=flat-square) ![4CAF50](https://img.shields.io/badge/-4CAF50-4CAF50?style=flat-square) ![1B5E20](https://img.shields.io/badge/-1B5E20-1B5E20?style=flat-square) ![795548](https://img.shields.io/badge/-795548-795548?style=flat-square) ![FFFFFF](https://img.shields.io/badge/-FFFFFF-FFFFFF?style=flat-square) |
| **Volcanic** | ![000000](https://img.shields.io/badge/-000000-000000?style=flat-square) ![8B0000](https://img.shields.io/badge/-8B0000-8B0000?style=flat-square) ![FF4500](https://img.shields.io/badge/-FF4500-FF4500?style=flat-square) ![FFA500](https://img.shields.io/badge/-FFA500-FFA500?style=flat-square) ![FFFF00](https://img.shields.io/badge/-FFFF00-FFFF00?style=flat-square) |
| **Arctic** | ![001F3F](https://img.shields.io/badge/-001F3F-001F3F?style=flat-square) ![0074D9](https://img.shields.io/badge/-0074D9-0074D9?style=flat-square) ![7FDBFF](https://img.shields.io/badge/-7FDBFF-7FDBFF?style=flat-square) ![F0F8FF](https://img.shields.io/badge/-F0F8FF-F0F8FF?style=flat-square) ![FFFFFF](https://img.shields.io/badge/-FFFFFF-FFFFFF?style=flat-square) |
| **Martian** | ![4E342E](https://img.shields.io/badge/-4E342E-4E342E?style=flat-square) ![D84315](https://img.shields.io/badge/-D84315-D84315?style=flat-square) ![FF9800](https://img.shields.io/badge/-FF9800-FF9800?style=flat-square) ![FFCC80](https://img.shields.io/badge/-FFCC80-FFCC80?style=flat-square) ![FAEBD7](https://img.shields.io/badge/-FAEBD7-FAEBD7?style=flat-square) |

---

## Auteur

**madelvin** — [42 Lyon](https://42lyon.fr) · `madelvin@student.42lyon.fr`

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-delmath-181717?style=for-the-badge&logo=github)](https://github.com/delmath)

<sub>Projet réalisé dans le cadre du cursus 42.</sub>

</div>

# English

This is a tool that helps with the implementation of translations using 
butane. It supports sprites, regular_bg, affine_bg and strings.

## traduction_converter.py
This is the main file that takes care of converting files to a more manageable format.

To use it you can do the following
```console
python -B traduction_converter.py -d=input_folder -o=output_folder
```
Other functions are:

* Remove invalid characters from input files by passing ````-rmn -rmcsv````
* Choose the delimiter for values in the csv by passing ```-de='delimiter'``` by default ”;”
* Choose whether to recursively traverse the input folder
* Show output of what is being done by passing ```-v```.

## Translations
Generates a file named “traduction_languages.hpp” containing an enum all languages with the following structure 
languages with the following structure

```c++
namespace traduction {
enum languages {
    language_1,
    language_2,
    language_3,
    ...
};
}
```

## Sprites
To use sprites it is necessary to have first the images and json for sprites to be used for [butano](https://gvaliente.github.io/butano/import.html#import_sprite).
To create the translation we create a file with the extension ‘*.trad.json’ with the following structure

```json
{
    "lenguaje_1": "nombre_sprite_1",
    "lenhuaje_2": "nombre_sprite_2",
    ...
}
```

Output generates a file ‘translation_sprite_name_translation_name.hpp’ 
containing reference to the sprite_items

#### Example:

```json
// translations.trad.json
{
    "esp": "sprite_esp",
    "eng": "sprite_eng",
    "fr": "sprite_fr’
}
```

To use it you can do the following
```c++
#include "traduction_sprite_translations.hpp"

traduction::languages language = traduction::languages::eng;

bn::sprite_item sprite_item = traduction::sprite_items::translations(language);

bn::sprite_ptr sprite(sprite_item.create_sprite());
```


## Regular backgrounds

To use regular backgrounds it is necessary to have first the images and json for regular backgrounds to be used for [butano](https://gvaliente.github.io/butano/import.html#import_regular_bg).
To create the translation you create a file with the extension ‘*.trad.json’ with the following structure

```json
{
    "language_1": "regular_name_bg_1",
    "language_2": "regular_bg_name_2",
    ...
}
```

Output generates a file ‘traduction_regular_bg_regular_bg_translation_name.hpp’ 
containing reference to the regular_bg_items.

#### Example:

```json
// translations.trad.json
{
    "esp": "regular_bg_eng",
    "eng": "regular_bg_eng",
    "fr": "regular_bg_fr"
}
```

To use it you can do the following
```c++
#include ‘traduction_regular_bg_translations.hpp’

traduction::languages language = traduction::languages::eng;

bn::regular_bg_item regular_bg_item = traduction::regular_bg_items::translations(language);

bn::regular_bg_ptr regular_bg(regular_bg_item.create_bg());

```

## Affine backgrounds

To use regular backgrounds it is necessary to have first the images and json for regular backgrounds to be used for [butano](https://gvaliente.github.io/butano/import.html#import_affine_bg).
To create the translation you create a file with the extension ‘*.trad.json’ with the following structure

```json
{
    "lenguaje_1": "nombre_affine_bg_1",
    "lenhuaje_2": "nombre_affine_bg_2",
    ...
}
```

Output generates a file ‘traduction_affine_bg_affine_bg_translation_name.hpp’ 
containing reference to the affine_bg_items.

#### Example:

```json
// translations.trad.json
{
    "esp": "affine_bg_eng",
    "eng": "affine_bg_eng",
    "fr": "affine_bg_fr"
}
```

To use it you can do the following
```c++
#include "traduction_affine_affine_bg_translations.hpp"

traduction::languages language = traduction::languages::eng;

bn::affine_bg_item affine_bg_item = traduction::affine_bg_items::translations(language);

bn::affine_bg_ptr affine_bg(affine_bg_item.create_bg());
```

## Strings

To use strings you need a ‘*.csv’ file, which when opened with an excel-like program has the following structure.
|            | language_1       | language_2       |
| ---------- | ---------------- |:---------------: |
| key_name_1 | language_1 value | language_2 value |
| key_name_2 | language_1_value | language_2_value |
| ...        | ...              | ...              |

Output generates ‘traduction_string_translation_name.hpp’ containing reference to translations

#### Example:

// translations.csv
|           | esp   | eng   | fr        |
| --------- | ----- | ----- |:--------: |
| greeting  | Hola  | Hello | Bonjour   |
| fasewell  | Adiós | Bye   | Au revoir |


To use it you can do the following

```c++
#include ‘traduction_string_traslations.hpp’

traduction::languages language = traduction::languages::eng;

bn::string<10> greeting = traduction::string::greeting(language);
bn::string<10> farewell = traduction::string::farewell(language);
```

#
#
# Español {#espanol}
Esto es ua herramienta que ayuda con la implementacion de traducciones usando 
butano. Soporta sprites, regular_bg, affine_bg y strings.

## traduction_converter.py {#esp_traduction_converter}
Es el archivo principal que se encarga de la conversion de los archivos a un formato mas facil de manejar.

Para usarlo se puede hacer lo siguiente
```console
python -B traduction_converter.py -d=input_folder -o=output_folder
```
Otras funciones son:

* Eliminar caracteres invalidos de los archivos de entrada pasando ```-rmn -rmcsv```
* Elegir el delimitador para los valores en el csv pasando ```-de='delimitador'``` por defecto es ";"
* Elegir si recorrer de manera recursiva la carpeta de entrada
* Mostrar output de lo que se va haciendo pasando ```-v```

## Traducciones
Genera un archivo llamado "traduction_languages.hpp" que contiene un enum todos 
los lenguajes con la siguiente estructura

```c++
namespace traduction {
enum languages {
    language_1,
    language_2,
    language_3,
    ...
};
}
```

## Sprites
Para usar sprites es necesario tener primero las imagenes y json para sprites que sirvan para [butano](https://gvaliente.github.io/butano/import.html#import_sprite).
Para crear la traduccion se crea un archivo con la extencion "*.trad.json" con la siguiente estructura

```json
{
    "lenguaje_1": "nombre_sprite_1",
    "lenhuaje_2": "nombre_sprite_2",
    ...
}
```

De salida genera un archivo "traduction_sprite_nombre_traduccion.hpp" 
que contiene referencia a los sprite_items

#### Ejemplo:

```json
// traducciones.trad.json
{
    "esp": "sprite_esp",
    "eng": "sprite_eng",
    "fr": "sprite_fr"
}
```

Para usarlo se puede hacer lo siguiente
```c++
#include "traduction_sprite_traducciones.hpp"

traduction::languages language = traduction::languages::esp;

bn::sprite_item sprite_item = traduction::sprite_items::traducciones(language);

bn::sprite_ptr sprite(sprite_item.create_sprite());
```

## Regular backgrounds

Para usar regular backgrounds es necesario tener primero las imagenes y json para regular backgrounds que sirvan para [butano](https://gvaliente.github.io/butano/import.html#import_regular_bg).
Para crear la traduccion se crea un archivo con la extencion "*.trad.json" con la siguiente estructura

```json
{
    "lenguaje_1": "nombre_regular_bg_1",
    "lenhuaje_2": "nombre_regular_bg_2",
    ...
}
```

De salida genera un archivo "traduction_regular_bg_nombre_traduccion.hpp" 
que contiene referencia a los regular_bg_items

#### Ejemplo:

```json
// traducciones.trad.json
{
    "esp": "regular_bg_esp",
    "eng": "regular_bg_eng",
    "fr": "regular_bg_fr"
}
```

Para usarlo se puede hacer lo siguiente
```c++
#include "traduction_regular_bg_traducciones.hpp"

traduction::languages language = traduction::languages::esp;

bn::regular_bg_item regular_bg_item = traduction::regular_bg_items::traducciones(language);

bn::regular_bg_ptr regular_bg(regular_bg_item.create_bg());

```

## Affine backgrounds

Para usar regular backgrounds es necesario tener primero las imagenes y json para regular backgrounds que sirvan para [butano](https://gvaliente.github.io/butano/import.html#import_affine_bg).
Para crear la traduccion se crea un archivo con la extencion "*.trad.json" con la siguiente estructura

```json
{
    "lenguaje_1": "nombre_affine_bg_1",
    "lenhuaje_2": "nombre_affine_bg_2",
    ...
}
```

De salida genera un archivo "traduction_affine_bg_nombre_traduccion.hpp" 
que contiene referencia a los affine_bg_items

#### Ejemplo:

```json
// traducciones.trad.json
{
    "esp": "affine_bg_esp",
    "eng": "affine_bg_eng",
    "fr": "affine_bg_fr"
}
```

Para usarlo se puede hacer lo siguiente
```c++
#include "traduction_affine_bg_traducciones.hpp"

traduction::languages language = traduction::languages::esp;

bn::affine_bg_item affine_bg_item = traduction::affine_bg_items::traducciones(language);

bn::affine_bg_ptr affine_bg(affine_bg_item.create_bg());
```

## Strings

Para usar strings es necesario un archivo "*.csv", que al abrirlo con un programa tipo excel tenga la siguiente estructura.
|                | lenguaje_1       | lenguaje_2       |
| -------------- | ---------------- |:---------------: |
| nombre_clave_1 | valor lenguaje 1 | valor lenguaje 2 |
| nombre_clave_2 | valor lenguaje 1 | valor lenguaje 2 |
| ...            | ...              | ...              |

De salida genera "traduction_string_nombre_traduccion.hpp" que contiene referencia a las traducciones

#### Ejemplo:

// tradicciones.csv

|           | esp   | eng   | fr        |
| --------- | ----- | ----- |:--------: |
| saludo    | Hola  | Hello | Bonjour   |
| despedida | Adiós | Bye   | Au revoir |

Para usarlo se puede hacer lo siguiente

```c++
#include "traduction_string_traducciones.hpp"

traduction::languages language = traduction::languages::esp;

bn::string<10> saludo = traduction::string::saludo(language);
bn::string<10> despedida = traduction::string::despedida(language);
```
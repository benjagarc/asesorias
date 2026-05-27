# Asesorías de C++

Repositorio con ejercicios y ejemplos de las asesorías de programación en C++.

## Estructura del proyecto

```
asesorias/
├── fundamentos/          # Conceptos básicos de C++
│   ├── variables.cpp
│   ├── funciones.cpp
│   ├── ciclos.cpp
│   ├── entrada_datos.cpp
│   ├── imprimir_arreglos.cpp
│   ├── early_returns.cpp
│   ├── alias_cout_cin.cpp
│   ├── colores.cpp
│   └── pruebas.cpp
├── POO/                  # Programación Orientada a Objetos
│   ├── herencia.cpp
│   ├── prueba-herencia.cpp
│   ├── main.cpp
│   └── test.cpp
├── .vscode/              # Configuración de VS Code
└── README.md
```

## Requisitos

- Compilador de C++ (g++ recomendado)
- VS Code (opcional, pero incluye configuración de tareas y debug)

## Cómo compilar

Desde la terminal, dentro de la carpeta del archivo que quieras ejecutar:

```bash
g++ -o nombre_ejecutable archivo.cpp
./nombre_ejecutable
```

Ejemplo:

```bash
cd POO
g++ -o herencia herencia.cpp
./herencia
```

> En Windows usa `herencia.exe` en lugar de `./herencia`.

## Temas cubiertos

### Fundamentos
- Variables y tipos de datos
- Funciones
- Ciclos y condicionales
- Entrada y salida de datos
- Arreglos
- Early returns
- Uso de `cout`/`cin` y aliases

### POO
- Clases y objetos
- Herencia
- Polimorfismo

## Notas

- Los archivos `.exe` y `.log` están ignorados por Git (ver `.gitignore`).
- Si encuentras algún error o tienes dudas, abre un issue o pregunta en la asesoría.

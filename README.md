# prestige
Prestige is a robust language oriented towards game developers to swiftly create and deploy games for the HTML5 Canvas (and, soon, pygame). It compiles directly to JavaScript and HTML and has a fully-fledged package management system.

## Installing
[On every release](https://github.com/prestigeengine/prestige/releases), there is a build added for Windows (x86) and Linux (x86). You can download the executable directly from there and add it to your PATH variables.

## Building
To build Prestige you will need:
- gcc or another C++ compiler
- `make`
- git

Initially, clone the Prestige repository and change to the Prestige directory.
```
git clone https://github.com/prestigeengine/prestige && cd prestige
```

If you're using GCC and you're on UNIX, you can compile using `make fc-linux`, and the code will be compiled to `compiler.out` and will be ran. 

If you simply want to compile, but not immediately run, use `make compile-only-linux`.

Otherwise, simply use your own compiler to do this. 

On Windows, with GCC: `gcc -o compiler.exe main.cpp test/* compile/javascript/* manifest/* cat/* -I. -lstdc++`


## Usage
### Compilation
When compiling a Prestige file, you need two files, `<main_file_name>.pres` and `manifest.txt`. 

Your Prestige file should contain your code and your manifest file should contain any extra information needed to run the project - such as images. 
```
CMP: javascript
IMG: hello "https://fakeurl.fake/lol.png"
IMG: other_image "https://fakeurl.fake/lol2.png"
PKG: some_package
PKG: some_other_package
```

Your compilation should look something like this:
```
prestige main.pres manifest.txt
```

### Manifest options
| Option | Meaning | Usage |  Default | Limit |
|:------:|:-------:|:------:|:--------:|:-----:|
| CMP    | Language to compile to. | `CMP: javascript` | `javascript` | 1 |
| IMG    | Image name and URL. | `IMG: <name> <url>` | none | none |
| PKG    | Project needs a package from the ppm directory. | `PKG: <name>` | none | none |


### Usage with ppm
[ppm](https://github.com/prestigeengine/ppm), or, the Prestige Package Manager, is the tool used to get package from the ppm directory. 

**ppm is not included with Prestige, you need to install it seperately.**

If you need to add a package into your project, simply add it to your manifest file (`PKG`) and install it with ppm.
```
ppm install super-good-package
```

To install all packages required by your project in the manifest, simply do 
```
ppm pr-install
```

## Roadmap 
You can see our roadmap [here](https://github.com/prestigeengine/prestige/projects/1).
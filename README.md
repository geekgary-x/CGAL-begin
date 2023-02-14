# CGAL-begin

## how to use it
```bash
# clone repository and submodule

git clone --recursive https://github.com/StoneHappy/CGAL-begin.git

# create buid dir

mkdir build

# generate build project
cmake ..
```
## Recommended to use vscode for configure
Recommended plug-ins:
```
CMake
CMake Tools
Git History
git-commit-plugin 
```

Install plug-ins, ``Ctrl + Shift + P`` call ``CMake: Configure`` to generate ninja config file.

``CMake: Run Without Debug`` to run target, the arguements was configured in ``.vscode/settings.json``

debug configure in ``.vscode/launch.json``

## CGAL chinese documents notes

[中文文档](doc/CGAL-doc-CN.md)
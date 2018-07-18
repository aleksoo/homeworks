PREREQUISITES
============================

1. Python 2.5+, recommended 2.7

2. For all tasks there should be used only Python standard library
   and modules provided in "lib" directory


REQUIREMENTS
=======================

1. PEP-8 (http://www.python.org/dev/peps/pep-0008/)
----------------------------------------------------------

  a) use 4 spaces per indentation level
  b) use **ONLY** spaces for indentation, tabs are **NOT ALLOWED** ("python -tt" is your friend)
  c) in case of non-ascii characters specify source file encoding as utf-8
  d) imports: every module in separate line, "from <whatever> import \*" is **FORBIDDEN**
  e) documentation strings at least for functions
  f) consistent naming style, e.g.: 

     * functions/methods: lower_case_with_underscores
     * classes/types:     CamelCase
     * constants:         ALL_CAPS


2. Module Structure
-------------------------------

::

    """module docstring"""

    # imports
    # constants
    # exception classes
    # interface functions
    # classes
    # internal functions & classes

    def main(...):
        ...

    if __name__ == '__main__':
        main()


3. Don't reinvent the wheel, always check Python's standard library.
------------------------------------------------------------------------------

4. refer to "Code Like a Pythonista: Idiomatic Python" often for Python idioms
---------------------------------------------------------------------------------


REVIEW
==================

When program is ready for review please perform following steps:

1. Open setup.py file and replace line "author='<Your name>'" with real name
--------------------------------------------------------------------------------


2. Execute command "python setup.py check_tabs" in order to check if there are any TABs in files e.g.:
--------------------------------------------------------------------------------------------------------

::

    $ python setup.py check_tabs
    running check_tabs
    ERROR: TABs in <.\main.py>

Correct all files until there is no error.


3. Execute command "python setup.py sdist" in order to create source package in subdirectory "dist", e.g:
------------------------------------------------------------------------------------------------------------

::

    $ python setup.py sdist
    running sdist
    running check
    [...]
    creating wordcount-1.0
    copying files to wordcount-1.0...
    [...]
    creating dist
    creating 'dist\wordcount-1.0.zip' and adding 'wordcount-1.0' to it

4. Send me package "dist/<package-name>-<package-version>.zip" created in step 3
--------------------------------------------------------------------------------------


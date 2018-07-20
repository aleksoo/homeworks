
import os
from os.path import join, normpath, dirname, basename, splitext
import sys
import getopt
import logging
import fnmatch

import commands


def load_commands():
    '''
    Load commands from external modules
    located in subdirectory `commands`
    '''
    path = normpath(join(dirname(__file__), 'commands'))
    cmdlst = os.listdir(path)
    cmdlst = fnmatch.filter(cmdlst, '*.py')
    cmdlst = map(lambda p: splitext(p)[0], cmdlst)
    if not path in sys.path:
        sys.path.insert(0, path)
    for cmd in cmdlst:
        mod = __import__(cmd, globals(), locals(), [])
        if not mod:
            raise RuntimeError('Module <%s> import failed!' % cmd)


def _configlog(loglevel):
    '''
    Configure logging
    '''
    # !!!Your code here!!!

    logger = logging.getLogger(__name__)
    logging.basicConfig(level = loglevel)
    return logger


def _usage(prog):
    '''
    Display program help message to standard output
    '''
    s = 'Usage: %s [-h | --help] [-v | --verbose]'
    # add information about available commands in subdirectory `commands`
    # in the form:
    #     <command name>           - <command description>
    # !!!Your code here!!!


    for i in prog:
        print (s % basename(prog))
    sys.exit(1)


def main(argv):
    loglevel = logging.ERROR
    load_commands()

    # handle input switches and parameters using `getopt.getopt` function
    # there should be handled following switches:
    # -h and --help   - display help message prepared in _usage function above
    # -v and --verbose  - display additional debug ouput, set log level as logging.DEBUG
    #
    # There should be accepted only one input parameter, namely <command name>
    #
    # Missing input parameters should cause displaying help message.
    # Wrong command name in the first parameter, should cause displaying error message.

    # !!!Your code here!!!

    loglevel = logging.DEBUG



    try:
        opts, args = getopt.getopt(argv[1:], 'h:v', ['help', 'verbose'])
    except getopt.GetoptError as err:
        print(err)
        _usage(args[0])
        sys.exit(2)

    verbose = False

    for o in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        if (o in ("-h", "--help")) and verbose:
            _usage(argv[0])
            sys.exit()

    for a in args:
        if a not in ("-v", "--verbose", "-h", "--help"):
            command = a
            #print(command)
            break


    logger = _configlog(loglevel)
    logger.debug('START')
    try:
        cmdclass = commands.get_command(command)
        # execute command provided by user as first parameter
        # `cmdclass` it should be class, which implements given command
        # this class should be instantiated with appropriate arguments
        # and `execute` method of this instance should be called
        #
        # !!!Your code here!!!
        cmd = cmdclass()
        cmd.execute()
        
        
        #tutaj nizej dalem "as" w miejsce przecinka, w razie czego zamienic
    except Exception as ex:
        logger.error('Command error: %s' % ex)
    logger.debug('DONE')


if __name__ == '__main__':
    main(sys.argv)

import subprocess as sp
import logging

class Command(object):
    cmd_name = ''           # command name
    cmd_description = ''    # command description
    
    def __init__(self, args=None, loglevel=logging.ERROR):
        self.args = args
        self.logger = logging.getLogger(self.__class__.__name__)
        self.logger.setLevel(loglevel)
    
    def execute(self):
        '''Execute command'''
        raise NotImplementedError('Method must be implemented in subclass')

    def _run(self, args):
        '''Run subprocess'''
        command = ' '.join(args)
        self.logger.info('Command: %s' % command)
        p = sp.Popen(command, stdout=sp.PIPE, stderr=sp.PIPE, shell=True)
        # read stdout
        while True: 
            line = p.stdout.readline() 
            if not line: break
            self.logger.debug('output: %r' % line)
        # read stderr
        while True: 
            line = p.stderr.readline() 
            if not line: break
            self.logger.debug('error: %r' % line)


def get_commands_all():
    '''
    Get all `Command` class subclasses
    '''
    # !!!Your code here!!!


def get_command(name):
    '''
    Get `Command` class subclass with given name.
    If not found raise exception informing that given command is not implemented.
    '''
    # !!!Your code here!!!
import apachelog


def get_largest(log):
    '''
    Find the largest data transfer in the given `log` sequence
    '''
    # !!!Your code here!!!


def main():
    '''Main function'''
    lines = apachelog.lines_from_dir('access-log*', 'www')
    log = apachelog.apache_log(lines)
    print '%d %s' % get_largest(log)


if __name__ == '__main__':
    main()

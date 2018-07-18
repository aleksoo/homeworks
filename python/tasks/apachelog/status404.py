import apachelog


def get_404(log):
    '''
    Find the set of all requests with status 404 in the given `log` sequence
    '''
    # !!!Your code here!!!


def main():
    '''Main function'''
    lines = apachelog.lines_from_dir('access-log*', 'www')
    log = apachelog.apache_log(lines)
    for r in sorted(get_404(log)):
        print r


if __name__ == '__main__':
    main()

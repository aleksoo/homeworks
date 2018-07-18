import apachelog


def get_downloads_count(log, fpath):
    '''
    Count number of downloads of file `fpath` in the given log sequence
    '''
    # !!!Your code here!!!


def main():
    '''Main function'''
    lines = apachelog.lines_from_dir('access-log*', 'www')
    log = apachelog.apache_log(lines)
    print 'Total: %d' % get_downloads_count(log, '/ply/ply-2.3.tar.gz')
    

if __name__ == '__main__':
    main()
